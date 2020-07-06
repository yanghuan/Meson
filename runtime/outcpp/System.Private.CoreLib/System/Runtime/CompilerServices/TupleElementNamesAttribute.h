#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace TupleElementNamesAttributeNamespace {
using namespace Collections::Generic;
using Collections::Generic::IList;
CLASS(TupleElementNamesAttribute) {
  public: IList<String> get_TransformNames();
  private: Array<String> _transformNames;
};
} // namespace TupleElementNamesAttributeNamespace
using TupleElementNamesAttribute = TupleElementNamesAttributeNamespace::TupleElementNamesAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
