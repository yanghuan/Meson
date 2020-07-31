#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Text {
FORWARDS(ValueStringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARD(String)
FORWARD(Version)
namespace ApplicationIdNamespace {
using namespace Text;
CLASS(ApplicationId) : public Object::in {
  public: String get_Culture() { return Culture; }
  public: String get_Name() { return Name; }
  public: String get_ProcessorArchitecture() { return ProcessorArchitecture; }
  public: Version get_Version() { return Version; }
  public: Array<Byte> get_PublicKeyToken();
  public: void Ctor(Array<Byte> publicKeyToken, String name, Version version, String processorArchitecture, String culture);
  public: ApplicationId Copy();
  public: String ToString();
  private: static void EncodeHexString(Array<Byte> sArray, ValueStringBuilder& stringBuilder);
  public: Boolean Equals(Object o);
  public: Int32 GetHashCode();
  private: Array<Byte> _publicKeyToken;
  private: String Culture;
  private: String Name;
  private: String ProcessorArchitecture;
  private: Version Version;
};
} // namespace ApplicationIdNamespace
using ApplicationId = ApplicationIdNamespace::ApplicationId;
} // namespace System::Private::CoreLib::System
