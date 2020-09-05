#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/UInt64.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(IDeserializationCallback)
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(IDisposable)
FORWARD(Predicate, T)
FORWARDS_(ValueTuple, T1, T2, T3, T4, T5, T6, T7, T8, T9)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(ICollection, T)
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
FORWARD(IEqualityComparer, T)
FORWARD(IReadOnlyCollection, T)
FORWARD(IReadOnlySet, T)
FORWARD(ISet, T)
namespace HashSetNamespace {
using namespace System::Runtime::Serialization;
template <class T>
using ICollection = Generic::ICollection<T>;
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
template <class T>
using IEnumerator = Generic::IEnumerator<T>;
using IEnumerator_ = Collections::IEnumerator;
template <class T>
using IEqualityComparer = Generic::IEqualityComparer<T>;
CLASS(HashSet, T) : public object {
  public: using interface = rt::TypeList<ICollection<T>, IEnumerable<T>, IEnumerable_, ISet<T>, IReadOnlyCollection<T>, IReadOnlySet<T>, ISerializable, IDeserializationCallback>;
  private: struct Entry : public valueType<Entry> {
    public: Int32 HashCode;
    public: Int32 Next;
    public: T Value;
  };
  public: struct Enumerator : public valueType<Enumerator> {
    public: using interface = rt::TypeList<IEnumerator<T>, IDisposable, IEnumerator_>;
    public: T get_Current();
    private: Object get_CurrentOfIEnumerator();
    public: explicit Enumerator(HashSet<T> hashSet);
    public: Boolean MoveNext();
    public: void Dispose();
    public: explicit Enumerator() {}
    private: HashSet<T> _hashSet;
    private: Int32 _version;
    private: Int32 _index;
    private: T _current;
  };
  public: Int32 get_Count();
  private: Boolean get_IsReadOnlyOfICollectionT();
  public: IEqualityComparer<T> get_Comparer();
  public: void ctor();
  public: void ctor(IEqualityComparer<T> comparer);
  public: void ctor(Int32 capacity);
  public: void ctor(IEnumerable<T> collection);
  public: void ctor(IEnumerable<T> collection, IEqualityComparer<T> comparer);
  public: void ctor(Int32 capacity, IEqualityComparer<T> comparer);
  public: void ctor(SerializationInfo info, StreamingContext context);
  private: void ConstructFrom(HashSet<T> source);
  public: void Clear();
  public: Boolean Contains(T item);
  private: Int32 FindItemIndex(T item);
  private: Int32& GetBucketRef(Int32 hashCode);
  public: Boolean Remove(T item);
  public: Enumerator GetEnumerator();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: void OnDeserialization(Object sender);
  public: Boolean Add(T item);
  public: Boolean TryGetValue(T equalValue, T& actualValue);
  public: void UnionWith(IEnumerable<T> other);
  public: void IntersectWith(IEnumerable<T> other);
  public: void ExceptWith(IEnumerable<T> other);
  public: void SymmetricExceptWith(IEnumerable<T> other);
  public: Boolean IsSubsetOf(IEnumerable<T> other);
  public: Boolean IsProperSubsetOf(IEnumerable<T> other);
  public: Boolean IsSupersetOf(IEnumerable<T> other);
  public: Boolean IsProperSupersetOf(IEnumerable<T> other);
  public: Boolean Overlaps(IEnumerable<T> other);
  public: Boolean SetEquals(IEnumerable<T> other);
  public: void CopyTo(Array<T> array);
  public: void CopyTo(Array<T> array, Int32 arrayIndex);
  public: void CopyTo(Array<T> array, Int32 arrayIndex, Int32 count);
  public: Int32 RemoveWhere(Predicate<T> match);
  public: Int32 EnsureCapacity(Int32 capacity);
  private: void Resize();
  private: void Resize(Int32 newSize, Boolean forceNewHashCodes);
  public: void TrimExcess();
  public: static IEqualityComparer<HashSet<T>> CreateSetComparer();
  private: Int32 Initialize(Int32 capacity);
  private: Boolean AddIfNotPresent(T value, Int32& location);
  private: Boolean ContainsAllElements(IEnumerable<T> other);
  public: Boolean IsSubsetOfHashSetWithSameComparer(HashSet<T> other);
  private: void IntersectWithHashSetWithSameComparer(HashSet<T> other);
  private: void IntersectWithEnumerable(IEnumerable<T> other);
  private: void SymmetricExceptWithUniqueHashSet(HashSet<T> other);
  private: void SymmetricExceptWithEnumerable(IEnumerable<T> other);
  private: ValueTuple<Int32, Int32> CheckUniqueAndUnfoundElements(IEnumerable<T> other, Boolean returnIfUnfound);
  public: static Boolean EqualityComparersAreEqual(HashSet<T> set1, HashSet<T> set2);
  private: Array<Int32> _buckets;
  private: Array<Entry> _entries;
  private: UInt64 _fastModMultiplier;
  private: Int32 _count;
  private: Int32 _freeList;
  private: Int32 _freeCount;
  private: Int32 _version;
  private: IEqualityComparer<T> _comparer;
  private: SerializationInfo _siInfo;
};
} // namespace HashSetNamespace
template <class T>
using HashSet = HashSetNamespace::HashSet<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
