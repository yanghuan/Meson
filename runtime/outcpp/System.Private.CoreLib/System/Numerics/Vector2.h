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
FORWARDS(Matrix3x2)
FORWARDS(Matrix4x4)
FORWARDS(Quaternion)
namespace Vector2Namespace {
struct Vector2 {
  public: static Vector2 get_Zero();
  public: static Vector2 get_One();
  public: static Vector2 get_UnitX();
  public: static Vector2 get_UnitY();
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: String ToString();
  public: String ToString(String format);
  public: String ToString(String format, IFormatProvider formatProvider);
  public: Single Length();
  public: Single LengthSquared();
  public: static Single Distance(Vector2 value1, Vector2 value2);
  public: static Single DistanceSquared(Vector2 value1, Vector2 value2);
  public: static Vector2 Normalize(Vector2 value);
  public: static Vector2 Reflect(Vector2 vector, Vector2 normal);
  public: static Vector2 Clamp(Vector2 value1, Vector2 min, Vector2 max);
  public: static Vector2 Lerp(Vector2 value1, Vector2 value2, Single amount);
  public: static Vector2 Transform(Vector2 position, Matrix3x2 matrix);
  public: static Vector2 Transform(Vector2 position, Matrix4x4 matrix);
  public: static Vector2 TransformNormal(Vector2 normal, Matrix3x2 matrix);
  public: static Vector2 TransformNormal(Vector2 normal, Matrix4x4 matrix);
  public: static Vector2 Transform(Vector2 value, Quaternion rotation);
  public: static Vector2 Add(Vector2 left, Vector2 right);
  public: static Vector2 Subtract(Vector2 left, Vector2 right);
  public: static Vector2 Multiply(Vector2 left, Vector2 right);
  public: static Vector2 Multiply(Vector2 left, Single right);
  public: static Vector2 Multiply(Single left, Vector2 right);
  public: static Vector2 Divide(Vector2 left, Vector2 right);
  public: static Vector2 Divide(Vector2 left, Single divisor);
  public: static Vector2 Negate(Vector2 value);
  public: void Ctor(Single value);
  public: void Ctor(Single x, Single y);
  public: void CopyTo(Array<Single> array);
  public: void CopyTo(Array<Single> array, Int32 index);
  public: Boolean Equals(Vector2 other);
  public: static Single Dot(Vector2 value1, Vector2 value2);
  public: static Vector2 Min(Vector2 value1, Vector2 value2);
  public: static Vector2 Max(Vector2 value1, Vector2 value2);
  public: static Vector2 Abs(Vector2 value);
  public: static Vector2 SquareRoot(Vector2 value);
  public: static Vector2 op_Addition(Vector2 left, Vector2 right);
  public: static Vector2 op_Subtraction(Vector2 left, Vector2 right);
  public: static Vector2 op_Multiply(Vector2 left, Vector2 right);
  public: static Vector2 op_Multiply(Single left, Vector2 right);
  public: static Vector2 op_Multiply(Vector2 left, Single right);
  public: static Vector2 op_Division(Vector2 left, Vector2 right);
  public: static Vector2 op_Division(Vector2 value1, Single value2);
  public: static Vector2 op_UnaryNegation(Vector2 value);
  public: static Boolean op_Equality(Vector2 left, Vector2 right);
  public: static Boolean op_Inequality(Vector2 left, Vector2 right);
  public: void Ctor();
  public: Single X;
  public: Single Y;
};
} // namespace Vector2Namespace
using Vector2 = Vector2Namespace::Vector2;
} // namespace System::Private::CoreLib::System::Numerics
