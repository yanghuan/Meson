#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CharSet;
enum class CallingConvention;
namespace DllImportAttributeNamespace {
CLASS(DllImportAttribute) {
  public: String get_Value() { return Value; }
  private: String Value;
  public: String EntryPoint;
  public: CharSet CharSet;
  public: Boolean SetLastError;
  public: Boolean ExactSpelling;
  public: CallingConvention CallingConvention;
  public: Boolean BestFitMapping;
  public: Boolean PreserveSig;
  public: Boolean ThrowOnUnmappableChar;
};
} // namespace DllImportAttributeNamespace
using DllImportAttribute = DllImportAttributeNamespace::DllImportAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
