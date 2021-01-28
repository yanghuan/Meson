#include "CastHelpers-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArrayTypeMismatchException-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/CastHelpers-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/MethodTable-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::CastHelpersNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Threading;

Int32 CastHelpers::KeyToBucket(Int32& tableData, UIntPtr source, UIntPtr target) {
  Int32 num = HashShift(tableData);
  UInt64 num2 = (((UInt64)source << 32) | ((UInt64)source >> 32)) ^ target;
  return (Int32)((UInt64)((Int64)num2 * -7046029254386353131) >> num);
}

Int32& CastHelpers::TableData(Array<Int32> table) {
  return MemoryMarshal::GetArrayDataReference(table);
}

CastHelpers::CastCacheEntry& CastHelpers::Element(Int32& tableData, Int32 index) {
  return Unsafe::Add(Unsafe::As<Int32, CastCacheEntry>(tableData), index + 1);
}

Int32 CastHelpers::HashShift(Int32& tableData) {
  return tableData;
}

Int32 CastHelpers::TableMask(Int32& tableData) {
  return Unsafe::Add(tableData, 1);
}

CastHelpers::CastResult CastHelpers::TryGet(UIntPtr source, UIntPtr target) {
  Int32& tableData = TableData(s_table);
  Int32 num = KeyToBucket(tableData, source, target);
  Int32 num2 = 0;
  while (num2 < 8) {
    CastCacheEntry& reference = Element(tableData, num);
    Int32 num3 = Volatile::Read(reference._version);
    UIntPtr source2 = reference._source;
    num3 &= -2;
    if (source2 == (UIntPtr)source) {
      UIntPtr targetAndResult = reference._targetAndResult;
      targetAndResult = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)targetAndResult ^ (UInt64)target);
      if ((UInt64)targetAndResult <= 1) {
        Interlocked::ReadMemoryBarrier();
        if (num3 != reference._version) {
          break;
        }
        return (CastResult)(UInt32)targetAndResult;
      }
    }
    if (num3 == 0) {
      break;
    }
    num2++;
    num = (num + num2) & TableMask(tableData);
  }
  return CastResult::MaybeCast;
}

Object CastHelpers::IsInstanceOfAny(void* toTypeHnd, Object obj) {
  if (obj != nullptr) {
    void* methodTable = RuntimeHelpers::GetMethodTable(obj);
    if (methodTable != toTypeHnd) {
      CastResult castResult = TryGet((UIntPtr)methodTable, (UIntPtr)toTypeHnd);
      if (castResult != CastResult::CanCast) {
        if (castResult != 0) {
          return IsInstanceOfAny_NoCacheLookup(toTypeHnd, obj);
        }
        obj = nullptr;
      }
    }
  }
  return obj;
}

Object CastHelpers::IsInstanceOfInterface(void* toTypeHnd, Object obj) {
  MethodTable* methodTable;
  if (obj != nullptr) {
    methodTable = RuntimeHelpers::GetMethodTable(obj);
    UIntPtr uIntPtr = (UIntPtr)(void*)methodTable->InterfaceCount;
    if (uIntPtr == (UIntPtr)(void*)(void*)nullptr) {
      goto IL_0095;
    }
    MethodTable* interfaceMap = methodTable->InterfaceMap;
    UIntPtr uIntPtr2 = (UIntPtr)(void*)(void*)nullptr;
    while (*(interfaceMap + (UInt64)(UIntPtr)(void*)((Int64)(UInt64)uIntPtr2 + 0)) != toTypeHnd) {
      if ((uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - 1)) != (UIntPtr)(void*)(void*)nullptr) {
        if (*(interfaceMap + (UInt64)(UIntPtr)(void*)((Int64)(UInt64)uIntPtr2 + 1)) == toTypeHnd) {
          break;
        }
        if ((uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - 1)) != (UIntPtr)(void*)(void*)nullptr) {
          if (*(interfaceMap + (UInt64)(UIntPtr)(void*)((Int64)(UInt64)uIntPtr2 + 2)) == toTypeHnd) {
            break;
          }
          if ((uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - 1)) != (UIntPtr)(void*)(void*)nullptr) {
            if (*(interfaceMap + (UInt64)(UIntPtr)(void*)((Int64)(UInt64)uIntPtr2 + 3)) == toTypeHnd) {
              break;
            }
            if ((uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - 1)) != (UIntPtr)(void*)(void*)nullptr) {
              uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + 4);
              continue;
            }
          }
        }
      }
      goto IL_0095;
    }
  }
  goto IL_00a0;

