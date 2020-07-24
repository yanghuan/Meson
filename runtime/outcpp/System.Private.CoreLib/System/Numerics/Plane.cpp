#include "Plane-dep.h"

#include <System.Private.CoreLib/System/Numerics/Plane-dep.h>

namespace System::Private::CoreLib::System::Numerics::PlaneNamespace {
Plane::Plane(Single x, Single y, Single z, Single d) {
};

Plane::Plane(Vector3 normal, Single d) {
};

Plane::Plane(Vector4 value) {
};

Plane Plane::CreateFromVertices(Vector3 point1, Vector3 point2, Vector3 point3) {
  return Plane();
};

Plane Plane::Normalize(Plane value) {
  return Plane();
};

Plane Plane::Transform(Plane plane, Matrix4x4 matrix) {
  return Plane();
};

Plane Plane::Transform(Plane plane, Quaternion rotation) {
  return Plane();
};

Single Plane::Dot(Plane plane, Vector4 value) {
  return Single();
};

Single Plane::DotCoordinate(Plane plane, Vector3 value) {
  return Single();
};

Single Plane::DotNormal(Plane plane, Vector3 value) {
  return Single();
};

Boolean Plane::op_Equality(Plane value1, Plane value2) {
  return Boolean();
};

Boolean Plane::op_Inequality(Plane value1, Plane value2) {
  return Boolean();
};

Boolean Plane::Equals(Plane other) {
  return Boolean();
};

Boolean Plane::Equals(Object obj) {
  return Boolean();
};

String Plane::ToString() {
  return nullptr;
};

Int32 Plane::GetHashCode() {
  return Int32();
};

} // namespace System::Private::CoreLib::System::Numerics::PlaneNamespace
