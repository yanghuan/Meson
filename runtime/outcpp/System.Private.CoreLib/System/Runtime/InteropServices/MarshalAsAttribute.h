#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class VarEnum;
enum class UnmanagedType;
namespace MarshalAsAttributeNamespace {
CLASS(MarshalAsAttribute) {
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
