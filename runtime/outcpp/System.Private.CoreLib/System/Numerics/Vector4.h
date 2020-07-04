#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Single.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(IFormatProvider)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Numerics {
FORWARDS(Vector2)
FORWARDS(Matrix4x4)
FORWARDS(Vector3)
FORWARDS(Quaternion)
namespace Vector4Namespace {
struct Vector4 {
  public: static Vector4 get_Zero();
  public: static Vector4 get_One();
  public: static Vector4 get_UnitX();
  public: static Vector4 get_UnitY();
  public: static Vector4 get_UnitZ();
  public: static Vector4 get_UnitW();
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: String ToString();
  public: String ToString(String format);
  public: String ToString(String format, IFormatProvider formatProvider);
  public: Single Length();
  public: Single LengthSquared();
  public: static Single Distance(Vector4 value1, Vector4 value2);
  public: static Single DistanceSquared(Vector4 value1, Vector4 value2);
  public: static Vector4 Normalize(Vector4 vector);
  public: static Vector4 Clamp(Vector4 value1, Vector4 min, Vector4 max);
  public: static Vector4 Lerp(Vector4 value1, Vector4 value2, Single amount);
  public: static Vector4 Transform(Vector2 position, Matrix4x4 matrix);
  public: static Vector4 Transform(Vector3 position, Matrix4x4 matrix);
  public: static Vector4 Transform(Vector4 vector, Matrix4x4 matrix);
  public: static Vector4 Transform(Vector2 value, Quaternion rotation);
  public: static Vector4 Transform(Vector3 value, Quaternion rotation);
  public: static Vector4 Transform(Vector4 value, Quaternion rotation);
  public: static Vector4 Add(Vector4 left, Vector4 right);
  public: static Vector4 Subtract(Vector4 left, Vector4 right);
  public: static Vector4 Multiply(Vector4 left, Vector4 right);
  public: static Vector4 Multiply(Vector4 left, Single right);
  public: static Vector4 Multiply(Single left, Vector4 right);
  public: static Vector4 Divide(Vector4 left, Vector4 right);
  public: static Vector4 Divide(Vector4 left, Single divisor);
  public: static Vector4 Negate(Vector4 value);
  public: void CopyTo(Array<Single> array);
  public: void CopyTo(Array<Single> array, Int32 index);
  public: Boolean Equals(Vector4 other);
  public: static Single Dot(Vector4 vector1, Vector4 vector2);
  public: static Vector4 Min(Vector4 value1, Vector4 value2);
  public: static Vector4 Max(Vector4 value1, Vector4 value2);
  public: static Vector4 Abs(Vector4 value);
  public: static Vector4 SquareRoot(Vector4 value);
  public: Single X;
  public: Single Y;
  public: Single Z;
  public: Single W;
};
} // namespace Vector4Namespace
using Vector4 = Vector4Namespace::Vector4;
} // namespace System::Private::CoreLib::System::Numerics
