#include "DefaultBinder-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/DBNull-dep.h>
#include <System.Private.CoreLib/System/DefaultBinder-dep.h>
#include <System.Private.CoreLib/System/Empty-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/MissingFieldException-dep.h>
#include <System.Private.CoreLib/System/MissingMethodException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/ParamArrayAttribute-dep.h>
#include <System.Private.CoreLib/System/Reflection/AmbiguousMatchException-dep.h>
#include <System.Private.CoreLib/System/Reflection/CallingConventions.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/ParameterInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/SignatureType-dep.h>
#include <System.Private.CoreLib/System/Reflection/SignatureTypeExtensions-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

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
  Boolean flag = (bindingAttr & BindingFlags::OptionalParamBinding) != 0;
  for (Int32 i = 0; i < array->get_Length(); i++) {
    Type type = nullptr;
    if (array[i] == nullptr) {
      continue;
    }
    Array<ParameterInfo> parametersNoCopy2 = array[i]->GetParametersNoCopy();
    if (parametersNoCopy2->get_Length() == 0) {
      if (args->get_Length() == 0 || (array[i]->get_CallingConvention() & CallingConventions::VarArgs) != 0) {
        array2[num] = array2[i];
        array[num++] = array[i];
      }
      continue;
    }
    Int32 j;
    if (parametersNoCopy2->get_Length() > args->get_Length()) {
      for (j = args->get_Length(); j < parametersNoCopy2->get_Length() - 1 && parametersNoCopy2[j]->get_DefaultValue() != DBNull::in::Value; j++) {
      }
      if (j != parametersNoCopy2->get_Length() - 1) {
        continue;
      }
      if (parametersNoCopy2[j]->get_DefaultValue() == DBNull::in::Value) {
        if (!parametersNoCopy2[j]->get_ParameterType()->get_IsArray() || !parametersNoCopy2[j]->IsDefined(typeof<ParamArrayAttribute>(), true)) {
          continue;
        }
        type = parametersNoCopy2[j]->get_ParameterType()->GetElementType();
      }
    } else if (parametersNoCopy2->get_Length() < args->get_Length()) {
      Int32 num2 = parametersNoCopy2->get_Length() - 1;
      if (!parametersNoCopy2[num2]->get_ParameterType()->get_IsArray() || !parametersNoCopy2[num2]->IsDefined(typeof<ParamArrayAttribute>(), true) || array2[i][num2] != num2) {
        continue;
      }
      type = parametersNoCopy2[num2]->get_ParameterType()->GetElementType();
    } else {
      Int32 num3 = parametersNoCopy2->get_Length() - 1;
      if (parametersNoCopy2[num3]->get_ParameterType()->get_IsArray() && parametersNoCopy2[num3]->IsDefined(typeof<ParamArrayAttribute>(), true) && array2[i][num3] == num3 && !parametersNoCopy2[num3]->get_ParameterType()->IsAssignableFrom(array4[num3])) {
        type = parametersNoCopy2[num3]->get_ParameterType()->GetElementType();
      }
    }

    Int32 num4 = (type != nullptr) ? (parametersNoCopy2->get_Length() - 1) : args->get_Length();
    for (j = 0; j < num4; j++) {
      Type type2 = parametersNoCopy2[j]->get_ParameterType();
      if (type2->get_IsByRef()) {
        type2 = type2->GetElementType();
      }
      if (type2 == array4[array2[i][j]] || (flag && args[array2[i][j]] == Type::in::Missing) || args[array2[i][j]] == nullptr || type2 == typeof<Object>()) {
        continue;
      }
      if (type2->get_IsPrimitive()) {
        if (array4[array2[i][j]] == nullptr) {
          break;
        }
        Object obj = args[array2[i][j]];
        if (!CanChangePrimitive((obj != nullptr) ? obj->GetType() : nullptr, type2)) {
          break;
        }
      } else if (!(array4[array2[i][j]] == nullptr) && !type2->IsAssignableFrom(array4[array2[i][j]]) && (!array4[array2[i][j]]->get_IsCOMObject() || !type2->IsInstanceOfType(args[array2[i][j]]))) {
        break;
      }

    }
    if (type != nullptr && j == parametersNoCopy2->get_Length() - 1) {
      for (; j < args->get_Length(); j++) {
        if (type->get_IsPrimitive()) {
          if (array4[j] == nullptr) {
            break;
          }
          Object obj2 = args[j];
          if (!CanChangePrimitive((obj2 != nullptr) ? obj2->GetType() : nullptr, type)) {
            break;
          }
        } else if (!(array4[j] == nullptr) && !type->IsAssignableFrom(array4[j]) && (!array4[j]->get_IsCOMObject() || !type->IsInstanceOfType(args[j]))) {
          break;
        }

      }
    }
    if (j == args->get_Length()) {
      array2[num] = array2[i];
      array3[num] = type;
      array[num++] = array[i];
    }
  }
  switch (num.get()) {
    case 0:
      rt::throw_exception<MissingMethodException>(SR::get_MissingMember());
    case 1:
      {
        if (names != nullptr) {
          state = rt::newobj<BinderState>((Array<Int32>)array2[0]->Clone(), args->get_Length(), array3[0] != nullptr);
          ReorderParams(array2[0], args);
        }
        Array<ParameterInfo> parametersNoCopy4 = array[0]->GetParametersNoCopy();
        if (parametersNoCopy4->get_Length() == args->get_Length()) {
          if (array3[0] != nullptr) {
            Array<Object> array8 = rt::newarr<Array<Object>>(parametersNoCopy4->get_Length());
            Int32 num8 = parametersNoCopy4->get_Length() - 1;
            Array<>::in::Copy(args, array8, num8);
            array8[num8] = Array<>::in::CreateInstance(array3[0], 1);
            ((Array<>)array8[num8])->SetValue(args[num8], (Int32)0);
            args = array8;
          }
        } else if (parametersNoCopy4->get_Length() > args->get_Length()) {
          Array<Object> array9 = rt::newarr<Array<Object>>(parametersNoCopy4->get_Length());
          Int32 i;
          for (i = 0; i < args->get_Length(); i++) {
            array9[i] = args[i];
          }
          for (; i < parametersNoCopy4->get_Length() - 1; i++) {
            array9[i] = parametersNoCopy4[i]->get_DefaultValue();
          }
          if (array3[0] != nullptr) {
            array9[i] = Array<>::in::CreateInstance(array3[0], (Int32)0);
          } else {
            array9[i] = parametersNoCopy4[i]->get_DefaultValue();
          }
          args = array9;
        } else if ((array[0]->get_CallingConvention() & CallingConventions::VarArgs) == 0) {
          Array<Object> array10 = rt::newarr<Array<Object>>(parametersNoCopy4->get_Length());
          Int32 num9 = parametersNoCopy4->get_Length() - 1;
          Array<>::in::Copy(args, array10, num9);
          array10[num9] = Array<>::in::CreateInstance(array3[0], args->get_Length() - num9);
          Array<>::in::Copy(args, num9, (Array<>)array10[num9], 0, args->get_Length() - num9);
          args = array10;
        }


        return array[0];
      }default:
      {
        Int32 num5 = 0;
        Boolean flag2 = false;
        for (Int32 i = 1; i < num; i++) {
          switch (FindMostSpecificMethod(array[num5], array2[num5], array3[num5], array[i], array2[i], array3[i], array4, args).get()) {
            case 0:
              flag2 = true;
              break;
            case 2:
              num5 = i;
              flag2 = false;
              break;
          }
        }
        if (flag2) {
          rt::throw_exception<AmbiguousMatchException>(SR::get_Arg_AmbiguousMatchException());
        }
        if (names != nullptr) {
          state = rt::newobj<BinderState>((Array<Int32>)array2[num5]->Clone(), args->get_Length(), array3[num5] != nullptr);
          ReorderParams(array2[num5], args);
        }
        Array<ParameterInfo> parametersNoCopy3 = array[num5]->GetParametersNoCopy();
        if (parametersNoCopy3->get_Length() == args->get_Length()) {
          if (array3[num5] != nullptr) {
            Array<Object> array5 = rt::newarr<Array<Object>>(parametersNoCopy3->get_Length());
            Int32 num6 = parametersNoCopy3->get_Length() - 1;
            Array<>::in::Copy(args, array5, num6);
            array5[num6] = Array<>::in::CreateInstance(array3[num5], 1);
            ((Array<>)array5[num6])->SetValue(args[num6], (Int32)0);
            args = array5;
          }
        } else if (parametersNoCopy3->get_Length() > args->get_Length()) {
          Array<Object> array6 = rt::newarr<Array<Object>>(parametersNoCopy3->get_Length());
          Int32 i;
          for (i = 0; i < args->get_Length(); i++) {
            array6[i] = args[i];
          }
          for (; i < parametersNoCopy3->get_Length() - 1; i++) {
            array6[i] = parametersNoCopy3[i]->get_DefaultValue();
          }
          if (array3[num5] != nullptr) {
            array6[i] = Array<>::in::CreateInstance(array3[num5], (Int32)0);
          } else {
            array6[i] = parametersNoCopy3[i]->get_DefaultValue();
          }
          args = array6;
        } else if ((array[num5]->get_CallingConvention() & CallingConventions::VarArgs) == 0) {
          Array<Object> array7 = rt::newarr<Array<Object>>(parametersNoCopy3->get_Length());
          Int32 num7 = parametersNoCopy3->get_Length() - 1;
          Array<>::in::Copy(args, array7, num7);
          array7[num7] = Array<>::in::CreateInstance(array3[num5], args->get_Length() - num7);
          Array<>::in::Copy(args, num7, (Array<>)array7[num7], 0, args->get_Length() - num7);
          args = array7;
        }


        return array[num5];
      }}
}

