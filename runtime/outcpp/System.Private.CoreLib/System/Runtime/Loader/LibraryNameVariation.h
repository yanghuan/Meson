#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD(IDisposable)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Loader {
namespace LibraryNameVariationNamespace {
using namespace System::Collections;
using namespace System::Collections::Generic;
template <class T>
using IEnumerable = Collections::Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
template <class T>
using IEnumerator = Collections::Generic::IEnumerator<T>;
using IEnumerator_ = Collections::IEnumerator;
struct LibraryNameVariation : public valueType<LibraryNameVariation> {
  private: FRIENDN(<DetermineLibraryNameVariations>d__4)
  public: explicit LibraryNameVariation(String prefix, String suffix);
  public: static IEnumerable<LibraryNameVariation> DetermineLibraryNameVariations(String libName, Boolean isRelativePath, Boolean forOSLoader = false);
  public: explicit LibraryNameVariation() {}
  public: String Prefix;
  public: String Suffix;
};
CLASS(_DetermineLibraryNameVariations_d__4) : public object {
  public: using interface = rt::TypeList<IEnumerable<LibraryNameVariation>, IEnumerable_, IEnumerator<LibraryNameVariation>, IDisposable, IEnumerator_>;
  private: LibraryNameVariation get_CurrentOfLibraryNameVariation();
  private: Object get_CurrentOfIEnumerator();
  public: void ctor(Int32 __1__state);
  private: void DisposeOfIDisposable();
  private: Boolean MoveNext();
  private: void ResetOfIEnumerator();
  private: IEnumerator<LibraryNameVariation> GetEnumeratorOfLibraryNameVariation();
  private: IEnumerator_ GetEnumeratorOfIEnumerable();
  private: Int32 __1__state;
  private: LibraryNameVariation __2__current;
  private: Int32 __l__initialThreadId;
  private: Boolean isRelativePath;
  public: Boolean __3__isRelativePath;
  private: Boolean forOSLoader;
  public: Boolean __3__forOSLoader;
  private: String libName;
  public: String __3__libName;
};
} // namespace LibraryNameVariationNamespace
using LibraryNameVariation = LibraryNameVariationNamespace::LibraryNameVariation;
} // namespace System::Private::CoreLib::System::Runtime::Loader
