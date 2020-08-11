#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CallingConvention : int32_t;
enum class CharSet : int32_t;
namespace DllImportAttributeNamespace {
CLASS(DllImportAttribute) : public Attribute::in {
  public: String get_Value() { return Value; }
  public: void ctor(String dllName);
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
