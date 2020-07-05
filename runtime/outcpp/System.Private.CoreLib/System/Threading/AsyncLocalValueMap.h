#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Threading/IAsyncLocalValueMap.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARDS_(KeyValuePair, T1, T2, T3)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Threading {
FORWARD(IAsyncLocal)
namespace AsyncLocalValueMapNamespace {
using namespace Collections::Generic;
class AsyncLocalValueMap {
  private: CLASS(EmptyAsyncLocalValueMap) {
    public: IAsyncLocalValueMap Set(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent);
    public: Boolean TryGetValue(IAsyncLocal key, Object& value);
  };
  private: CLASS(OneElementAsyncLocalValueMap) {
    public: IAsyncLocalValueMap Set(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent);
    public: Boolean TryGetValue(IAsyncLocal key, Object& value);
    private: IAsyncLocal _key1;
    private: Object _value1;
  };
  private: CLASS(TwoElementAsyncLocalValueMap) {
    public: IAsyncLocalValueMap Set(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent);
    public: Boolean TryGetValue(IAsyncLocal key, Object& value);
    private: IAsyncLocal _key1;
    private: IAsyncLocal _key2;
    private: Object _value1;
    private: Object _value2;
  };
  private: CLASS(ThreeElementAsyncLocalValueMap) {
    public: IAsyncLocalValueMap Set(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent);
    public: Boolean TryGetValue(IAsyncLocal key, Object& value);
    private: IAsyncLocal _key1;
    private: IAsyncLocal _key2;
    private: IAsyncLocal _key3;
    private: Object _value1;
    private: Object _value2;
    private: Object _value3;
  };
  private: CLASS(MultiElementAsyncLocalValueMap) {
    public: void UnsafeStore(Int32 index, IAsyncLocal key, Object value);
    public: IAsyncLocalValueMap Set(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent);
    public: Boolean TryGetValue(IAsyncLocal key, Object& value);
    private: Array<KeyValuePair<IAsyncLocal, Object>> _keyValues;
  };
  private: CLASS(ManyElementAsyncLocalValueMap) {
    public: IAsyncLocalValueMap Set(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent);
  };
  public: static IAsyncLocalValueMap get_Empty() { return Empty; }
  public: static Boolean IsEmpty(IAsyncLocalValueMap asyncLocalValueMap);
  public: static IAsyncLocalValueMap Create(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent);
  private: static IAsyncLocalValueMap Empty;
};
} // namespace AsyncLocalValueMapNamespace
using AsyncLocalValueMap = AsyncLocalValueMapNamespace::AsyncLocalValueMap;
} // namespace System::Private::CoreLib::System::Threading
