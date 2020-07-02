#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Resources {
FORWARD(ResourceManager)
} // namespace System::Private::CoreLib::System::Resources
namespace System::Private::Uri::System {
namespace SRNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Resources;
class SR {
  private: static Boolean UsingResourceKeys();
  public: static String GetResourceString(String resourceKey, String defaultString);
  public: static String Format(String resourceFormat, Object p1);
  public: static String Format(String resourceFormat, Object p1, Object p2);
  private: static ResourceManager s_resourceManager;
};
} // namespace SRNamespace
using SR = SRNamespace::SR;
} // namespace System::Private::Uri::System
