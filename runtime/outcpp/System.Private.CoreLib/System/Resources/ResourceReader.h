#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARDS(DictionaryEntry)
FORWARD(IDictionaryEnumerator)
FORWARD(IEnumerable)
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Byte)
FORWARD_(Func)
FORWARD(IDisposable)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::IO {
FORWARD(BinaryReader)
FORWARD(Stream)
FORWARD(UnmanagedMemoryStream)
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Resources {
enum class ResourceTypeCode : int32_t;
FORWARD(IResourceReader)
FORWARDS(ResourceLocator)
namespace ResourceReaderNamespace {
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Reflection;
using IEnumerable = Collections::IEnumerable;
using IEnumerator = Collections::IEnumerator;
CLASS(ResourceReader) : public object {
  public: using interface = rt::TypeList<IResourceReader, IEnumerable, IDisposable>;
  public: CLASS(ResourceEnumerator) : public object {
    public: using interface = rt::TypeList<IDictionaryEnumerator, IEnumerator>;
    public: Object get_Key();
    public: Object get_Current();
    public: Int32 get_DataPosition();
    public: DictionaryEntry get_Entry();
    public: Object get_Value();
    public: void ctor(ResourceReader reader);
    public: Boolean MoveNext();
    public: void Reset();
    private: ResourceReader _reader;
    private: Boolean _currentIsValid;
    private: Int32 _currentName;
    private: Int32 _dataPosition;
  };
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: Type _InitializeBinaryFormatter_b__6_0();
    public: Func<Object, Stream, Object> _InitializeBinaryFormatter_b__6_1();
    public: static __c __9;
    public: static Func<Type> __9__6_0;
    public: static Func<Func<Object, Stream, Object>> __9__6_1;
  };
  private: CLASS(__c__DisplayClass7_0, TInstance) : public object {
    public: void ctor();
    public: Object _CreateUntypedDelegate_b__0(Object obj, Stream stream);
    public: Func<TInstance, Stream, Object> typedDelegate;
  };
  public: void ctor(Stream stream, Dictionary<String, ResourceLocator> resCache, Boolean permitDeserialization);
  private: Object DeserializeObject(Int32 typeIndex);
  private: void InitializeBinaryFormatter();
  private: template <class TInstance>
  static Func<Object, Stream, Object> CreateUntypedDelegate(MethodInfo method);
  private: static Boolean ValidateReaderType(String readerType);
  public: void GetResourceData(String resourceName, String& resourceType, Array<Byte>& resourceData);
  public: void ctor(String fileName);
  public: void ctor(Stream stream);
  public: void Close();
  public: void Dispose();
  private: void Dispose(Boolean disposing);
  public: static Int32 ReadUnalignedI4(Int32* p);
  private: void SkipString();
  private: Int32 GetNameHash(Int32 index);
  private: Int32 GetNamePosition(Int32 index);
  private: IEnumerator GetEnumeratorOfIEnumerable();
  public: IDictionaryEnumerator GetEnumerator();
  public: ResourceEnumerator GetEnumeratorInternal();
  public: Int32 FindPosForResource(String name);
  private: Boolean CompareStringEqualsName(String name);
  private: String AllocateStringForNameIndex(Int32 index, Int32& dataOffset);
  private: Object GetValueForNameIndex(Int32 index);
  public: String LoadString(Int32 pos);
  public: Object LoadObject(Int32 pos);
  public: Object LoadObject(Int32 pos, ResourceTypeCode& typeCode);
  public: Object LoadObjectV1(Int32 pos);
  private: Object _LoadObjectV1(Int32 pos);
  public: Object LoadObjectV2(Int32 pos, ResourceTypeCode& typeCode);
  private: Object _LoadObjectV2(Int32 pos, ResourceTypeCode& typeCode);
  private: void ReadResources();
  private: void _ReadResources();
  private: Type FindType(Int32 typeIndex);
  private: String TypeNameFromTypeCode(ResourceTypeCode typeCode);
  private: Boolean _permitDeserialization;
  private: Object _binaryFormatter;
  private: static Type s_binaryFormatterType;
  private: static Func<Object, Stream, Object> s_deserializeMethod;
  private: BinaryReader _store;
  public: Dictionary<String, ResourceLocator> _resCache;
  private: Int64 _nameSectionOffset;
  private: Int64 _dataSectionOffset;
  private: Array<Int32> _nameHashes;
  private: Int32* _nameHashesPtr;
  private: Array<Int32> _namePositions;
  private: Int32* _namePositionsPtr;
  private: Array<Type> _typeTable;
  private: Array<Int32> _typeNamePositions;
  private: Int32 _numResources;
  private: UnmanagedMemoryStream _ums;
  private: Int32 _version;
};
} // namespace ResourceReaderNamespace
using ResourceReader = ResourceReaderNamespace::ResourceReader;
} // namespace System::Private::CoreLib::System::Resources
