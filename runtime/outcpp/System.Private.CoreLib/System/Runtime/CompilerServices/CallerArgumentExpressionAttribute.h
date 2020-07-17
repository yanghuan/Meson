#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace CallerArgumentExpressionAttributeNamespace {
CLASS(CallerArgumentExpressionAttribute) {
  public: String get_ParameterName() { return ParameterName; }
  public: void Ctor(String parameterName);
  private: String ParameterName;
};
} // namespace CallerArgumentExpressionAttributeNamespace
using CallerArgumentExpressionAttribute = CallerArgumentExpressionAttributeNamespace::CallerArgumentExpressionAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
