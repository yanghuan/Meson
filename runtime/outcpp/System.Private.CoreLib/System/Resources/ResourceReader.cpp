#include "ResourceReader-dep.h"

#include <System.Private.CoreLib/System/Activator-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/BadImageFormatException-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/DateTime-dep.h>
#include <System.Private.CoreLib/System/Decimal-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/IndexOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/IO/BinaryReader-dep.h>
#include <System.Private.CoreLib/System/IO/EndOfStreamException-dep.h>
#include <System.Private.CoreLib/System/IO/FileAccess.h>
#include <System.Private.CoreLib/System/IO/FileMode.h>
#include <System.Private.CoreLib/System/IO/FileNotFoundException-dep.h>
#include <System.Private.CoreLib/System/IO/FileOptions.h>
#include <System.Private.CoreLib/System/IO/FileShare.h>
#include <System.Private.CoreLib/System/IO/FileStream-dep.h>
#include <System.Private.CoreLib/System/IO/PinnedBufferMemoryStream-dep.h>
#include <System.Private.CoreLib/System/IO/SeekOrigin.h>
#include <System.Private.CoreLib/System/IO/UnmanagedMemoryStream-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/Resources/FastResourceComparer-dep.h>
#include <System.Private.CoreLib/System/Resources/ResourceLocator-dep.h>
#include <System.Private.CoreLib/System/Resources/ResourceManager-dep.h>
#include <System.Private.CoreLib/System/Resources/ResourceReader-dep.h>
#include <System.Private.CoreLib/System/Resources/ResourceTypeCode.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/Single-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>
#include <System.Private.CoreLib/System/Threading/LazyInitializer-dep.h>
#include <System.Private.CoreLib/System/TimeSpan-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::Resources::ResourceReaderNamespace {
using namespace System::IO;
using namespace System::Reflection;
using namespace System::Text;
using namespace System::Threading;

Object ResourceReader___::ResourceEnumerator___::get_Key() {
  if (_currentName == Int32::MinValue) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumEnded());
  }
  if (!_currentIsValid) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumNotStarted());
  }
  if (_reader->_resCache == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_ResourceReaderIsClosed());
  }
  return _reader->AllocateStringForNameIndex(_currentName, _dataPosition);
}

Object ResourceReader___::ResourceEnumerator___::get_Current() {
  return get_Entry();
}

Int32 ResourceReader___::ResourceEnumerator___::get_DataPosition() {
  return _dataPosition;
}

DictionaryEntry ResourceReader___::ResourceEnumerator___::get_Entry() {
  if (_currentName == Int32::MinValue) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumEnded());
  }
  if (!_currentIsValid) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumNotStarted());
  }
  if (_reader->_resCache == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_ResourceReaderIsClosed());
  }
  Object obj = nullptr;
  String key;
  {
    rt::lock(_reader);
    {
      rt::lock(_reader->_resCache);
      key = _reader->AllocateStringForNameIndex(_currentName, _dataPosition);
      ResourceLocator value;
      if (_reader->_resCache->TryGetValue(key, value)) {
        obj = value.set_Value();
      }
      if (obj == nullptr) {
        obj = ((_dataPosition != -1) ? _reader->LoadObject(_dataPosition) : _reader->GetValueForNameIndex(_currentName));
      }
    }
  }
  return DictionaryEntry(key, obj);
}

Object ResourceReader___::ResourceEnumerator___::get_Value() {
  if (_currentName == Int32::MinValue) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumEnded());
  }
  if (!_currentIsValid) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_EnumNotStarted());
  }
  if (_reader->_resCache == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_ResourceReaderIsClosed());
  }
  return _reader->GetValueForNameIndex(_currentName);
}

void ResourceReader___::ResourceEnumerator___::ctor(ResourceReader reader) {
  _currentName = -1;
  _reader = reader;
  _dataPosition = -2;
}

