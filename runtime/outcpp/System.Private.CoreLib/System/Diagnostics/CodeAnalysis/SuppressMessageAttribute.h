#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace SuppressMessageAttributeNamespace {
CLASS(SuppressMessageAttribute) {
  private: String Category;
  private: String CheckId;
  private: String Scope;
  private: String Target;
  private: String MessageId;
  private: String Justification;
};
} // namespace SuppressMessageAttributeNamespace
using SuppressMessageAttribute = SuppressMessageAttributeNamespace::SuppressMessageAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
