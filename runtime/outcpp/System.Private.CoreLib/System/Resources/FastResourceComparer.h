#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IComparer)
FORWARD(IEqualityComparer)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IComparer, T)
FORWARD(IEqualityComparer, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Resources {
namespace FastResourceComparerNamespace {
using namespace System::Collections;
using namespace System::Collections::Generic;
using IComparer = Collections::IComparer;
using IEqualityComparer = Collections::IEqualityComparer;
template <class T>
using IComparer_ = Collections::Generic::IComparer<T>;
template <class T>
using IEqualityComparer_ = Collections::Generic::IEqualityComparer<T>;
CLASS(FastResourceComparer) : public Object::in {
  public: using interface = rt::TypeList<IComparer, IEqualityComparer, IComparer_<String>, IEqualityComparer_<String>>;
  public: Int32 GetHashCode(Object key);
  public: Int32 GetHashCode(String key);
  public: static Int32 HashFunction(String key);
  public: Int32 Compare(Object a, Object b);
  public: Int32 Compare(String a, String b);
  public: Boolean Equals(String a, String b);
  public: Boolean Equals(Object a, Object b);
  public: static Int32 CompareOrdinal(String a, Array<Byte> bytes, Int32 bCharLength);
  public: static Int32 CompareOrdinal(Array<Byte> bytes, Int32 aCharLength, String b);
  public: static Int32 CompareOrdinal(Byte* a, Int32 byteLen, String b);
  public: void ctor();
  private: static void cctor();
  public: static FastResourceComparer Default;
};
} // namespace FastResourceComparerNamespace
using FastResourceComparer = FastResourceComparerNamespace::FastResourceComparer;
} // namespace System::Private::CoreLib::System::Resources
