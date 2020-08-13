#include "DefaultBinder-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/DefaultBinder-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/AmbiguousMatchException-dep.h>
#include <System.Private.CoreLib/System/Reflection/ParameterInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/SignatureType-dep.h>
#include <System.Private.CoreLib/System/Reflection/SignatureTypeExtensions-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::DefaultBinderNamespace {
using namespace System::Reflection;

void DefaultBinder___::BinderState___::ctor(Array<Int32> argsMap, Int32 originalSize, Boolean isParamArray) {
  _argsMap = argsMap;
  _originalSize = originalSize;
  _isParamArray = isParamArray;
}

MethodBase DefaultBinder___::BindToMethod(BindingFlags bindingAttr, Array<MethodBase> match, Array<Object>& args, Array<ParameterModifier> modifiers, CultureInfo cultureInfo, Array<String> names, Object& state) {
  if (match == nullptr || match->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_EmptyArray(), "match");
  }
  Array<MethodBase> array = (Array<MethodBase>)match->Clone();
  state = nullptr;
  Array<Int32> array2 = rt::newarr<Array<Array<Int32>>>(array->get_Length());
  for (Int32 i = 0; i < array->get_Length(); i++) {
    Array<ParameterInfo> parametersNoCopy = array[i]->GetParametersNoCopy();
    array2[i] = rt::newarr<Array<Int32>>((parametersNoCopy->get_Length() > args->get_Length()) ? parametersNoCopy->get_Length() : args->get_Length());
    if (names == nullptr) {
      for (Int32 j = 0; j < args->get_Length(); j++) {
        array2[i][j] = j;
      }
    } else if (!CreateParamOrder(array2[i], parametersNoCopy, names)) {
      array[i] = nullptr;
    }

  }
  Array<Type> array3 = rt::newarr<Array<Type>>(array->get_Length());
  Array<Type> array4 = rt::newarr<Array<Type>>(args->get_Length());
  for (Int32 i = 0; i < args->get_Length(); i++) {
    if (args[i] != nullptr) {
      array4[i] = args[i]->GetType();
    }
  }
  Int32 num = 0;
}

FieldInfo DefaultBinder___::BindToField(BindingFlags bindingAttr, Array<FieldInfo> match, Object value, CultureInfo cultureInfo) {
  if (match == nullptr) {
    rt::throw_exception<ArgumentNullException>("match");
  }
  Int32 num = 0;
  Array<FieldInfo> array = (Array<FieldInfo>)match->Clone();
}

MethodBase DefaultBinder___::SelectMethod(BindingFlags bindingAttr, Array<MethodBase> match, Array<Type> types, Array<ParameterModifier> modifiers) {
  Array<Type> array = rt::newarr<Array<Type>>(types->get_Length());
  for (Int32 i = 0; i < types->get_Length(); i++) {
    array[i] = types[i]->get_UnderlyingSystemType();
    if (!array[i]->IsRuntimeImplemented() && !rt::is<SignatureType>(array[i])) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_MustBeType(), "types");
    }
  }
  types = array;
  if (match == nullptr || match->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_EmptyArray(), "match");
  }
  Array<MethodBase> array2 = (Array<MethodBase>)match->Clone();
  Int32 num = 0;
  for (Int32 i = 0; i < array2->get_Length(); i++) {
    Array<ParameterInfo> parametersNoCopy = array2[i]->GetParametersNoCopy();
    if (parametersNoCopy->get_Length() != types->get_Length()) {
    }
    Int32 j;
    for (j = 0; j < types->get_Length(); j++) {
      Type parameterType = parametersNoCopy[j]->get_ParameterType();
    }
    if (j == types->get_Length()) {
      array2[num++] = array2[i];
    }
  }
  switch (num.get()) {
    case 0:
      return nullptr;
    case 1:
      return array2[0];
    default:
      {
        Int32 num2 = 0;
        Boolean flag = false;
        Array<Int32> array3 = rt::newarr<Array<Int32>>(types->get_Length());
        for (Int32 i = 0; i < types->get_Length(); i++) {
          array3[i] = i;
        }
        for (Int32 i = 1; i < num; i++) {
          switch (FindMostSpecificMethod(array2[num2], array3, nullptr, array2[i], array3, nullptr, types, nullptr).get()) {
            case 0:
              flag = true;
              break;
            case 2:
              flag = false;
              num2 = i;
              break;
          }
        }
        if (flag) {
          rt::throw_exception<AmbiguousMatchException>(SR::get_Arg_AmbiguousMatchException());
        }
        return array2[num2];
      }}
}

