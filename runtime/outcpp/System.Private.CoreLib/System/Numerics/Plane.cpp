#include "Plane-dep.h"

#include <System.Private.CoreLib/System/Numerics/Plane-dep.h>

namespace System::Private::CoreLib::System::Numerics::PlaneNamespace {
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
