#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection {
FORWARD(ExceptionHandlingClause)
FORWARD(LocalVariableInfo)
namespace MethodBodyNamespace {
using namespace Collections::Generic;
using ::System::Private::CoreLib::System::Collections::Generic::IList;
CLASS(MethodBody) {
  public: Int32 get_LocalSignatureMetadataToken();
  public: IList<LocalVariableInfo> get_LocalVariables();
  public: Int32 get_MaxStackSize();
  public: Boolean get_InitLocals();
  public: IList<ExceptionHandlingClause> get_ExceptionHandlingClauses();
  public: Array<Byte> GetILAsByteArray();
};
} // namespace MethodBodyNamespace
using MethodBody = MethodBodyNamespace::MethodBody;
} // namespace System::Private::CoreLib::System::Reflection
