#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Byte.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Buffers {
namespace StandardFormatNamespace {
struct StandardFormat {
  public: Char get_Symbol();
  public: Byte get_Precision();
  public: Boolean get_HasPrecision();
  public: Boolean get_IsDefault();
  public: void Ctor(Char symbol, Byte precision);
  public: static StandardFormat op_Implicit(Char symbol);
  public: static StandardFormat Parse(ReadOnlySpan<Char> format);
  public: static StandardFormat Parse(String format);
  public: static Boolean TryParse(ReadOnlySpan<Char> format, StandardFormat& result);
  private: static Boolean ParseHelper(ReadOnlySpan<Char> format, StandardFormat& standardFormat, Boolean throws);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: Boolean Equals(StandardFormat other);
  public: String ToString();
  public: Int32 Format(Span<Char> destination);
  public: static Boolean op_Equality(StandardFormat left, StandardFormat right);
  public: static Boolean op_Inequality(StandardFormat left, StandardFormat right);
  public: void Ctor();
  public: static constexpr Byte NoPrecision = 255;
  public: static constexpr Byte MaxPrecision = 99;
  private: Byte _format;
  private: Byte _precision;
};
} // namespace StandardFormatNamespace
using StandardFormat = StandardFormatNamespace::StandardFormat;
} // namespace System::Private::CoreLib::System::Buffers