Boolean ResourceReader___::ResourceEnumerator___::MoveNext() {
  if (_currentName == _reader->_numResources - 1 || _currentName == Int32::MinValue) {
    _currentIsValid = false;
    _currentName = Int32::MinValue;
    return false;
  }
  _currentIsValid = true;
  _currentName++;
  return true;
}

void ResourceReader___::ResourceEnumerator___::Reset() {
  if (_reader->_resCache == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_ResourceReaderIsClosed());
  }
  _currentIsValid = false;
  _currentName = -1;
}

void ResourceReader___::__c___::cctor() {
  __9 = rt::newobj<__c>();
}

void ResourceReader___::__c___::ctor() {
}

Type ResourceReader___::__c___::_InitializeBinaryFormatter_b__6_0() {
  return Type::in::GetType("System.Runtime.Serialization.Formatters.Binary.BinaryFormatter, System.Runtime.Serialization.Formatters, Version=0.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a", true);
}

Func<Object, Stream, Object> ResourceReader___::__c___::_InitializeBinaryFormatter_b__6_1() {
  MethodInfo method = s_binaryFormatterType->GetMethod("Deserialize", rt::newarr<Array<Type>>(1));
  return (Func<Object, Stream, Object>)typeof<ResourceReader>()->GetMethod("CreateUntypedDelegate", BindingFlags::Static | BindingFlags::NonPublic)->MakeGenericMethod(s_binaryFormatterType)->Invoke(nullptr, rt::newarr<Array<Object>>(1));
}

void ResourceReader___::ctor(Stream stream, Dictionary<String, ResourceLocator> resCache, Boolean permitDeserialization) {
  _resCache = resCache;
  _store = rt::newobj<BinaryReader>(stream, Encoding::in::get_UTF8());
  _ums = rt::as<UnmanagedMemoryStream>(stream);
  _permitDeserialization = permitDeserialization;
  ReadResources();
}

Object ResourceReader___::DeserializeObject(Int32 typeIndex) {
  if (!_permitDeserialization) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ResourceObjectSerialization());
  }
  if (_binaryFormatter == nullptr && !InitializeBinaryFormatter()) {
    rt::throw_exception<NotSupportedException>(SR::get_BinaryFormatter_SerializationDisallowed());
  }
  Type type = FindType(typeIndex);
  Object obj = s_deserializeMethod(_binaryFormatter, _store->get_BaseStream());
  if (obj->GetType() != type) {
    rt::throw_exception<BadImageFormatException>(SR::Format(SR::get_BadImageFormat_ResType_SerBlobMismatch(), type->get_FullName(), obj->GetType()->get_FullName()));
  }
  return obj;
}

Boolean ResourceReader___::InitializeBinaryFormatter() {
  Func<Type> as = __c::in::__9__6_0;
  LazyInitializer::EnsureInitialized(s_binaryFormatterType, as != nullptr ? as : (__c::in::__9__6_0 = {__c::in::__9, &__c::in::_InitializeBinaryFormatter_b__6_0}));
  Func<Func<Object, Stream, Object>> is = __c::in::__9__6_1;
  LazyInitializer::EnsureInitialized(s_deserializeMethod, is != nullptr ? is : (__c::in::__9__6_1 = {__c::in::__9, &__c::in::_InitializeBinaryFormatter_b__6_1}));
  _binaryFormatter = Activator::CreateInstance(s_binaryFormatterType);
  return true;
}

Boolean ResourceReader___::ValidateReaderType(String readerType) {
  return ResourceManager::in::IsDefaultType(readerType, "System.Resources.ResourceReader");
}

