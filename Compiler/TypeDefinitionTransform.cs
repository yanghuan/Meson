using System;
using System.Collections.Generic;
using System.Diagnostics.Contracts;
using System.Linq;
using System.Reflection;

using ICSharpCode.Decompiler.TypeSystem;
using Meson.Compiler.CppAst;

namespace Meson.Compiler {
  internal class TypeDefinitionTransform {
    public CompilationUnitTransform CompilationUnit { get; }
    public AssemblyTransform AssemblyTransform => CompilationUnit.AssemblyTransform;
    public SyntaxGenerator Generator => AssemblyTransform.Generator;
    private readonly BlockSyntax parent_;
    private readonly List<ITypeDefinition> types_;
    private readonly TypeDefinitionTransform parentTransform_;
    private readonly Dictionary<ITypeDefinition, ITypeDefinition> nestedCycleTypes_ = new Dictionary<ITypeDefinition, ITypeDefinition>();
    private readonly Dictionary<ITypeDefinition, List<IMember>> typeMemberCaches_ = new Dictionary<ITypeDefinition, List<IMember>>();

    public TypeDefinitionTransform(CompilationUnitTransform compilationUnit, BlockSyntax parent, IEnumerable<ITypeDefinition> types, TypeDefinitionTransform parentTransform = null) {
      CompilationUnit = compilationUnit;
      types_ = types.ToList();
      parent_ = parent;
      parentTransform_ = parentTransform;
      Visit();
    }

    public bool IsMulti => types_.Count > 1;
    public bool HasRef => types_.Exists(i => i.IsRefType());
    private ITypeDefinition Root => types_.First();
    public IdentifierSyntax GetMemberName(ISymbol symbol) => Generator.GetMemberName(symbol);

    private void Visit() {
      if (IsMulti) {
        int typeParameterCount = types_.Last().TypeParameterCount + 1;
        ClassSyntax node = new ClassSyntax(Root.Name, Root.Kind == TypeKind.Struct) {
          Template = typeParameterCount.GetVoidTemplate(),
          Kind = HasRef ? ClassKind.MultiRefForward : ClassKind.None,
        };
        parent_.Add(node);
      }

      foreach (var type in types_) {
        var referenceType = parentTransform_?.nestedCycleTypes_.GetOrDefault(type);
        if (referenceType != null) {
          var forward = referenceType.GetNestedForwardStatement();
          forward.AccessibilityToken = GetAccessibilityString(referenceType);
          parent_.Add(forward);
        }
        VisitTypeDefinition(type);
      }
    }

    private void VisitTypeDefinition(ITypeDefinition type) {
      switch (type.Kind) {
        case TypeKind.Enum: {
            VistEnum(type);
            break;
          }
        case TypeKind.Struct: {
            VisitStruct(type);
            break;
          }
        default: {
            VistClass(type);
            break;
          }
      }
    }

    private void VistEnum(ITypeDefinition type) {
      EnumSyntax node = new EnumSyntax(type.Name) {
        AccessibilityToken = GetAccessibilityString(type),
        UnderlyingType = type.GetEnumUnderlyingTypeName(),
      };
      VisitEnumFields(type, node);
      parent_.Add(node);
    }

    private void VisitEnumFields(ITypeDefinition typeDefinition, EnumSyntax node) {
      foreach (var field in typeDefinition.Fields) {
        if (field.Name != "value__") {
          object v = field.GetConstantValue();
          // https://stackoverflow.com/questions/14695118/2147483648-0-returns-true-in-c
          if (v.Equals(int.MinValue)) {
            v = $"{int.MinValue + 1} - 1";
          }
          var fieldName = GetMemberName(field);
          node.Add(new EnumFieldSyntax(fieldName, v.ToString()));
        }
      }
    }

