#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/Int16.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/SByte.h>
#include <System.Private.CoreLib/System/Single.h>
#include <System.Private.CoreLib/System/UInt16.h>
#include <System.Private.CoreLib/System/UInt32.h>
#include <System.Private.CoreLib/System/UIntPtr.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Double)
FORWARDS(Int64)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace VolatileNamespace {
class Volatile {
  private: struct VolatileBoolean {
    public: Boolean Value;
  };
  private: struct VolatileByte {
    public: Byte Value;
  };
  private: struct VolatileInt16 {
    public: Int16 Value;
  };
  private: struct VolatileInt32 {
    public: Int32 Value;
  };
  private: struct VolatileIntPtr {
    public: IntPtr Value;
  };
  private: struct VolatileSByte {
    public: SByte Value;
  };
  private: struct VolatileSingle {
    public: Single Value;
  };
  private: struct VolatileUInt16 {
    public: UInt16 Value;
  };
  private: struct VolatileUInt32 {
    public: UInt32 Value;
  };
  private: struct VolatileUIntPtr {
    public: UIntPtr Value;
  };
  private: struct VolatileObject {
    public: Object Value;
  };
  public: static Boolean Read(Boolean& location);
  public: static void Write(Boolean& location, Boolean value);
  public: static Byte Read(Byte& location);
  public: static void Write(Byte& location, Byte value);
  public: static Double Read(Double& location);
  public: static void Write(Double& location, Double value);
  public: static Int16 Read(Int16& location);
  public: static void Write(Int16& location, Int16 value);
  public: static Int32 Read(Int32& location);
  public: static void Write(Int32& location, Int32 value);
  public: static Int64 Read(Int64& location);
  public: static void Write(Int64& location, Int64 value);
  public: static IntPtr Read(IntPtr& location);
  public: static void Write(IntPtr& location, IntPtr value);
  public: static SByte Read(SByte& location);
  public: static void Write(SByte& location, SByte value);
  public: static Single Read(Single& location);
  public: static void Write(Single& location, Single value);
  public: static UInt16 Read(UInt16& location);
  public: static void Write(UInt16& location, UInt16 value);
  public: static UInt32 Read(UInt32& location);
  public: static void Write(UInt32& location, UInt32 value);
  public: static UInt64 Read(UInt64& location);
  public: static void Write(UInt64& location, UInt64 value);
  public: static UIntPtr Read(UIntPtr& location);
  public: static void Write(UIntPtr& location, UIntPtr value);
};
} // namespace VolatileNamespace
using Volatile = VolatileNamespace::Volatile;
} // namespace System::Private::CoreLib::System::Threading
