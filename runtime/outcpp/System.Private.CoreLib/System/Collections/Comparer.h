#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CompareInfo)
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(IComparer)
namespace ComparerNamespace {
using namespace Globalization;
using namespace Runtime::Serialization;
CLASS(Comparer) : public Object::in {
  public: using interface = rt::TypeList<IComparer, ISerializable>;
  public: void ctor(CultureInfo culture);
  private: void ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: Int32 Compare(Object a, Object b);
  private: static void ctor_static();
  private: CompareInfo _compareInfo;
  public: static Comparer Default;
  public: static Comparer DefaultInvariant;
};
} // namespace ComparerNamespace
using Comparer = ComparerNamespace::Comparer;
} // namespace System::Private::CoreLib::System::Collections
