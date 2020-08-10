#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Reflection/MethodBody.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(ExceptionHandlingClause)
FORWARD(LocalVariableInfo)
FORWARD(MethodBase)
namespace RuntimeMethodBodyNamespace {
using namespace Collections::Generic;
using Collections::Generic::IList;
CLASS(RuntimeMethodBody) : public MethodBody::in {
  public: Int32 get_LocalSignatureMetadataToken();
  public: IList<LocalVariableInfo> get_LocalVariables();
  public: Int32 get_MaxStackSize();
  public: Boolean get_InitLocals();
  public: IList<ExceptionHandlingClause> get_ExceptionHandlingClauses();
  private: void ctor();
  public: Array<Byte> GetILAsByteArray();
  private: Array<Byte> _IL;
  private: Array<ExceptionHandlingClause> _exceptionHandlingClauses;
  private: Array<LocalVariableInfo> _localVariables;
  public: MethodBase _methodBase;
  private: Int32 _localSignatureMetadataToken;
  private: Int32 _maxStackSize;
  private: Boolean _initLocals;
};
} // namespace RuntimeMethodBodyNamespace
using RuntimeMethodBody = RuntimeMethodBodyNamespace::RuntimeMethodBody;
} // namespace System::Private::CoreLib::System::Reflection
