#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARDS(DictionaryEntry)
FORWARD(IDictionaryEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::IO {
FORWARD(BinaryReader)
FORWARD(Stream)
FORWARD(UnmanagedMemoryStream)
} // namespace System::Private::CoreLib::System::IO
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Resources {
enum class ResourceTypeCode;
FORWARDS(ResourceLocator)
namespace ResourceReaderNamespace {
using namespace ::System::Private::CoreLib::System::Collections;
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::IO;
CLASS(ResourceReader) {
  public: CLASS(ResourceEnumerator) {
    public: Object get_Key();
    public: Object get_Current();
    public: Int32 get_DataPosition();
    public: DictionaryEntry get_Entry();
    public: Object get_Value();
    public: Boolean MoveNext();
    public: void Reset();
    private: ResourceReader _reader;
    private: Boolean _currentIsValid;
    private: Int32 _currentName;
    private: Int32 _dataPosition;
  };
  public: void Close();
  public: void Dispose();
  private: void Dispose(Boolean disposing);
  public: static Int32 ReadUnalignedI4(Int32* p);
  private: void SkipString();
  private: Int32 GetNameHash(Int32 index);
  private: Int32 GetNamePosition(Int32 index);
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
  private: Object DeserializeObject(Int32 typeIndex);
  private: void InitializeBinaryFormatter();
  private: Boolean ValidateReaderType(String readerType);
  public: void GetResourceData(String resourceName, String& resourceType, Array<Byte>& resourceData);
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
  private: Boolean _permitDeserialization;
  private: Object _binaryFormatter;
  private: static Type s_binaryFormatterType;
  private: static Func<Object, Stream, Object> s_deserializeMethod;
};
} // namespace ResourceReaderNamespace
using ResourceReader = ResourceReaderNamespace::ResourceReader;
} // namespace System::Private::CoreLib::System::Resources