    private void VisitStruct(ITypeDefinition type) {
      var template = type.GetTemplateSyntax();
      ClassSyntax node = new ClassSyntax(type.Name, true) {
        Template = template,
        Kind = GetClassKind(type),
        AccessibilityToken = GetAccessibilityString(type),
      };
      var baseType = type.DirectBaseTypes.First();
      Contract.Assert(baseType.IsKnownType(KnownTypeCode.ValueType));
      CompilationUnit.GetTypeName(new TypeNameArgs() {
        Type = baseType,
        Definition = type,
        IsForward = false,
        IsInHead = true,
      });
      IdentifierSyntax typeArgument;
      if (template == null) {
        typeArgument = Generator.IsVoidGenericType(type) ? node.Name.Generic() : node.Name;
      } else {
        typeArgument = node.Name.Generic(template.TypeNames);
      }
      node.Bases.Add(new BaseSyntax(((IdentifierSyntax)baseType.Name.FirstCharLow()).Generic(typeArgument)));
      AddInterfaces(type, node, type.DirectBaseTypes.Skip(1));
      parent_.Add(node);
      VisitMembers(type, node);
    }

    private ClassKind GetClassKind(ITypeDefinition type) {
      if (IsMulti) {
        return types_.Exists(i => i.IsRefType()) ? ClassKind.MultiRef : ClassKind.Multi;
      }

      if (type.IsArrayType()) {
        return ClassKind.Array;
      }

      return type.IsRefType() ? ClassKind.Ref : ClassKind.None;
    }

    private ExpressionSyntax GetInterfaceType(ITypeDefinition definition, IType type) {
      return CompilationUnit.GetTypeName(new TypeNameArgs() {
        Type = type,
        Definition = definition,
        IsInHead = true,
        IsForward = true,
      });
    }

    private void AddInterfaces(ITypeDefinition type, ClassSyntax node, IEnumerable<IType> interfaces) {
      if (interfaces.Any()) {
        var interfaceTypes = interfaces.Select(i => GetInterfaceType(type, i));
        node.Add(new UsingDeclarationSyntax(IdentifierSyntax.Interface, IdentifierSyntax.TypeList.Generic(interfaceTypes)) {
          AccessibilityToken = Accessibility.Public.ToTokenString(),
        });
      }
    }

    private void VistClass(ITypeDefinition type) {
      var template = type.GetTemplateSyntax();
      ClassSyntax node = new ClassSyntax(type.Name) {
        Template = template,
        Kind = GetClassKind(type),
        AccessibilityToken = GetAccessibilityString(type),
      };
      if (!type.IsStatic) {
        var firstBaseType = type.DirectBaseTypes.FirstOrDefault();
        if (firstBaseType != null) {
          IEnumerable<IType> interfaces;
          if (firstBaseType.Kind == TypeKind.Class) {
            var baseTypeName = CompilationUnit.GetTypeName(new TypeNameArgs() {
              Type = firstBaseType,
              Definition = type,
              IsInHead = true,
            });
            node.Bases.Add(new BaseSyntax(baseTypeName.WithIn()));
            interfaces = type.DirectBaseTypes.Skip(1);
          } else {
            interfaces = type.DirectBaseTypes;
          }
          AddInterfaces(type, node, interfaces);
        }
      }
      parent_.Add(node);
      if (node.Kind == ClassKind.Array) {
        ClassSyntax array = new ClassSyntax(node.Name) {
          Template = TemplateSyntax.T,
          Kind = ClassKind.MultiRef,
        };
        var baseType = IdentifierSyntax.Meson.TwoColon(((IdentifierSyntax)type.Name).Generic(IdentifierSyntax.T, node.Name.Generic().WithIn()));
        array.Bases.Add(new BaseSyntax(baseType));
        parent_.Add(array);
      }
      VisitMembers(type, node);
    }

    private bool IsExportMethod(IMethod method) {
      if (method.Name.Contains('<')) {
        return false;
      }

      if (method.IsConstructor) {
        if (method.DeclaringTypeDefinition.IsStringType()) {
          return false;
        }
      } else if (method.Name.Contains('.')) {
        return false;
      }

      return true;
    }

    internal void CheckOperatorParameters(IMethod method, List<ParameterSyntax> parameters, ExpressionSyntax returnType) {
      if (method.SymbolKind == SymbolKind.Operator && method.Name == "op_Explicit") {
        if (method.DeclaringTypeDefinition.Methods.Any(i => i != method && i.Name == method.Name && i.Parameters.First().Type == method.Parameters.First().Type)) {
          parameters.Add(new ParameterSyntax(returnType, null));
        }
      }
    }

