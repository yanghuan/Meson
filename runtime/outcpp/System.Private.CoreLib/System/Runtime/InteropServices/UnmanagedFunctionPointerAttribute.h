#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CallingConvention;
enum class CharSet;
namespace UnmanagedFunctionPointerAttributeNamespace {
CLASS(UnmanagedFunctionPointerAttribute) {
  private: CallingConvention CallingConvention;
  public: Boolean BestFitMapping;
  public: Boolean SetLastError;
  public: Boolean ThrowOnUnmappableChar;
  public: CharSet CharSet;
};
} // namespace UnmanagedFunctionPointerAttributeNamespace
using UnmanagedFunctionPointerAttribute = UnmanagedFunctionPointerAttributeNamespace::UnmanagedFunctionPointerAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
