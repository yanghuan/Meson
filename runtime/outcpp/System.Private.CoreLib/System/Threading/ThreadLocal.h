#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IList, T)
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Threading {
namespace ThreadLocalNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using ::System::Private::CoreLib::System::Collections::Generic::IList;
CLASS(ThreadLocal, T) {
  private: FORWARDN(LinkedSlot)
  private: struct LinkedSlotVolatile {
    public: LinkedSlot Value;
  };
  private: CLASS(LinkedSlot) {
    public: LinkedSlot _next;
    public: LinkedSlot _previous;
    public: Array<LinkedSlotVolatile> _slotArray;
    public: T _value;
  };
  private: CLASS(IdManager) {
    public: Int32 GetId();
    public: void ReturnId(Int32 id);
    private: Int32 _nextIdToTry;
    private: List<Boolean> _freeIds;
  };
  private: CLASS(FinalizationHelper) {
    protected: void Finalize();
    public: Array<LinkedSlotVolatile> SlotArray;
    private: Boolean _trackAllValues;
  };
  public: T get_Value();
  public: void set_Value(T value);
  public: IList<T> get_Values();
  private: Int32 get_ValuesCountForDebugDisplay();
  public: Boolean get_IsValueCreated();
  public: T get_ValueForDebugDisplay();
  public: List<T> get_ValuesForDebugDisplay();
  private: void Initialize(Func<T> valueFactory, Boolean trackAllValues);
  protected: void Finalize();
  public: void Dispose();
  protected: void Dispose(Boolean disposing);
  public: String ToString();
  private: T GetValueSlow();
  private: void SetValueSlow(T value, Array<LinkedSlotVolatile> slotArray);
  private: void CreateLinkedSlot(Array<LinkedSlotVolatile> slotArray, Int32 id, T value);
  private: List<T> GetValuesAsList();
  private: static void GrowTable(Array<LinkedSlotVolatile>& table, Int32 minLength);
  private: static Int32 GetNewTableSize(Int32 minSize);
  private: Func<T> _valueFactory;
  private: static Array<LinkedSlotVolatile> ts_slotArray;
  private: static FinalizationHelper ts_finalizationHelper;
  private: Int32 _idComplement;
  private: Boolean _initialized;
  private: static IdManager s_idManager;
  private: LinkedSlot _linkedSlot;
  private: Boolean _trackAllValues;
};
} // namespace ThreadLocalNamespace
template <class T>
using ThreadLocal = ThreadLocalNamespace::ThreadLocal<T>;
} // namespace System::Private::CoreLib::System::Threading
