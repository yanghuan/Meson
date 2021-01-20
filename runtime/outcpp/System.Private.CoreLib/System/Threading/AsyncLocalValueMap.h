#pragma once

#include <System.Private.CoreLib/System/Collections/Generic/Dictionary.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARDS_(KeyValuePair)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Threading {
FORWARD(IAsyncLocal)
FORWARD(IAsyncLocalValueMap)
namespace AsyncLocalValueMapNamespace {
using namespace System::Collections::Generic;
class AsyncLocalValueMap {
  private: CLASS(EmptyAsyncLocalValueMap) : public object {
    public: using interface = rt::TypeList<IAsyncLocalValueMap>;
    public: IAsyncLocalValueMap Set(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent);
    public: Boolean TryGetValue(IAsyncLocal key, Object& value);
    public: void ctor();
  };
  private: CLASS(OneElementAsyncLocalValueMap) : public object {
    public: using interface = rt::TypeList<IAsyncLocalValueMap>;
    public: void ctor(IAsyncLocal key, Object value);
    public: IAsyncLocalValueMap Set(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent);
    public: Boolean TryGetValue(IAsyncLocal key, Object& value);
    private: IAsyncLocal _key1;
    private: Object _value1;
  };
  private: CLASS(TwoElementAsyncLocalValueMap) : public object {
    public: using interface = rt::TypeList<IAsyncLocalValueMap>;
    public: void ctor(IAsyncLocal key1, Object value1, IAsyncLocal key2, Object value2);
    public: IAsyncLocalValueMap Set(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent);
    public: Boolean TryGetValue(IAsyncLocal key, Object& value);
    private: IAsyncLocal _key1;
    private: IAsyncLocal _key2;
    private: Object _value1;
    private: Object _value2;
  };
  private: CLASS(ThreeElementAsyncLocalValueMap) : public object {
    public: using interface = rt::TypeList<IAsyncLocalValueMap>;
    public: void ctor(IAsyncLocal key1, Object value1, IAsyncLocal key2, Object value2, IAsyncLocal key3, Object value3);
    public: IAsyncLocalValueMap Set(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent);
    public: Boolean TryGetValue(IAsyncLocal key, Object& value);
    private: IAsyncLocal _key1;
    private: IAsyncLocal _key2;
    private: IAsyncLocal _key3;
    private: Object _value1;
    private: Object _value2;
    private: Object _value3;
  };
  private: CLASS(MultiElementAsyncLocalValueMap) : public object {
    public: using interface = rt::TypeList<IAsyncLocalValueMap>;
    public: void ctor(Int32 count);
    public: void UnsafeStore(Int32 index, IAsyncLocal key, Object value);
    public: IAsyncLocalValueMap Set(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent);
    public: Boolean TryGetValue(IAsyncLocal key, Object& value);
    private: Array<KeyValuePair<IAsyncLocal, Object>> _keyValues;
  };
  private: CLASS(ManyElementAsyncLocalValueMap) : public Dictionary<IAsyncLocal, Object>::in {
    public: using interface = rt::TypeList<IAsyncLocalValueMap>;
    public: void ctor(Int32 capacity);
    public: IAsyncLocalValueMap Set(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent);
  };
  public: static IAsyncLocalValueMap get_Empty() { return Empty; }
  public: static Boolean IsEmpty(IAsyncLocalValueMap asyncLocalValueMap);
  public: static IAsyncLocalValueMap Create(IAsyncLocal key, Object value, Boolean treatNullValueAsNonexistent);
  public: static void cctor();
  private: static IAsyncLocalValueMap Empty;
};
} // namespace AsyncLocalValueMapNamespace
using AsyncLocalValueMap = AsyncLocalValueMapNamespace::AsyncLocalValueMap;
} // namespace System::Private::CoreLib::System::Threading
