#include "LibraryNameVariation-dep.h"

#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Runtime/Loader/LibraryNameVariation-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/StringComparison.h>

namespace System::Private::CoreLib::System::Runtime::Loader::LibraryNameVariationNamespace {
LibraryNameVariation _DetermineLibraryNameVariations_d__4___::get_CurrentOfLibraryNameVariation() {
  return <>2__current;
}

Object _DetermineLibraryNameVariations_d__4___::get_CurrentOfIEnumerator() {
  return <>2__current;
}

void _DetermineLibraryNameVariations_d__4___::ctor(Int32 __1__state) {
  this->__1__state = __1__state;
  <>l__initialThreadId = Environment::get_CurrentManagedThreadId();
}

void _DetermineLibraryNameVariations_d__4___::DisposeOfIDisposable() {
}

Boolean _DetermineLibraryNameVariations_d__4___::MoveNext() {
  switch (<>1__state.get()) {
    default:
      return false;
    case 0:
      <>1__state = -1;
      <>2__current = LibraryNameVariation(String::in::Empty, String::in::Empty);
      <>1__state = 1;
      return true;
    case 1:
      <>1__state = -1;
      if (isRelativePath && (!forOSLoader || (libName->Contains(46) && !libName->EndsWith(46))) && !libName->EndsWith(".dll", StringComparison::OrdinalIgnoreCase) && !libName->EndsWith(".exe", StringComparison::OrdinalIgnoreCase)) {
        <>2__current = LibraryNameVariation(String::in::Empty, ".dll");
        <>1__state = 2;
        return true;
      }
      break;
    case 2:
      <>1__state = -1;
      break;
  }
  return false;
}

void _DetermineLibraryNameVariations_d__4___::ResetOfIEnumerator() {
  rt::throw_exception<NotSupportedException>();
}

IEnumerator<LibraryNameVariation> _DetermineLibraryNameVariations_d__4___::GetEnumeratorOfLibraryNameVariation() {
  _DetermineLibraryNameVariations_d__4 _DetermineLibraryNameVariations_d__;
  if (<>1__state == -2 && <>l__initialThreadId == Environment::get_CurrentManagedThreadId()) {
    <>1__state = 0;
    _DetermineLibraryNameVariations_d__ = (_DetermineLibraryNameVariations_d__4)this;
  } else {
    _DetermineLibraryNameVariations_d__ = rt::newobj<_DetermineLibraryNameVariations_d__4>(0);
  }
  _DetermineLibraryNameVariations_d__->libName = <>3__libName;
  _DetermineLibraryNameVariations_d__->isRelativePath = <>3__isRelativePath;
  _DetermineLibraryNameVariations_d__->forOSLoader = <>3__forOSLoader;
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
