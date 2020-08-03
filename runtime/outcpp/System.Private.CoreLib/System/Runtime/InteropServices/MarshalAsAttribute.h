#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class UnmanagedType;
enum class VarEnum;
namespace MarshalAsAttributeNamespace {
CLASS(MarshalAsAttribute) : public Attribute::in {
  public: UnmanagedType get_Value() { return Value; }
  public: void Ctor(UnmanagedType unmanagedType);
  public: void Ctor(Int16 unmanagedType);
  private: UnmanagedType Value;
  public: VarEnum SafeArraySubType;
  public: Type SafeArrayUserDefinedSubType;
  public: Int32 IidParameterIndex;
  public: UnmanagedType ArraySubType;
  public: Int16 SizeParamIndex;
  public: Int32 SizeConst;
  public: String MarshalType;
  public: Type MarshalTypeRef;
  public: String MarshalCookie;
};
} // namespace MarshalAsAttributeNamespace
using MarshalAsAttribute = MarshalAsAttributeNamespace::MarshalAsAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