void ResourceReader___::GetResourceData(String resourceName, String& resourceType, Array<Byte>& resourceData) {
  if (resourceName == nullptr) {
    rt::throw_exception<ArgumentNullException>("resourceName");
  }
  if (_resCache == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_ResourceReaderIsClosed());
  }
  Array<Int32> array = rt::newarr<Array<Int32>>(_numResources);
  Int32 num = FindPosForResource(resourceName);
  if (num == -1) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_ResourceNameNotExist(), resourceName));
  }
  {
    rt::lock((ResourceReader)this);
    for (Int32 i = 0; i < _numResources; i++) {
      _store->get_BaseStream()->set_Position(_nameSectionOffset + GetNamePosition(i));
      Int32 num2 = _store->Read7BitEncodedInt();
      if (num2 < 0) {
        rt::throw_exception<FormatException>(SR::Format(SR::get_BadImageFormat_ResourcesNameInvalidOffset(), num2));
      }
      _store->get_BaseStream()->set_Position(num2);
      Int32 num3 = _store->ReadInt32();
      if (num3 < 0 || num3 >= _store->get_BaseStream()->get_Length() - _dataSectionOffset) {
        rt::throw_exception<FormatException>(SR::Format(SR::get_BadImageFormat_ResourcesDataInvalidOffset(), num3));
      }
      array[i] = num3;
    }
    Array<>::in::Sort(array);
    Int32 num4 = Array<>::in::BinarySearch(array, num);
    Int64 num5 = ((num4 < _numResources - 1) ? (array[num4 + 1] + _dataSectionOffset) : _store->get_BaseStream()->get_Length());
    Int32 num6 = (Int32)(num5 - (num + _dataSectionOffset));
    _store->get_BaseStream()->set_Position(_dataSectionOffset + num);
    ResourceTypeCode resourceTypeCode = (ResourceTypeCode)_store->Read7BitEncodedInt();
    if (resourceTypeCode < ResourceTypeCode::Null || (Int32)resourceTypeCode >= 64 + _typeTable->get_Length()) {
      rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_InvalidType());
    }
    resourceType = TypeNameFromTypeCode(resourceTypeCode);
    num6 -= (Int32)(_store->get_BaseStream()->get_Position() - (_dataSectionOffset + num));
    Array<Byte> array2 = _store->ReadBytes(num6);
    if (array2->get_Length() != num6) {
      rt::throw_exception<FormatException>(SR::get_BadImageFormat_ResourceNameCorrupted());
    }
    resourceData = array2;
  }
}

void ResourceReader___::ctor(String fileName) {
  _resCache = rt::newobj<Dictionary<String, ResourceLocator>>(FastResourceComparer::in::Default);
  _store = rt::newobj<BinaryReader>(rt::newobj<FileStream>(fileName, FileMode::Open, FileAccess::Read, FileShare::Read, 4096, FileOptions::RandomAccess), Encoding::in::get_UTF8());
  try {
    ReadResources();
  } catch (...) {
    _store->Close();
    throw;
  }
}

void ResourceReader___::ctor(Stream stream) {
  if (stream == nullptr) {
    rt::throw_exception<ArgumentNullException>("stream");
  }
  if (!stream->get_CanRead()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_StreamNotReadable());
  }
  _resCache = rt::newobj<Dictionary<String, ResourceLocator>>(FastResourceComparer::in::Default);
  _store = rt::newobj<BinaryReader>(stream, Encoding::in::get_UTF8());
  _ums = rt::as<UnmanagedMemoryStream>(stream);
  ReadResources();
}

void ResourceReader___::Close() {
  Dispose(true);
}

void ResourceReader___::Dispose() {
  Close();
}

void ResourceReader___::Dispose(Boolean disposing) {
  if (_store == nullptr) {
    return;
  }
  _resCache = nullptr;
  if (disposing) {
    BinaryReader store = _store;
    _store = nullptr;
    if (store != nullptr) {
      store->Close();
    }
  }
  _store = nullptr;
  _namePositions = nullptr;
  _nameHashes = nullptr;
  _ums = nullptr;
  _namePositionsPtr = nullptr;
  _nameHashesPtr = nullptr;
}

Int32 ResourceReader___::ReadUnalignedI4(Int32* p) {
  return *(Byte*)p | (((Byte*)p)[1] << 8) | (((Byte*)p)[2] << 16) | (((Byte*)p)[3] << 24);
}

void ResourceReader___::SkipString() {
  Int32 num = _store->Read7BitEncodedInt();
  if (num < 0) {
    rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_NegativeStringLength());
  }
  _store->get_BaseStream()->Seek(num, SeekOrigin::Current);
}

