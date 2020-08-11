#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Reflection/Binder.h>

namespace System::Private::CoreLib::System::Reflection {
enum class BindingFlags : int32_t;
FORWARD(FieldInfo)
FORWARD(MethodBase)
FORWARD(ParameterInfo)
FORWARDS(ParameterModifier)
FORWARD(PropertyInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(String)
FORWARD(Type)
namespace DefaultBinderNamespace {
using namespace Globalization;
using namespace Reflection;
CLASS(DefaultBinder) : public Binder::in {
  private: enum class Primitives : int32_t {
    Boolean = 8,
    Char = 16,
    SByte = 32,
    Byte = 64,
    Int16 = 128,
    UInt16 = 256,
    Int32 = 512,
    UInt32 = 1024,
    Int64 = 2048,
    UInt64 = 4096,
    Single = 8192,
    Double = 16384,
    Decimal = 32768,
    DateTime = 65536,
    String = 262144,
  };
  public: CLASS(BinderState) : public Object::in {
    public: void ctor(Array<Int32> argsMap, Int32 originalSize, Boolean isParamArray);
    public: Array<Int32> _argsMap;
    public: Int32 _originalSize;
    public: Boolean _isParamArray;
  };
  public: MethodBase BindToMethod(BindingFlags bindingAttr, Array<MethodBase> match, Array<Object>& args, Array<ParameterModifier> modifiers, CultureInfo cultureInfo, Array<String> names, Object& state);
  public: FieldInfo BindToField(BindingFlags bindingAttr, Array<FieldInfo> match, Object value, CultureInfo cultureInfo);
  public: MethodBase SelectMethod(BindingFlags bindingAttr, Array<MethodBase> match, Array<Type> types, Array<ParameterModifier> modifiers);
  public: PropertyInfo SelectProperty(BindingFlags bindingAttr, Array<PropertyInfo> match, Type returnType, Array<Type> indexes, Array<ParameterModifier> modifiers);
  public: Object ChangeType(Object value, Type type, CultureInfo cultureInfo);
  public: void ReorderArgumentArray(Array<Object>& args, Object state);
  public: static MethodBase ExactBinding(Array<MethodBase> match, Array<Type> types, Array<ParameterModifier> modifiers);
  public: static PropertyInfo ExactPropertyBinding(Array<PropertyInfo> match, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers);
  private: static Int32 FindMostSpecific(Array<ParameterInfo> p1, Array<Int32> paramOrder1, Type paramArrayType1, Array<ParameterInfo> p2, Array<Int32> paramOrder2, Type paramArrayType2, Array<Type> types, Array<Object> args);
  private: static Int32 FindMostSpecificType(Type c1, Type c2, Type t);
  private: static Int32 FindMostSpecificMethod(MethodBase m1, Array<Int32> paramOrder1, Type paramArrayType1, MethodBase m2, Array<Int32> paramOrder2, Type paramArrayType2, Array<Type> types, Array<Object> args);
  private: static Int32 FindMostSpecificField(FieldInfo cur1, FieldInfo cur2);
  private: static Int32 FindMostSpecificProperty(PropertyInfo cur1, PropertyInfo cur2);
  public: static Boolean CompareMethodSig(MethodBase m1, MethodBase m2);
  private: static Int32 GetHierarchyDepth(Type t);
  public: static MethodBase FindMostDerivedNewSlotMeth(Array<MethodBase> match, Int32 cMatches);
  private: static void ReorderParams(Array<Int32> paramOrder, Array<Object> vars);
  private: static Boolean CreateParamOrder(Array<Int32> paramOrder, Array<ParameterInfo> pars, Array<String> names);
  public: static Boolean CanChangePrimitive(Type source, Type target);
  public: void ctor();
  private: static void ctor_static();
  private: static Array<Primitives> s_primitiveConversions;
};
} // namespace DefaultBinderNamespace
using DefaultBinder = DefaultBinderNamespace::DefaultBinder;
} // namespace System::Private::CoreLib::System
