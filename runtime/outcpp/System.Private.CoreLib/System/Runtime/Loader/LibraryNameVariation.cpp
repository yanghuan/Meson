#include "LibraryNameVariation-dep.h"

#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Runtime/Loader/LibraryNameVariation-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>

namespace System::Private::CoreLib::System::Runtime::Loader::LibraryNameVariationNamespace {
LibraryNameVariation _DetermineLibraryNameVariations_d__4___::get_CurrentOfLibraryNameVariation() {
  return __2__current;
}

Object _DetermineLibraryNameVariations_d__4___::get_CurrentOfIEnumerator() {
  return __2__current;
}

void _DetermineLibraryNameVariations_d__4___::ctor(Int32 __1__state) {
  this->__1__state = __1__state;
  __l__initialThreadId = Environment::get_CurrentManagedThreadId();
}

void _DetermineLibraryNameVariations_d__4___::DisposeOfIDisposable() {
}

Boolean _DetermineLibraryNameVariations_d__4___::MoveNext() {
  switch (__1__state.get()) {
    default:
      return false;
    case 0:
      __1__state = -1;
      __2__current = LibraryNameVariation(String::in::Empty, String::in::Empty);
      __1__state = 1;
      return true;
    case 1:
      __1__state = -1;
      if (isRelativePath && (!forOSLoader || (libName->Contains(u'.') && !libName->EndsWith(u'.'))) && !libName->EndsWith(".dll", StringComparison::OrdinalIgnoreCase) && !libName->EndsWith(".exe", StringComparison::OrdinalIgnoreCase)) {
        __2__current = LibraryNameVariation(String::in::Empty, ".dll");
        __1__state = 2;
        return true;
      }
      break;
    case 2:
      __1__state = -1;
      break;
  }
  return false;
}

void _DetermineLibraryNameVariations_d__4___::ResetOfIEnumerator() {
  rt::throw_exception<NotSupportedException>();
}

IEnumerator<LibraryNameVariation> _DetermineLibraryNameVariations_d__4___::GetEnumeratorOfLibraryNameVariation() {
  _DetermineLibraryNameVariations_d__4 _DetermineLibraryNameVariations_d__;
  if (__1__state == -2 && __l__initialThreadId == Environment::get_CurrentManagedThreadId()) {
    __1__state = 0;
    _DetermineLibraryNameVariations_d__ = (_DetermineLibraryNameVariations_d__4)this;
  } else {
    _DetermineLibraryNameVariations_d__ = rt::newobj<_DetermineLibraryNameVariations_d__4>(0);
  }
  _DetermineLibraryNameVariations_d__->libName = __3__libName;
  _DetermineLibraryNameVariations_d__->isRelativePath = __3__isRelativePath;
  _DetermineLibraryNameVariations_d__->forOSLoader = __3__forOSLoader;
  return _DetermineLibraryNameVariations_d__;
}

IEnumerator_ _DetermineLibraryNameVariations_d__4___::GetEnumeratorOfIEnumerable() {
  return ((IEnumerable<LibraryNameVariation>)(_DetermineLibraryNameVariations_d__4)this)->GetEnumerator();
}

LibraryNameVariation::LibraryNameVariation(String prefix, String suffix) {
  Prefix = prefix;
  Suffix = suffix;
}

IEnumerable<LibraryNameVariation> LibraryNameVariation::DetermineLibraryNameVariations(String libName, Boolean isRelativePath, Boolean forOSLoader) {
}

} // namespace System::Private::CoreLib::System::Runtime::Loader::LibraryNameVariationNamespace
