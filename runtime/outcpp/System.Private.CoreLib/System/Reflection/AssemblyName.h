#pragma once

#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARD(ICloneable)
FORWARDS(Int32)
FORWARD(String)
FORWARD(Version)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(IDeserializationCallback)
FORWARD(ISerializable)
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Configuration::Assemblies {
enum class AssemblyHashAlgorithm : int32_t;
enum class AssemblyVersionCompatibility : int32_t;
} // namespace System::Private::CoreLib::System::Configuration::Assemblies
namespace System::Private::CoreLib::System::Reflection {
enum class AssemblyContentType : int32_t;
enum class AssemblyNameFlags : int32_t;
enum class ImageFileMachine : int32_t;
enum class PortableExecutableKinds : int32_t;
enum class ProcessorArchitecture : int32_t;
FORWARD(StrongNameKeyPair)
namespace AssemblyNameNamespace {
using namespace System::Configuration::Assemblies;
using namespace System::Globalization;
using namespace System::Runtime::Serialization;
CLASS(AssemblyName) : public object {
  public: using interface = rt::TypeList<ICloneable, IDeserializationCallback, ISerializable>;
  public: String get_Name();
  public: void set_Name(String value);
  public: Version get_Version();
  public: void set_Version(Version value);
  public: CultureInfo get_CultureInfo();
  public: void set_CultureInfo(CultureInfo value);
  public: String get_CultureName();
  public: void set_CultureName(String value);
  public: String get_CodeBase();
  public: void set_CodeBase(String value);
  public: String get_EscapedCodeBase();
  public: ProcessorArchitecture get_ProcessorArchitecture();
  public: void set_ProcessorArchitecture(ProcessorArchitecture value);
  public: AssemblyContentType get_ContentType();
  public: void set_ContentType(AssemblyContentType value);
  public: AssemblyNameFlags get_Flags();
  public: void set_Flags(AssemblyNameFlags value);
  public: AssemblyHashAlgorithm get_HashAlgorithm();
  public: void set_HashAlgorithm(AssemblyHashAlgorithm value);
  public: AssemblyVersionCompatibility get_VersionCompatibility();
  public: void set_VersionCompatibility(AssemblyVersionCompatibility value);
  public: StrongNameKeyPair get_KeyPair();
  public: void set_KeyPair(StrongNameKeyPair value);
  public: String get_FullName();
  public: void ctor(String assemblyName);
  public: void ctor(String name, Array<Byte> publicKey, Array<Byte> publicKeyToken, Version version, CultureInfo cultureInfo, AssemblyHashAlgorithm hashAlgorithm, AssemblyVersionCompatibility versionCompatibility, String codeBase, AssemblyNameFlags flags, StrongNameKeyPair keyPair);
  public: void nInit();
  public: static AssemblyName nGetFileInformation(String s);
  public: static AssemblyName GetFileInformationCore(String assemblyFile);
  private: Array<Byte> ComputePublicKeyToken();
  public: void SetProcArchIndex(PortableExecutableKinds pek, ImageFileMachine ifm);
  public: static ProcessorArchitecture CalculateProcArchIndex(PortableExecutableKinds pek, ImageFileMachine ifm, AssemblyNameFlags flags);
  public: void ctor();
  public: Object Clone();
  public: static AssemblyName GetAssemblyName(String assemblyFile);
  public: Array<Byte> GetPublicKey();
  public: void SetPublicKey(Array<Byte> publicKey);
  public: Array<Byte> GetPublicKeyToken();
  public: void SetPublicKeyToken(Array<Byte> publicKeyToken);
  public: String ToString();
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: void OnDeserialization(Object sender);
  public: static Boolean ReferenceMatchesDefinition(AssemblyName reference, AssemblyName definition);
  public: static String EscapeCodeBase(String codebase);
  public: static Array<Char> EscapeString(String input, Int32 start, Int32 end, Array<Char> dest, Int32& destPos, Boolean isUriString, Char force1, Char force2, Char rsvd);
  private: static Array<Char> EnsureDestinationSize(Char* pStr, Array<Char> dest, Int32 currentInputPos, Int16 charsToAdd, Int16 minReallocateChars, Int32& destPos, Int32 prevInputPos);
  public: static void EscapeAsciiChar(Char ch, Array<Char> to, Int32& pos);
  public: static Char EscapedAscii(Char digit, Char next);
  private: static Boolean IsReservedUnreservedOrHash(Char c);
  public: static Boolean IsUnreserved(Char c);
  public: static Boolean IsAsciiLetter(Char character);
  public: static Boolean IsAsciiLetterOrDigit(Char character);
  private: String _name;
  private: Array<Byte> _publicKey;
  private: Array<Byte> _publicKeyToken;
  private: CultureInfo _cultureInfo;
  private: String _codeBase;
  private: Version _version;
  private: StrongNameKeyPair _strongNameKeyPair;
  private: AssemblyHashAlgorithm _hashAlgorithm;
  private: AssemblyVersionCompatibility _versionCompatibility;
  private: AssemblyNameFlags _flags;
  public: static constexpr Char c_DummyChar = 'ÿ';
  private: static constexpr Int16 c_MaxAsciiCharsReallocate = 40;
  private: static constexpr Int16 c_MaxUnicodeCharsReallocate = 40;
  private: static constexpr Int16 c_MaxUTF_8BytesPerUnicodeChar = 4;
  private: static constexpr Int16 c_EncodedCharsPerByte = 3;
};
} // namespace AssemblyNameNamespace
using AssemblyName = AssemblyNameNamespace::AssemblyName;
} // namespace System::Private::CoreLib::System::Reflection
