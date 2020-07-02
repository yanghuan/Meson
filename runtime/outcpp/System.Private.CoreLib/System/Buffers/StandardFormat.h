#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Byte.h>

namespace System::Private::CoreLib::System {
FORWARDS(Char)
FORWARDS(Boolean)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
FORWARD(Object)
FORWARDS(Int32)
FORWARDS(Span, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
namespace StandardFormatNamespace {
struct StandardFormat {
  public: Char get_Symbol();
  public: Byte get_Precision();
  public: Boolean get_HasPrecision();
  public: Boolean get_IsDefault();
  public: static StandardFormat Parse(ReadOnlySpan<Char> format);
  public: static StandardFormat Parse(String format);
  public: static Boolean TryParse(ReadOnlySpan<Char> format, StandardFormat& result);
  private: static Boolean ParseHelper(ReadOnlySpan<Char> format, StandardFormat& standardFormat, Boolean throws);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: Boolean Equals(StandardFormat other);
  public: String ToString();
  public: Int32 Format(Span<Char> destination);
  public: static Byte NoPrecision;
  public: static Byte MaxPrecision;
  private: Byte _format;
  private: Byte _precision;
};
} // namespace StandardFormatNamespace
using StandardFormat = StandardFormatNamespace::StandardFormat;
} // namespace System::Private::CoreLib::System::Buffers