Int32 ResourceReader___::GetNameHash(Int32 index) {
  if (_ums == nullptr) {
    return _nameHashes[index];
  }
  return ReadUnalignedI4(_nameHashesPtr + index);
}

Int32 ResourceReader___::GetNamePosition(Int32 index) {
  Int32 num = ((_ums != nullptr) ? ReadUnalignedI4(_namePositionsPtr + index) : _namePositions[index]);
  if (num < 0 || num > _dataSectionOffset - _nameSectionOffset) {
    rt::throw_exception<FormatException>(SR::Format(SR::get_BadImageFormat_ResourcesNameInvalidOffset(), num));
  }
  return num;
}

IEnumerator ResourceReader___::GetEnumeratorOfIEnumerable() {
  return GetEnumerator();
}

IDictionaryEnumerator ResourceReader___::GetEnumerator() {
  if (_resCache == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_ResourceReaderIsClosed());
  }
  return rt::newobj<ResourceEnumerator>((ResourceReader)this);
}

ResourceReader::in::ResourceEnumerator ResourceReader___::GetEnumeratorInternal() {
  return rt::newobj<ResourceEnumerator>((ResourceReader)this);
}

Int32 ResourceReader___::FindPosForResource(String name) {
  Int32 num = FastResourceComparer::in::HashFunction(name);
  Int32 num2 = 0;
  Int32 i = _numResources - 1;
  Int32 num3 = -1;
  Boolean flag = false;
  while (num2 <= i) {
    num3 = num2 + i >> 1;
    Int32 nameHash = GetNameHash(num3);
    Int32 num4 = ((nameHash != num) ? ((nameHash >= num) ? 1 : (-1)) : 0);
    if (num4 == 0) {
      flag = true;
      break;
    }
    if (num4 < 0) {
      num2 = num3 + 1;
    } else {
      i = num3 - 1;
    }
  }
  if (!flag) {
    return -1;
  }
  if (num2 != num3) {
    num2 = num3;
    while (num2 > 0 && GetNameHash(num2 - 1) == num) {
      num2--;
    }
  }
  if (i != num3) {
    for (i = num3; i < _numResources - 1 && GetNameHash(i + 1) == num; i++) {
    }
  }
  {
    rt::lock((ResourceReader)this);
    for (Int32 j = num2; j <= i; j++) {
      _store->get_BaseStream()->Seek(_nameSectionOffset + GetNamePosition(j), SeekOrigin::Begin);
      if (CompareStringEqualsName(name)) {
        Int32 num5 = _store->ReadInt32();
        if (num5 < 0 || num5 >= _store->get_BaseStream()->get_Length() - _dataSectionOffset) {
          rt::throw_exception<FormatException>(SR::Format(SR::get_BadImageFormat_ResourcesDataInvalidOffset(), num5));
        }
        return num5;
      }
    }
  }
  return -1;
}

Boolean ResourceReader___::CompareStringEqualsName(String name) {
  Int32 num = _store->Read7BitEncodedInt();
  if (num < 0) {
    rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_NegativeStringLength());
  }
  if (_ums != nullptr) {
    Byte* positionPointer = _ums->get_PositionPointer();
    _ums->Seek(num, SeekOrigin::Current);
    if (_ums->get_Position() > _ums->get_Length()) {
      rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_ResourcesNameTooLong());
    }
    return FastResourceComparer::in::CompareOrdinal(positionPointer, num, name) == 0;
  }
  Array<Byte> array = rt::newarr<Array<Byte>>(num);
  Int32 num2 = num;
  while (num2 > 0) {
    Int32 num3 = _store->Read(array, num - num2, num2);
    if (num3 == 0) {
      rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_ResourceNameCorrupted());
    }
    num2 -= num3;
  }
  return FastResourceComparer::in::CompareOrdinal(array, num / 2, name) == 0;
}

