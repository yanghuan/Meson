#include "Marvin-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Buffers/ArrayPool-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/Numerics/BitOperations-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/Text/Unicode/Utf16Utility-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::MarvinNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Buffers;
using namespace System::Numerics;
using namespace System::Runtime::InteropServices;
using namespace System::Text::Unicode;

UInt64 Marvin::get_DefaultSeed() {
  return <DefaultSeed>k__BackingField;
}

Int32 Marvin::ComputeHash32(ReadOnlySpan<Byte> data, UInt64 seed) {
  return ComputeHash32(MemoryMarshal::GetReference(data), (UInt32)data.get_Length(), (UInt32)seed, (UInt32)(seed >> 32));
}

Int32 Marvin::ComputeHash32(Byte& data, UInt32 count, UInt32 p0, UInt32 p1) {
  UInt32 num;
  if (count < 8) {
    if (count < 4) {
      num = ((!BitConverter::IsLittleEndian) ? 2147483648u : 128u);
    }
  } else {
    UInt32 num2 = count / 8u;
  }
  p0 += Unsafe::ReadUnaligned<UInt32>(data);
  Block(p0, p1);
}

void Marvin::Block(UInt32& rp0, UInt32& rp1) {
  UInt32 num = rp0;
  UInt32 num2 = rp1;
  num2 ^= num;
  num = BitOperations::RotateLeft(num, 20);
  num += num2;
  num2 = BitOperations::RotateLeft(num2, 9);
  num2 ^= num;
  num = BitOperations::RotateLeft(num, 27);
  num += num2;
  num2 = BitOperations::RotateLeft(num2, 19);
  rp0 = num;
  rp1 = num2;
}

UInt64 Marvin::GenerateSeed() {
  UInt64 result;
  Interop::GetRandomBytes((Byte*)(&result), 8);
  return result;
}

Int32 Marvin::ComputeHash32OrdinalIgnoreCase(Char& data, Int32 count, UInt32 p0, UInt32 p1) {
  UInt32 num = (UInt32)count;
  unsigned int num2 = 0u;
  while (true) {
    if (num >= 2) {
      UInt32 value = Unsafe::ReadUnaligned<UInt32>(Unsafe::As<Char, Byte>(Unsafe::AddByteOffset(data, num2)));
      if (!Utf16Utility::AllCharsInUInt32AreAscii(value)) {
        break;
      }
      p0 += Utf16Utility::ConvertAllAsciiCharsInUInt32ToUppercase(value);
      Block(p0, p1);
      num2 += 4;
      num -= 2;
    }
    if (num != 0) {
      UInt32 value = Unsafe::AddByteOffset(data, num2);
      if (value > 127) {
        break;
      }
      p0 += Utf16Utility::ConvertAllAsciiCharsInUInt32ToUppercase(value) + 8388480;
    }
    p0 += 128;
    Block(p0, p1);
    Block(p0, p1);
  }
  return ComputeHash32OrdinalIgnoreCaseSlow(Unsafe::AddByteOffset(data, num2), (Int32)num, p0, p1);
}

Int32 Marvin::ComputeHash32OrdinalIgnoreCaseSlow(Char& data, Int32 count, UInt32 p0, UInt32 p1) {
  Array<Char> array = nullptr;
  Char default[64] = {};
  Span<Char> span = ((UInt32)count > 64u) ? ((Span<Char>)(array = ArrayPool<Char>::in::get_Shared()->Rent(count))) : default;
  Span<Char> span2 = span;
  Int32 num = MemoryExtensions::ToUpperInvariant(ReadOnlySpan<Char>(data, count), span2);
  Int32 result = ComputeHash32(Unsafe::As<Char, Byte>(MemoryMarshal::GetReference(span2)), (UInt32)(num * 2), p0, p1);
  if (array != nullptr) {
    ArrayPool<Char>::in::get_Shared()->Return(array);
  }
  return result;
}

void Marvin::ctor_static() {
  DefaultSeed = GenerateSeed();
}

} // namespace System::Private::CoreLib::System::MarvinNamespace
