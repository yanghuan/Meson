#include "ParamsArray-dep.h"

namespace System::Private::CoreLib::System::ParamsArrayNamespace {
Int32 ParamsArray::get_Length() {
  return _args->get_Length();
}

Object ParamsArray::get_Item(Int32 index) {
  if (index != 0) {
    return GetAtSlow(index);
  }
  return _arg0;
}

ParamsArray::ParamsArray(Object arg0) {
  _arg0 = arg0;
  _arg1 = nullptr;
  _arg2 = nullptr;
  _args = s_oneArgArray;
}

ParamsArray::ParamsArray(Object arg0, Object arg1) {
  _arg0 = arg0;
  _arg1 = arg1;
  _arg2 = nullptr;
  _args = s_twoArgArray;
}

ParamsArray::ParamsArray(Object arg0, Object arg1, Object arg2) {
  _arg0 = arg0;
  _arg1 = arg1;
  _arg2 = arg2;
  _args = s_threeArgArray;
}

ParamsArray::ParamsArray(Array<Object> args) {
  Int32 num = args->get_Length();
  _arg0 = ((num > 0) ? args[0] : nullptr);
  _arg1 = ((num > 1) ? args[1] : nullptr);
  _arg2 = ((num > 2) ? args[2] : nullptr);
  _args = args;
}

Object ParamsArray::GetAtSlow(Int32 index) {
  switch (index.get()) {
    case 1:
      return _arg1;
    case 2:
      return _arg2;
    default:
      return _args[index];
  }
}

void ParamsArray::ctor_static() {
  s_oneArgArray = rt::newarr<Array<Object>>(1);
  s_twoArgArray = rt::newarr<Array<Object>>(2);
  s_threeArgArray = rt::newarr<Array<Object>>(3);
}

} // namespace System::Private::CoreLib::System::ParamsArrayNamespace