IL_0095:
  if (!methodTable->get_NonTrivialInterfaceCast()) {
    obj = nullptr;
    goto IL_00a0;
  }
  return IsInstance_Helper(toTypeHnd, obj);

IL_00a0:
  return obj;
}

Object CastHelpers::IsInstanceOfClass(void* toTypeHnd, Object obj) {
  if (obj == nullptr || RuntimeHelpers::GetMethodTable(obj) == toTypeHnd) {
    return obj;
  }
  MethodTable* parentMethodTable = RuntimeHelpers::GetMethodTable(obj)->ParentMethodTable;
  while (true) {
    if (parentMethodTable != toTypeHnd) {
      if (parentMethodTable != nullptr) {
        parentMethodTable = parentMethodTable->ParentMethodTable;
        if (parentMethodTable == toTypeHnd) {
          goto IL_006c;
        }
        if (parentMethodTable != nullptr) {
          parentMethodTable = parentMethodTable->ParentMethodTable;
          if (parentMethodTable == toTypeHnd) {
            goto IL_006c;
          }
          if (parentMethodTable != nullptr) {
            parentMethodTable = parentMethodTable->ParentMethodTable;
            if (parentMethodTable == toTypeHnd) {
              goto IL_006c;
            }
            if (parentMethodTable != nullptr) {
              parentMethodTable = parentMethodTable->ParentMethodTable;
              continue;
            }
          }
        }
      }
      if (RuntimeHelpers::GetMethodTable(obj)->get_HasTypeEquivalence()) {
        break;
      }
      obj = nullptr;
    }
    goto IL_006c;

  IL_006c:
    return obj;
  }
  return IsInstance_Helper(toTypeHnd, obj);
}

Object CastHelpers::IsInstance_Helper(void* toTypeHnd, Object obj) {
}

Object CastHelpers::ChkCastAny(void* toTypeHnd, Object obj) {
  if (obj != nullptr) {
    void* methodTable = RuntimeHelpers::GetMethodTable(obj);
    if (methodTable != toTypeHnd) {
      CastResult castResult = TryGet((UIntPtr)methodTable, (UIntPtr)toTypeHnd);
      if (castResult != CastResult::CanCast) {
        return ChkCastAny_NoCacheLookup(toTypeHnd, obj);
      }
    }
  }
  return obj;
}

Object CastHelpers::ChkCast_Helper(void* toTypeHnd, Object obj) {
  CastResult castResult = TryGet((UIntPtr)RuntimeHelpers::GetMethodTable(obj), (UIntPtr)toTypeHnd);
  if (castResult == CastResult::CanCast) {
    return obj;
  }
  return ChkCastAny_NoCacheLookup(toTypeHnd, obj);
}

Object CastHelpers::ChkCastInterface(void* toTypeHnd, Object obj) {
  if (obj != nullptr) {
    MethodTable* methodTable = RuntimeHelpers::GetMethodTable(obj);
    UIntPtr uIntPtr = (UIntPtr)(void*)methodTable->InterfaceCount;
    if (uIntPtr == (UIntPtr)(void*)(void*)nullptr) {
      goto IL_0097;
    }
    MethodTable* interfaceMap = methodTable->InterfaceMap;
    UIntPtr uIntPtr2 = (UIntPtr)(void*)(void*)nullptr;
    while (*(interfaceMap + (UInt64)(UIntPtr)(void*)((Int64)(UInt64)uIntPtr2 + 0)) != toTypeHnd) {
      if ((uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - 1)) != (UIntPtr)(void*)(void*)nullptr) {
        if (*(interfaceMap + (UInt64)(UIntPtr)(void*)((Int64)(UInt64)uIntPtr2 + 1)) == toTypeHnd) {
          break;
        }
        if ((uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - 1)) != (UIntPtr)(void*)(void*)nullptr) {
          if (*(interfaceMap + (UInt64)(UIntPtr)(void*)((Int64)(UInt64)uIntPtr2 + 2)) == toTypeHnd) {
            break;
          }
          if ((uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - 1)) != (UIntPtr)(void*)(void*)nullptr) {
            if (*(interfaceMap + (UInt64)(UIntPtr)(void*)((Int64)(UInt64)uIntPtr2 + 3)) == toTypeHnd) {
              break;
            }
            if ((uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - 1)) != (UIntPtr)(void*)(void*)nullptr) {
              uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + 4);
              continue;
            }
          }
        }
      }
      goto IL_0097;
    }
  }
  return obj;

