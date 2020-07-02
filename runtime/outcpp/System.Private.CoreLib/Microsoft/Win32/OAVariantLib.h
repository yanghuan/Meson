#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Variant)
FORWARD(Type)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::Microsoft::Win32 {
namespace OAVariantLibNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Globalization;
class OAVariantLib {
  public: static Variant ChangeType(Variant source, Type targetClass, Int16 options, CultureInfo culture);
  private: static Int32 GetCVTypeFromClass(Type ctype);
  private: static void ChangeTypeEx(Variant& result, Variant& source, Int32 lcid, IntPtr typeHandle, Int32 cvType, Int16 flags);
  public: static Array<Type> ClassTypes;
};
} // namespace OAVariantLibNamespace
using OAVariantLib = OAVariantLibNamespace::OAVariantLib;
} // namespace System::Private::CoreLib::Microsoft::Win32