    internal IdentifierSyntax GetPropertyFieldName(ITypeDefinition typeDefinition, IProperty property) {
      string fieldName = property.GetBackingFieldName();
      var field = typeDefinition.Fields.First(i => i.Name == fieldName);
      Contract.Assert(field != null);
      return Generator.GetMemberName(field);
    }

    private void CheckStructDefaultParameters(IMethod method, MethodDefinitionSyntax methodDefinition) {
      int index = 0;
      foreach (var parameter in methodDefinition.Parameters) {
        if (parameter.Value == IdentifierSyntax.Default) {
          var parameterSymbol = method.Parameters[index];
          if (parameterSymbol.Type.Kind != TypeKind.TypeParameter) {
            Contract.Assert(parameterSymbol.Type.Kind == TypeKind.Struct);
            var template = methodDefinition.Template;
            if (template == null) {
              template = new TemplateSyntax();
              methodDefinition.Template = template;
            }
            IdentifierSyntax name = "T" + template.Arguments.Count;
            template.Arguments.Add(new TemplateTypenameSyntax(name, parameter.Type));
            parameter.Type = name;
          }
        }
        ++index;
      }
    }

    private void VisitMethod(IMethod method, ITypeDefinition typeDefinition, ClassSyntax node) {
      bool isCtor = method.IsCtor();
      if (isCtor && !method.HasBody) {
        bool hasOtherCtor = typeDefinition.Methods.Any(i => i.SymbolKind == SymbolKind.Constructor && i != method && !i.IsStatic);
        if (!hasOtherCtor) {
          return;
        }
      }

      var parameters = method.Parameters.Select(i => GetParameterSyntax(i, method, typeDefinition)).ToList();
      MethodDefinitionSyntax methodDefinition;
      if (isCtor) {
        methodDefinition = new MethodDefinitionSyntax(node.Name, parameters) {
          IsExplicit = true,
          AccessibilityToken = method.Accessibility.ToTokenString(),
        };
      } else {
        var methodName = GetMemberName(method);
        var returnType = GetRetuenTypeSyntax(method, typeDefinition);
        CheckOperatorParameters(method, parameters, returnType);
        methodDefinition = new MethodDefinitionSyntax(methodName, parameters, returnType) {
          Template = method.GetTemplateSyntax(),
          IsStatic = method.IsStatic,
          AccessibilityToken = !method.IsMainEntryPoint() ? method.Accessibility.ToTokenString() : Tokens.Public,
        };
        CheckStructDefaultParameters(method, methodDefinition);
      }
      node.Statements.Add(methodDefinition);
      if (method.HasBody) {
        if ((!method.IsStatic || method.ReturnType.IsReferenceType == true) && method.AccessorOwner is IProperty property && property.IsPropertyField()) {
          var fieldName = GetPropertyFieldName(typeDefinition, property);
          if (method.AccessorKind == MethodSemanticsAttributes.Getter) {
            methodDefinition.Body = new BlockSyntax(new ReturnStatementSyntax(fieldName)) { IsSingleLine = true };
          } else {
            methodDefinition.Body = new BlockSyntax(new BinaryExpressionSyntax(fieldName, Tokens.Equals, IdentifierSyntax.Value)) { IsSingleLine = true };
          }
        } else {
          if (typeDefinition.TypeParameterCount == 0 && method.TypeParameters.Count == 0 && method.TypeArguments.Count == 0) {
            new MethodTransform(this, method, node);
          }
        }
      } else {
        if (isCtor) {
          methodDefinition.Body = new BlockSyntax() { IsSingleLine = true };
        }
      }
    }

    private void VisitMethods(ITypeDefinition typeDefinition, ClassSyntax node) {
      foreach (var method in typeDefinition.Methods.Where(IsExportMethod)) {
        VisitMethod(method, typeDefinition, node);
      }
    }

    private ExpressionSyntax GetRetuenTypeSyntax(IMethod method, ITypeDefinition typeDefinition) {
      return CompilationUnit.GetTypeName(new TypeNameArgs {
        Type = method.ReturnType,
        Definition = typeDefinition,
        IsForward = true,
        IsInHead = true,
        Original = method.ReturnType,
        Symbol = method,
      });
    }

