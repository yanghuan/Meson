#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CallingConvention;
enum class CharSet;
namespace UnmanagedFunctionPointerAttributeNamespace {
CLASS(UnmanagedFunctionPointerAttribute) : public Attribute::in {
  public: CallingConvention get_CallingConvention() { return CallingConvention; }
  public: void Ctor();
  public: void Ctor(CallingConvention callingConvention);
  private: CallingConvention CallingConvention;
  public: Boolean BestFitMapping;
  public: Boolean SetLastError;
  public: Boolean ThrowOnUnmappableChar;
  public: CharSet CharSet;
};
} // namespace UnmanagedFunctionPointerAttributeNamespace
using UnmanagedFunctionPointerAttribute = UnmanagedFunctionPointerAttributeNamespace::UnmanagedFunctionPointerAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
