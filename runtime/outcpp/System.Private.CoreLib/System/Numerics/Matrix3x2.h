#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Single.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Numerics {
FORWARDS(Vector2)
namespace Matrix3x2Namespace {
struct Matrix3x2 {
  public: static Matrix3x2 get_Identity();
  public: Boolean get_IsIdentity();
  public: Vector2 get_Translation();
  public: void set_Translation(Vector2 value);
  public: void Ctor(Single m11, Single m12, Single m21, Single m22, Single m31, Single m32);
  public: static Matrix3x2 CreateTranslation(Vector2 position);
  public: static Matrix3x2 CreateTranslation(Single xPosition, Single yPosition);
  public: static Matrix3x2 CreateScale(Single xScale, Single yScale);
  public: static Matrix3x2 CreateScale(Single xScale, Single yScale, Vector2 centerPoint);
  public: static Matrix3x2 CreateScale(Vector2 scales);
  public: static Matrix3x2 CreateScale(Vector2 scales, Vector2 centerPoint);
  public: static Matrix3x2 CreateScale(Single scale);
  public: static Matrix3x2 CreateScale(Single scale, Vector2 centerPoint);
  public: static Matrix3x2 CreateSkew(Single radiansX, Single radiansY);
  public: static Matrix3x2 CreateSkew(Single radiansX, Single radiansY, Vector2 centerPoint);
  public: static Matrix3x2 CreateRotation(Single radians);
  public: static Matrix3x2 CreateRotation(Single radians, Vector2 centerPoint);
  public: Single GetDeterminant();
  public: static Boolean Invert(Matrix3x2 matrix, Matrix3x2& result);
  public: static Matrix3x2 Lerp(Matrix3x2 matrix1, Matrix3x2 matrix2, Single amount);
  public: static Matrix3x2 Negate(Matrix3x2 value);
  public: static Matrix3x2 Add(Matrix3x2 value1, Matrix3x2 value2);
  public: static Matrix3x2 Subtract(Matrix3x2 value1, Matrix3x2 value2);
  public: static Matrix3x2 Multiply(Matrix3x2 value1, Matrix3x2 value2);
  public: static Matrix3x2 Multiply(Matrix3x2 value1, Single value2);
  public: static Matrix3x2 op_UnaryNegation(Matrix3x2 value);
  public: static Matrix3x2 op_Addition(Matrix3x2 value1, Matrix3x2 value2);
  public: static Matrix3x2 op_Subtraction(Matrix3x2 value1, Matrix3x2 value2);
  public: static Matrix3x2 op_Multiply(Matrix3x2 value1, Matrix3x2 value2);
  public: static Matrix3x2 op_Multiply(Matrix3x2 value1, Single value2);
  public: static Boolean op_Equality(Matrix3x2 value1, Matrix3x2 value2);
  public: static Boolean op_Inequality(Matrix3x2 value1, Matrix3x2 value2);
  public: Boolean Equals(Matrix3x2 other);
  public: Boolean Equals(Object obj);
  public: String ToString();
  public: Int32 GetHashCode();
  private: static void SCtor();
  public: void Ctor();
  public: Single M11;
  public: Single M12;
  public: Single M21;
  public: Single M22;
  public: Single M31;
  public: Single M32;
  private: static Matrix3x2 _identity;
};
} // namespace Matrix3x2Namespace
using Matrix3x2 = Matrix3x2Namespace::Matrix3x2;
} // namespace System::Private::CoreLib::System::Numerics