PropertyInfo DefaultBinder___::SelectProperty(BindingFlags bindingAttr, Array<PropertyInfo> match, Type returnType, Array<Type> indexes, Array<ParameterModifier> modifiers) {
  if (indexes != nullptr) {
  }
  if (match == nullptr || match->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_EmptyArray(), "match");
  }
  Array<PropertyInfo> array = (Array<PropertyInfo>)match->Clone();
  Int32 j = 0;
  Int32 num = 0;
  Int32 num2 = (indexes != nullptr) ? indexes->get_Length() : 0;
  for (Int32 k = 0; k < array->get_Length(); k++) {
    if (indexes != nullptr) {
      Array<ParameterInfo> indexParameters = array[k]->GetIndexParameters();
      if (indexParameters->get_Length() != num2) {
      }
      for (j = 0; j < num2; j++) {
        Type parameterType = indexParameters[j]->get_ParameterType();
      }
    }
    if (j != num2) {
    }
    if (returnType != nullptr) {
      if (array[k]->get_PropertyType()->get_IsPrimitive()) {
        if (!returnType->get_UnderlyingSystemType()->IsRuntimeImplemented() || !CanChangePrimitive(returnType->get_UnderlyingSystemType(), array[k]->get_PropertyType()->get_UnderlyingSystemType())) {
        }
      } else if (!array[k]->get_PropertyType()->IsAssignableFrom(returnType)) {
      }

    }
    array[num++] = array[k];
  }
  switch (num.get()) {
    case 0:
      return nullptr;
    case 1:
      return array[0];
    default:
      {
        Int32 num3 = 0;
        Boolean flag = false;
        Array<Int32> array2 = rt::newarr<Array<Int32>>(num2);
        for (Int32 k = 0; k < num2; k++) {
          array2[k] = k;
        }
        for (Int32 k = 1; k < num; k++) {
          Int32 num4 = FindMostSpecificType(array[num3]->get_PropertyType(), array[k]->get_PropertyType(), returnType);
          if (num4 == 0 && indexes != nullptr) {
            num4 = FindMostSpecific(array[num3]->GetIndexParameters(), array2, nullptr, array[k]->GetIndexParameters(), array2, nullptr, indexes, nullptr);
          }
          if (num4 == 0) {
            num4 = FindMostSpecificProperty(array[num3], array[k]);
            if (num4 == 0) {
              flag = true;
            }
          }
          if (num4 == 2) {
            flag = false;
            num3 = k;
          }
        }
        if (flag) {
          rt::throw_exception<AmbiguousMatchException>(SR::get_Arg_AmbiguousMatchException());
        }
        return array[num3];
      }}
}

Object DefaultBinder___::ChangeType(Object value, Type type, CultureInfo cultureInfo) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ChangeType());
}

void DefaultBinder___::ReorderArgumentArray(Array<Object>& args, Object state) {
  BinderState binderState = (BinderState)state;
  ReorderParams(binderState->_argsMap, args);
  if (binderState->_isParamArray) {
    Int32 num = args->get_Length() - 1;
    if (args->get_Length() == binderState->_originalSize) {
      args[num] = ((Array<Object>)args[num])[0];
      return;
    }
    Array<Object> array = rt::newarr<Array<Object>>(args->get_Length());
    Array<>::in::Copy(args, array, num);
    Int32 num2 = num;
    Int32 num3 = 0;
    while (num2 < array->get_Length()) {
      array[num2] = ((Array<Object>)args[num])[num3];
      num2++;
      num3++;
    }
    args = array;
  } else if (args->get_Length() > binderState->_originalSize) {
    Array<Object> array2 = rt::newarr<Array<Object>>(binderState->_originalSize);
    Array<>::in::Copy(args, array2, binderState->_originalSize);
    args = array2;
  }

}

MethodBase DefaultBinder___::ExactBinding(Array<MethodBase> match, Array<Type> types, Array<ParameterModifier> modifiers) {
  if (match == nullptr) {
    rt::throw_exception<ArgumentNullException>("match");
  }
  Array<MethodBase> array = rt::newarr<Array<MethodBase>>(match->get_Length());
  Int32 num = 0;
  for (Int32 i = 0; i < match->get_Length(); i++) {
    Array<ParameterInfo> parametersNoCopy = match[i]->GetParametersNoCopy();
    if (parametersNoCopy->get_Length() == 0) {
    }
    Int32 j;
    for (j = 0; j < types->get_Length(); j++) {
      Type parameterType = parametersNoCopy[j]->get_ParameterType();
      if (!parameterType->Equals(types[j])) {
        break;
      }
    }
    if (j >= types->get_Length()) {
      array[num] = match[i];
      num++;
    }
  }
  switch (num.get()) {
    case 0:
      return nullptr;
    case 1:
      return array[0];
    default:
      return FindMostDerivedNewSlotMeth(array, num);
  }
}

