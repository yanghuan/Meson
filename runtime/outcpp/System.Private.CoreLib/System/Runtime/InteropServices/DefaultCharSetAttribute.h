#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CharSet : int32_t;
namespace DefaultCharSetAttributeNamespace {
CLASS(DefaultCharSetAttribute) : public Attribute::in {
  public: CharSet get_CharSet() { return CharSet; }
  public: void ctor(CharSet charSet);
  private: CharSet CharSet;
};
} // namespace DefaultCharSetAttributeNamespace
using DefaultCharSetAttribute = DefaultCharSetAttributeNamespace::DefaultCharSetAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
