#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CharSet;
namespace UnmanagedFunctionPointerAttributeNamespace {
CLASS(UnmanagedFunctionPointerAttribute) {
  public: Boolean BestFitMapping;
  public: Boolean SetLastError;
  public: Boolean ThrowOnUnmappableChar;
  public: CharSet CharSet;
};
} // namespace UnmanagedFunctionPointerAttributeNamespace
using UnmanagedFunctionPointerAttribute = UnmanagedFunctionPointerAttributeNamespace::UnmanagedFunctionPointerAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