PropertyInfo DefaultBinder___::ExactPropertyBinding(Array<PropertyInfo> match, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers) {
  if (match == nullptr) {
    rt::throw_exception<ArgumentNullException>("match");
  }
  PropertyInfo propertyInfo = nullptr;
  Int32 num = (types != nullptr) ? types->get_Length() : 0;
  for (Int32 i = 0; i < match->get_Length(); i++) {
    Array<ParameterInfo> indexParameters = match[i]->GetIndexParameters();
    Int32 j;
    for (j = 0; j < num; j++) {
      Type parameterType = indexParameters[j]->get_ParameterType();
      if (parameterType != types[j]) {
        break;
      }
    }
    if (j >= num && (!(returnType != nullptr) || !(returnType != match[i]->get_PropertyType()))) {
      if (propertyInfo != nullptr) {
        rt::throw_exception<AmbiguousMatchException>(SR::get_Arg_AmbiguousMatchException());
      }
      propertyInfo = match[i];
    }
  }
  return propertyInfo;
}

Int32 DefaultBinder___::FindMostSpecific(Array<ParameterInfo> p1, Array<Int32> paramOrder1, Type paramArrayType1, Array<ParameterInfo> p2, Array<Int32> paramOrder2, Type paramArrayType2, Array<Type> types, Array<Object> args) {
  if (paramArrayType1 != nullptr && paramArrayType2 == nullptr) {
    return 2;
  }
  if (paramArrayType2 != nullptr && paramArrayType1 == nullptr) {
    return 1;
  }
  Boolean flag = false;
  Boolean flag2 = false;
  for (Int32 i = 0; i < types->get_Length(); i++) {
    if (args != nullptr && args[i] == Type::in::Missing) {
    }
    Type type = (!(paramArrayType1 != nullptr) || paramOrder1[i] < p1->get_Length() - 1) ? p1[paramOrder1[i]]->get_ParameterType() : paramArrayType1;
    Type type2 = (!(paramArrayType2 != nullptr) || paramOrder2[i] < p2->get_Length() - 1) ? p2[paramOrder2[i]]->get_ParameterType() : paramArrayType2;
    if (!(type == type2)) {
      switch (FindMostSpecificType(type, type2, types[i]).get()) {
        case 0:
          return 0;
        case 1:
          flag = true;
          break;
        case 2:
          flag2 = true;
          break;
      }
    }
  }
  if (flag == flag2) {
    if (!flag && args != nullptr) {
      if (p1->get_Length() > p2->get_Length()) {
        return 1;
      }
      if (p2->get_Length() > p1->get_Length()) {
        return 2;
      }
    }
    return 0;
  }
  if (!flag) {
    return 2;
  }
  return 1;
}

Int32 DefaultBinder___::FindMostSpecificType(Type c1, Type c2, Type t) {
  if (c1 == c2) {
    return 0;
  }
  SignatureType signatureType = rt::as<SignatureType>(t);
  if ((Object)signatureType != nullptr) {
    if (SignatureTypeExtensions::MatchesExactly(signatureType, c1)) {
      return 1;
    }
    if (SignatureTypeExtensions::MatchesExactly(signatureType, c2)) {
      return 2;
    }
  } else {
    if (c1 == t) {
      return 1;
    }
    if (c2 == t) {
      return 2;
    }
  }
  if (c1->get_IsByRef() || c2->get_IsByRef()) {
    if (c1->get_IsByRef() && c2->get_IsByRef()) {
      c1 = c1->GetElementType();
      c2 = c2->GetElementType();
    } else if (c1->get_IsByRef()) {
      if (c1->GetElementType() == c2) {
        return 2;
      }
      c1 = c1->GetElementType();
    } else {
      if (c2->GetElementType() == c1) {
        return 1;
      }
      c2 = c2->GetElementType();
    }

  }
  Boolean flag;
  Boolean flag2;
  if (c1->get_IsPrimitive() && c2->get_IsPrimitive()) {
    flag = CanChangePrimitive(c2, c1);
    flag2 = CanChangePrimitive(c1, c2);
  } else {
    flag = c1->IsAssignableFrom(c2);
    flag2 = c2->IsAssignableFrom(c1);
  }
  if (flag == flag2) {
    return 0;
  }
  if (flag) {
    return 2;
  }
  return 1;
}

Int32 DefaultBinder___::FindMostSpecificMethod(MethodBase m1, Array<Int32> paramOrder1, Type paramArrayType1, MethodBase m2, Array<Int32> paramOrder2, Type paramArrayType2, Array<Type> types, Array<Object> args) {
  Int32 num = FindMostSpecific(m1->GetParametersNoCopy(), paramOrder1, paramArrayType1, m2->GetParametersNoCopy(), paramOrder2, paramArrayType2, types, args);
  if (num != 0) {
    return num;
  }
  if (CompareMethodSig(m1, m2)) {
    Int32 hierarchyDepth = GetHierarchyDepth(m1->get_DeclaringType());
    Int32 hierarchyDepth2 = GetHierarchyDepth(m2->get_DeclaringType());
    if (hierarchyDepth == hierarchyDepth2) {
      return 0;
    }
    if (hierarchyDepth < hierarchyDepth2) {
      return 2;
    }
    return 1;
  }
  return 0;
}

