#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(StringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::StubHelpers {
FORWARD(CleanupWorkListElement)
namespace AsAnyMarshalerNamespace {
using namespace ::System::Private::CoreLib::System::Text;
struct AsAnyMarshaler {
  private: enum class BackPropAction {
    None = 0,
    Array = 1,
    Layout = 2,
    StringBuilderAnsi = 3,
    StringBuilderUnicode = 4,
  };
  private: static Boolean IsIn(Int32 dwFlags);
  private: static Boolean IsOut(Int32 dwFlags);
  private: static Boolean IsAnsi(Int32 dwFlags);
  private: static Boolean IsThrowOn(Int32 dwFlags);
  private: static Boolean IsBestFit(Int32 dwFlags);
  private: IntPtr ConvertArrayToNative(Object pManagedHome, Int32 dwFlags);
  private: static IntPtr ConvertStringToNative(String pManagedHome, Int32 dwFlags);
  private: IntPtr ConvertStringBuilderToNative(StringBuilder pManagedHome, Int32 dwFlags);
  private: IntPtr ConvertLayoutToNative(Object pManagedHome, Int32 dwFlags);
  public: IntPtr ConvertToNative(Object pManagedHome, Int32 dwFlags);
  public: void ConvertToManaged(Object pManagedHome, IntPtr pNativeHome);
  public: void ClearNative(IntPtr pNativeHome);
  private: IntPtr pvArrayMarshaler;
  private: BackPropAction backPropAction;
  private: Type layoutType;
  private: CleanupWorkListElement cleanupWorkList;
};
} // namespace AsAnyMarshalerNamespace
using AsAnyMarshaler = AsAnyMarshalerNamespace::AsAnyMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
