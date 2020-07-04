#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CompareInfo)
enum class CompareOptions;
namespace SortKeyNamespace {
CLASS(SortKey) {
  public: String get_OriginalString();
  public: Array<Byte> get_KeyData();
  public: static Int32 Compare(SortKey sortkey1, SortKey sortkey2);
  public: Boolean Equals(Object value);
  public: Int32 GetHashCode();
  public: String ToString();
  private: CompareInfo _compareInfo;
  private: CompareOptions _options;
  private: String _string;
  private: Array<Byte> _keyData;
};
} // namespace SortKeyNamespace
using SortKey = SortKeyNamespace::SortKey;
} // namespace System::Private::CoreLib::System::Globalization