    private ExpressionSyntax GetDefaultEnumValue(IParameter parameter, object constValue, ExpressionSyntax typeName) {
      var fields = parameter.Type.GetDefinition().Fields;
      var field = fields.FirstOrDefault(i => constValue.Equals(i.GetConstantValue()));
      if (field != null) {
        return typeName.TwoColon(field.Name);
      }
      long v = Convert.ToInt64(constValue);
      ExpressionSyntax value = null;
      long v1 = 0;
      foreach (var f in fields.Skip(1)) {
        long fieldValue = Convert.ToInt64(f.GetConstantValue());
        if ((v & fieldValue) != 0) {
          if (value == null) {
            value = typeName.TwoColon(f.Name);
            v1 = fieldValue;
          } else {
            value = value.Binary(Tokens.BitOr, typeName.TwoColon(f.Name));
            v1 |= fieldValue;
          }
          if (v == v1) {
            return value;
          }
        }
      }
      return constValue.ToString().Identifier().CastTo(typeName);
    }

    private ExpressionSyntax GetDefaultParameterValue(IParameter parameter, ExpressionSyntax parametertype) {
      var constValue = parameter.GetConstantValue();
      ExpressionSyntax defaultValue;
      if (constValue == null) {
        defaultValue = parameter.Type.IsReferenceType == true ? IdentifierSyntax.Nullptr : IdentifierSyntax.Default;
      } else if (parameter.Type.Kind == TypeKind.Enum) {
        defaultValue = GetDefaultEnumValue(parameter, constValue, parametertype);
      } else {
        defaultValue = Utils.GetPrimitiveExpression(constValue);
      }
      return defaultValue;
    }

    private ParameterSyntax GetParameterSyntax(IParameter parameter, IMethod method, ITypeDefinition typeDefinition) {
      var type = CompilationUnit.GetTypeName(new TypeNameArgs {
        Type = parameter.Type,
        Definition = typeDefinition,
        IsForward = true,
        IsInHead = true,
        Original = parameter.Type,
        Symbol = parameter,
      });
      CheckParameterTypeConflict(ref type, parameter, method, typeDefinition);
      var name = GetMemberName(parameter);
      ExpressionSyntax value;
      if (parameter.HasConstantValueInSignature) {
        value = GetDefaultParameterValue(parameter, type);
      } else {
        value = null;
      }
      return new ParameterSyntax(type, name, value);
    }

    public List<IMember> GetTypeMembersFromCache(ITypeDefinition typeDefinition) {
      var members = typeMemberCaches_.GetOrDefault(typeDefinition);
      if (members == null) {
        members = typeDefinition.GetAllMembers().ToList();
        typeMemberCaches_.Add(typeDefinition, members);
      }
      return members;
    }

    public void CheckParameterTypeConflict(ref ExpressionSyntax type, IParameter parameter, IMethod method, ITypeDefinition typeDefinition) {
      var members = GetTypeMembersFromCache(typeDefinition);
      foreach (var m in members) {
        if (m.Equals(method)) {
          break;
        }
        if (parameter.Type.Name == m.GetMemberName()) {
          type = type.WithFullName(parameter.Type, typeDefinition);
          break;
        }
      }
    }

    private static bool IsValueTypeInnerField(IField field, ITypeDefinition typeDefinition, out ExpressionSyntax typeName) {
      if (typeDefinition.Kind == TypeKind.Struct && (!field.IsStatic || field.IsConst) && field.Type == typeDefinition) {
        string name = field.Type.GetValueTypeInnerName();
        if (name != null) {
          typeName = (IdentifierSyntax)name;
          return true;
        }
      }
      typeName = null;
      return false;
    }

    private static bool IsFieldExport(IField field) {
      if (field.IsConst) {
        if (field.Type.IsString()) {
          return false;
        }
        if (field.Type.IsDecimal()) {
          return false;
        }
        if (field.Type.Kind == TypeKind.Enum) {
          return false;
        }
      }
      return true;
    }

    private bool GetFieldNameAndType(ITypeDefinition typeDefinition, ClassSyntax node, IField field, out IdentifierSyntax fieldName, out ExpressionSyntax typeName) {
      bool isPrimitiveType = false;
      fieldName = GetMemberName(field);
      if (IsValueTypeInnerField(field, typeDefinition, out typeName)) {
        isPrimitiveType = true;
      } else {
        typeName = GetFieldTypeName(field, typeDefinition);
      }
      return isPrimitiveType;
    }

