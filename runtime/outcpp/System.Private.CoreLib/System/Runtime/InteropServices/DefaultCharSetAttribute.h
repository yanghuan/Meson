#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CharSet;
namespace DefaultCharSetAttributeNamespace {
CLASS(DefaultCharSetAttribute) {
  public: CharSet get_CharSet() { return CharSet; }
  public: void Ctor(CharSet charSet);
  private: CharSet CharSet;
};
} // namespace DefaultCharSetAttributeNamespace
using DefaultCharSetAttribute = DefaultCharSetAttributeNamespace::DefaultCharSetAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
