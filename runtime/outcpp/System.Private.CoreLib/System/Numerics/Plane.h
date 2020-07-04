#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Numerics/Vector3.h>
#include <System.Private.CoreLib/System/Single.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Numerics {
FORWARDS(Matrix4x4)
FORWARDS(Quaternion)
FORWARDS(Vector4)
namespace PlaneNamespace {
struct Plane {
  public: static Plane CreateFromVertices(Vector3 point1, Vector3 point2, Vector3 point3);
  public: static Plane Normalize(Plane value);
  public: static Plane Transform(Plane plane, Matrix4x4 matrix);
  public: static Plane Transform(Plane plane, Quaternion rotation);
  public: static Single Dot(Plane plane, Vector4 value);
  public: static Single DotCoordinate(Plane plane, Vector3 value);
  public: static Single DotNormal(Plane plane, Vector3 value);
  public: Boolean Equals(Plane other);
  public: Boolean Equals(Object obj);
  public: String ToString();
  public: Int32 GetHashCode();
  public: Vector3 Normal;
  public: Single D;
};
} // namespace PlaneNamespace
using Plane = PlaneNamespace::Plane;
} // namespace System::Private::CoreLib::System::Numerics