    private void VisitFields(ITypeDefinition typeDefinition, ClassSyntax node) {
      foreach (var field in typeDefinition.Fields.Where(IsFieldExport)) {
        bool isPrimitiveType = GetFieldNameAndType(typeDefinition, node, field, out var fieldName, out var typeName);
        Contract.Assert(typeName != null);
        var constantValue = field.GetConstantValue();
        node.Statements.Add(new FieldDefinitionSyntax(typeName, fieldName, field.IsStatic, field.Accessibility.ToTokenString()) {
          IsConstexpr = field.IsConst,
          ConstantValue = field.IsConst ? Utils.GetPrimitiveExpression(constantValue, isPrimitiveType) : null,
        });
      }
    }

    private bool CheckFixedBufferField(IField field, ITypeDefinition typeDefinition, out ExpressionSyntax result) {
      if (field.Type.Name.StartsWith('<')) {
        var attr = field.GetAttribute(KnownAttribute.FixedBuffer);
        if (attr != null) {
          var type = (IType)attr.FixedArguments[0].Value;
          int size = (int)attr.FixedArguments[1].Value;
          var name = CompilationUnit.GetTypeName(new TypeNameArgs {
            Type = type,
            Definition = typeDefinition,
            IsForward = field.IsStatic,
            IsInHead = true,
            Original = type,
            Symbol = field,
          });
          result = new GenericIdentifierSyntax(IdentifierSyntax.FixedBuffer, name, (IdentifierSyntax)size.ToString());
          return true;
        }
      }
      result = null;
      return false;
    }

    private ExpressionSyntax GetFieldTypeName(IField field, ITypeDefinition typeDefinition) {
      if (CheckFixedBufferField(field, typeDefinition, out var buffField)) {
        return buffField;
      }

      var typeName = CompilationUnit.GetTypeName(new TypeNameArgs {
        Type = field.Type,
        Definition = typeDefinition,
        IsForward = field.Type.IsRefType() || (field.IsStatic && !field.IsConst),
        IsInHead = true,
        Original = field.Type,
        Symbol = field,
      });
      CheckFieldTypeConflict(ref typeName, field, typeDefinition);
      return typeName;
    }

    private void CheckFieldTypeConflict(ref ExpressionSyntax type, IField field, ITypeDefinition typeDefinition) {
      foreach (var m in typeDefinition.Methods) {
        if (m.Name == field.Type.Name) {
          type = type.WithFullName(field.Type, typeDefinition);
          return;
        }
      }

      foreach (var f in typeDefinition.Fields) {
        if (f == field) {
          break;
        }
        if (f.GetFieldName() == field.Type.Name) {
          type = type.WithFullName(field.Type, typeDefinition);
          break;
        }
      }
    }

    public ExpressionSyntax GetTypeName(IType type, ITypeDefinition typeDefinition, ISymbol symbol) {
      return CompilationUnit.GetTypeName(new TypeNameArgs {
        Type = type,
        Definition = typeDefinition,
        IsForward = false,
        IsInHead = false,
        Original = type,
        Symbol = symbol,
      });
    }

    private List<ITypeDefinition> SortNestedTypes(List<ITypeDefinition> types) {
      List<List<ITypeDefinition>> typesList = new List<List<ITypeDefinition>>() { types.ToList() };
      while (true) {
        var parentTypes = new HashSet<ITypeDefinition>();
        var lastTypes = typesList.Last();
        foreach (var x in lastTypes) {
          foreach (var y in lastTypes) {
            if (x != y && y != nestedCycleTypes_.GetOrDefault(x)) {
              bool yInX = x.IsMemberTypeExists(y);
              bool xInY = y.IsMemberTypeExists(x);
              if (yInX) {
                var y1 = y;
                if (xInY) {
                  var x1 = x;
                  if (x1.Kind == TypeKind.Struct) {
                    (y1, x1) = (x1, y1);
                  }
                  nestedCycleTypes_[y1] = x1;
                }
                parentTypes.Add(y1);
              }
            }
          }
        }
        if (parentTypes.Count == 0) {
          break;
        }
        typesList.Add(parentTypes.ToList());
      }
      typesList.Reverse();
      return typesList.SelectMany(i => i).Distinct().ToList();
    }