String ResourceReader___::AllocateStringForNameIndex(Int32 index, Int32& dataOffset) {
  Int64 num = GetNamePosition(index);
  Int32 num2;
  Array<Byte> array;
  {
    rt::lock((ResourceReader)this);
    _store->get_BaseStream()->Seek(num + _nameSectionOffset, SeekOrigin::Begin);
    num2 = _store->Read7BitEncodedInt();
    if (num2 < 0) {
      rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_NegativeStringLength());
    }
    if (_ums != nullptr) {
      if (_ums->get_Position() > _ums->get_Length() - num2) {
        rt::throw_exception<BadImageFormatException>(SR::Format(SR::get_BadImageFormat_ResourcesIndexTooLong(), index));
      }
      String text = nullptr;
      Char* positionPointer = (Char*)_ums->get_PositionPointer();
      text = rt::newstr<String>(positionPointer, 0, num2 / 2);
      _ums->set_Position(num2);
      dataOffset = _store->ReadInt32();
      if (dataOffset < 0 || dataOffset >= _store->get_BaseStream()->get_Length() - _dataSectionOffset) {
        rt::throw_exception<FormatException>(SR::Format(SR::get_BadImageFormat_ResourcesDataInvalidOffset(), dataOffset));
      }
      return text;
    }
    array = rt::newarr<Array<Byte>>(num2);
    Int32 num3 = num2;
    while (num3 > 0) {
      Int32 num4 = _store->Read(array, num2 - num3, num3);
      if (num4 == 0) {
        rt::throw_exception<EndOfStreamException>(SR::Format(SR::get_BadImageFormat_ResourceNameCorrupted_NameIndex(), index));
      }
      num3 -= num4;
    }
    dataOffset = _store->ReadInt32();
    if (dataOffset < 0 || dataOffset >= _store->get_BaseStream()->get_Length() - _dataSectionOffset) {
      rt::throw_exception<FormatException>(SR::Format(SR::get_BadImageFormat_ResourcesDataInvalidOffset(), dataOffset));
    }
  }
  return Encoding::in::get_Unicode()->GetString(array, 0, num2);
}

Object ResourceReader___::GetValueForNameIndex(Int32 index) {
  Int64 num = GetNamePosition(index);
  {
    rt::lock((ResourceReader)this);
    _store->get_BaseStream()->Seek(num + _nameSectionOffset, SeekOrigin::Begin);
    SkipString();
    Int32 num2 = _store->ReadInt32();
    if (num2 < 0 || num2 >= _store->get_BaseStream()->get_Length() - _dataSectionOffset) {
      rt::throw_exception<FormatException>(SR::Format(SR::get_BadImageFormat_ResourcesDataInvalidOffset(), num2));
    }
    if (_version == 1) {
      return LoadObjectV1(num2);
    }
    ResourceTypeCode typeCode;
    return LoadObjectV2(num2, typeCode);
  }
}

String ResourceReader___::LoadString(Int32 pos) {
  _store->get_BaseStream()->Seek(_dataSectionOffset + pos, SeekOrigin::Begin);
  String result = nullptr;
  Int32 num = _store->Read7BitEncodedInt();
  if (_version == 1) {
    if (num == -1) {
      return nullptr;
    }
    if (FindType(num) != typeof<String>()) {
      rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_InvalidOperation_ResourceNotString_Type(), FindType(num)->get_FullName()));
    }
    result = _store->ReadString();
  } else {
    ResourceTypeCode resourceTypeCode = (ResourceTypeCode)num;
    if (resourceTypeCode != ResourceTypeCode::String && resourceTypeCode != 0) {
      String p = ((resourceTypeCode >= ResourceTypeCode::StartOfUserTypes) ? FindType((Int32)(resourceTypeCode - 64))->get_FullName() : resourceTypeCode->ToString());
      rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_InvalidOperation_ResourceNotString_Type(), p));
    }
    if (resourceTypeCode == ResourceTypeCode::String) {
      result = _store->ReadString();
    }
  }
  return result;
}

Object ResourceReader___::LoadObject(Int32 pos) {
  if (_version == 1) {
    return LoadObjectV1(pos);
  }
  ResourceTypeCode typeCode;
  return LoadObjectV2(pos, typeCode);
}

