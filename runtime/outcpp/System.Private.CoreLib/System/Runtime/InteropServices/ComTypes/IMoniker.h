#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Guid)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
FORWARDS(FILETIME)
FORWARD(IBindCtx)
FORWARD(IEnumMoniker)
FORWARD(IStream)
namespace IMonikerNamespace {
CLASS(IMoniker) : public object {
  public: void GetClassID(Guid& pClassID);
  public: Int32 IsDirty();
  public: void Load(IStream pStm);
  public: void Save(IStream pStm, Boolean fClearDirty);
  public: void GetSizeMax(Int64& pcbSize);
  public: void BindToObject(IBindCtx pbc, IMoniker pmkToLeft, Guid& riidResult, Object& ppvResult);
  public: void BindToStorage(IBindCtx pbc, IMoniker pmkToLeft, Guid& riid, Object& ppvObj);
  public: void Reduce(IBindCtx pbc, Int32 dwReduceHowFar, IMoniker& ppmkToLeft, IMoniker& ppmkReduced);
  public: void ComposeWith(IMoniker pmkRight, Boolean fOnlyIfNotGeneric, IMoniker& ppmkComposite);
  public: void Enum(Boolean fForward, IEnumMoniker& ppenumMoniker);
  public: Int32 IsEqual(IMoniker pmkOtherMoniker);
  public: void Hash(Int32& pdwHash);
  public: Int32 IsRunning(IBindCtx pbc, IMoniker pmkToLeft, IMoniker pmkNewlyRunning);
  public: void GetTimeOfLastChange(IBindCtx pbc, IMoniker pmkToLeft, FILETIME& pFileTime);
  public: void Inverse(IMoniker& ppmk);
  public: void CommonPrefixWith(IMoniker pmkOther, IMoniker& ppmkPrefix);
  public: void RelativePathTo(IMoniker pmkOther, IMoniker& ppmkRelPath);
  public: void GetDisplayName(IBindCtx pbc, IMoniker pmkToLeft, String& ppszDisplayName);
  public: void ParseDisplayName(IBindCtx pbc, IMoniker pmkToLeft, String pszDisplayName, Int32& pchEaten, IMoniker& ppmkOut);
  public: Int32 IsSystemMoniker(Int32& pdwMksys);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IMonikerNamespace
using IMoniker = IMonikerNamespace::IMoniker;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
