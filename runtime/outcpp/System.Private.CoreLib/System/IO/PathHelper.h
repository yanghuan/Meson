#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Char)
FORWARDS(Int32)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARDS(ValueStringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::IO {
namespace PathHelperNamespace {
using namespace System::Text;
class PathHelper {
  public: static String Normalize(String path);
  public: static String Normalize(ValueStringBuilder& path);
  private: static void GetFullPathName(ReadOnlySpan<Char> path, ValueStringBuilder& builder);
  public: static Int32 PrependDevicePathChars(ValueStringBuilder& content, Boolean isDosUnc, ValueStringBuilder& buffer);
  public: static String TryExpandShortFileName(ValueStringBuilder& outputBuilder, String originalPath);
};
} // namespace PathHelperNamespace
using PathHelper = PathHelperNamespace::PathHelper;
} // namespace System::Private::CoreLib::System::IO
