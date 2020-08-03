#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace IsByRefLikeAttributeNamespace {
CLASS(IsByRefLikeAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace IsByRefLikeAttributeNamespace
using IsByRefLikeAttribute = IsByRefLikeAttributeNamespace::IsByRefLikeAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
