#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Char)
FORWARD(String)
FORWARD(Version)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARDS_(KeyValuePair, T1, T2, T3)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection {
enum class AssemblyContentType : int32_t;
enum class AssemblyNameFlags : int32_t;
namespace AssemblyNameFormatterNamespace {
using namespace Collections::Generic;
using namespace Text;
class AssemblyNameFormatter {
  public: static String ComputeDisplayName(String name, Version version, String cultureName, Array<Byte> pkt, AssemblyNameFlags flags, AssemblyContentType contentType);
  private: static void AppendQuoted(StringBuilder sb, String s);
  private: static Version CanonicalizeVersion(Version version);
  private: static void ctor_static();
  public: static Array<KeyValuePair<Char, String>> EscapeSequences;
};
} // namespace AssemblyNameFormatterNamespace
using AssemblyNameFormatter = AssemblyNameFormatterNamespace::AssemblyNameFormatter;
} // namespace System::Private::CoreLib::System::Reflection