Object ResourceReader___::LoadObject(Int32 pos, ResourceTypeCode& typeCode) {
  if (_version == 1) {
    Object obj = LoadObjectV1(pos);
    typeCode = (rt::is<String>(obj) ? ResourceTypeCode::String : ResourceTypeCode::StartOfUserTypes);
    return obj;
  }
  return LoadObjectV2(pos, typeCode);
}

Object ResourceReader___::LoadObjectV1(Int32 pos) {
  try {
    return _LoadObjectV1(pos);
  } catch (EndOfStreamException inner) {
    rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_TypeMismatch(), inner);
  } catch (ArgumentOutOfRangeException inner2) {
    rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_TypeMismatch(), inner2);
  }
}

Object ResourceReader___::_LoadObjectV1(Int32 pos) {
  _store->get_BaseStream()->Seek(_dataSectionOffset + pos, SeekOrigin::Begin);
  Int32 num = _store->Read7BitEncodedInt();
  if (num == -1) {
    return nullptr;
  }
  Type left = FindType(num);
  if (left == typeof<String>()) {
    return _store->ReadString();
  }
  if (left == typeof<Int32>()) {
    return _store->ReadInt32();
  }
  if (left == typeof<Byte>()) {
    return _store->ReadByte();
  }
  if (left == typeof<SByte>()) {
    return _store->ReadSByte();
  }
  if (left == typeof<Int16>()) {
    return _store->ReadInt16();
  }
  if (left == typeof<Int64>()) {
    return _store->ReadInt64();
  }
  if (left == typeof<UInt16>()) {
    return _store->ReadUInt16();
  }
  if (left == typeof<UInt32>()) {
    return _store->ReadUInt32();
  }
  if (left == typeof<UInt64>()) {
    return _store->ReadUInt64();
  }
  if (left == typeof<Single>()) {
    return _store->ReadSingle();
  }
  if (left == typeof<Double>()) {
    return _store->ReadDouble();
  }
  if (left == typeof<DateTime>()) {
    return DateTime(_store->ReadInt64());
  }
  if (left == typeof<TimeSpan>()) {
    return TimeSpan(_store->ReadInt64());
  }
  if (left == typeof<Decimal>()) {
    Array<Int32> array = rt::newarr<Array<Int32>>(4);
    for (Int32 i = 0; i < array->get_Length(); i++) {
      array[i] = _store->ReadInt32();
    }
    return Decimal(array);
  }
  return DeserializeObject(num);
}

Object ResourceReader___::LoadObjectV2(Int32 pos, ResourceTypeCode& typeCode) {
  try {
    return _LoadObjectV2(pos, typeCode);
  } catch (EndOfStreamException inner) {
    rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_TypeMismatch(), inner);
  } catch (ArgumentOutOfRangeException inner2) {
    rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_TypeMismatch(), inner2);
  }
}

