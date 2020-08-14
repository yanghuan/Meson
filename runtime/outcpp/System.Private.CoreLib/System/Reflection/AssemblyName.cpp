#include "AssemblyName-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/FormatException-dep.h>
#include <System.Private.CoreLib/System/HexConverter-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IO/Path-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/AssemblyName-dep.h>
#include <System.Private.CoreLib/System/Reflection/AssemblyNameFlags.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/Encoding-dep.h>

namespace System::Private::CoreLib::System::Reflection::AssemblyNameNamespace {
using namespace System::IO;
using namespace System::Text;

String AssemblyName___::get_Name() {
  return _name;
}

void AssemblyName___::set_Name(String value) {
  _name = value;
}

Version AssemblyName___::get_Version() {
  return _version;
}

void AssemblyName___::set_Version(Version value) {
  _version = value;
}

CultureInfo AssemblyName___::get_CultureInfo() {
  return _cultureInfo;
}

void AssemblyName___::set_CultureInfo(CultureInfo value) {
  _cultureInfo = value;
}

String AssemblyName___::get_CultureName() {
}

void AssemblyName___::set_CultureName(String value) {
  _cultureInfo = ((value == nullptr) ? nullptr : rt::newobj<CultureInfo>(value));
}

String AssemblyName___::get_CodeBase() {
  return _codeBase;
}

void AssemblyName___::set_CodeBase(String value) {
  _codeBase = value;
}

String AssemblyName___::get_EscapedCodeBase() {
  if (_codeBase == nullptr) {
    return nullptr;
  }
  return EscapeCodeBase(_codeBase);
}

ProcessorArchitecture AssemblyName___::get_ProcessorArchitecture() {
  Int32 num = (Int32)(_flags & (AssemblyNameFlags)112) >> 4;
  if (num > 5) {
    num = 0;
  }
  return (ProcessorArchitecture)num;
}

void AssemblyName___::set_ProcessorArchitecture(ProcessorArchitecture value) {
  Int32 num = (Int32)(value & (ProcessorArchitecture)7);
  if (num <= 5) {
    _flags = (AssemblyNameFlags)((Int64)_flags & 4294967055);
    _flags |= (AssemblyNameFlags)(num << 4);
  }
}

AssemblyContentType AssemblyName___::get_ContentType() {
  Int32 num = (Int32)(_flags & (AssemblyNameFlags)3584) >> 9;
  if (num > 1) {
    num = 0;
  }
  return (AssemblyContentType)num;
}

void AssemblyName___::set_ContentType(AssemblyContentType value) {
  Int32 num = (Int32)(value & (AssemblyContentType)7);
  if (num <= 1) {
    _flags = (AssemblyNameFlags)((Int64)_flags & 4294963711);
    _flags |= (AssemblyNameFlags)(num << 9);
  }
}

AssemblyNameFlags AssemblyName___::get_Flags() {
  return _flags & (AssemblyNameFlags)(-3825);
}

void AssemblyName___::set_Flags(AssemblyNameFlags value) {
  _flags &= (AssemblyNameFlags)3824;
  _flags |= (value & (AssemblyNameFlags)(-3825));
}

AssemblyHashAlgorithm AssemblyName___::get_HashAlgorithm() {
  return _hashAlgorithm;
}

void AssemblyName___::set_HashAlgorithm(AssemblyHashAlgorithm value) {
  _hashAlgorithm = value;
}

AssemblyVersionCompatibility AssemblyName___::get_VersionCompatibility() {
  return _versionCompatibility;
}

void AssemblyName___::set_VersionCompatibility(AssemblyVersionCompatibility value) {
  _versionCompatibility = value;
}

StrongNameKeyPair AssemblyName___::get_KeyPair() {
  return _strongNameKeyPair;
}

void AssemblyName___::set_KeyPair(StrongNameKeyPair value) {
  _strongNameKeyPair = value;
}

String AssemblyName___::get_FullName() {
  if (get_Name() == nullptr) {
    return String::in::Empty;
  }
}

void AssemblyName___::ctor(String assemblyName) {
  if (assemblyName == nullptr) {
    rt::throw_exception<ArgumentNullException>("assemblyName");
  }
  if (assemblyName->get_Length() == 0 || assemblyName[0] == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Format_StringZeroLength());
  }
  _name = assemblyName;
  nInit();
}

void AssemblyName___::ctor(String name, Array<Byte> publicKey, Array<Byte> publicKeyToken, Version version, CultureInfo cultureInfo, AssemblyHashAlgorithm hashAlgorithm, AssemblyVersionCompatibility versionCompatibility, String codeBase, AssemblyNameFlags flags, StrongNameKeyPair keyPair) {
  _name = name;
  _publicKey = publicKey;
  _publicKeyToken = publicKeyToken;
  _version = version;
  _cultureInfo = cultureInfo;
  _hashAlgorithm = hashAlgorithm;
  _versionCompatibility = versionCompatibility;
  _codeBase = codeBase;
  _flags = flags;
  _strongNameKeyPair = keyPair;
}

