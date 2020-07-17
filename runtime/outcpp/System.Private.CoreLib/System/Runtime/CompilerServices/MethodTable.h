#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/UInt16.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace MethodTableNamespace {
struct MethodTable {
  public: Boolean get_HasComponentSize();
  public: Boolean get_ContainsGCPointers();
  public: Boolean get_NonTrivialInterfaceCast();
  public: Boolean get_HasTypeEquivalence();
  public: Boolean get_IsMultiDimensionalArray();
  public: Int32 get_MultiDimensionalArrayRank();
  public: void Ctor();
  public: UInt16 ComponentSize;
  private: UInt32 Flags;
  public: UInt32 BaseSize;
  public: UInt16 InterfaceCount;
  public: MethodTable* ParentMethodTable;
  public: void* ElementType;
  public: MethodTable** InterfaceMap;
};
} // namespace MethodTableNamespace
using MethodTable = MethodTableNamespace::MethodTable;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
