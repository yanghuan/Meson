#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD(IDisposable)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::IO {
namespace DisableMediaInsertionPromptNamespace {
struct DisableMediaInsertionPrompt : public valueType<DisableMediaInsertionPrompt> {
  public: using interface = rt::TypeList<IDisposable>;
  public: static DisableMediaInsertionPrompt Create();
  public: void Dispose();
  private: Boolean _disableSuccess;
  private: UInt32 _oldMode;
};
} // namespace DisableMediaInsertionPromptNamespace
using DisableMediaInsertionPrompt = DisableMediaInsertionPromptNamespace::DisableMediaInsertionPrompt;
} // namespace System::Private::CoreLib::System::IO