Object ResourceReader___::_LoadObjectV2(Int32 pos, ResourceTypeCode& typeCode) {
  _store->get_BaseStream()->Seek(_dataSectionOffset + pos, SeekOrigin::Begin);
  typeCode = (ResourceTypeCode)_store->Read7BitEncodedInt();
  switch (typeCode) {
    case ResourceTypeCode::Null:
      return nullptr;
    case ResourceTypeCode::String:
      return _store->ReadString();
    case ResourceTypeCode::Boolean:
      return _store->ReadBoolean();
    case ResourceTypeCode::Char:
      return (Char)_store->ReadUInt16();
    case ResourceTypeCode::Byte:
      return _store->ReadByte();
    case ResourceTypeCode::SByte:
      return _store->ReadSByte();
    case ResourceTypeCode::Int16:
      return _store->ReadInt16();
    case ResourceTypeCode::UInt16:
      return _store->ReadUInt16();
    case ResourceTypeCode::Int32:
      return _store->ReadInt32();
    case ResourceTypeCode::UInt32:
      return _store->ReadUInt32();
    case ResourceTypeCode::Int64:
      return _store->ReadInt64();
    case ResourceTypeCode::UInt64:
      return _store->ReadUInt64();
    case ResourceTypeCode::Single:
      return _store->ReadSingle();
    case ResourceTypeCode::Double:
      return _store->ReadDouble();
    case ResourceTypeCode::Decimal:
      return _store->ReadDecimal();
    case ResourceTypeCode::DateTime:
      {
        Int64 dateData = _store->ReadInt64();
        return DateTime::FromBinary(dateData);
      }case ResourceTypeCode::TimeSpan:
      {
        Int64 ticks = _store->ReadInt64();
        return TimeSpan(ticks);
      }case ResourceTypeCode::ByteArray:
      {
        Int32 num2 = _store->ReadInt32();
        if (num2 < 0) {
          rt::throw_exception<BadImageFormatException>(SR::Format(SR::get_BadImageFormat_ResourceDataLengthInvalid(), num2));
        }
        if (_ums == nullptr) {
          if (num2 > _store->get_BaseStream()->get_Length()) {
            rt::throw_exception<BadImageFormatException>(SR::Format(SR::get_BadImageFormat_ResourceDataLengthInvalid(), num2));
          }
          return _store->ReadBytes(num2);
        }
        if (num2 > _ums->get_Length() - _ums->get_Position()) {
          rt::throw_exception<BadImageFormatException>(SR::Format(SR::get_BadImageFormat_ResourceDataLengthInvalid(), num2));
        }
        Array<Byte> array2 = rt::newarr<Array<Byte>>(num2);
        Int32 num3 = _ums->Read(array2, 0, num2);
        return array2;
      }case ResourceTypeCode::Stream:
      {
        Int32 num = _store->ReadInt32();
        if (num < 0) {
          rt::throw_exception<BadImageFormatException>(SR::Format(SR::get_BadImageFormat_ResourceDataLengthInvalid(), num));
        }
        if (_ums == nullptr) {
          Array<Byte> array = _store->ReadBytes(num);
          return rt::newobj<PinnedBufferMemoryStream>(array);
        }
        if (num > _ums->get_Length() - _ums->get_Position()) {
          rt::throw_exception<BadImageFormatException>(SR::Format(SR::get_BadImageFormat_ResourceDataLengthInvalid(), num));
        }
        return rt::newobj<UnmanagedMemoryStream>(_ums->get_PositionPointer(), num, num, FileAccess::Read);
      }default:
      {
        if (typeCode < ResourceTypeCode::StartOfUserTypes) {
          rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_TypeMismatch());
        }
        Int32 typeIndex = (Int32)(typeCode - 64);
        return DeserializeObject(typeIndex);
      }}
}

void ResourceReader___::ReadResources() {
  try {
    _ReadResources();
  } catch (EndOfStreamException inner) {
    rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_ResourcesHeaderCorrupted(), inner);
  } catch (IndexOutOfRangeException inner2) {
    rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_ResourcesHeaderCorrupted(), inner2);
  }
}

