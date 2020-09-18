#pragma once

#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
namespace StringBuilderCacheNamespace {
class StringBuilderCache {
  public: static StringBuilder Acquire(Int32 capacity = 16);
  public: static void Release(StringBuilder sb);
  public: static String GetStringAndRelease(StringBuilder sb);
  private: static StringBuilder t_cachedInstance;
};
} // namespace StringBuilderCacheNamespace
using StringBuilderCache = StringBuilderCacheNamespace::StringBuilderCache;
} // namespace System::Private::CoreLib::System::Text
