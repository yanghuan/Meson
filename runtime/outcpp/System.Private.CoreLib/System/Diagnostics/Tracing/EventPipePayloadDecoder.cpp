#include "EventPipePayloadDecoder-dep.h"

#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Buffers/Binary/BinaryPrimitives-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/Guid-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Reflection/ParameterInfo-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/Single-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipePayloadDecoderNamespace {
using namespace System::Buffers::Binary;
using namespace System::Reflection;
using namespace System::Runtime::InteropServices;
using namespace System::Text;

Array<Object> EventPipePayloadDecoder::DecodePayload(EventSource::in::EventMetadata& metadata, ReadOnlySpan<Byte> payload) {
  Array<ParameterInfo> parameters = metadata.Parameters;
  Array<Object> array = rt::newarr<Array<Object>>(parameters->get_Length());
  for (Int32 i = 0; i < parameters->get_Length(); i++) {
    if (payload.get_Length() <= 0) {
      break;
    }
    Type parameterType = parameters[i]->get_ParameterType();
    if (parameterType == typeof<IntPtr>()) {
      Int32 size = IntPtr::get_Size();
      array[i] = (IntPtr)BinaryPrimitives::ReadInt64LittleEndian(payload);
      payload = payload.Slice(IntPtr::get_Size());
    } else if (parameterType == typeof<Int32>()) {
      array[i] = BinaryPrimitives::ReadInt32LittleEndian(payload);
      payload = payload.Slice(4);
    } else if (parameterType == typeof<UInt32>()) {
      array[i] = BinaryPrimitives::ReadUInt32LittleEndian(payload);
      payload = payload.Slice(4);
    } else if (parameterType == typeof<Int64>()) {
      array[i] = BinaryPrimitives::ReadInt64LittleEndian(payload);
      payload = payload.Slice(8);
    } else if (parameterType == typeof<UInt64>()) {
      array[i] = BinaryPrimitives::ReadUInt64LittleEndian(payload);
      payload = payload.Slice(8);
    } else if (parameterType == typeof<Byte>()) {
      array[i] = MemoryMarshal::Read<Byte>(payload);
      payload = payload.Slice(1);
    } else if (parameterType == typeof<SByte>()) {
      array[i] = MemoryMarshal::Read<SByte>(payload);
      payload = payload.Slice(1);
    } else if (parameterType == typeof<Int16>()) {
      array[i] = BinaryPrimitives::ReadInt16LittleEndian(payload);
      payload = payload.Slice(2);
    } else if (parameterType == typeof<UInt16>()) {
      array[i] = BinaryPrimitives::ReadUInt16LittleEndian(payload);
      payload = payload.Slice(2);
    } else if (parameterType == typeof<Single>()) {
      array[i] = BitConverter::Int32BitsToSingle(BinaryPrimitives::ReadInt32LittleEndian(payload));
      payload = payload.Slice(4);
    } else if (parameterType == typeof<Double>()) {
      array[i] = BitConverter::Int64BitsToDouble(BinaryPrimitives::ReadInt64LittleEndian(payload));
      payload = payload.Slice(8);
    } else if (parameterType == typeof<Boolean>()) {
      array[i] = BinaryPrimitives::ReadInt32LittleEndian(payload) == 1;
      payload = payload.Slice(4);
    } else if (parameterType == typeof<Guid>()) {
      array[i] = Guid(payload.Slice(0, 16));
      payload = payload.Slice(16);
    } else if (parameterType == typeof<Char>()) {
      array[i] = (Char)BinaryPrimitives::ReadUInt16LittleEndian(payload);
      payload = payload.Slice(2);
    } else {
      if (!(parameterType == typeof<String>())) {
        continue;
      }
      Int32 num = -1;
      for (Int32 j = 1; j < payload.get_Length(); j += 2) {
        if (payload[j - 1] == 0 && payload[j] == 0) {
          num = j + 1;
          break;
        }
      }
      ReadOnlySpan<Char> readOnlySpan;
      if (num < 0) {
        readOnlySpan = MemoryMarshal::Cast<Byte, Char>(payload);
        payload = rt::default__;
      } else {
        readOnlySpan = MemoryMarshal::Cast<Byte, Char>(payload.Slice(0, num - 2));
        payload = payload.Slice(num);
      }
      array[i] = (BitConverter::IsLittleEndian ? rt::newstr<String>(readOnlySpan) : Encoding::in::get_Unicode()->GetString(MemoryMarshal::Cast<Char, Byte>(readOnlySpan)));
    }













  }
  return array;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::EventPipePayloadDecoderNamespace