AssemblyName AssemblyName___::GetFileInformationCore(String assemblyFile) {
  String fullPath = Path::GetFullPath(assemblyFile);
  return nGetFileInformation(fullPath);
}

void AssemblyName___::SetProcArchIndex(PortableExecutableKinds pek, ImageFileMachine ifm) {
  get_ProcessorArchitecture() = CalculateProcArchIndex(pek, ifm, _flags);
}

ProcessorArchitecture AssemblyName___::CalculateProcArchIndex(PortableExecutableKinds pek, ImageFileMachine ifm, AssemblyNameFlags flags) {
  if ((flags & (AssemblyNameFlags)240) == (AssemblyNameFlags)112) {
    return ProcessorArchitecture::None;
  }
  if ((pek & PortableExecutableKinds::PE32Plus) == PortableExecutableKinds::PE32Plus) {
    switch (ifm) {
      case ImageFileMachine::IA64:
        return ProcessorArchitecture::IA64;
      case ImageFileMachine::AMD64:
        return ProcessorArchitecture::Amd64;
      case ImageFileMachine::I386:
        if ((pek & PortableExecutableKinds::ILOnly) == PortableExecutableKinds::ILOnly) {
          return ProcessorArchitecture::MSIL;
        }
        break;
    }
  } else {
    switch (ifm) {
      case ImageFileMachine::I386:
        if ((pek & PortableExecutableKinds::Required32Bit) == PortableExecutableKinds::Required32Bit) {
          return ProcessorArchitecture::X86;
        }
        if ((pek & PortableExecutableKinds::ILOnly) == PortableExecutableKinds::ILOnly) {
          return ProcessorArchitecture::MSIL;
        }
        return ProcessorArchitecture::X86;
      case ImageFileMachine::ARM:
        return ProcessorArchitecture::Arm;
    }
  }
  return ProcessorArchitecture::None;
}

void AssemblyName___::ctor() {
  _versionCompatibility = AssemblyVersionCompatibility::SameMachine;
}

Object AssemblyName___::Clone() {
  return rt::newobj<AssemblyName>();
}

AssemblyName AssemblyName___::GetAssemblyName(String assemblyFile) {
  if (assemblyFile == nullptr) {
    rt::throw_exception<ArgumentNullException>("assemblyFile");
  }
  return GetFileInformationCore(assemblyFile);
}

Array<Byte> AssemblyName___::GetPublicKey() {
  return _publicKey;
}

void AssemblyName___::SetPublicKey(Array<Byte> publicKey) {
  _publicKey = publicKey;
  if (publicKey == nullptr) {
    _flags &= ~AssemblyNameFlags::PublicKey;
  } else {
    _flags |= AssemblyNameFlags::PublicKey;
  }
}

Array<Byte> AssemblyName___::GetPublicKeyToken() {
}

void AssemblyName___::SetPublicKeyToken(Array<Byte> publicKeyToken) {
  _publicKeyToken = publicKeyToken;
}

String AssemblyName___::ToString() {
  String fullName = get_FullName();
  if (fullName == nullptr) {
  }
  return fullName;
}

void AssemblyName___::GetObjectData(SerializationInfo info, StreamingContext context) {
  rt::throw_exception<PlatformNotSupportedException>();
}

void AssemblyName___::OnDeserialization(Object sender) {
  rt::throw_exception<PlatformNotSupportedException>();
}

Boolean AssemblyName___::ReferenceMatchesDefinition(AssemblyName reference, AssemblyName definition) {
  if (reference == definition) {
    return true;
  }
  if (reference == nullptr) {
    rt::throw_exception<ArgumentNullException>("reference");
  }
  if (definition == nullptr) {
    rt::throw_exception<ArgumentNullException>("definition");
  }
}

String AssemblyName___::EscapeCodeBase(String codebase) {
  if (codebase == nullptr) {
    return String::in::Empty;
  }
  Int32 destPos = 0;
  Array<Char> array = EscapeString(codebase, 0, codebase->get_Length(), nullptr, destPos, true, 65535, 65535, 65535);
  if (array == nullptr) {
    return codebase;
  }
  return rt::newobj<String>(array, 0, destPos);
}