Int32 DefaultBinder___::FindMostSpecificField(FieldInfo cur1, FieldInfo cur2) {
  if (cur1->get_Name() == cur2->get_Name()) {
    Int32 hierarchyDepth = GetHierarchyDepth(cur1->get_DeclaringType());
    Int32 hierarchyDepth2 = GetHierarchyDepth(cur2->get_DeclaringType());
    if (hierarchyDepth == hierarchyDepth2) {
      return 0;
    }
    if (hierarchyDepth < hierarchyDepth2) {
      return 2;
    }
    return 1;
  }
  return 0;
}

Int32 DefaultBinder___::FindMostSpecificProperty(PropertyInfo cur1, PropertyInfo cur2) {
  if (cur1->get_Name() == cur2->get_Name()) {
    Int32 hierarchyDepth = GetHierarchyDepth(cur1->get_DeclaringType());
    Int32 hierarchyDepth2 = GetHierarchyDepth(cur2->get_DeclaringType());
    if (hierarchyDepth == hierarchyDepth2) {
      return 0;
    }
    if (hierarchyDepth < hierarchyDepth2) {
      return 2;
    }
    return 1;
  }
  return 0;
}

Boolean DefaultBinder___::CompareMethodSig(MethodBase m1, MethodBase m2) {
  Array<ParameterInfo> parametersNoCopy = m1->GetParametersNoCopy();
  Array<ParameterInfo> parametersNoCopy2 = m2->GetParametersNoCopy();
  if (parametersNoCopy->get_Length() != parametersNoCopy2->get_Length()) {
    return false;
  }
  Int32 num = parametersNoCopy->get_Length();
  for (Int32 i = 0; i < num; i++) {
    if (parametersNoCopy[i]->get_ParameterType() != parametersNoCopy2[i]->get_ParameterType()) {
      return false;
    }
  }
  return true;
}

Int32 DefaultBinder___::GetHierarchyDepth(Type t) {
  Int32 num = 0;
  Type type = t;
}

MethodBase DefaultBinder___::FindMostDerivedNewSlotMeth(Array<MethodBase> match, Int32 cMatches) {
  Int32 num = 0;
  MethodBase result = nullptr;
  for (Int32 i = 0; i < cMatches; i++) {
    Int32 hierarchyDepth = GetHierarchyDepth(match[i]->get_DeclaringType());
    if (hierarchyDepth == num) {
      rt::throw_exception<AmbiguousMatchException>(SR::get_Arg_AmbiguousMatchException());
    }
    if (hierarchyDepth > num) {
      num = hierarchyDepth;
      result = match[i];
    }
  }
  return result;
}

void DefaultBinder___::ReorderParams(Array<Int32> paramOrder, Array<Object> vars) {
  Array<Object> array = rt::newarr<Array<Object>>(vars->get_Length());
  for (Int32 i = 0; i < vars->get_Length(); i++) {
    array[i] = vars[i];
  }
  for (Int32 j = 0; j < vars->get_Length(); j++) {
    vars[j] = array[paramOrder[j]];
  }
}

Boolean DefaultBinder___::CreateParamOrder(Array<Int32> paramOrder, Array<ParameterInfo> pars, Array<String> names) {
  Array<Boolean> array = rt::newarr<Array<Boolean>>(pars->get_Length());
  for (Int32 i = 0; i < pars->get_Length(); i++) {
    paramOrder[i] = -1;
  }
  for (Int32 j = 0; j < names->get_Length(); j++) {
    Int32 k;
    for (k = 0; k < pars->get_Length(); k++) {
      if (names[j]->Equals(pars[k]->get_Name())) {
        paramOrder[k] = j;
        array[j] = true;
        break;
      }
    }
    if (k == pars->get_Length()) {
      return false;
    }
  }
  Int32 l = 0;
  for (Int32 m = 0; m < pars->get_Length(); m++) {
    if (paramOrder[m] != -1) {
    }
    for (; l < pars->get_Length(); l++) {
      if (!array[l]) {
        paramOrder[m] = l;
        l++;
        break;
      }
    }
  }
  return true;
}

Boolean DefaultBinder___::CanChangePrimitive(Type source, Type target) {
}

void DefaultBinder___::ctor() {
}

void DefaultBinder___::ctor_static() {
  s_primitiveConversions = rt::newarr<Array<Primitives>>(19);
}

} // namespace System::Private::CoreLib::System::DefaultBinderNamespace
