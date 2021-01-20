#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
enum class CompareOptions : int32_t;
FORWARD(CompareInfo)
namespace SortKeyNamespace {
CLASS(SortKey) : public object {
  public: String get_OriginalString();
  public: Array<Byte> get_KeyData();
  public: void ctor(CompareInfo compareInfo, String str, CompareOptions options, Array<Byte> keyData);
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