FieldInfo DefaultBinder___::BindToField(BindingFlags bindingAttr, Array<FieldInfo> match, Object value, CultureInfo cultureInfo) {
  if (match == nullptr) {
    rt::throw_exception<ArgumentNullException>("match");
  }
  Int32 num = 0;
  Array<FieldInfo> array = (Array<FieldInfo>)match->Clone();
  if ((bindingAttr & BindingFlags::SetField) != 0) {
    Type type = value->GetType();
    for (Int32 i = 0; i < array->get_Length(); i++) {
      Type fieldType = array[i]->get_FieldType();
      if (fieldType == type) {
        array[num++] = array[i];
      } else if (value == Empty::in::Value && fieldType->get_IsClass()) {
        array[num++] = array[i];
      } else if (fieldType == typeof<Object>()) {
        array[num++] = array[i];
      } else if (fieldType->get_IsPrimitive()) {
        if (CanChangePrimitive(type, fieldType)) {
          array[num++] = array[i];
        }
      } else if (fieldType->IsAssignableFrom(type)) {
        array[num++] = array[i];
      }




    }
    switch (num.get()) {
      case 0:
        rt::throw_exception<MissingFieldException>(SR::get_MissingField());
      case 1:
        return array[0];
    }
  }
  Int32 num2 = 0;
  Boolean flag = false;
  for (Int32 i = 1; i < num; i++) {
    switch (FindMostSpecificField(array[num2], array[i]).get()) {
      case 0:
        flag = true;
        break;
      case 2:
        num2 = i;
        flag = false;
        break;
    }
  }
  if (flag) {
    rt::throw_exception<AmbiguousMatchException>(SR::get_Arg_AmbiguousMatchException());
  }
  return array[num2];
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
      continue;
    }
    Int32 j;
    for (j = 0; j < types->get_Length(); j++) {
      Type parameterType = parametersNoCopy[j]->get_ParameterType();
      if (SignatureTypeExtensions::MatchesParameterTypeExactly(types[j], parametersNoCopy[j]) || parameterType == typeof<Object>()) {
        continue;
      }
      Type type = types[j];
      SignatureType signatureType = rt::as<SignatureType>(type);
      if ((Object)signatureType != nullptr) {
        MethodInfo methodInfo = rt::as<MethodInfo>(array2[i]);
        if ((Object)methodInfo == nullptr) {
          break;
        }
        type = SignatureTypeExtensions::TryResolveAgainstGenericMethod(signatureType, methodInfo);
        if (type == nullptr) {
          break;
        }
      }
      if (parameterType->get_IsPrimitive()) {
        if (!type->get_UnderlyingSystemType()->IsRuntimeImplemented() || !CanChangePrimitive(type->get_UnderlyingSystemType(), parameterType->get_UnderlyingSystemType())) {
          break;
        }
      } else if (!parameterType->IsAssignableFrom(type)) {
        break;
      }

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
    for (Type&& left : *indexes) {
      if (left == nullptr) {
        rt::throw_exception<ArgumentNullException>("indexes");
      }
    }
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
        continue;
      }
      for (j = 0; j < num2; j++) {
        Type parameterType = indexParameters[j]->get_ParameterType();
        if (parameterType == indexes[j] || parameterType == typeof<Object>()) {
          continue;
        }
        if (parameterType->get_IsPrimitive()) {
          if (!indexes[j]->get_UnderlyingSystemType()->IsRuntimeImplemented() || !CanChangePrimitive(indexes[j]->get_UnderlyingSystemType(), parameterType->get_UnderlyingSystemType())) {
            break;
          }
        } else if (!parameterType->IsAssignableFrom(indexes[j])) {
          break;
        }

      }
    }
    if (j != num2) {
      continue;
    }
    if (returnType != nullptr) {
      if (array[k]->get_PropertyType()->get_IsPrimitive()) {
        if (!returnType->get_UnderlyingSystemType()->IsRuntimeImplemented() || !CanChangePrimitive(returnType->get_UnderlyingSystemType(), array[k]->get_PropertyType()->get_UnderlyingSystemType())) {
          continue;
        }
      } else if (!array[k]->get_PropertyType()->IsAssignableFrom(returnType)) {
        continue;
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
      continue;
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
      continue;
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
  do {
    num++;
    type = type->get_BaseType();
  } while (type != nullptr)
  return num;
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
      continue;
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
  if ((source == typeof<IntPtr>() && target == typeof<IntPtr>()) || (source == typeof<UIntPtr>() && target == typeof<UIntPtr>())) {
    return true;
  }
  Primitives primitives = s_primitiveConversions[(Int32)Type::in::GetTypeCode(source)];
  Primitives primitives2 = (Primitives)(1 << (Int32)Type::in::GetTypeCode(target));
  return (primitives & primitives2) != 0;
}

void DefaultBinder___::ctor() {
}

void DefaultBinder___::cctor() {
  s_primitiveConversions = rt::newarr<Array<Primitives>>(19);
}

} // namespace System::Private::CoreLib::System::DefaultBinderNamespace