Array<Char> AssemblyName___::EscapeString(String input, Int32 start, Int32 end, Array<Char> dest, Int32& destPos, Boolean isUriString, Char force1, Char force2, Char rsvd) {
  Int32 i = start;
  Int32 num = start;
  Byte default[160] = {};
  Byte* ptr = default;
  {
    Char* ptr2 = input;
    Char* ptr3 = ptr2;
    for (; i < end; i++) {
      Char c = ptr3[i];
      if (c > 127) {
        Int16 num2 = (Int16)Math::Min(end - i, 39);
        Int16 num3 = 1;
        while (num3 < num2 && ptr3[i + num3] > 127) {
          num3 = (Int16)(num3 + 1);
        }
        if (ptr3[i + num3 - 1] >= 55296 && ptr3[i + num3 - 1] <= 56319) {
          if (num3 == 1 || num3 == end - i) {
            rt::throw_exception<FormatException>(SR::get_Arg_FormatException());
          }
          num3 = (Int16)(num3 + 1);
        }
        dest = EnsureDestinationSize(ptr3, dest, i, (Int16)(num3 * 4 * 3), 480, destPos, num);
        Int16 num4 = (Int16)Encoding::in::get_UTF8()->GetBytes(ptr3 + i, num3, ptr, 160);
        if (num4 == 0) {
          rt::throw_exception<FormatException>(SR::get_Arg_FormatException());
        }
        i += num3 - 1;
        for (num3 = 0; num3 < num4; num3 = (Int16)(num3 + 1)) {
          EscapeAsciiChar((Char)ptr[num3], dest, destPos);
        }
        num = i + 1;
      } else if (c == 37 && rsvd == 37) {
        dest = EnsureDestinationSize(ptr3, dest, i, 3, 120, destPos, num);
        if (i + 2 < end && EscapedAscii(ptr3[i + 1], ptr3[i + 2]) != 65535) {
          dest[destPos++] = 37;
          dest[destPos++] = ptr3[i + 1];
          dest[destPos++] = ptr3[i + 2];
          i += 2;
        } else {
          EscapeAsciiChar(37, dest, destPos);
        }
        num = i + 1;
      } else if (c == force1 || c == force2 || (c != rsvd && (isUriString ? (!IsReservedUnreservedOrHash(c)) : (!IsUnreserved(c))))) {
        dest = EnsureDestinationSize(ptr3, dest, i, 3, 120, destPos, num);
        EscapeAsciiChar(c, dest, destPos);
        num = i + 1;
      }


    }
    if (num != i && (num != start || dest != nullptr)) {
      dest = EnsureDestinationSize(ptr3, dest, i, 0, 0, destPos, num);
    }
  }
  return dest;
}

Array<Char> AssemblyName___::EnsureDestinationSize(Char* pStr, Array<Char> dest, Int32 currentInputPos, Int16 charsToAdd, Int16 minReallocateChars, Int32& destPos, Int32 prevInputPos) {
  if (dest == nullptr || dest->get_Length() < destPos + (currentInputPos - prevInputPos) + charsToAdd) {
    Array<Char> array = rt::newarr<Array<Char>>(destPos + (currentInputPos - prevInputPos) + minReallocateChars);
    if (dest != nullptr && destPos != 0) {
      Buffer::BlockCopy(dest, 0, array, 0, destPos << 1);
    }
    dest = array;
  }
  while (prevInputPos != currentInputPos) {
    dest[destPos++] = pStr[prevInputPos++];
  }
  return dest;
}

void AssemblyName___::EscapeAsciiChar(Char ch, Array<Char> to, Int32& pos) {
  to[pos++] = 37;
  to[pos++] = HexConverter::ToCharUpper((Int32)ch >> 4);
  to[pos++] = HexConverter::ToCharUpper(ch);
}

Char AssemblyName___::EscapedAscii(Char digit, Char next) {
  if ((digit < 48 || digit > 57) && (digit < 65 || digit > 70) && (digit < 97 || digit > 102)) {
    return 65535;
  }
  Int32 num = (digit <= 57) ? (digit - 48) : (((digit <= 70) ? (digit - 65) : (digit - 97)) + 10);
  if ((next < 48 || next > 57) && (next < 65 || next > 70) && (next < 97 || next > 102)) {
    return 65535;
  }
  return (Char)((num << 4) + ((next <= 57) ? (next - 48) : (((next <= 70) ? (next - 65) : (next - 97)) + 10)));
}

Boolean AssemblyName___::IsReservedUnreservedOrHash(Char c) {
  if (IsUnreserved(c)) {
    return true;
  }
  return ":/?#[]@!$&'()*+,;="->Contains(c);
}

Boolean AssemblyName___::IsUnreserved(Char c) {
  if (IsAsciiLetterOrDigit(c)) {
    return true;
  }
  return "-._~"->Contains(c);
}

Boolean AssemblyName___::IsAsciiLetter(Char character) {
  if (character < 97 || character > 122) {
    if (character >= 65) {
      return character <= 90;
    }
    return false;
  }
  return true;
}

Boolean AssemblyName___::IsAsciiLetterOrDigit(Char character) {
  if (!IsAsciiLetter(character)) {
    if (character >= 48) {
      return character <= 57;
    }
    return false;
  }
  return true;
}

} // namespace System::Private::CoreLib::System::Reflection::AssemblyNameNamespace
