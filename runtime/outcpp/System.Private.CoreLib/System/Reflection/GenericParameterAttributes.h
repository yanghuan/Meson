#pragma once

namespace System::Private::CoreLib::System::Reflection {
enum class GenericParameterAttributes {
  None = 0,
  VarianceMask = 3,
  Covariant = 1,
  Contravariant = 2,
  SpecialConstraintMask = 28,
  ReferenceTypeConstraint = 4,
  NotNullableValueTypeConstraint = 8,
  DefaultConstructorConstraint = 16,
};
} // namespace System::Private::CoreLib::System::Reflection
