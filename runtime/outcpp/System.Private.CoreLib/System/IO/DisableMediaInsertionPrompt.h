#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System::IO {
namespace DisableMediaInsertionPromptNamespace {
struct DisableMediaInsertionPrompt {
  public: static DisableMediaInsertionPrompt Create();
  public: void Dispose();
  public: void Ctor();
  private: Boolean _disableSuccess;
  private: UInt32 _oldMode;
};
} // namespace DisableMediaInsertionPromptNamespace
using DisableMediaInsertionPrompt = DisableMediaInsertionPromptNamespace::DisableMediaInsertionPrompt;
} // namespace System::Private::CoreLib::System::IO
