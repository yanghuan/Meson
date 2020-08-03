#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Security::Permissions {
enum class PermissionState;
} // namespace System::Private::CoreLib::System::Security::Permissions
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Security {
FORWARD(IPermission)
FORWARD(SecurityElement)
namespace PermissionSetNamespace {
using namespace Collections;
using namespace Permissions;
CLASS(PermissionSet) : public Object::in {
  public: Int32 get_Count();
  public: Boolean get_IsReadOnly();
  public: Boolean get_IsSynchronized();
  public: Object get_SyncRoot();
  public: void Ctor(PermissionState state);
  public: void Ctor(PermissionSet permSet);
  public: IPermission AddPermission(IPermission perm);
  protected: IPermission AddPermissionImpl(IPermission perm);
  public: void Assert();
  public: Boolean ContainsNonCodeAccessPermissions();
  public: static Array<Byte> ConvertPermissionSet(String inFormat, Array<Byte> inData, String outFormat);
  public: PermissionSet Copy();
  public: void CopyTo(Array<> array, Int32 index);
  public: void Demand();
  public: void Deny();
  public: Boolean Equals(Object o);
  public: void FromXml(SecurityElement et);
  public: IEnumerator GetEnumerator();
  protected: IEnumerator GetEnumeratorImpl();
  public: Int32 GetHashCode();
  public: IPermission GetPermission(Type permClass);
  protected: IPermission GetPermissionImpl(Type permClass);
  public: PermissionSet Intersect(PermissionSet other);
  public: Boolean IsEmpty();
  public: Boolean IsSubsetOf(PermissionSet target);
  public: Boolean IsUnrestricted();
  public: void PermitOnly();
  public: IPermission RemovePermission(Type permClass);
  protected: IPermission RemovePermissionImpl(Type permClass);
  public: static void RevertAssert();
  public: IPermission SetPermission(IPermission perm);
  protected: IPermission SetPermissionImpl(IPermission perm);
  public: String ToString();
  public: SecurityElement ToXml();
  public: PermissionSet Union(PermissionSet other);
};
} // namespace PermissionSetNamespace
using PermissionSet = PermissionSetNamespace::PermissionSet;
} // namespace System::Private::CoreLib::System::Security