    private IEnumerable<ITypeDefinition> GetNestedTypes(ITypeDefinition type) {
      IEnumerable<ITypeDefinition> types;
      if (type.NestedTypes.Count > 1) {
        var nestedTypes = type.NestedTypes.ToList();
        var enums = new List<ITypeDefinition>();
        nestedTypes.RemoveAll(i => {
          bool isEnum = i.Kind == TypeKind.Enum;
          if (isEnum) {
            enums.Add(i);
          }
          return isEnum;
        });
        nestedTypes = SortNestedTypes(nestedTypes);
        nestedTypes.InsertRange(0, enums);
        types = nestedTypes;
      } else {
        types = type.NestedTypes;
      }
      return types.Where(i => !i.Name.StartsWith('<'));
    }

    private ITypeDefinition GetNestedBrotherType(IEnumerable<ITypeDefinition> types, ClassSyntax node) {
      var brotherType = AssemblyTransform.GetNestedBrotherType(types);
      if (brotherType != null) {
        if (types.Count() == 1) {
          node.Add(types.First().GetNestedFriendStatement());
        } else {
          /*
          foreach (var nestedType in types) {
            bool isRef = nestedType.IsRefType();
            string name = isRef ? nestedType.Name.Wrap() : nestedType.Name;
            var template = nestedType.GetTemplateSyntax();
            var friend = new FriendClassDeclarationSyntax(name, !isRef) { Template = template };
            node.Add(friend);
          }*/
        }
      }
      return brotherType;
    }

    private void VisitTypes(ITypeDefinition type, ClassSyntax node) {
      var nestedTypes = GetNestedTypes(type);
      var sameNameTypes = nestedTypes.GroupBy(i => i.Name);
      foreach (var types in sameNameTypes) {
        var brotherType = GetNestedBrotherType(types, node);
        var block = brotherType != null ? GetBrotherTypeParnetBlock(brotherType) : node;
        new TypeDefinitionTransform(CompilationUnit, block, types, this);
      }
    }

    private void VisitPropertys(ITypeDefinition typeDefinition, ClassSyntax node) {
      foreach (var property in typeDefinition.Properties) {
        if (property.CanGet) {
          VisitMethod(property.Getter, typeDefinition, node);
        }
        if (property.CanSet) {
          VisitMethod(property.Setter, typeDefinition, node);
        }
      }
    }

    private void VisitMembers(ITypeDefinition type, ClassSyntax node) {
      VisitTypes(type, node);
      VisitPropertys(type, node);
      VisitMethods(type, node);
      VisitFields(type, node);
      AddTypeExtra(type, node);
    }