void ResourceReader___::_ReadResources() {
  Int32 num = _store->ReadInt32();
  if (num != ResourceManager::in::MagicNumber) {
    rt::throw_exception<ArgumentException>(SR::get_Resources_StreamNotValid());
  }
  Int32 num2 = _store->ReadInt32();
  Int32 num3 = _store->ReadInt32();
  if (num3 < 0 || num2 < 0) {
    rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_ResourcesHeaderCorrupted());
  }
  if (num2 > 1) {
    _store->get_BaseStream()->Seek(num3, SeekOrigin::Current);
  } else {
    String text = _store->ReadString();
    if (!ValidateReaderType(text)) {
      rt::throw_exception<NotSupportedException>(SR::Format(SR::get_NotSupported_WrongResourceReader_Type(), text));
    }
    SkipString();
  }
  Int32 num4 = _store->ReadInt32();
  if (num4 != 2 && num4 != 1) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_ResourceFileUnsupportedVersion(), 2, num4));
  }
  _version = num4;
  _numResources = _store->ReadInt32();
  if (_numResources < 0) {
    rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_ResourcesHeaderCorrupted());
  }
  Int32 num5 = _store->ReadInt32();
  if (num5 < 0) {
    rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_ResourcesHeaderCorrupted());
  }
  _typeTable = rt::newarr<Array<Type>>(num5);
  _typeNamePositions = rt::newarr<Array<Int32>>(num5);
  for (Int32 i = 0; i < num5; i++) {
    _typeNamePositions[i] = (Int32)_store->get_BaseStream()->get_Position();
    SkipString();
  }
  Int64 position = _store->get_BaseStream()->get_Position();
  Int32 num6 = (Int32)position & 7;
  if (num6 != 0) {
    for (Int32 j = 0; j < 8 - num6; j++) {
      _store->ReadByte();
    }
  }
  if (_ums == nullptr) {
    _nameHashes = rt::newarr<Array<Int32>>(_numResources);
    for (Int32 k = 0; k < _numResources; k++) {
      _nameHashes[k] = _store->ReadInt32();
    }
  } else {
    Int32 num7 = 4 * _numResources;
    if (num7 < 0) {
      rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_ResourcesHeaderCorrupted());
    }
    _nameHashesPtr = (Int32*)_ums->get_PositionPointer();
    _ums->Seek(num7, SeekOrigin::Current);
    Byte* positionPointer = _ums->get_PositionPointer();
  }
  if (_ums == nullptr) {
    _namePositions = rt::newarr<Array<Int32>>(_numResources);
    for (Int32 l = 0; l < _numResources; l++) {
      Int32 num8 = _store->ReadInt32();
      if (num8 < 0) {
        rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_ResourcesHeaderCorrupted());
      }
      _namePositions[l] = num8;
    }
  } else {
    Int32 num9 = 4 * _numResources;
    if (num9 < 0) {
      rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_ResourcesHeaderCorrupted());
    }
    _namePositionsPtr = (Int32*)_ums->get_PositionPointer();
    _ums->Seek(num9, SeekOrigin::Current);
    Byte* positionPointer2 = _ums->get_PositionPointer();
  }
  _dataSectionOffset = _store->ReadInt32();
  if (_dataSectionOffset < 0) {
    rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_ResourcesHeaderCorrupted());
  }
  _nameSectionOffset = _store->get_BaseStream()->set_Position();
  if (_dataSectionOffset < _nameSectionOffset) {
    rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_ResourcesHeaderCorrupted());
  }
}

Type ResourceReader___::FindType(Int32 typeIndex) {
  if (typeIndex < 0 || typeIndex >= _typeTable->get_Length()) {
    rt::throw_exception<BadImageFormatException>(SR::get_BadImageFormat_InvalidType());
  }
  if (_typeTable[typeIndex] == nullptr) {
    Int64 position = _store->get_BaseStream()->get_Position();
    try {
      _store->get_BaseStream()->set_Position(_typeNamePositions[typeIndex]);
      String typeName = _store->ReadString();
      _typeTable[typeIndex] = Type::in::GetType(typeName, true);
    } catch (FileNotFoundException) {
      rt::throw_exception<NotSupportedException>(SR::get_NotSupported_ResourceObjectSerialization());
    } finally: {
      _store->get_BaseStream()->set_Position(position);
    }
  }
  return _typeTable[typeIndex];
}

String ResourceReader___::TypeNameFromTypeCode(ResourceTypeCode typeCode) {
  if (typeCode < ResourceTypeCode::StartOfUserTypes) {
    return "ResourceTypeCode." + typeCode;
  }
  Int32 num = (Int32)(typeCode - 64);
  Int64 position = _store->get_BaseStream()->get_Position();
  try {
    _store->get_BaseStream()->set_Position(_typeNamePositions[num]);
    return _store->ReadString();
  } catch (...) {
  } finally: {
    _store->get_BaseStream()->set_Position(position);
  }
}

} // namespace System::Private::CoreLib::System::Resources::ResourceReaderNamespace
