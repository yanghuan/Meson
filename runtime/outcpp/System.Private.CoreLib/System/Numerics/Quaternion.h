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
FORWARDS(Matrix4x4)
FORWARDS(Vector3)
namespace QuaternionNamespace {
struct Quaternion : public rt::ValueType<Quaternion> {
  public: static Quaternion get_Identity();
  public: Boolean get_IsIdentity();
  public: void Ctor(Single x, Single y, Single z, Single w);
  public: void Ctor(Vector3 vectorPart, Single scalarPart);
  public: Single Length();
  public: Single LengthSquared();
  public: static Quaternion Normalize(Quaternion value);
  public: static Quaternion Conjugate(Quaternion value);
  public: static Quaternion Inverse(Quaternion value);
  public: static Quaternion CreateFromAxisAngle(Vector3 axis, Single angle);
  public: static Quaternion CreateFromYawPitchRoll(Single yaw, Single pitch, Single roll);
  public: static Quaternion CreateFromRotationMatrix(Matrix4x4 matrix);
  public: static Single Dot(Quaternion quaternion1, Quaternion quaternion2);
  public: static Quaternion Slerp(Quaternion quaternion1, Quaternion quaternion2, Single amount);
  public: static Quaternion Lerp(Quaternion quaternion1, Quaternion quaternion2, Single amount);
  public: static Quaternion Concatenate(Quaternion value1, Quaternion value2);
  public: static Quaternion Negate(Quaternion value);
  public: static Quaternion Add(Quaternion value1, Quaternion value2);
  public: static Quaternion Subtract(Quaternion value1, Quaternion value2);
  public: static Quaternion Multiply(Quaternion value1, Quaternion value2);
  public: static Quaternion Multiply(Quaternion value1, Single value2);
  public: static Quaternion Divide(Quaternion value1, Quaternion value2);
  public: static Quaternion op_UnaryNegation(Quaternion value);
  public: static Quaternion op_Addition(Quaternion value1, Quaternion value2);
  public: static Quaternion op_Subtraction(Quaternion value1, Quaternion value2);
  public: static Quaternion op_Multiply(Quaternion value1, Quaternion value2);
  public: static Quaternion op_Multiply(Quaternion value1, Single value2);
  public: static Quaternion op_Division(Quaternion value1, Quaternion value2);
  public: static Boolean op_Equality(Quaternion value1, Quaternion value2);
  public: static Boolean op_Inequality(Quaternion value1, Quaternion value2);
  public: Boolean Equals(Quaternion other);
  public: Boolean Equals(Object obj);
  public: String ToString();
  public: Int32 GetHashCode();
  public: void Ctor();
  public: Single X;
  public: Single Y;
  public: Single Z;
  public: Single W;
};
} // namespace QuaternionNamespace
using Quaternion = QuaternionNamespace::Quaternion;
} // namespace System::Private::CoreLib::System::Numerics