    private void AddTypeExtra(ITypeDefinition type, ClassSyntax node) {
      const string code = nameof(code);
      switch (type.KnownTypeCode) {
        case KnownTypeCode.Object:
        case KnownTypeCode.Boolean:
        case KnownTypeCode.Char:
        case KnownTypeCode.SByte:
        case KnownTypeCode.Byte:
        case KnownTypeCode.Int16:
        case KnownTypeCode.UInt16:
        case KnownTypeCode.Int32:
        case KnownTypeCode.UInt32:
        case KnownTypeCode.Int64:
        case KnownTypeCode.UInt64:
        case KnownTypeCode.Single:
        case KnownTypeCode.Double: 
        case KnownTypeCode.String: {
            node.Add(new FieldDefinitionSyntax(IdentifierSyntax.TypeCode, code, true, Accessibility.Public.ToTokenString()) {
              IsConstexpr = true,
              ConstantValue = IdentifierSyntax.TypeCode.TwoColon(type.Name),
            });
            if (type.Kind == TypeKind.Struct) {
              var field = type.Fields.Single(i => !i.IsStatic);
              var fieldName = GetMemberName(field);
              var typeName = (IdentifierSyntax)field.Type.GetValueTypeInnerName();
              string accessibilityToken = Accessibility.Public.ToTokenString();
              var defaultConstructor = new MethodDefinitionSyntax(node.Name) {
                AccessibilityToken = accessibilityToken,
                Body = BlockSyntax.EmptyBlock,
                IsConstexpr = true,
                IsNoexcept = true,
              };
              defaultConstructor.AddInitializationList(fieldName, field.Type.GetDefinition().GetPrimitiveTypeDefaultValue());
              node.Add(defaultConstructor);

              var underlyingTypeConstructor = new MethodDefinitionSyntax(node.Name, new ParameterSyntax(typeName, IdentifierSyntax.Value).ArrayOf()) {
                AccessibilityToken = accessibilityToken,
                Body = BlockSyntax.EmptyBlock,
                IsConstexpr = true,
                IsNoexcept = true,
              };
              underlyingTypeConstructor.AddInitializationList(fieldName, IdentifierSyntax.Value);
              node.Add(underlyingTypeConstructor);

              if (type.IsNumberType()) {
                var enumTypeConstructor = new MethodDefinitionSyntax(node.Name, new ParameterSyntax(IdentifierSyntax.T, IdentifierSyntax.Value).ArrayOf()) {
                  AccessibilityToken = accessibilityToken,
                  Body = BlockSyntax.EmptyBlock,
                  IsConstexpr = true,
                  IsNoexcept = true,
                  Template = new TemplateSyntax(TemplateTypenameSyntax.T) { Requires = IdentifierSyntax.IsEnumType.Generic(IdentifierSyntax.T) },
                };
                enumTypeConstructor.AddInitializationList(node.Name, IdentifierSyntax.Value.CastTo(typeName));
                node.Add(enumTypeConstructor);
              }

              var getValue = new MethodDefinitionSyntax(IdentifierSyntax.Get, null, new RefExpressionSyntax(typeName)) {
                AccessibilityToken = accessibilityToken,
                IsConstexpr = true,
                IsNoexcept = true,
                Body = new BlockSyntax() { IsSingleLine = true },
              };
              getValue.Body.Add(fieldName.Return());
              node.Add(getValue);

              var getValueConst = new MethodDefinitionSyntax(IdentifierSyntax.Get, null, typeName) {
                AccessibilityToken = accessibilityToken,
                IsConstexpr = true,
                IsNoexcept = true,
                IsConst = true,
                Body = new BlockSyntax() { IsSingleLine = true },
              };
              getValueConst.Body.Add(fieldName.Return());
              node.Add(getValueConst);
            }
            break;
          }
        case KnownTypeCode.SpanOfT:
        case KnownTypeCode.ReadOnlySpanOfT: {
            var method = new MethodDefinitionSyntax(type.Name, new ParameterSyntax(IdentifierSyntax.T, "(&array)[N]").ArrayOf()) { 
              Template = new TemplateSyntax(new TemplateTypenameSyntax("N") { ClassToken = "int" }),
              AccessibilityToken = Accessibility.Public.ToTokenString(),
              Body = new BlockSyntax() { IsSingleLine = true },
            };
            method.AddInitializationList(type.Name, "array", "N");
            node.Add(method);
            break;
          }
        default: {
            if (type.Kind == TypeKind.Interface) {
              node.Add(new FieldDefinitionSyntax(IdentifierSyntax.TypeCode, code, true, Accessibility.Public.ToTokenString()) {
                IsConstexpr = true,
                ConstantValue = IdentifierSyntax.TypeCode.TwoColon(TypeKind.Interface.ToString()),
              });
            }
            break;
          }
      }
    }

    private BlockSyntax GetBrotherTypeParnetBlock(ITypeDefinition brotherType) {
      if (types_.Contains(brotherType)) {
        return parent_;
      }
      Contract.Assert(parentTransform_ != null);
      return parentTransform_.GetBrotherTypeParnetBlock(brotherType);
    }

    private string GetAccessibilityString(ITypeDefinition type) {
      return AssemblyTransform.GetDeclaringType(type) != null ? type.Accessibility.ToTokenString() : null;
    }

    internal NestedCycleRefTypeNameSyntax GetNestedCycleRefTypeName(ISymbol symbol) {
      return CompilationUnit.GetNestedCycleRefTypeName(symbol);
    }
  }
}
