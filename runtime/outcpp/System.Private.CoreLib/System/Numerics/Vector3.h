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
FORWARDS(Matrix4x4)
FORWARDS(Quaternion)
FORWARDS(Vector2)
namespace Vector3Namespace {
struct Vector3 : public rt::ValueType<Vector3> {
  public: static Vector3 get_Zero();
  public: static Vector3 get_One();
  public: static Vector3 get_UnitX();
  public: static Vector3 get_UnitY();
  public: static Vector3 get_UnitZ();
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: String ToString();
  public: String ToString(String format);
  public: String ToString(String format, IFormatProvider formatProvider);
  public: Single Length();
  public: Single LengthSquared();
  public: static Single Distance(Vector3 value1, Vector3 value2);
  public: static Single DistanceSquared(Vector3 value1, Vector3 value2);
  public: static Vector3 Normalize(Vector3 value);
  public: static Vector3 Cross(Vector3 vector1, Vector3 vector2);
  public: static Vector3 Reflect(Vector3 vector, Vector3 normal);
  public: static Vector3 Clamp(Vector3 value1, Vector3 min, Vector3 max);
  public: static Vector3 Lerp(Vector3 value1, Vector3 value2, Single amount);
  public: static Vector3 Transform(Vector3 position, Matrix4x4 matrix);
  public: static Vector3 TransformNormal(Vector3 normal, Matrix4x4 matrix);
  public: static Vector3 Transform(Vector3 value, Quaternion rotation);
  public: static Vector3 Add(Vector3 left, Vector3 right);
  public: static Vector3 Subtract(Vector3 left, Vector3 right);
  public: static Vector3 Multiply(Vector3 left, Vector3 right);
  public: static Vector3 Multiply(Vector3 left, Single right);
  public: static Vector3 Multiply(Single left, Vector3 right);
  public: static Vector3 Divide(Vector3 left, Vector3 right);
  public: static Vector3 Divide(Vector3 left, Single divisor);
  public: static Vector3 Negate(Vector3 value);
  public: void Ctor(Single value);
  public: void Ctor(Vector2 value, Single z);
  public: void Ctor(Single x, Single y, Single z);
  public: void CopyTo(Array<Single> array);
  public: void CopyTo(Array<Single> array, Int32 index);
  public: Boolean Equals(Vector3 other);
  public: static Single Dot(Vector3 vector1, Vector3 vector2);
  public: static Vector3 Min(Vector3 value1, Vector3 value2);
  public: static Vector3 Max(Vector3 value1, Vector3 value2);
  public: static Vector3 Abs(Vector3 value);
  public: static Vector3 SquareRoot(Vector3 value);
  public: static Vector3 op_Addition(Vector3 left, Vector3 right);
  public: static Vector3 op_Subtraction(Vector3 left, Vector3 right);
  public: static Vector3 op_Multiply(Vector3 left, Vector3 right);
  public: static Vector3 op_Multiply(Vector3 left, Single right);
  public: static Vector3 op_Multiply(Single left, Vector3 right);
  public: static Vector3 op_Division(Vector3 left, Vector3 right);
  public: static Vector3 op_Division(Vector3 value1, Single value2);
  public: static Vector3 op_UnaryNegation(Vector3 value);
  public: static Boolean op_Equality(Vector3 left, Vector3 right);
  public: static Boolean op_Inequality(Vector3 left, Vector3 right);
  public: void Ctor();
  public: Single X;
  public: Single Y;
  public: Single Z;
};
} // namespace Vector3Namespace
using Vector3 = Vector3Namespace::Vector3;
} // namespace System::Private::CoreLib::System::Numerics