IL_0097:
  return ChkCast_Helper(toTypeHnd, obj);
}

Object CastHelpers::ChkCastClass(void* toTypeHnd, Object obj) {
  if (obj == nullptr || RuntimeHelpers::GetMethodTable(obj) == toTypeHnd) {
    return obj;
  }
  return ChkCastClassSpecial(toTypeHnd, obj);
}

Object CastHelpers::ChkCastClassSpecial(void* toTypeHnd, Object obj) {
  MethodTable* ptr = RuntimeHelpers::GetMethodTable(obj);
  while (true) {
    ptr = ptr->ParentMethodTable;
    if (ptr != toTypeHnd) {
      if (ptr == nullptr) {
        break;
      }
      ptr = ptr->ParentMethodTable;
      if (ptr != toTypeHnd) {
        if (ptr == nullptr) {
          break;
        }
        ptr = ptr->ParentMethodTable;
        if (ptr != toTypeHnd) {
          if (ptr == nullptr) {
            break;
          }
          ptr = ptr->ParentMethodTable;
          if (ptr != toTypeHnd) {
            if (ptr == nullptr) {
              break;
            }
            continue;
          }
        }
      }
    }
    return obj;
  }
  return ChkCast_Helper(toTypeHnd, obj);
}

Byte& CastHelpers::Unbox(void* toTypeHnd, Object obj) {
  if (RuntimeHelpers::GetMethodTable(obj) == toTypeHnd) {
    return RuntimeHelpers::GetRawData(obj);
  }
  return Unbox_Helper(toTypeHnd, obj);
}

Object& CastHelpers::ThrowArrayMismatchException() {
  rt::throw_exception<ArrayTypeMismatchException>();
}

Object& CastHelpers::LdelemaRef(Array<> array, Int32 index, void* type) {
  Object& value = Unsafe::As<Array<ArrayElement>>(array)[index].Value;
  void* elementType = RuntimeHelpers::GetMethodTable(array)->ElementType;
  if (elementType == type) {
    return value;
  }
  return ThrowArrayMismatchException();
}

void CastHelpers::StelemRef(Array<> array, Int32 index, Object obj) {
  Object& value = Unsafe::As<Array<ArrayElement>>(array)[index].Value;
  void* elementType = RuntimeHelpers::GetMethodTable(array)->ElementType;
  if (obj != nullptr) {
    if (elementType == RuntimeHelpers::GetMethodTable(obj) || array->GetType() == typeof<Array<Object>>()) {
      WriteBarrier(value, obj);
    } else {
      StelemRef_Helper(value, elementType, obj);
    }
  } else {
    value = nullptr;
  }
}

void CastHelpers::StelemRef_Helper(Object& element, void* elementType, Object obj) {
  CastResult castResult = TryGet((UIntPtr)RuntimeHelpers::GetMethodTable(obj), (UIntPtr)elementType);
  if (castResult == CastResult::CanCast) {
    WriteBarrier(element, obj);
  } else {
    StelemRef_Helper_NoCacheLookup(element, elementType, obj);
  }
}

void CastHelpers::StelemRef_Helper_NoCacheLookup(Object& element, void* elementType, Object obj) {
  obj = IsInstanceOfAny_NoCacheLookup(elementType, obj);
  if (obj != nullptr) {
    WriteBarrier(element, obj);
    return;
  }
  rt::throw_exception<ArrayTypeMismatchException>();
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::CastHelpersNamespace
