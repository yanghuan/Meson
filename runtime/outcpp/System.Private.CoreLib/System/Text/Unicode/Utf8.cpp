#include "Utf8-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Text/Rune-dep.h>
#include <System.Private.CoreLib/System/Text/Unicode/Utf8Utility-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Text::Unicode::Utf8Namespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;

OperationStatus Utf8::FromUtf16(ReadOnlySpan<Char> source, Span<Byte> destination, Int32& charsRead, Int32& bytesWritten, Boolean replaceInvalidSequences, Boolean isFinalBlock) {
  _ = source.get_Length();
  _ = destination.get_Length();
  {
    Char* ptr = &MemoryMarshal::GetReference(source);
    {
      Byte* ptr2 = &MemoryMarshal::GetReference(destination);
      OperationStatus operationStatus = OperationStatus::Done;
      Char* pInputBufferRemaining = ptr;
      Byte* pOutputBufferRemaining = ptr2;
      while (!source.get_IsEmpty()) {
        operationStatus = Utf8Utility::TranscodeToUtf8((Char*)Unsafe::AsPointer(MemoryMarshal::GetReference(source)), source.get_Length(), (Byte*)Unsafe::AsPointer(MemoryMarshal::GetReference(destination)), destination.get_Length(), pInputBufferRemaining, pOutputBufferRemaining);
        if (operationStatus <= OperationStatus::DestinationTooSmall || (operationStatus == OperationStatus::NeedMoreData && !isFinalBlock)) {
          break;
        }
        if (!replaceInvalidSequences) {
          operationStatus = OperationStatus::InvalidData;
          break;
        }
        destination = destination.Slice((Int32)(pOutputBufferRemaining - (Byte*)Unsafe::AsPointer(MemoryMarshal::GetReference(destination))));
        if (2u >= (UInt32)destination.get_Length()) {
          operationStatus = OperationStatus::DestinationTooSmall;
          break;
        }
        destination[0] = 239;
        destination[1] = 191;
        destination[2] = 189;
        destination = destination.Slice(3);
        source = source.Slice((Int32)(pInputBufferRemaining - (Char*)Unsafe::AsPointer(MemoryMarshal::GetReference(source))) + 1);
        operationStatus = OperationStatus::Done;
        pInputBufferRemaining = (Char*)Unsafe::AsPointer(MemoryMarshal::GetReference(source));
        pOutputBufferRemaining = (Byte*)Unsafe::AsPointer(MemoryMarshal::GetReference(destination));
      }
      charsRead = (Int32)(pInputBufferRemaining - ptr);
      bytesWritten = (Int32)(pOutputBufferRemaining - ptr2);
      return operationStatus;
    }
  }
}

OperationStatus Utf8::ToUtf16(ReadOnlySpan<Byte> source, Span<Char> destination, Int32& bytesRead, Int32& charsWritten, Boolean replaceInvalidSequences, Boolean isFinalBlock) {
  _ = source.get_Length();
  _ = destination.get_Length();
  {
    Byte* ptr = &MemoryMarshal::GetReference(source);
    {
      Char* ptr2 = &MemoryMarshal::GetReference(destination);
      OperationStatus operationStatus = OperationStatus::Done;
      Byte* pInputBufferRemaining = ptr;
      Char* pOutputBufferRemaining = ptr2;
      while (!source.get_IsEmpty()) {
        operationStatus = Utf8Utility::TranscodeToUtf16((Byte*)Unsafe::AsPointer(MemoryMarshal::GetReference(source)), source.get_Length(), (Char*)Unsafe::AsPointer(MemoryMarshal::GetReference(destination)), destination.get_Length(), pInputBufferRemaining, pOutputBufferRemaining);
        if (operationStatus <= OperationStatus::DestinationTooSmall || (operationStatus == OperationStatus::NeedMoreData && !isFinalBlock)) {
          break;
        }
        if (!replaceInvalidSequences) {
          operationStatus = OperationStatus::InvalidData;
          break;
        }
        destination = destination.Slice((Int32)(pOutputBufferRemaining - (Char*)Unsafe::AsPointer(MemoryMarshal::GetReference(destination))));
        if (destination.get_IsEmpty()) {
          operationStatus = OperationStatus::DestinationTooSmall;
          break;
        }
        destination[0] = 65533;
        destination = destination.Slice(1);
        source = source.Slice((Int32)(pInputBufferRemaining - (Byte*)Unsafe::AsPointer(MemoryMarshal::GetReference(source))));
        Rune result;
        Int32 bytesConsumed;
        Rune::DecodeFromUtf8(source, result, bytesConsumed);
        source = source.Slice(bytesConsumed);
        operationStatus = OperationStatus::Done;
        pInputBufferRemaining = (Byte*)Unsafe::AsPointer(MemoryMarshal::GetReference(source));
        pOutputBufferRemaining = (Char*)Unsafe::AsPointer(MemoryMarshal::GetReference(destination));
      }
      bytesRead = (Int32)(pInputBufferRemaining - ptr);
      charsWritten = (Int32)(pOutputBufferRemaining - ptr2);
      return operationStatus;
    }
  }
}

} // namespace System::Private::CoreLib::System::Text::Unicode::Utf8Namespace
