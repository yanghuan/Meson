#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Int32)
FORWARD(Object)
namespace ParamsArrayNamespace {
struct ParamsArray : public valueType<ParamsArray> {
  public: Int32 get_Length();
  public: Object get_Item(Int32 index);
  public: explicit ParamsArray(Object arg0);
  public: explicit ParamsArray(Object arg0, Object arg1);
  public: explicit ParamsArray(Object arg0, Object arg1, Object arg2);
  public: explicit ParamsArray(Array<Object> args);
  private: Object GetAtSlow(Int32 index);
  public: static void cctor();
  public: explicit ParamsArray() {}
  private: static Array<Object> s_oneArgArray;
  private: static Array<Object> s_twoArgArray;
  private: static Array<Object> s_threeArgArray;
  private: Object _arg0;
  private: Object _arg1;
  private: Object _arg2;
  private: Array<Object> _args;
};
} // namespace ParamsArrayNamespace
using ParamsArray = ParamsArrayNamespace::ParamsArray;
} // namespace System::Private::CoreLib::System
