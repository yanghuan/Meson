#include "SR-dep.h"

#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/IO/BinaryReader-dep.h>
#include <System.Private.CoreLib/System/Private/CoreLib/Strings-dep.h>
#include <System.Private.CoreLib/System/Resources/MissingManifestResourceException-dep.h>
#include <System.Private.CoreLib/System/Resources/ResourceReader-dep.h>
#include <System.Private.CoreLib/System/Resources/RuntimeResourceSet-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>
#include <System.Private.CoreLib/System/Threading/Monitor-dep.h>

namespace System::Private::CoreLib::System::SRNamespace {
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Private::CoreLib;
using namespace System::Resources;
using namespace System::Runtime::CompilerServices;
using namespace System::Threading;

ResourceManager SR::get_ResourceManager() {
  auto default = s_resourceManager;
  if (default != nullptr) default = (s_resourceManager = rt::newobj<ResourceManager>(rt::typeof<Strings>()));

  return default;
}

String SR::get_Acc_CreateAbstEx() {
  return GetResourceString("Acc_CreateAbstEx");
}

String SR::get_Acc_CreateArgIterator() {
  return GetResourceString("Acc_CreateArgIterator");
}

String SR::get_Acc_CreateGenericEx() {
  return GetResourceString("Acc_CreateGenericEx");
}

String SR::get_Acc_CreateInterfaceEx() {
  return GetResourceString("Acc_CreateInterfaceEx");
}

String SR::get_Acc_CreateVoid() {
  return GetResourceString("Acc_CreateVoid");
}

String SR::get_Acc_NotClassInit() {
  return GetResourceString("Acc_NotClassInit");
}

String SR::get_Acc_ReadOnly() {
  return GetResourceString("Acc_ReadOnly");
}

String SR::get_Access_Void() {
  return GetResourceString("Access_Void");
}

String SR::get_AggregateException_ctor_DefaultMessage() {
  return GetResourceString("AggregateException_ctor_DefaultMessage");
}

String SR::get_AggregateException_ctor_InnerExceptionNull() {
  return GetResourceString("AggregateException_ctor_InnerExceptionNull");
}

String SR::get_AggregateException_DeserializationFailure() {
  return GetResourceString("AggregateException_DeserializationFailure");
}

String SR::get_AggregateException_InnerException() {
  return GetResourceString("AggregateException_InnerException");
}

String SR::get_AppDomain_Name() {
  return GetResourceString("AppDomain_Name");
}

String SR::get_AppDomain_NoContextPolicies() {
  return GetResourceString("AppDomain_NoContextPolicies");
}

String SR::get_AppDomain_Policy_PrincipalTwice() {
  return GetResourceString("AppDomain_Policy_PrincipalTwice");
}

String SR::get_AmbiguousImplementationException_NullMessage() {
  return GetResourceString("AmbiguousImplementationException_NullMessage");
}

String SR::get_Arg_AccessException() {
  return GetResourceString("Arg_AccessException");
}

String SR::get_Arg_AccessViolationException() {
  return GetResourceString("Arg_AccessViolationException");
}

String SR::get_Arg_AmbiguousMatchException() {
  return GetResourceString("Arg_AmbiguousMatchException");
}

String SR::get_Arg_ApplicationException() {
  return GetResourceString("Arg_ApplicationException");
}

String SR::get_Arg_ArgumentException() {
  return GetResourceString("Arg_ArgumentException");
}

String SR::get_Arg_ArgumentOutOfRangeException() {
  return GetResourceString("Arg_ArgumentOutOfRangeException");
}

String SR::get_Arg_ArithmeticException() {
  return GetResourceString("Arg_ArithmeticException");
}

String SR::get_Arg_ArrayLengthsDiffer() {
  return GetResourceString("Arg_ArrayLengthsDiffer");
}

String SR::get_Arg_ArrayPlusOffTooSmall() {
  return GetResourceString("Arg_ArrayPlusOffTooSmall");
}

String SR::get_Arg_ArrayTypeMismatchException() {
  return GetResourceString("Arg_ArrayTypeMismatchException");
}

String SR::get_Arg_ArrayZeroError() {
  return GetResourceString("Arg_ArrayZeroError");
}

String SR::get_Arg_BadDecimal() {
  return GetResourceString("Arg_BadDecimal");
}

String SR::get_Arg_BadImageFormatException() {
  return GetResourceString("Arg_BadImageFormatException");
}

String SR::get_Arg_BadLiteralFormat() {
  return GetResourceString("Arg_BadLiteralFormat");
}

String SR::get_Arg_BogusIComparer() {
  return GetResourceString("Arg_BogusIComparer");
}

String SR::get_Arg_BufferTooSmall() {
  return GetResourceString("Arg_BufferTooSmall");
}

String SR::get_Arg_CannotBeNaN() {
  return GetResourceString("Arg_CannotBeNaN");
}

String SR::get_Arg_CannotHaveNegativeValue() {
  return GetResourceString("Arg_CannotHaveNegativeValue");
}

String SR::get_Arg_CannotMixComparisonInfrastructure() {
  return GetResourceString("Arg_CannotMixComparisonInfrastructure");
}

String SR::get_Arg_CannotUnloadAppDomainException() {
  return GetResourceString("Arg_CannotUnloadAppDomainException");
}

String SR::get_Arg_CATypeResolutionFailed() {
  return GetResourceString("Arg_CATypeResolutionFailed");
}

String SR::get_Arg_COMAccess() {
  return GetResourceString("Arg_COMAccess");
}

String SR::get_Arg_COMException() {
  return GetResourceString("Arg_COMException");
}

String SR::get_Arg_COMPropSetPut() {
  return GetResourceString("Arg_COMPropSetPut");
}

String SR::get_Arg_CreatInstAccess() {
  return GetResourceString("Arg_CreatInstAccess");
}

String SR::get_Arg_CryptographyException() {
  return GetResourceString("Arg_CryptographyException");
}

String SR::get_Arg_CustomAttributeFormatException() {
  return GetResourceString("Arg_CustomAttributeFormatException");
}

String SR::get_Arg_DataMisalignedException() {
  return GetResourceString("Arg_DataMisalignedException");
}

String SR::get_Arg_DateTimeRange() {
  return GetResourceString("Arg_DateTimeRange");
}

String SR::get_Arg_DecBitCtor() {
  return GetResourceString("Arg_DecBitCtor");
}

String SR::get_Arg_DirectoryNotFoundException() {
  return GetResourceString("Arg_DirectoryNotFoundException");
}

String SR::get_Arg_DivideByZero() {
  return GetResourceString("Arg_DivideByZero");
}

String SR::get_Arg_DlgtNullInst() {
  return GetResourceString("Arg_DlgtNullInst");
}

String SR::get_Arg_DlgtTargMeth() {
  return GetResourceString("Arg_DlgtTargMeth");
}

String SR::get_Arg_DlgtTypeMis() {
  return GetResourceString("Arg_DlgtTypeMis");
}

String SR::get_Arg_DllNotFoundException() {
  return GetResourceString("Arg_DllNotFoundException");
}

String SR::get_Arg_DuplicateWaitObjectException() {
  return GetResourceString("Arg_DuplicateWaitObjectException");
}

String SR::get_Arg_EHClauseNotClause() {
  return GetResourceString("Arg_EHClauseNotClause");
}

String SR::get_Arg_EHClauseNotFilter() {
  return GetResourceString("Arg_EHClauseNotFilter");
}

String SR::get_Arg_EmptyArray() {
  return GetResourceString("Arg_EmptyArray");
}

String SR::get_Arg_EndOfStreamException() {
  return GetResourceString("Arg_EndOfStreamException");
}

String SR::get_Arg_EntryPointNotFoundException() {
  return GetResourceString("Arg_EntryPointNotFoundException");
}

String SR::get_Arg_EnumAndObjectMustBeSameType() {
  return GetResourceString("Arg_EnumAndObjectMustBeSameType");
}

String SR::get_Arg_EnumFormatUnderlyingTypeAndObjectMustBeSameType() {
  return GetResourceString("Arg_EnumFormatUnderlyingTypeAndObjectMustBeSameType");
}

String SR::get_Arg_EnumIllegalVal() {
  return GetResourceString("Arg_EnumIllegalVal");
}

String SR::get_Arg_EnumLitValueNotFound() {
  return GetResourceString("Arg_EnumLitValueNotFound");
}

String SR::get_Arg_EnumUnderlyingTypeAndObjectMustBeSameType() {
  return GetResourceString("Arg_EnumUnderlyingTypeAndObjectMustBeSameType");
}

String SR::get_Arg_EnumValueNotFound() {
  return GetResourceString("Arg_EnumValueNotFound");
}

String SR::get_Arg_ExecutionEngineException() {
  return GetResourceString("Arg_ExecutionEngineException");
}

String SR::get_Arg_ExternalException() {
  return GetResourceString("Arg_ExternalException");
}

String SR::get_Arg_FieldAccessException() {
  return GetResourceString("Arg_FieldAccessException");
}

String SR::get_Arg_FieldDeclTarget() {
  return GetResourceString("Arg_FieldDeclTarget");
}

String SR::get_Arg_FldGetArgErr() {
  return GetResourceString("Arg_FldGetArgErr");
}

String SR::get_Arg_FldGetPropSet() {
  return GetResourceString("Arg_FldGetPropSet");
}

String SR::get_Arg_FldSetArgErr() {
  return GetResourceString("Arg_FldSetArgErr");
}

String SR::get_Arg_FldSetGet() {
  return GetResourceString("Arg_FldSetGet");
}

String SR::get_Arg_FldSetInvoke() {
  return GetResourceString("Arg_FldSetInvoke");
}

String SR::get_Arg_FldSetPropGet() {
  return GetResourceString("Arg_FldSetPropGet");
}

String SR::get_Arg_FormatException() {
  return GetResourceString("Arg_FormatException");
}

String SR::get_Arg_GenericParameter() {
  return GetResourceString("Arg_GenericParameter");
}

String SR::get_Arg_GetMethNotFnd() {
  return GetResourceString("Arg_GetMethNotFnd");
}

String SR::get_Arg_GuidArrayCtor() {
  return GetResourceString("Arg_GuidArrayCtor");
}

String SR::get_Arg_HandleNotAsync() {
  return GetResourceString("Arg_HandleNotAsync");
}

String SR::get_Arg_HandleNotSync() {
  return GetResourceString("Arg_HandleNotSync");
}

String SR::get_Arg_HexStyleNotSupported() {
  return GetResourceString("Arg_HexStyleNotSupported");
}

String SR::get_Arg_HTCapacityOverflow() {
  return GetResourceString("Arg_HTCapacityOverflow");
}

String SR::get_Arg_IndexMustBeInt() {
  return GetResourceString("Arg_IndexMustBeInt");
}

String SR::get_Arg_IndexOutOfRangeException() {
  return GetResourceString("Arg_IndexOutOfRangeException");
}

String SR::get_Arg_InsufficientExecutionStackException() {
  return GetResourceString("Arg_InsufficientExecutionStackException");
}

String SR::get_Arg_InvalidANSIString() {
  return GetResourceString("Arg_InvalidANSIString");
}

String SR::get_Arg_InvalidBase() {
  return GetResourceString("Arg_InvalidBase");
}

String SR::get_Arg_InvalidCastException() {
  return GetResourceString("Arg_InvalidCastException");
}

String SR::get_Arg_InvalidComObjectException() {
  return GetResourceString("Arg_InvalidComObjectException");
}

String SR::get_Arg_InvalidFilterCriteriaException() {
  return GetResourceString("Arg_InvalidFilterCriteriaException");
}

String SR::get_Arg_InvalidHandle() {
  return GetResourceString("Arg_InvalidHandle");
}

String SR::get_Arg_InvalidHexStyle() {
  return GetResourceString("Arg_InvalidHexStyle");
}

String SR::get_Arg_InvalidNeutralResourcesLanguage_Asm_Culture() {
  return GetResourceString("Arg_InvalidNeutralResourcesLanguage_Asm_Culture");
}

String SR::get_Arg_InvalidNeutralResourcesLanguage_FallbackLoc() {
  return GetResourceString("Arg_InvalidNeutralResourcesLanguage_FallbackLoc");
}

String SR::get_Arg_InvalidSatelliteContract_Asm_Ver() {
  return GetResourceString("Arg_InvalidSatelliteContract_Asm_Ver");
}

String SR::get_Arg_InvalidOleVariantTypeException() {
  return GetResourceString("Arg_InvalidOleVariantTypeException");
}

String SR::get_Arg_InvalidOperationException() {
  return GetResourceString("Arg_InvalidOperationException");
}

String SR::get_Arg_InvalidTypeInRetType() {
  return GetResourceString("Arg_InvalidTypeInRetType");
}

String SR::get_Arg_InvalidTypeInSignature() {
  return GetResourceString("Arg_InvalidTypeInSignature");
}

String SR::get_Arg_IOException() {
  return GetResourceString("Arg_IOException");
}

String SR::get_Arg_KeyNotFound() {
  return GetResourceString("Arg_KeyNotFound");
}

String SR::get_Arg_KeyNotFoundWithKey() {
  return GetResourceString("Arg_KeyNotFoundWithKey");
}

String SR::get_Arg_LongerThanDestArray() {
  return GetResourceString("Arg_LongerThanDestArray");
}

String SR::get_Arg_LongerThanSrcArray() {
  return GetResourceString("Arg_LongerThanSrcArray");
}

String SR::get_Arg_LongerThanSrcString() {
  return GetResourceString("Arg_LongerThanSrcString");
}

String SR::get_Arg_LowerBoundsMustMatch() {
  return GetResourceString("Arg_LowerBoundsMustMatch");
}

String SR::get_Arg_MarshalAsAnyRestriction() {
  return GetResourceString("Arg_MarshalAsAnyRestriction");
}

String SR::get_Arg_MarshalDirectiveException() {
  return GetResourceString("Arg_MarshalDirectiveException");
}

String SR::get_Arg_MethodAccessException() {
  return GetResourceString("Arg_MethodAccessException");
}

String SR::get_Arg_MissingFieldException() {
  return GetResourceString("Arg_MissingFieldException");
}

String SR::get_Arg_MissingManifestResourceException() {
  return GetResourceString("Arg_MissingManifestResourceException");
}

String SR::get_Arg_MissingMemberException() {
  return GetResourceString("Arg_MissingMemberException");
}

String SR::get_Arg_MissingMethodException() {
  return GetResourceString("Arg_MissingMethodException");
}

String SR::get_Arg_MulticastNotSupportedException() {
  return GetResourceString("Arg_MulticastNotSupportedException");
}

String SR::get_Arg_MustBeBoolean() {
  return GetResourceString("Arg_MustBeBoolean");
}

String SR::get_Arg_MustBeByte() {
  return GetResourceString("Arg_MustBeByte");
}

String SR::get_Arg_MustBeChar() {
  return GetResourceString("Arg_MustBeChar");
}

String SR::get_Arg_MustBeDateTime() {
  return GetResourceString("Arg_MustBeDateTime");
}

String SR::get_Arg_MustBeDateTimeOffset() {
  return GetResourceString("Arg_MustBeDateTimeOffset");
}

String SR::get_Arg_MustBeDecimal() {
  return GetResourceString("Arg_MustBeDecimal");
}

String SR::get_Arg_MustBeDelegate() {
  return GetResourceString("Arg_MustBeDelegate");
}

String SR::get_Arg_MustBeDouble() {
  return GetResourceString("Arg_MustBeDouble");
}

String SR::get_Arg_MustBeEnum() {
  return GetResourceString("Arg_MustBeEnum");
}

String SR::get_Arg_MustBeEnumBaseTypeOrEnum() {
  return GetResourceString("Arg_MustBeEnumBaseTypeOrEnum");
}

String SR::get_Arg_MustBeGuid() {
  return GetResourceString("Arg_MustBeGuid");
}

String SR::get_Arg_MustBeInt16() {
  return GetResourceString("Arg_MustBeInt16");
}

String SR::get_Arg_MustBeInt32() {
  return GetResourceString("Arg_MustBeInt32");
}

String SR::get_Arg_MustBeInt64() {
  return GetResourceString("Arg_MustBeInt64");
}

String SR::get_Arg_MustBeIntPtr() {
  return GetResourceString("Arg_MustBeIntPtr");
}

String SR::get_Arg_MustBePointer() {
  return GetResourceString("Arg_MustBePointer");
}

String SR::get_Arg_MustBePrimArray() {
  return GetResourceString("Arg_MustBePrimArray");
}

String SR::get_Arg_MustBeRuntimeAssembly() {
  return GetResourceString("Arg_MustBeRuntimeAssembly");
}

String SR::get_Arg_MustBeSByte() {
  return GetResourceString("Arg_MustBeSByte");
}

String SR::get_Arg_MustBeSingle() {
  return GetResourceString("Arg_MustBeSingle");
}

String SR::get_Arg_MustBeString() {
  return GetResourceString("Arg_MustBeString");
}

String SR::get_Arg_MustBeTimeSpan() {
  return GetResourceString("Arg_MustBeTimeSpan");
}

String SR::get_Arg_MustBeType() {
  return GetResourceString("Arg_MustBeType");
}

String SR::get_Arg_MustBeTrue() {
  return GetResourceString("Arg_MustBeTrue");
}

String SR::get_Arg_MustBeUInt16() {
  return GetResourceString("Arg_MustBeUInt16");
}

String SR::get_Arg_MustBeUInt32() {
  return GetResourceString("Arg_MustBeUInt32");
}

String SR::get_Arg_MustBeUInt64() {
  return GetResourceString("Arg_MustBeUInt64");
}

String SR::get_Arg_MustBeUIntPtr() {
  return GetResourceString("Arg_MustBeUIntPtr");
}

String SR::get_Arg_MustBeVersion() {
  return GetResourceString("Arg_MustBeVersion");
}

String SR::get_Arg_MustContainEnumInfo() {
  return GetResourceString("Arg_MustContainEnumInfo");
}

String SR::get_Arg_NamedParamNull() {
  return GetResourceString("Arg_NamedParamNull");
}

String SR::get_Arg_NamedParamTooBig() {
  return GetResourceString("Arg_NamedParamTooBig");
}

String SR::get_Arg_NDirectBadObject() {
  return GetResourceString("Arg_NDirectBadObject");
}

String SR::get_Arg_Need1DArray() {
  return GetResourceString("Arg_Need1DArray");
}

String SR::get_Arg_Need2DArray() {
  return GetResourceString("Arg_Need2DArray");
}

String SR::get_Arg_Need3DArray() {
  return GetResourceString("Arg_Need3DArray");
}

String SR::get_Arg_NeedAtLeast1Rank() {
  return GetResourceString("Arg_NeedAtLeast1Rank");
}

String SR::get_Arg_NegativeArgCount() {
  return GetResourceString("Arg_NegativeArgCount");
}

String SR::get_Arg_NoAccessSpec() {
  return GetResourceString("Arg_NoAccessSpec");
}

String SR::get_Arg_NoDefCTor() {
  return GetResourceString("Arg_NoDefCTor");
}

String SR::get_Arg_NonZeroLowerBound() {
  return GetResourceString("Arg_NonZeroLowerBound");
}

String SR::get_Arg_NoStaticVirtual() {
  return GetResourceString("Arg_NoStaticVirtual");
}

String SR::get_Arg_NotFiniteNumberException() {
  return GetResourceString("Arg_NotFiniteNumberException");
}

String SR::get_Arg_NotGenericMethodDefinition() {
  return GetResourceString("Arg_NotGenericMethodDefinition");
}

String SR::get_Arg_NotGenericParameter() {
  return GetResourceString("Arg_NotGenericParameter");
}

String SR::get_Arg_NotGenericTypeDefinition() {
  return GetResourceString("Arg_NotGenericTypeDefinition");
}

String SR::get_Arg_NotImplementedException() {
  return GetResourceString("Arg_NotImplementedException");
}

String SR::get_Arg_NotSupportedException() {
  return GetResourceString("Arg_NotSupportedException");
}

String SR::get_Arg_NullReferenceException() {
  return GetResourceString("Arg_NullReferenceException");
}

String SR::get_Arg_ObjObjEx() {
  return GetResourceString("Arg_ObjObjEx");
}

String SR::get_Arg_OleAutDateInvalid() {
  return GetResourceString("Arg_OleAutDateInvalid");
}

String SR::get_Arg_OleAutDateScale() {
  return GetResourceString("Arg_OleAutDateScale");
}

String SR::get_Arg_OverflowException() {
  return GetResourceString("Arg_OverflowException");
}

String SR::get_Arg_ParamName_Name() {
  return GetResourceString("Arg_ParamName_Name");
}

String SR::get_Arg_ParmArraySize() {
  return GetResourceString("Arg_ParmArraySize");
}

String SR::get_Arg_ParmCnt() {
  return GetResourceString("Arg_ParmCnt");
}

String SR::get_Arg_PathEmpty() {
  return GetResourceString("Arg_PathEmpty");
}

String SR::get_Arg_PlatformNotSupported() {
  return GetResourceString("Arg_PlatformNotSupported");
}

String SR::get_Arg_PropSetGet() {
  return GetResourceString("Arg_PropSetGet");
}

String SR::get_Arg_PropSetInvoke() {
  return GetResourceString("Arg_PropSetInvoke");
}

String SR::get_Arg_RankException() {
  return GetResourceString("Arg_RankException");
}

String SR::get_Arg_RankIndices() {
  return GetResourceString("Arg_RankIndices");
}

String SR::get_Arg_RankMultiDimNotSupported() {
  return GetResourceString("Arg_RankMultiDimNotSupported");
}

String SR::get_Arg_RanksAndBounds() {
  return GetResourceString("Arg_RanksAndBounds");
}

String SR::get_Arg_RegGetOverflowBug() {
  return GetResourceString("Arg_RegGetOverflowBug");
}

String SR::get_Arg_RegKeyNotFound() {
  return GetResourceString("Arg_RegKeyNotFound");
}

String SR::get_Arg_RegSubKeyValueAbsent() {
  return GetResourceString("Arg_RegSubKeyValueAbsent");
}

String SR::get_Arg_RegValStrLenBug() {
  return GetResourceString("Arg_RegValStrLenBug");
}

String SR::get_Arg_ResMgrNotResSet() {
  return GetResourceString("Arg_ResMgrNotResSet");
}

String SR::get_Arg_ResourceFileUnsupportedVersion() {
  return GetResourceString("Arg_ResourceFileUnsupportedVersion");
}

String SR::get_Arg_ResourceNameNotExist() {
  return GetResourceString("Arg_ResourceNameNotExist");
}

String SR::get_Arg_SafeArrayRankMismatchException() {
  return GetResourceString("Arg_SafeArrayRankMismatchException");
}

String SR::get_Arg_SafeArrayTypeMismatchException() {
  return GetResourceString("Arg_SafeArrayTypeMismatchException");
}

String SR::get_Arg_SecurityException() {
  return GetResourceString("Arg_SecurityException");
}

String SR::get_SerializationException() {
  return GetResourceString("SerializationException");
}

String SR::get_Arg_SetMethNotFnd() {
  return GetResourceString("Arg_SetMethNotFnd");
}

String SR::get_Arg_StackOverflowException() {
  return GetResourceString("Arg_StackOverflowException");
}

String SR::get_Arg_SurrogatesNotAllowedAsSingleChar() {
  return GetResourceString("Arg_SurrogatesNotAllowedAsSingleChar");
}

String SR::get_Arg_SynchronizationLockException() {
  return GetResourceString("Arg_SynchronizationLockException");
}

String SR::get_Arg_SystemException() {
  return GetResourceString("Arg_SystemException");
}

String SR::get_Arg_TargetInvocationException() {
  return GetResourceString("Arg_TargetInvocationException");
}

String SR::get_Arg_TargetParameterCountException() {
  return GetResourceString("Arg_TargetParameterCountException");
}

String SR::get_Arg_ThreadStartException() {
  return GetResourceString("Arg_ThreadStartException");
}

String SR::get_Arg_ThreadStateException() {
  return GetResourceString("Arg_ThreadStateException");
}

String SR::get_Arg_TimeoutException() {
  return GetResourceString("Arg_TimeoutException");
}

String SR::get_Arg_TypeAccessException() {
  return GetResourceString("Arg_TypeAccessException");
}

String SR::get_Arg_TypedReference_Null() {
  return GetResourceString("Arg_TypedReference_Null");
}

String SR::get_Arg_TypeLoadException() {
  return GetResourceString("Arg_TypeLoadException");
}

String SR::get_Arg_TypeLoadNullStr() {
  return GetResourceString("Arg_TypeLoadNullStr");
}

String SR::get_Arg_TypeRefPrimitve() {
  return GetResourceString("Arg_TypeRefPrimitve");
}

String SR::get_Arg_TypeUnloadedException() {
  return GetResourceString("Arg_TypeUnloadedException");
}

String SR::get_Arg_UnauthorizedAccessException() {
  return GetResourceString("Arg_UnauthorizedAccessException");
}

String SR::get_Arg_UnboundGenField() {
  return GetResourceString("Arg_UnboundGenField");
}

String SR::get_Arg_UnboundGenParam() {
  return GetResourceString("Arg_UnboundGenParam");
}

String SR::get_Arg_UnknownTypeCode() {
  return GetResourceString("Arg_UnknownTypeCode");
}

String SR::get_Arg_VarMissNull() {
  return GetResourceString("Arg_VarMissNull");
}

String SR::get_Arg_VersionString() {
  return GetResourceString("Arg_VersionString");
}

String SR::get_Arg_WrongAsyncResult() {
  return GetResourceString("Arg_WrongAsyncResult");
}

String SR::get_Arg_WrongType() {
  return GetResourceString("Arg_WrongType");
}

String SR::get_Argument_AbsolutePathRequired() {
  return GetResourceString("Argument_AbsolutePathRequired");
}

String SR::get_Argument_AddingDuplicate() {
  return GetResourceString("Argument_AddingDuplicate");
}

String SR::get_Argument_AddingDuplicate__() {
  return GetResourceString("Argument_AddingDuplicate__");
}

String SR::get_Argument_AddingDuplicateWithKey() {
  return GetResourceString("Argument_AddingDuplicateWithKey");
}

String SR::get_Argument_AdjustmentRulesNoNulls() {
  return GetResourceString("Argument_AdjustmentRulesNoNulls");
}

String SR::get_Argument_AdjustmentRulesOutOfOrder() {
  return GetResourceString("Argument_AdjustmentRulesOutOfOrder");
}

String SR::get_Argument_AlreadyBoundOrSyncHandle() {
  return GetResourceString("Argument_AlreadyBoundOrSyncHandle");
}

String SR::get_Argument_ArrayGetInterfaceMap() {
  return GetResourceString("Argument_ArrayGetInterfaceMap");
}

String SR::get_Argument_ArraysInvalid() {
  return GetResourceString("Argument_ArraysInvalid");
}

String SR::get_Argument_AttributeNamesMustBeUnique() {
  return GetResourceString("Argument_AttributeNamesMustBeUnique");
}

String SR::get_Argument_BadConstructor() {
  return GetResourceString("Argument_BadConstructor");
}

String SR::get_Argument_BadConstructorCallConv() {
  return GetResourceString("Argument_BadConstructorCallConv");
}

String SR::get_Argument_BadExceptionCodeGen() {
  return GetResourceString("Argument_BadExceptionCodeGen");
}

String SR::get_Argument_BadFieldForConstructorBuilder() {
  return GetResourceString("Argument_BadFieldForConstructorBuilder");
}

String SR::get_Argument_BadFieldSig() {
  return GetResourceString("Argument_BadFieldSig");
}

String SR::get_Argument_BadFieldType() {
  return GetResourceString("Argument_BadFieldType");
}

String SR::get_Argument_BadFormatSpecifier() {
  return GetResourceString("Argument_BadFormatSpecifier");
}

String SR::get_Argument_BadImageFormatExceptionResolve() {
  return GetResourceString("Argument_BadImageFormatExceptionResolve");
}

String SR::get_Argument_BadLabel() {
  return GetResourceString("Argument_BadLabel");
}

String SR::get_Argument_BadLabelContent() {
  return GetResourceString("Argument_BadLabelContent");
}

String SR::get_Argument_BadNestedTypeFlags() {
  return GetResourceString("Argument_BadNestedTypeFlags");
}

String SR::get_Argument_BadParameterCountsForConstructor() {
  return GetResourceString("Argument_BadParameterCountsForConstructor");
}

String SR::get_Argument_BadParameterTypeForCAB() {
  return GetResourceString("Argument_BadParameterTypeForCAB");
}

String SR::get_Argument_BadPropertyForConstructorBuilder() {
  return GetResourceString("Argument_BadPropertyForConstructorBuilder");
}

String SR::get_Argument_BadSigFormat() {
  return GetResourceString("Argument_BadSigFormat");
}

String SR::get_Argument_BadSizeForData() {
  return GetResourceString("Argument_BadSizeForData");
}

String SR::get_Argument_BadTypeAttrInvalidLayout() {
  return GetResourceString("Argument_BadTypeAttrInvalidLayout");
}

String SR::get_Argument_BadTypeAttrNestedVisibilityOnNonNestedType() {
  return GetResourceString("Argument_BadTypeAttrNestedVisibilityOnNonNestedType");
}

String SR::get_Argument_BadTypeAttrNonNestedVisibilityNestedType() {
  return GetResourceString("Argument_BadTypeAttrNonNestedVisibilityNestedType");
}

String SR::get_Argument_BadTypeAttrReservedBitsSet() {
  return GetResourceString("Argument_BadTypeAttrReservedBitsSet");
}

String SR::get_Argument_BadTypeInCustomAttribute() {
  return GetResourceString("Argument_BadTypeInCustomAttribute");
}

String SR::get_Argument_CannotGetTypeTokenForByRef() {
  return GetResourceString("Argument_CannotGetTypeTokenForByRef");
}

String SR::get_Argument_CannotSetParentToInterface() {
  return GetResourceString("Argument_CannotSetParentToInterface");
}

String SR::get_Argument_CodepageNotSupported() {
  return GetResourceString("Argument_CodepageNotSupported");
}

String SR::get_Argument_CompareOptionOrdinal() {
  return GetResourceString("Argument_CompareOptionOrdinal");
}

String SR::get_Argument_ConflictingDateTimeRoundtripStyles() {
  return GetResourceString("Argument_ConflictingDateTimeRoundtripStyles");
}

String SR::get_Argument_ConflictingDateTimeStyles() {
  return GetResourceString("Argument_ConflictingDateTimeStyles");
}

String SR::get_Argument_ConstantDoesntMatch() {
  return GetResourceString("Argument_ConstantDoesntMatch");
}

String SR::get_Argument_ConstantNotSupported() {
  return GetResourceString("Argument_ConstantNotSupported");
}

String SR::get_Argument_ConstantNull() {
  return GetResourceString("Argument_ConstantNull");
}

String SR::get_Argument_ConstructorNeedGenericDeclaringType() {
  return GetResourceString("Argument_ConstructorNeedGenericDeclaringType");
}

String SR::get_Argument_ConversionOverflow() {
  return GetResourceString("Argument_ConversionOverflow");
}

String SR::get_Argument_ConvertMismatch() {
  return GetResourceString("Argument_ConvertMismatch");
}

String SR::get_Argument_CultureIetfNotSupported() {
  return GetResourceString("Argument_CultureIetfNotSupported");
}

String SR::get_Argument_CultureInvalidIdentifier() {
  return GetResourceString("Argument_CultureInvalidIdentifier");
}

String SR::get_Argument_CultureIsNeutral() {
  return GetResourceString("Argument_CultureIsNeutral");
}

String SR::get_Argument_CultureNotSupported() {
  return GetResourceString("Argument_CultureNotSupported");
}

String SR::get_Argument_CustomAssemblyLoadContextRequestedNameMismatch() {
  return GetResourceString("Argument_CustomAssemblyLoadContextRequestedNameMismatch");
}

String SR::get_Argument_CustomCultureCannotBePassedByNumber() {
  return GetResourceString("Argument_CustomCultureCannotBePassedByNumber");
}

String SR::get_Argument_DateTimeBadBinaryData() {
  return GetResourceString("Argument_DateTimeBadBinaryData");
}

String SR::get_Argument_DateTimeHasTicks() {
  return GetResourceString("Argument_DateTimeHasTicks");
}

String SR::get_Argument_DateTimeHasTimeOfDay() {
  return GetResourceString("Argument_DateTimeHasTimeOfDay");
}

String SR::get_Argument_DateTimeIsInvalid() {
  return GetResourceString("Argument_DateTimeIsInvalid");
}

String SR::get_Argument_DateTimeIsNotAmbiguous() {
  return GetResourceString("Argument_DateTimeIsNotAmbiguous");
}

String SR::get_Argument_DateTimeKindMustBeUnspecified() {
  return GetResourceString("Argument_DateTimeKindMustBeUnspecified");
}

String SR::get_Argument_DateTimeKindMustBeUnspecifiedOrUtc() {
  return GetResourceString("Argument_DateTimeKindMustBeUnspecifiedOrUtc");
}

String SR::get_Argument_DateTimeOffsetInvalidDateTimeStyles() {
  return GetResourceString("Argument_DateTimeOffsetInvalidDateTimeStyles");
}

String SR::get_Argument_DateTimeOffsetIsNotAmbiguous() {
  return GetResourceString("Argument_DateTimeOffsetIsNotAmbiguous");
}

String SR::get_Argument_DestinationTooShort() {
  return GetResourceString("Argument_DestinationTooShort");
}

String SR::get_Argument_DuplicateTypeName() {
  return GetResourceString("Argument_DuplicateTypeName");
}

String SR::get_Argument_EmitWriteLineType() {
  return GetResourceString("Argument_EmitWriteLineType");
}

String SR::get_Argument_EmptyDecString() {
  return GetResourceString("Argument_EmptyDecString");
}

String SR::get_Argument_EmptyName() {
  return GetResourceString("Argument_EmptyName");
}

String SR::get_Argument_EmptyPath() {
  return GetResourceString("Argument_EmptyPath");
}

String SR::get_Argument_EmptyWaithandleArray() {
  return GetResourceString("Argument_EmptyWaithandleArray");
}

String SR::get_Argument_EncoderFallbackNotEmpty() {
  return GetResourceString("Argument_EncoderFallbackNotEmpty");
}

String SR::get_Argument_EncodingConversionOverflowBytes() {
  return GetResourceString("Argument_EncodingConversionOverflowBytes");
}

String SR::get_Argument_EncodingConversionOverflowChars() {
  return GetResourceString("Argument_EncodingConversionOverflowChars");
}

String SR::get_Argument_EncodingNotSupported() {
  return GetResourceString("Argument_EncodingNotSupported");
}

String SR::get_Argument_EnumTypeDoesNotMatch() {
  return GetResourceString("Argument_EnumTypeDoesNotMatch");
}

String SR::get_Argument_FallbackBufferNotEmpty() {
  return GetResourceString("Argument_FallbackBufferNotEmpty");
}

String SR::get_Argument_FieldDeclaringTypeGeneric() {
  return GetResourceString("Argument_FieldDeclaringTypeGeneric");
}

String SR::get_Argument_FieldNeedGenericDeclaringType() {
  return GetResourceString("Argument_FieldNeedGenericDeclaringType");
}

String SR::get_Argument_GenConstraintViolation() {
  return GetResourceString("Argument_GenConstraintViolation");
}

String SR::get_Argument_GenericArgsCount() {
  return GetResourceString("Argument_GenericArgsCount");
}

String SR::get_Argument_GenericsInvalid() {
  return GetResourceString("Argument_GenericsInvalid");
}

String SR::get_Argument_GlobalFunctionHasToBeStatic() {
  return GetResourceString("Argument_GlobalFunctionHasToBeStatic");
}

String SR::get_Argument_HasToBeArrayClass() {
  return GetResourceString("Argument_HasToBeArrayClass");
}

String SR::get_Argument_IdnBadBidi() {
  return GetResourceString("Argument_IdnBadBidi");
}

String SR::get_Argument_IdnBadLabelSize() {
  return GetResourceString("Argument_IdnBadLabelSize");
}

String SR::get_Argument_IdnBadNameSize() {
  return GetResourceString("Argument_IdnBadNameSize");
}

String SR::get_Argument_IdnBadPunycode() {
  return GetResourceString("Argument_IdnBadPunycode");
}

String SR::get_Argument_IdnBadStd3() {
  return GetResourceString("Argument_IdnBadStd3");
}

String SR::get_Argument_IdnIllegalName() {
  return GetResourceString("Argument_IdnIllegalName");
}

String SR::get_Argument_IllegalEnvVarName() {
  return GetResourceString("Argument_IllegalEnvVarName");
}

String SR::get_Argument_IllegalName() {
  return GetResourceString("Argument_IllegalName");
}

String SR::get_Argument_ImplementIComparable() {
  return GetResourceString("Argument_ImplementIComparable");
}

String SR::get_Argument_InvalidAppendMode() {
  return GetResourceString("Argument_InvalidAppendMode");
}

String SR::get_Argument_InvalidArgumentForComparison() {
  return GetResourceString("Argument_InvalidArgumentForComparison");
}

String SR::get_Argument_InvalidArrayLength() {
  return GetResourceString("Argument_InvalidArrayLength");
}

String SR::get_Argument_InvalidArrayType() {
  return GetResourceString("Argument_InvalidArrayType");
}

String SR::get_Argument_InvalidCalendar() {
  return GetResourceString("Argument_InvalidCalendar");
}

String SR::get_Argument_InvalidCharSequence() {
  return GetResourceString("Argument_InvalidCharSequence");
}

String SR::get_Argument_InvalidCharSequenceNoIndex() {
  return GetResourceString("Argument_InvalidCharSequenceNoIndex");
}

String SR::get_Argument_InvalidCodePageBytesIndex() {
  return GetResourceString("Argument_InvalidCodePageBytesIndex");
}

String SR::get_Argument_InvalidCodePageConversionIndex() {
  return GetResourceString("Argument_InvalidCodePageConversionIndex");
}

String SR::get_Argument_InvalidConstructorDeclaringType() {
  return GetResourceString("Argument_InvalidConstructorDeclaringType");
}

String SR::get_Argument_InvalidConstructorInfo() {
  return GetResourceString("Argument_InvalidConstructorInfo");
}

String SR::get_Argument_InvalidCultureName() {
  return GetResourceString("Argument_InvalidCultureName");
}

String SR::get_Argument_InvalidPredefinedCultureName() {
  return GetResourceString("Argument_InvalidPredefinedCultureName");
}

String SR::get_Argument_InvalidDateTimeKind() {
  return GetResourceString("Argument_InvalidDateTimeKind");
}

String SR::get_Argument_InvalidDateTimeStyles() {
  return GetResourceString("Argument_InvalidDateTimeStyles");
}

String SR::get_Argument_InvalidDigitSubstitution() {
  return GetResourceString("Argument_InvalidDigitSubstitution");
}

String SR::get_Argument_InvalidElementName() {
  return GetResourceString("Argument_InvalidElementName");
}

String SR::get_Argument_InvalidElementTag() {
  return GetResourceString("Argument_InvalidElementTag");
}

String SR::get_Argument_InvalidElementText() {
  return GetResourceString("Argument_InvalidElementText");
}

String SR::get_Argument_InvalidElementValue() {
  return GetResourceString("Argument_InvalidElementValue");
}

String SR::get_Argument_InvalidEnum() {
  return GetResourceString("Argument_InvalidEnum");
}

String SR::get_Argument_InvalidEnumValue() {
  return GetResourceString("Argument_InvalidEnumValue");
}

String SR::get_Argument_InvalidFieldDeclaringType() {
  return GetResourceString("Argument_InvalidFieldDeclaringType");
}

String SR::get_Argument_InvalidFileModeAndAccessCombo() {
  return GetResourceString("Argument_InvalidFileModeAndAccessCombo");
}

String SR::get_Argument_InvalidFlag() {
  return GetResourceString("Argument_InvalidFlag");
}

String SR::get_Argument_InvalidGenericInstArray() {
  return GetResourceString("Argument_InvalidGenericInstArray");
}

String SR::get_Argument_InvalidGroupSize() {
  return GetResourceString("Argument_InvalidGroupSize");
}

String SR::get_Argument_InvalidHandle() {
  return GetResourceString("Argument_InvalidHandle");
}

String SR::get_Argument_InvalidHighSurrogate() {
  return GetResourceString("Argument_InvalidHighSurrogate");
}

String SR::get_Argument_InvalidId() {
  return GetResourceString("Argument_InvalidId");
}

String SR::get_Argument_InvalidKindOfTypeForCA() {
  return GetResourceString("Argument_InvalidKindOfTypeForCA");
}

String SR::get_Argument_InvalidLabel() {
  return GetResourceString("Argument_InvalidLabel");
}

String SR::get_Argument_InvalidLowSurrogate() {
  return GetResourceString("Argument_InvalidLowSurrogate");
}

String SR::get_Argument_InvalidMemberForNamedArgument() {
  return GetResourceString("Argument_InvalidMemberForNamedArgument");
}

String SR::get_Argument_InvalidMethodDeclaringType() {
  return GetResourceString("Argument_InvalidMethodDeclaringType");
}

String SR::get_Argument_InvalidName() {
  return GetResourceString("Argument_InvalidName");
}

String SR::get_Argument_InvalidNativeDigitCount() {
  return GetResourceString("Argument_InvalidNativeDigitCount");
}

String SR::get_Argument_InvalidNativeDigitValue() {
  return GetResourceString("Argument_InvalidNativeDigitValue");
}

String SR::get_Argument_InvalidNeutralRegionName() {
  return GetResourceString("Argument_InvalidNeutralRegionName");
}

String SR::get_Argument_InvalidNormalizationForm() {
  return GetResourceString("Argument_InvalidNormalizationForm");
}

String SR::get_Argument_InvalidNumberStyles() {
  return GetResourceString("Argument_InvalidNumberStyles");
}

String SR::get_Argument_InvalidOffLen() {
  return GetResourceString("Argument_InvalidOffLen");
}

String SR::get_Argument_InvalidOpCodeOnDynamicMethod() {
  return GetResourceString("Argument_InvalidOpCodeOnDynamicMethod");
}

String SR::get_Argument_InvalidParameterInfo() {
  return GetResourceString("Argument_InvalidParameterInfo");
}

String SR::get_Argument_InvalidParamInfo() {
  return GetResourceString("Argument_InvalidParamInfo");
}

String SR::get_Argument_InvalidPathChars() {
  return GetResourceString("Argument_InvalidPathChars");
}

String SR::get_Argument_InvalidResourceCultureName() {
  return GetResourceString("Argument_InvalidResourceCultureName");
}

String SR::get_Argument_InvalidSafeBufferOffLen() {
  return GetResourceString("Argument_InvalidSafeBufferOffLen");
}

String SR::get_Argument_InvalidSeekOrigin() {
  return GetResourceString("Argument_InvalidSeekOrigin");
}

String SR::get_Argument_InvalidSerializedString() {
  return GetResourceString("Argument_InvalidSerializedString");
}

String SR::get_Argument_InvalidStartupHookSignature() {
  return GetResourceString("Argument_InvalidStartupHookSignature");
}

String SR::get_Argument_InvalidTimeSpanStyles() {
  return GetResourceString("Argument_InvalidTimeSpanStyles");
}

String SR::get_Argument_InvalidToken() {
  return GetResourceString("Argument_InvalidToken");
}

String SR::get_Argument_InvalidTypeForCA() {
  return GetResourceString("Argument_InvalidTypeForCA");
}

String SR::get_Argument_InvalidTypeForDynamicMethod() {
  return GetResourceString("Argument_InvalidTypeForDynamicMethod");
}

String SR::get_Argument_InvalidTypeName() {
  return GetResourceString("Argument_InvalidTypeName");
}

String SR::get_Argument_InvalidTypeWithPointersNotSupported() {
  return GetResourceString("Argument_InvalidTypeWithPointersNotSupported");
}

String SR::get_Argument_InvalidUnity() {
  return GetResourceString("Argument_InvalidUnity");
}

String SR::get_Argument_LargeInteger() {
  return GetResourceString("Argument_LargeInteger");
}

String SR::get_Argument_LongEnvVarValue() {
  return GetResourceString("Argument_LongEnvVarValue");
}

String SR::get_Argument_MethodDeclaringTypeGeneric() {
  return GetResourceString("Argument_MethodDeclaringTypeGeneric");
}

String SR::get_Argument_MethodDeclaringTypeGenericLcg() {
  return GetResourceString("Argument_MethodDeclaringTypeGenericLcg");
}

String SR::get_Argument_MethodNeedGenericDeclaringType() {
  return GetResourceString("Argument_MethodNeedGenericDeclaringType");
}

String SR::get_Argument_MinMaxValue() {
  return GetResourceString("Argument_MinMaxValue");
}

String SR::get_Argument_MismatchedArrays() {
  return GetResourceString("Argument_MismatchedArrays");
}

String SR::get_Argument_MissingDefaultConstructor() {
  return GetResourceString("Argument_MissingDefaultConstructor");
}

String SR::get_Argument_MustBeFalse() {
  return GetResourceString("Argument_MustBeFalse");
}

String SR::get_Argument_MustBeRuntimeAssembly() {
  return GetResourceString("Argument_MustBeRuntimeAssembly");
}

String SR::get_Argument_MustBeRuntimeFieldInfo() {
  return GetResourceString("Argument_MustBeRuntimeFieldInfo");
}

String SR::get_Argument_MustBeRuntimeMethodInfo() {
  return GetResourceString("Argument_MustBeRuntimeMethodInfo");
}

String SR::get_Argument_MustBeRuntimeReflectionObject() {
  return GetResourceString("Argument_MustBeRuntimeReflectionObject");
}

String SR::get_Argument_MustBeRuntimeType() {
  return GetResourceString("Argument_MustBeRuntimeType");
}

String SR::get_Argument_MustBeTypeBuilder() {
  return GetResourceString("Argument_MustBeTypeBuilder");
}

String SR::get_Argument_MustHaveAttributeBaseClass() {
  return GetResourceString("Argument_MustHaveAttributeBaseClass");
}

String SR::get_Argument_NativeOverlappedAlreadyFree() {
  return GetResourceString("Argument_NativeOverlappedAlreadyFree");
}

String SR::get_Argument_NativeOverlappedWrongBoundHandle() {
  return GetResourceString("Argument_NativeOverlappedWrongBoundHandle");
}

String SR::get_Argument_NeedGenericMethodDefinition() {
  return GetResourceString("Argument_NeedGenericMethodDefinition");
}

String SR::get_Argument_NeedNonGenericType() {
  return GetResourceString("Argument_NeedNonGenericType");
}

String SR::get_Argument_NeedStructWithNoRefs() {
  return GetResourceString("Argument_NeedStructWithNoRefs");
}

String SR::get_Argument_NeverValidGenericArgument() {
  return GetResourceString("Argument_NeverValidGenericArgument");
}

String SR::get_Argument_NoEra() {
  return GetResourceString("Argument_NoEra");
}

String SR::get_Argument_NoRegionInvariantCulture() {
  return GetResourceString("Argument_NoRegionInvariantCulture");
}

String SR::get_Argument_NotAWritableProperty() {
  return GetResourceString("Argument_NotAWritableProperty");
}

String SR::get_Argument_NotEnoughBytesToRead() {
  return GetResourceString("Argument_NotEnoughBytesToRead");
}

String SR::get_Argument_NotEnoughBytesToWrite() {
  return GetResourceString("Argument_NotEnoughBytesToWrite");
}

String SR::get_Argument_NotEnoughGenArguments() {
  return GetResourceString("Argument_NotEnoughGenArguments");
}

String SR::get_Argument_NotExceptionType() {
  return GetResourceString("Argument_NotExceptionType");
}

String SR::get_Argument_NotInExceptionBlock() {
  return GetResourceString("Argument_NotInExceptionBlock");
}

String SR::get_Argument_NotMethodCallOpcode() {
  return GetResourceString("Argument_NotMethodCallOpcode");
}

String SR::get_Argument_NotSerializable() {
  return GetResourceString("Argument_NotSerializable");
}

String SR::get_Argument_ObjNotComObject() {
  return GetResourceString("Argument_ObjNotComObject");
}

String SR::get_Argument_OffsetAndCapacityOutOfBounds() {
  return GetResourceString("Argument_OffsetAndCapacityOutOfBounds");
}

String SR::get_Argument_OffsetLocalMismatch() {
  return GetResourceString("Argument_OffsetLocalMismatch");
}

String SR::get_Argument_OffsetOfFieldNotFound() {
  return GetResourceString("Argument_OffsetOfFieldNotFound");
}

String SR::get_Argument_OffsetOutOfRange() {
  return GetResourceString("Argument_OffsetOutOfRange");
}

String SR::get_Argument_OffsetPrecision() {
  return GetResourceString("Argument_OffsetPrecision");
}

String SR::get_Argument_OffsetUtcMismatch() {
  return GetResourceString("Argument_OffsetUtcMismatch");
}

String SR::get_Argument_OneOfCulturesNotSupported() {
  return GetResourceString("Argument_OneOfCulturesNotSupported");
}

String SR::get_Argument_OnlyMscorlib() {
  return GetResourceString("Argument_OnlyMscorlib");
}

String SR::get_Argument_OutOfOrderDateTimes() {
  return GetResourceString("Argument_OutOfOrderDateTimes");
}

String SR::get_Argument_PathEmpty() {
  return GetResourceString("Argument_PathEmpty");
}

String SR::get_Argument_PreAllocatedAlreadyAllocated() {
  return GetResourceString("Argument_PreAllocatedAlreadyAllocated");
}

String SR::get_Argument_RecursiveFallback() {
  return GetResourceString("Argument_RecursiveFallback");
}

String SR::get_Argument_RecursiveFallbackBytes() {
  return GetResourceString("Argument_RecursiveFallbackBytes");
}

String SR::get_Argument_RedefinedLabel() {
  return GetResourceString("Argument_RedefinedLabel");
}

String SR::get_Argument_ResolveField() {
  return GetResourceString("Argument_ResolveField");
}

String SR::get_Argument_ResolveFieldHandle() {
  return GetResourceString("Argument_ResolveFieldHandle");
}

String SR::get_Argument_ResolveMember() {
  return GetResourceString("Argument_ResolveMember");
}

String SR::get_Argument_ResolveMethod() {
  return GetResourceString("Argument_ResolveMethod");
}

String SR::get_Argument_ResolveMethodHandle() {
  return GetResourceString("Argument_ResolveMethodHandle");
}

String SR::get_Argument_ResolveModuleType() {
  return GetResourceString("Argument_ResolveModuleType");
}

String SR::get_Argument_ResolveString() {
  return GetResourceString("Argument_ResolveString");
}

String SR::get_Argument_ResolveType() {
  return GetResourceString("Argument_ResolveType");
}

String SR::get_Argument_ResultCalendarRange() {
  return GetResourceString("Argument_ResultCalendarRange");
}

String SR::get_Argument_SemaphoreInitialMaximum() {
  return GetResourceString("Argument_SemaphoreInitialMaximum");
}

String SR::get_Argument_ShouldNotSpecifyExceptionType() {
  return GetResourceString("Argument_ShouldNotSpecifyExceptionType");
}

String SR::get_Argument_ShouldOnlySetVisibilityFlags() {
  return GetResourceString("Argument_ShouldOnlySetVisibilityFlags");
}

String SR::get_Argument_SigIsFinalized() {
  return GetResourceString("Argument_SigIsFinalized");
}

String SR::get_Argument_StreamNotReadable() {
  return GetResourceString("Argument_StreamNotReadable");
}

String SR::get_Argument_StreamNotWritable() {
  return GetResourceString("Argument_StreamNotWritable");
}

String SR::get_Argument_StringFirstCharIsZero() {
  return GetResourceString("Argument_StringFirstCharIsZero");
}

String SR::get_Argument_StringZeroLength() {
  return GetResourceString("Argument_StringZeroLength");
}

String SR::get_Argument_TimeSpanHasSeconds() {
  return GetResourceString("Argument_TimeSpanHasSeconds");
}

String SR::get_Argument_ToExclusiveLessThanFromExclusive() {
  return GetResourceString("Argument_ToExclusiveLessThanFromExclusive");
}

String SR::get_Argument_TooManyFinallyClause() {
  return GetResourceString("Argument_TooManyFinallyClause");
}

String SR::get_Argument_TransitionTimesAreIdentical() {
  return GetResourceString("Argument_TransitionTimesAreIdentical");
}

String SR::get_Argument_TypedReferenceInvalidField() {
  return GetResourceString("Argument_TypedReferenceInvalidField");
}

String SR::get_Argument_TypeMustNotBeComImport() {
  return GetResourceString("Argument_TypeMustNotBeComImport");
}

String SR::get_Argument_TypeNameTooLong() {
  return GetResourceString("Argument_TypeNameTooLong");
}

String SR::get_Argument_TypeNotComObject() {
  return GetResourceString("Argument_TypeNotComObject");
}

String SR::get_Argument_TypeNotValid() {
  return GetResourceString("Argument_TypeNotValid");
}

String SR::get_Argument_UnclosedExceptionBlock() {
  return GetResourceString("Argument_UnclosedExceptionBlock");
}

String SR::get_Argument_UnknownUnmanagedCallConv() {
  return GetResourceString("Argument_UnknownUnmanagedCallConv");
}

String SR::get_Argument_UnmanagedMemAccessorWrapAround() {
  return GetResourceString("Argument_UnmanagedMemAccessorWrapAround");
}

String SR::get_Argument_UnmatchedMethodForLocal() {
  return GetResourceString("Argument_UnmatchedMethodForLocal");
}

String SR::get_Argument_UnmatchingSymScope() {
  return GetResourceString("Argument_UnmatchingSymScope");
}

String SR::get_Argument_UTCOutOfRange() {
  return GetResourceString("Argument_UTCOutOfRange");
}

String SR::get_ArgumentException_BadMethodImplBody() {
  return GetResourceString("ArgumentException_BadMethodImplBody");
}

String SR::get_ArgumentException_BufferNotFromPool() {
  return GetResourceString("ArgumentException_BufferNotFromPool");
}

String SR::get_ArgumentException_OtherNotArrayOfCorrectLength() {
  return GetResourceString("ArgumentException_OtherNotArrayOfCorrectLength");
}

String SR::get_ArgumentException_NotIsomorphic() {
  return GetResourceString("ArgumentException_NotIsomorphic");
}

String SR::get_ArgumentException_TupleIncorrectType() {
  return GetResourceString("ArgumentException_TupleIncorrectType");
}

String SR::get_ArgumentException_TupleLastArgumentNotATuple() {
  return GetResourceString("ArgumentException_TupleLastArgumentNotATuple");
}

String SR::get_ArgumentException_ValueTupleIncorrectType() {
  return GetResourceString("ArgumentException_ValueTupleIncorrectType");
}

String SR::get_ArgumentException_ValueTupleLastArgumentNotAValueTuple() {
  return GetResourceString("ArgumentException_ValueTupleLastArgumentNotAValueTuple");
}

String SR::get_ArgumentNull_Array() {
  return GetResourceString("ArgumentNull_Array");
}

String SR::get_ArgumentNull_ArrayElement() {
  return GetResourceString("ArgumentNull_ArrayElement");
}

String SR::get_ArgumentNull_ArrayValue() {
  return GetResourceString("ArgumentNull_ArrayValue");
}

String SR::get_ArgumentNull_Assembly() {
  return GetResourceString("ArgumentNull_Assembly");
}

String SR::get_ArgumentNull_AssemblyNameName() {
  return GetResourceString("ArgumentNull_AssemblyNameName");
}

String SR::get_ArgumentNull_Buffer() {
  return GetResourceString("ArgumentNull_Buffer");
}

String SR::get_ArgumentNull_Child() {
  return GetResourceString("ArgumentNull_Child");
}

String SR::get_ArgumentNull_Collection() {
  return GetResourceString("ArgumentNull_Collection");
}

String SR::get_ArgumentNull_Dictionary() {
  return GetResourceString("ArgumentNull_Dictionary");
}

String SR::get_ArgumentNull_Generic() {
  return GetResourceString("ArgumentNull_Generic");
}

String SR::get_ArgumentNull_Key() {
  return GetResourceString("ArgumentNull_Key");
}

String SR::get_ArgumentNull_Path() {
  return GetResourceString("ArgumentNull_Path");
}

String SR::get_ArgumentNull_SafeHandle() {
  return GetResourceString("ArgumentNull_SafeHandle");
}

String SR::get_ArgumentNull_Stream() {
  return GetResourceString("ArgumentNull_Stream");
}

String SR::get_ArgumentNull_String() {
  return GetResourceString("ArgumentNull_String");
}

String SR::get_ArgumentNull_Type() {
  return GetResourceString("ArgumentNull_Type");
}

String SR::get_ArgumentNull_Waithandles() {
  return GetResourceString("ArgumentNull_Waithandles");
}

String SR::get_ArgumentOutOfRange_ActualValue() {
  return GetResourceString("ArgumentOutOfRange_ActualValue");
}

String SR::get_ArgumentOutOfRange_AddValue() {
  return GetResourceString("ArgumentOutOfRange_AddValue");
}

String SR::get_ArgumentOutOfRange_ArrayLB() {
  return GetResourceString("ArgumentOutOfRange_ArrayLB");
}

String SR::get_ArgumentOutOfRange_BadHourMinuteSecond() {
  return GetResourceString("ArgumentOutOfRange_BadHourMinuteSecond");
}

String SR::get_ArgumentOutOfRange_BadYearMonthDay() {
  return GetResourceString("ArgumentOutOfRange_BadYearMonthDay");
}

String SR::get_ArgumentOutOfRange_BiggerThanCollection() {
  return GetResourceString("ArgumentOutOfRange_BiggerThanCollection");
}

String SR::get_ArgumentOutOfRange_BinaryReaderFillBuffer() {
  return GetResourceString("ArgumentOutOfRange_BinaryReaderFillBuffer");
}

String SR::get_ArgumentOutOfRange_Bounds_Lower_Upper() {
  return GetResourceString("ArgumentOutOfRange_Bounds_Lower_Upper");
}

String SR::get_ArgumentOutOfRange_CalendarRange() {
  return GetResourceString("ArgumentOutOfRange_CalendarRange");
}

String SR::get_ArgumentOutOfRange_Capacity() {
  return GetResourceString("ArgumentOutOfRange_Capacity");
}

String SR::get_ArgumentOutOfRange_Count() {
  return GetResourceString("ArgumentOutOfRange_Count");
}

String SR::get_ArgumentOutOfRange_DateArithmetic() {
  return GetResourceString("ArgumentOutOfRange_DateArithmetic");
}

String SR::get_ArgumentOutOfRange_DateTimeBadMonths() {
  return GetResourceString("ArgumentOutOfRange_DateTimeBadMonths");
}

String SR::get_ArgumentOutOfRange_DateTimeBadTicks() {
  return GetResourceString("ArgumentOutOfRange_DateTimeBadTicks");
}

String SR::get_ArgumentOutOfRange_DateTimeBadYears() {
  return GetResourceString("ArgumentOutOfRange_DateTimeBadYears");
}

String SR::get_ArgumentOutOfRange_Day() {
  return GetResourceString("ArgumentOutOfRange_Day");
}

String SR::get_ArgumentOutOfRange_DayOfWeek() {
  return GetResourceString("ArgumentOutOfRange_DayOfWeek");
}

String SR::get_ArgumentOutOfRange_DayParam() {
  return GetResourceString("ArgumentOutOfRange_DayParam");
}

String SR::get_ArgumentOutOfRange_DecimalRound() {
  return GetResourceString("ArgumentOutOfRange_DecimalRound");
}

String SR::get_ArgumentOutOfRange_DecimalScale() {
  return GetResourceString("ArgumentOutOfRange_DecimalScale");
}

String SR::get_ArgumentOutOfRange_EndIndexStartIndex() {
  return GetResourceString("ArgumentOutOfRange_EndIndexStartIndex");
}

String SR::get_ArgumentOutOfRange_Enum() {
  return GetResourceString("ArgumentOutOfRange_Enum");
}

String SR::get_ArgumentOutOfRange_Era() {
  return GetResourceString("ArgumentOutOfRange_Era");
}

String SR::get_ArgumentOutOfRange_FileLengthTooBig() {
  return GetResourceString("ArgumentOutOfRange_FileLengthTooBig");
}

String SR::get_ArgumentOutOfRange_FileTimeInvalid() {
  return GetResourceString("ArgumentOutOfRange_FileTimeInvalid");
}

String SR::get_ArgumentOutOfRange_GenericPositive() {
  return GetResourceString("ArgumentOutOfRange_GenericPositive");
}

String SR::get_ArgumentOutOfRange_GetByteCountOverflow() {
  return GetResourceString("ArgumentOutOfRange_GetByteCountOverflow");
}

String SR::get_ArgumentOutOfRange_GetCharCountOverflow() {
  return GetResourceString("ArgumentOutOfRange_GetCharCountOverflow");
}

String SR::get_ArgumentOutOfRange_HashtableLoadFactor() {
  return GetResourceString("ArgumentOutOfRange_HashtableLoadFactor");
}

String SR::get_ArgumentOutOfRange_HugeArrayNotSupported() {
  return GetResourceString("ArgumentOutOfRange_HugeArrayNotSupported");
}

String SR::get_ArgumentOutOfRange_Index() {
  return GetResourceString("ArgumentOutOfRange_Index");
}

String SR::get_ArgumentOutOfRange_IndexCount() {
  return GetResourceString("ArgumentOutOfRange_IndexCount");
}

String SR::get_ArgumentOutOfRange_IndexCountBuffer() {
  return GetResourceString("ArgumentOutOfRange_IndexCountBuffer");
}

String SR::get_ArgumentOutOfRange_IndexLength() {
  return GetResourceString("ArgumentOutOfRange_IndexLength");
}

String SR::get_ArgumentOutOfRange_IndexString() {
  return GetResourceString("ArgumentOutOfRange_IndexString");
}

String SR::get_ArgumentOutOfRange_InvalidEraValue() {
  return GetResourceString("ArgumentOutOfRange_InvalidEraValue");
}

String SR::get_ArgumentOutOfRange_InvalidHighSurrogate() {
  return GetResourceString("ArgumentOutOfRange_InvalidHighSurrogate");
}

String SR::get_ArgumentOutOfRange_InvalidLowSurrogate() {
  return GetResourceString("ArgumentOutOfRange_InvalidLowSurrogate");
}

String SR::get_ArgumentOutOfRange_InvalidUTF32() {
  return GetResourceString("ArgumentOutOfRange_InvalidUTF32");
}

String SR::get_ArgumentOutOfRange_Length() {
  return GetResourceString("ArgumentOutOfRange_Length");
}

String SR::get_ArgumentOutOfRange_LengthGreaterThanCapacity() {
  return GetResourceString("ArgumentOutOfRange_LengthGreaterThanCapacity");
}

String SR::get_ArgumentOutOfRange_LengthTooLarge() {
  return GetResourceString("ArgumentOutOfRange_LengthTooLarge");
}

String SR::get_ArgumentOutOfRange_LessEqualToIntegerMaxVal() {
  return GetResourceString("ArgumentOutOfRange_LessEqualToIntegerMaxVal");
}

String SR::get_ArgumentOutOfRange_ListInsert() {
  return GetResourceString("ArgumentOutOfRange_ListInsert");
}

String SR::get_ArgumentOutOfRange_Month() {
  return GetResourceString("ArgumentOutOfRange_Month");
}

String SR::get_ArgumentOutOfRange_MonthParam() {
  return GetResourceString("ArgumentOutOfRange_MonthParam");
}

String SR::get_ArgumentOutOfRange_MustBeNonNegInt32() {
  return GetResourceString("ArgumentOutOfRange_MustBeNonNegInt32");
}

String SR::get_ArgumentOutOfRange_MustBeNonNegNum() {
  return GetResourceString("ArgumentOutOfRange_MustBeNonNegNum");
}

String SR::get_ArgumentOutOfRange_MustBePositive() {
  return GetResourceString("ArgumentOutOfRange_MustBePositive");
}

String SR::get_ArgumentOutOfRange_NeedNonNegNum() {
  return GetResourceString("ArgumentOutOfRange_NeedNonNegNum");
}

String SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1() {
  return GetResourceString("ArgumentOutOfRange_NeedNonNegOrNegative1");
}

String SR::get_ArgumentOutOfRange_NeedPosNum() {
  return GetResourceString("ArgumentOutOfRange_NeedPosNum");
}

String SR::get_ArgumentOutOfRange_NeedValidId() {
  return GetResourceString("ArgumentOutOfRange_NeedValidId");
}

String SR::get_ArgumentOutOfRange_NegativeCapacity() {
  return GetResourceString("ArgumentOutOfRange_NegativeCapacity");
}

String SR::get_ArgumentOutOfRange_NegativeCount() {
  return GetResourceString("ArgumentOutOfRange_NegativeCount");
}

String SR::get_ArgumentOutOfRange_NegativeLength() {
  return GetResourceString("ArgumentOutOfRange_NegativeLength");
}

String SR::get_ArgumentOutOfRange_OffsetLength() {
  return GetResourceString("ArgumentOutOfRange_OffsetLength");
}

String SR::get_ArgumentOutOfRange_OffsetOut() {
  return GetResourceString("ArgumentOutOfRange_OffsetOut");
}

String SR::get_ArgumentOutOfRange_ParamSequence() {
  return GetResourceString("ArgumentOutOfRange_ParamSequence");
}

String SR::get_ArgumentOutOfRange_PartialWCHAR() {
  return GetResourceString("ArgumentOutOfRange_PartialWCHAR");
}

String SR::get_ArgumentOutOfRange_PeriodTooLarge() {
  return GetResourceString("ArgumentOutOfRange_PeriodTooLarge");
}

String SR::get_ArgumentOutOfRange_PositionLessThanCapacityRequired() {
  return GetResourceString("ArgumentOutOfRange_PositionLessThanCapacityRequired");
}

String SR::get_ArgumentOutOfRange_Range() {
  return GetResourceString("ArgumentOutOfRange_Range");
}

String SR::get_ArgumentOutOfRange_RoundingDigits() {
  return GetResourceString("ArgumentOutOfRange_RoundingDigits");
}

String SR::get_ArgumentOutOfRange_SmallCapacity() {
  return GetResourceString("ArgumentOutOfRange_SmallCapacity");
}

String SR::get_ArgumentOutOfRange_SmallMaxCapacity() {
  return GetResourceString("ArgumentOutOfRange_SmallMaxCapacity");
}

String SR::get_ArgumentOutOfRange_StartIndex() {
  return GetResourceString("ArgumentOutOfRange_StartIndex");
}

String SR::get_ArgumentOutOfRange_StartIndexLargerThanLength() {
  return GetResourceString("ArgumentOutOfRange_StartIndexLargerThanLength");
}

String SR::get_ArgumentOutOfRange_StartIndexLessThanLength() {
  return GetResourceString("ArgumentOutOfRange_StartIndexLessThanLength");
}

String SR::get_ArgumentOutOfRange_StreamLength() {
  return GetResourceString("ArgumentOutOfRange_StreamLength");
}

String SR::get_ArgumentOutOfRange_TimeoutTooLarge() {
  return GetResourceString("ArgumentOutOfRange_TimeoutTooLarge");
}

String SR::get_ArgumentOutOfRange_UIntPtrMax() {
  return GetResourceString("ArgumentOutOfRange_UIntPtrMax");
}

String SR::get_ArgumentOutOfRange_UnmanagedMemStreamLength() {
  return GetResourceString("ArgumentOutOfRange_UnmanagedMemStreamLength");
}

String SR::get_ArgumentOutOfRange_UnmanagedMemStreamWrapAround() {
  return GetResourceString("ArgumentOutOfRange_UnmanagedMemStreamWrapAround");
}

String SR::get_ArgumentOutOfRange_UtcOffset() {
  return GetResourceString("ArgumentOutOfRange_UtcOffset");
}

String SR::get_ArgumentOutOfRange_UtcOffsetAndDaylightDelta() {
  return GetResourceString("ArgumentOutOfRange_UtcOffsetAndDaylightDelta");
}

String SR::get_ArgumentOutOfRange_Version() {
  return GetResourceString("ArgumentOutOfRange_Version");
}

String SR::get_ArgumentOutOfRange_Week() {
  return GetResourceString("ArgumentOutOfRange_Week");
}

String SR::get_ArgumentOutOfRange_Year() {
  return GetResourceString("ArgumentOutOfRange_Year");
}

String SR::get_Arithmetic_NaN() {
  return GetResourceString("Arithmetic_NaN");
}

String SR::get_ArrayTypeMismatch_ConstrainedCopy() {
  return GetResourceString("ArrayTypeMismatch_ConstrainedCopy");
}

String SR::get_AssemblyLoadContext_Unload_CannotUnloadIfNotCollectible() {
  return GetResourceString("AssemblyLoadContext_Unload_CannotUnloadIfNotCollectible");
}

String SR::get_AssemblyLoadContext_Verify_NotUnloading() {
  return GetResourceString("AssemblyLoadContext_Verify_NotUnloading");
}

String SR::get_AssertionFailed() {
  return GetResourceString("AssertionFailed");
}

String SR::get_AssertionFailed_Cnd() {
  return GetResourceString("AssertionFailed_Cnd");
}

String SR::get_AssumptionFailed() {
  return GetResourceString("AssumptionFailed");
}

String SR::get_AssumptionFailed_Cnd() {
  return GetResourceString("AssumptionFailed_Cnd");
}

String SR::get_AsyncMethodBuilder_InstanceNotInitialized() {
  return GetResourceString("AsyncMethodBuilder_InstanceNotInitialized");
}

String SR::get_BadImageFormat_BadILFormat() {
  return GetResourceString("BadImageFormat_BadILFormat");
}

String SR::get_BadImageFormat_InvalidType() {
  return GetResourceString("BadImageFormat_InvalidType");
}

String SR::get_BadImageFormat_NegativeStringLength() {
  return GetResourceString("BadImageFormat_NegativeStringLength");
}

String SR::get_BadImageFormat_ParameterSignatureMismatch() {
  return GetResourceString("BadImageFormat_ParameterSignatureMismatch");
}

String SR::get_BadImageFormat_ResType_SerBlobMismatch() {
  return GetResourceString("BadImageFormat_ResType_SerBlobMismatch");
}

String SR::get_BadImageFormat_ResourceDataLengthInvalid() {
  return GetResourceString("BadImageFormat_ResourceDataLengthInvalid");
}

String SR::get_BadImageFormat_ResourceNameCorrupted() {
  return GetResourceString("BadImageFormat_ResourceNameCorrupted");
}

String SR::get_BadImageFormat_ResourceNameCorrupted_NameIndex() {
  return GetResourceString("BadImageFormat_ResourceNameCorrupted_NameIndex");
}

String SR::get_BadImageFormat_ResourcesDataInvalidOffset() {
  return GetResourceString("BadImageFormat_ResourcesDataInvalidOffset");
}

String SR::get_BadImageFormat_ResourcesHeaderCorrupted() {
  return GetResourceString("BadImageFormat_ResourcesHeaderCorrupted");
}

String SR::get_BadImageFormat_ResourcesIndexTooLong() {
  return GetResourceString("BadImageFormat_ResourcesIndexTooLong");
}

String SR::get_BadImageFormat_ResourcesNameInvalidOffset() {
  return GetResourceString("BadImageFormat_ResourcesNameInvalidOffset");
}

String SR::get_BadImageFormat_ResourcesNameTooLong() {
  return GetResourceString("BadImageFormat_ResourcesNameTooLong");
}

String SR::get_BadImageFormat_TypeMismatch() {
  return GetResourceString("BadImageFormat_TypeMismatch");
}

String SR::get_CancellationToken_CreateLinkedToken_TokensIsEmpty() {
  return GetResourceString("CancellationToken_CreateLinkedToken_TokensIsEmpty");
}

String SR::get_CancellationTokenSource_Disposed() {
  return GetResourceString("CancellationTokenSource_Disposed");
}

String SR::get_ConcurrentCollection_SyncRoot_NotSupported() {
  return GetResourceString("ConcurrentCollection_SyncRoot_NotSupported");
}

String SR::get_EventSource_AbstractMustNotDeclareEventMethods() {
  return GetResourceString("EventSource_AbstractMustNotDeclareEventMethods");
}

String SR::get_EventSource_AbstractMustNotDeclareKTOC() {
  return GetResourceString("EventSource_AbstractMustNotDeclareKTOC");
}

String SR::get_EventSource_AddScalarOutOfRange() {
  return GetResourceString("EventSource_AddScalarOutOfRange");
}

String SR::get_EventSource_BadHexDigit() {
  return GetResourceString("EventSource_BadHexDigit");
}

String SR::get_EventSource_ChannelTypeDoesNotMatchEventChannelValue() {
  return GetResourceString("EventSource_ChannelTypeDoesNotMatchEventChannelValue");
}

String SR::get_EventSource_DataDescriptorsOutOfRange() {
  return GetResourceString("EventSource_DataDescriptorsOutOfRange");
}

String SR::get_EventSource_DuplicateStringKey() {
  return GetResourceString("EventSource_DuplicateStringKey");
}

String SR::get_EventSource_EnumKindMismatch() {
  return GetResourceString("EventSource_EnumKindMismatch");
}

String SR::get_EventSource_EvenHexDigits() {
  return GetResourceString("EventSource_EvenHexDigits");
}

String SR::get_EventSource_EventChannelOutOfRange() {
  return GetResourceString("EventSource_EventChannelOutOfRange");
}

String SR::get_EventSource_EventIdReused() {
  return GetResourceString("EventSource_EventIdReused");
}

String SR::get_EventSource_EventMustHaveTaskIfNonDefaultOpcode() {
  return GetResourceString("EventSource_EventMustHaveTaskIfNonDefaultOpcode");
}

String SR::get_EventSource_EventMustNotBeExplicitImplementation() {
  return GetResourceString("EventSource_EventMustNotBeExplicitImplementation");
}

String SR::get_EventSource_EventNameReused() {
  return GetResourceString("EventSource_EventNameReused");
}

String SR::get_EventSource_EventParametersMismatch() {
  return GetResourceString("EventSource_EventParametersMismatch");
}

String SR::get_EventSource_EventSourceGuidInUse() {
  return GetResourceString("EventSource_EventSourceGuidInUse");
}

String SR::get_EventSource_EventTooBig() {
  return GetResourceString("EventSource_EventTooBig");
}

String SR::get_EventSource_EventWithAdminChannelMustHaveMessage() {
  return GetResourceString("EventSource_EventWithAdminChannelMustHaveMessage");
}

String SR::get_EventSource_IllegalKeywordsValue() {
  return GetResourceString("EventSource_IllegalKeywordsValue");
}

String SR::get_EventSource_IllegalOpcodeValue() {
  return GetResourceString("EventSource_IllegalOpcodeValue");
}

String SR::get_EventSource_IllegalTaskValue() {
  return GetResourceString("EventSource_IllegalTaskValue");
}

String SR::get_EventSource_IllegalValue() {
  return GetResourceString("EventSource_IllegalValue");
}

String SR::get_EventSource_IncorrentlyAuthoredTypeInfo() {
  return GetResourceString("EventSource_IncorrentlyAuthoredTypeInfo");
}

String SR::get_EventSource_InvalidCommand() {
  return GetResourceString("EventSource_InvalidCommand");
}

String SR::get_EventSource_InvalidEventFormat() {
  return GetResourceString("EventSource_InvalidEventFormat");
}

String SR::get_EventSource_KeywordCollision() {
  return GetResourceString("EventSource_KeywordCollision");
}

String SR::get_EventSource_KeywordNeedPowerOfTwo() {
  return GetResourceString("EventSource_KeywordNeedPowerOfTwo");
}

String SR::get_EventSource_ListenerCreatedInsideCallback() {
  return GetResourceString("EventSource_ListenerCreatedInsideCallback");
}

String SR::get_EventSource_ListenerNotFound() {
  return GetResourceString("EventSource_ListenerNotFound");
}

String SR::get_EventSource_ListenerWriteFailure() {
  return GetResourceString("EventSource_ListenerWriteFailure");
}

String SR::get_EventSource_MaxChannelExceeded() {
  return GetResourceString("EventSource_MaxChannelExceeded");
}

String SR::get_EventSource_MismatchIdToWriteEvent() {
  return GetResourceString("EventSource_MismatchIdToWriteEvent");
}

String SR::get_EventSource_NeedGuid() {
  return GetResourceString("EventSource_NeedGuid");
}

String SR::get_EventSource_NeedName() {
  return GetResourceString("EventSource_NeedName");
}

String SR::get_EventSource_NeedPositiveId() {
  return GetResourceString("EventSource_NeedPositiveId");
}

String SR::get_EventSource_NoFreeBuffers() {
  return GetResourceString("EventSource_NoFreeBuffers");
}

String SR::get_EventSource_NonCompliantTypeError() {
  return GetResourceString("EventSource_NonCompliantTypeError");
}

String SR::get_EventSource_NoRelatedActivityId() {
  return GetResourceString("EventSource_NoRelatedActivityId");
}

String SR::get_EventSource_NotSupportedArrayOfBinary() {
  return GetResourceString("EventSource_NotSupportedArrayOfBinary");
}

String SR::get_EventSource_NotSupportedArrayOfNil() {
  return GetResourceString("EventSource_NotSupportedArrayOfNil");
}

String SR::get_EventSource_NotSupportedArrayOfNullTerminatedString() {
  return GetResourceString("EventSource_NotSupportedArrayOfNullTerminatedString");
}

String SR::get_EventSource_NotSupportedNestedArraysEnums() {
  return GetResourceString("EventSource_NotSupportedNestedArraysEnums");
}

String SR::get_EventSource_NullInput() {
  return GetResourceString("EventSource_NullInput");
}

String SR::get_EventSource_OpcodeCollision() {
  return GetResourceString("EventSource_OpcodeCollision");
}

String SR::get_EventSource_PinArrayOutOfRange() {
  return GetResourceString("EventSource_PinArrayOutOfRange");
}

String SR::get_EventSource_RecursiveTypeDefinition() {
  return GetResourceString("EventSource_RecursiveTypeDefinition");
}

String SR::get_EventSource_StopsFollowStarts() {
  return GetResourceString("EventSource_StopsFollowStarts");
}

String SR::get_EventSource_TaskCollision() {
  return GetResourceString("EventSource_TaskCollision");
}

String SR::get_EventSource_TaskOpcodePairReused() {
  return GetResourceString("EventSource_TaskOpcodePairReused");
}

String SR::get_EventSource_TooManyArgs() {
  return GetResourceString("EventSource_TooManyArgs");
}

String SR::get_EventSource_TooManyFields() {
  return GetResourceString("EventSource_TooManyFields");
}

String SR::get_EventSource_ToString() {
  return GetResourceString("EventSource_ToString");
}

String SR::get_EventSource_TraitEven() {
  return GetResourceString("EventSource_TraitEven");
}

String SR::get_EventSource_TypeMustBeSealedOrAbstract() {
  return GetResourceString("EventSource_TypeMustBeSealedOrAbstract");
}

String SR::get_EventSource_TypeMustDeriveFromEventSource() {
  return GetResourceString("EventSource_TypeMustDeriveFromEventSource");
}

String SR::get_EventSource_UndefinedChannel() {
  return GetResourceString("EventSource_UndefinedChannel");
}

String SR::get_EventSource_UndefinedKeyword() {
  return GetResourceString("EventSource_UndefinedKeyword");
}

String SR::get_EventSource_UndefinedOpcode() {
  return GetResourceString("EventSource_UndefinedOpcode");
}

String SR::get_EventSource_UnknownEtwTrait() {
  return GetResourceString("EventSource_UnknownEtwTrait");
}

String SR::get_EventSource_UnsupportedEventTypeInManifest() {
  return GetResourceString("EventSource_UnsupportedEventTypeInManifest");
}

String SR::get_EventSource_UnsupportedMessageProperty() {
  return GetResourceString("EventSource_UnsupportedMessageProperty");
}

String SR::get_EventSource_VarArgsParameterMismatch() {
  return GetResourceString("EventSource_VarArgsParameterMismatch");
}

String SR::get_Exception_EndOfInnerExceptionStack() {
  return GetResourceString("Exception_EndOfInnerExceptionStack");
}

String SR::get_Exception_EndStackTraceFromPreviousThrow() {
  return GetResourceString("Exception_EndStackTraceFromPreviousThrow");
}

String SR::get_Exception_WasThrown() {
  return GetResourceString("Exception_WasThrown");
}

String SR::get_ExecutionContext_ExceptionInAsyncLocalNotification() {
  return GetResourceString("ExecutionContext_ExceptionInAsyncLocalNotification");
}

String SR::get_FileNotFound_ResolveAssembly() {
  return GetResourceString("FileNotFound_ResolveAssembly");
}

String SR::get_Format_AttributeUsage() {
  return GetResourceString("Format_AttributeUsage");
}

String SR::get_Format_Bad7BitInt() {
  return GetResourceString("Format_Bad7BitInt");
}

String SR::get_Format_BadBase64Char() {
  return GetResourceString("Format_BadBase64Char");
}

String SR::get_Format_BadBoolean() {
  return GetResourceString("Format_BadBoolean");
}

String SR::get_Format_BadFormatSpecifier() {
  return GetResourceString("Format_BadFormatSpecifier");
}

String SR::get_Format_NoFormatSpecifier() {
  return GetResourceString("Format_NoFormatSpecifier");
}

String SR::get_Format_BadQuote() {
  return GetResourceString("Format_BadQuote");
}

String SR::get_Format_BadTimeSpan() {
  return GetResourceString("Format_BadTimeSpan");
}

String SR::get_Format_EmptyInputString() {
  return GetResourceString("Format_EmptyInputString");
}

String SR::get_Format_ExtraJunkAtEnd() {
  return GetResourceString("Format_ExtraJunkAtEnd");
}

String SR::get_Format_GuidUnrecognized() {
  return GetResourceString("Format_GuidUnrecognized");
}

String SR::get_Format_IndexOutOfRange() {
  return GetResourceString("Format_IndexOutOfRange");
}

String SR::get_Format_InvalidEnumFormatSpecification() {
  return GetResourceString("Format_InvalidEnumFormatSpecification");
}

String SR::get_Format_InvalidGuidFormatSpecification() {
  return GetResourceString("Format_InvalidGuidFormatSpecification");
}

String SR::get_Format_InvalidString() {
  return GetResourceString("Format_InvalidString");
}

String SR::get_Format_NeedSingleChar() {
  return GetResourceString("Format_NeedSingleChar");
}

String SR::get_Format_NoParsibleDigits() {
  return GetResourceString("Format_NoParsibleDigits");
}

String SR::get_Format_StringZeroLength() {
  return GetResourceString("Format_StringZeroLength");
}

String SR::get_IndexOutOfRange_ArrayRankIndex() {
  return GetResourceString("IndexOutOfRange_ArrayRankIndex");
}

String SR::get_IndexOutOfRange_UMSPosition() {
  return GetResourceString("IndexOutOfRange_UMSPosition");
}

String SR::get_InsufficientMemory_MemFailPoint() {
  return GetResourceString("InsufficientMemory_MemFailPoint");
}

String SR::get_InsufficientMemory_MemFailPoint_TooBig() {
  return GetResourceString("InsufficientMemory_MemFailPoint_TooBig");
}

String SR::get_InsufficientMemory_MemFailPoint_VAFrag() {
  return GetResourceString("InsufficientMemory_MemFailPoint_VAFrag");
}

String SR::get_Interop_COM_TypeMismatch() {
  return GetResourceString("Interop_COM_TypeMismatch");
}

String SR::get_Interop_Marshal_Unmappable_Char() {
  return GetResourceString("Interop_Marshal_Unmappable_Char");
}

String SR::get_Interop_Marshal_SafeHandle_InvalidOperation() {
  return GetResourceString("Interop_Marshal_SafeHandle_InvalidOperation");
}

String SR::get_Interop_Marshal_CannotCreateSafeHandleField() {
  return GetResourceString("Interop_Marshal_CannotCreateSafeHandleField");
}

String SR::get_Interop_Marshal_CannotCreateCriticalHandleField() {
  return GetResourceString("Interop_Marshal_CannotCreateCriticalHandleField");
}

String SR::get_InvalidCast_CannotCastNullToValueType() {
  return GetResourceString("InvalidCast_CannotCastNullToValueType");
}

String SR::get_InvalidCast_CannotCoerceByRefVariant() {
  return GetResourceString("InvalidCast_CannotCoerceByRefVariant");
}

String SR::get_InvalidCast_DBNull() {
  return GetResourceString("InvalidCast_DBNull");
}

String SR::get_InvalidCast_Empty() {
  return GetResourceString("InvalidCast_Empty");
}

String SR::get_InvalidCast_FromDBNull() {
  return GetResourceString("InvalidCast_FromDBNull");
}

String SR::get_InvalidCast_FromTo() {
  return GetResourceString("InvalidCast_FromTo");
}

String SR::get_InvalidCast_IConvertible() {
  return GetResourceString("InvalidCast_IConvertible");
}

String SR::get_InvalidOperation_AsyncFlowCtrlCtxMismatch() {
  return GetResourceString("InvalidOperation_AsyncFlowCtrlCtxMismatch");
}

String SR::get_InvalidOperation_AsyncIOInProgress() {
  return GetResourceString("InvalidOperation_AsyncIOInProgress");
}

String SR::get_InvalidOperation_BadEmptyMethodBody() {
  return GetResourceString("InvalidOperation_BadEmptyMethodBody");
}

String SR::get_InvalidOperation_BadILGeneratorUsage() {
  return GetResourceString("InvalidOperation_BadILGeneratorUsage");
}

String SR::get_InvalidOperation_BadInstructionOrIndexOutOfBound() {
  return GetResourceString("InvalidOperation_BadInstructionOrIndexOutOfBound");
}

String SR::get_InvalidOperation_BadInterfaceNotAbstract() {
  return GetResourceString("InvalidOperation_BadInterfaceNotAbstract");
}

String SR::get_InvalidOperation_BadMethodBody() {
  return GetResourceString("InvalidOperation_BadMethodBody");
}

String SR::get_InvalidOperation_BadTypeAttributesNotAbstract() {
  return GetResourceString("InvalidOperation_BadTypeAttributesNotAbstract");
}

String SR::get_InvalidOperation_CalledTwice() {
  return GetResourceString("InvalidOperation_CalledTwice");
}

String SR::get_InvalidOperation_CannotImportGlobalFromDifferentModule() {
  return GetResourceString("InvalidOperation_CannotImportGlobalFromDifferentModule");
}

String SR::get_InvalidOperation_CannotRegisterSecondResolver() {
  return GetResourceString("InvalidOperation_CannotRegisterSecondResolver");
}

String SR::get_InvalidOperation_CannotRestoreUnsupressedFlow() {
  return GetResourceString("InvalidOperation_CannotRestoreUnsupressedFlow");
}

String SR::get_InvalidOperation_CannotSupressFlowMultipleTimes() {
  return GetResourceString("InvalidOperation_CannotSupressFlowMultipleTimes");
}

String SR::get_InvalidOperation_CannotUseAFCMultiple() {
  return GetResourceString("InvalidOperation_CannotUseAFCMultiple");
}

String SR::get_InvalidOperation_CannotUseAFCOtherThread() {
  return GetResourceString("InvalidOperation_CannotUseAFCOtherThread");
}

String SR::get_InvalidOperation_CollectionCorrupted() {
  return GetResourceString("InvalidOperation_CollectionCorrupted");
}

String SR::get_InvalidOperation_ComputerName() {
  return GetResourceString("InvalidOperation_ComputerName");
}

String SR::get_InvalidOperation_ConcurrentOperationsNotSupported() {
  return GetResourceString("InvalidOperation_ConcurrentOperationsNotSupported");
}

String SR::get_InvalidOperation_ConstructorNotAllowedOnInterface() {
  return GetResourceString("InvalidOperation_ConstructorNotAllowedOnInterface");
}

String SR::get_InvalidOperation_DateTimeParsing() {
  return GetResourceString("InvalidOperation_DateTimeParsing");
}

String SR::get_InvalidOperation_DefaultConstructorILGen() {
  return GetResourceString("InvalidOperation_DefaultConstructorILGen");
}

String SR::get_InvalidOperation_EndReadCalledMultiple() {
  return GetResourceString("InvalidOperation_EndReadCalledMultiple");
}

String SR::get_InvalidOperation_EndWriteCalledMultiple() {
  return GetResourceString("InvalidOperation_EndWriteCalledMultiple");
}

String SR::get_InvalidOperation_EnumEnded() {
  return GetResourceString("InvalidOperation_EnumEnded");
}

String SR::get_InvalidOperation_EnumFailedVersion() {
  return GetResourceString("InvalidOperation_EnumFailedVersion");
}

String SR::get_InvalidOperation_EnumNotStarted() {
  return GetResourceString("InvalidOperation_EnumNotStarted");
}

String SR::get_InvalidOperation_EnumOpCantHappen() {
  return GetResourceString("InvalidOperation_EnumOpCantHappen");
}

String SR::get_InvalidOperation_EventInfoNotAvailable() {
  return GetResourceString("InvalidOperation_EventInfoNotAvailable");
}

String SR::get_InvalidOperation_GenericParametersAlreadySet() {
  return GetResourceString("InvalidOperation_GenericParametersAlreadySet");
}

String SR::get_InvalidOperation_GetVersion() {
  return GetResourceString("InvalidOperation_GetVersion");
}

String SR::get_InvalidOperation_GlobalsHaveBeenCreated() {
  return GetResourceString("InvalidOperation_GlobalsHaveBeenCreated");
}

String SR::get_InvalidOperation_HandleIsNotInitialized() {
  return GetResourceString("InvalidOperation_HandleIsNotInitialized");
}

String SR::get_InvalidOperation_HandleIsNotPinned() {
  return GetResourceString("InvalidOperation_HandleIsNotPinned");
}

String SR::get_InvalidOperation_HashInsertFailed() {
  return GetResourceString("InvalidOperation_HashInsertFailed");
}

String SR::get_InvalidOperation_IComparerFailed() {
  return GetResourceString("InvalidOperation_IComparerFailed");
}

String SR::get_InvalidOperation_MethodBaked() {
  return GetResourceString("InvalidOperation_MethodBaked");
}

String SR::get_InvalidOperation_MethodBuilderBaked() {
  return GetResourceString("InvalidOperation_MethodBuilderBaked");
}

String SR::get_InvalidOperation_MethodHasBody() {
  return GetResourceString("InvalidOperation_MethodHasBody");
}

String SR::get_InvalidOperation_MustCallInitialize() {
  return GetResourceString("InvalidOperation_MustCallInitialize");
}

String SR::get_InvalidOperation_NativeOverlappedReused() {
  return GetResourceString("InvalidOperation_NativeOverlappedReused");
}

String SR::get_InvalidOperation_NoMultiModuleAssembly() {
  return GetResourceString("InvalidOperation_NoMultiModuleAssembly");
}

String SR::get_InvalidOperation_NoPublicAddMethod() {
  return GetResourceString("InvalidOperation_NoPublicAddMethod");
}

String SR::get_InvalidOperation_NoPublicRemoveMethod() {
  return GetResourceString("InvalidOperation_NoPublicRemoveMethod");
}

String SR::get_InvalidOperation_NotADebugModule() {
  return GetResourceString("InvalidOperation_NotADebugModule");
}

String SR::get_InvalidOperation_NotAllowedInDynamicMethod() {
  return GetResourceString("InvalidOperation_NotAllowedInDynamicMethod");
}

String SR::get_InvalidOperation_NotAVarArgCallingConvention() {
  return GetResourceString("InvalidOperation_NotAVarArgCallingConvention");
}

String SR::get_InvalidOperation_NotGenericType() {
  return GetResourceString("InvalidOperation_NotGenericType");
}

String SR::get_InvalidOperation_NotWithConcurrentGC() {
  return GetResourceString("InvalidOperation_NotWithConcurrentGC");
}

String SR::get_InvalidOperation_NoUnderlyingTypeOnEnum() {
  return GetResourceString("InvalidOperation_NoUnderlyingTypeOnEnum");
}

String SR::get_InvalidOperation_NoValue() {
  return GetResourceString("InvalidOperation_NoValue");
}

String SR::get_InvalidOperation_NullArray() {
  return GetResourceString("InvalidOperation_NullArray");
}

String SR::get_InvalidOperation_NullContext() {
  return GetResourceString("InvalidOperation_NullContext");
}

String SR::get_InvalidOperation_NullModuleHandle() {
  return GetResourceString("InvalidOperation_NullModuleHandle");
}

String SR::get_InvalidOperation_OpenLocalVariableScope() {
  return GetResourceString("InvalidOperation_OpenLocalVariableScope");
}

String SR::get_InvalidOperation_Overlapped_Pack() {
  return GetResourceString("InvalidOperation_Overlapped_Pack");
}

String SR::get_InvalidOperation_PropertyInfoNotAvailable() {
  return GetResourceString("InvalidOperation_PropertyInfoNotAvailable");
}

String SR::get_InvalidOperation_ReadOnly() {
  return GetResourceString("InvalidOperation_ReadOnly");
}

String SR::get_InvalidOperation_ResMgrBadResSet_Type() {
  return GetResourceString("InvalidOperation_ResMgrBadResSet_Type");
}

String SR::get_InvalidOperation_ResourceNotStream_Name() {
  return GetResourceString("InvalidOperation_ResourceNotStream_Name");
}

String SR::get_InvalidOperation_ResourceNotString_Name() {
  return GetResourceString("InvalidOperation_ResourceNotString_Name");
}

String SR::get_InvalidOperation_ResourceNotString_Type() {
  return GetResourceString("InvalidOperation_ResourceNotString_Type");
}

String SR::get_InvalidOperation_SetLatencyModeNoGC() {
  return GetResourceString("InvalidOperation_SetLatencyModeNoGC");
}

String SR::get_InvalidOperation_ShouldNotHaveMethodBody() {
  return GetResourceString("InvalidOperation_ShouldNotHaveMethodBody");
}

String SR::get_InvalidOperation_ThreadWrongThreadStart() {
  return GetResourceString("InvalidOperation_ThreadWrongThreadStart");
}

String SR::get_InvalidOperation_TimeoutsNotSupported() {
  return GetResourceString("InvalidOperation_TimeoutsNotSupported");
}

String SR::get_InvalidOperation_TimerAlreadyClosed() {
  return GetResourceString("InvalidOperation_TimerAlreadyClosed");
}

String SR::get_InvalidOperation_TypeHasBeenCreated() {
  return GetResourceString("InvalidOperation_TypeHasBeenCreated");
}

String SR::get_InvalidOperation_TypeNotCreated() {
  return GetResourceString("InvalidOperation_TypeNotCreated");
}

String SR::get_InvalidOperation_UnderlyingArrayListChanged() {
  return GetResourceString("InvalidOperation_UnderlyingArrayListChanged");
}

String SR::get_InvalidOperation_UnknownEnumType() {
  return GetResourceString("InvalidOperation_UnknownEnumType");
}

String SR::get_InvalidOperation_WriteOnce() {
  return GetResourceString("InvalidOperation_WriteOnce");
}

String SR::get_InvalidOperation_WrongAsyncResultOrEndCalledMultiple() {
  return GetResourceString("InvalidOperation_WrongAsyncResultOrEndCalledMultiple");
}

String SR::get_InvalidOperation_WrongAsyncResultOrEndReadCalledMultiple() {
  return GetResourceString("InvalidOperation_WrongAsyncResultOrEndReadCalledMultiple");
}

String SR::get_InvalidOperation_WrongAsyncResultOrEndWriteCalledMultiple() {
  return GetResourceString("InvalidOperation_WrongAsyncResultOrEndWriteCalledMultiple");
}

String SR::get_InvalidProgram_Default() {
  return GetResourceString("InvalidProgram_Default");
}

String SR::get_InvalidTimeZone_InvalidRegistryData() {
  return GetResourceString("InvalidTimeZone_InvalidRegistryData");
}

String SR::get_InvariantFailed() {
  return GetResourceString("InvariantFailed");
}

String SR::get_InvariantFailed_Cnd() {
  return GetResourceString("InvariantFailed_Cnd");
}

String SR::get_IO_EOF_ReadBeyondEOF() {
  return GetResourceString("IO_EOF_ReadBeyondEOF");
}

String SR::get_IO_FileLoad() {
  return GetResourceString("IO_FileLoad");
}

String SR::get_IO_FileName_Name() {
  return GetResourceString("IO_FileName_Name");
}

String SR::get_IO_FileNotFound() {
  return GetResourceString("IO_FileNotFound");
}

String SR::get_IO_FileNotFound_FileName() {
  return GetResourceString("IO_FileNotFound_FileName");
}

String SR::get_IO_AlreadyExists_Name() {
  return GetResourceString("IO_AlreadyExists_Name");
}

String SR::get_IO_BindHandleFailed() {
  return GetResourceString("IO_BindHandleFailed");
}

String SR::get_IO_FileExists_Name() {
  return GetResourceString("IO_FileExists_Name");
}

String SR::get_IO_FileStreamHandlePosition() {
  return GetResourceString("IO_FileStreamHandlePosition");
}

String SR::get_IO_FileTooLongOrHandleNotSync() {
  return GetResourceString("IO_FileTooLongOrHandleNotSync");
}

String SR::get_IO_FixedCapacity() {
  return GetResourceString("IO_FixedCapacity");
}

String SR::get_IO_InvalidStringLen_Len() {
  return GetResourceString("IO_InvalidStringLen_Len");
}

String SR::get_IO_SeekAppendOverwrite() {
  return GetResourceString("IO_SeekAppendOverwrite");
}

String SR::get_IO_SeekBeforeBegin() {
  return GetResourceString("IO_SeekBeforeBegin");
}

String SR::get_IO_SetLengthAppendTruncate() {
  return GetResourceString("IO_SetLengthAppendTruncate");
}

String SR::get_IO_SharingViolation_File() {
  return GetResourceString("IO_SharingViolation_File");
}

String SR::get_IO_SharingViolation_NoFileName() {
  return GetResourceString("IO_SharingViolation_NoFileName");
}

String SR::get_IO_StreamTooLong() {
  return GetResourceString("IO_StreamTooLong");
}

String SR::get_IO_PathNotFound_NoPathName() {
  return GetResourceString("IO_PathNotFound_NoPathName");
}

String SR::get_IO_PathNotFound_Path() {
  return GetResourceString("IO_PathNotFound_Path");
}

String SR::get_IO_PathTooLong() {
  return GetResourceString("IO_PathTooLong");
}

String SR::get_IO_PathTooLong_Path() {
  return GetResourceString("IO_PathTooLong_Path");
}

String SR::get_IO_UnknownFileName() {
  return GetResourceString("IO_UnknownFileName");
}

String SR::get_Lazy_CreateValue_NoParameterlessCtorForT() {
  return GetResourceString("Lazy_CreateValue_NoParameterlessCtorForT");
}

String SR::get_Lazy_ctor_ModeInvalid() {
  return GetResourceString("Lazy_ctor_ModeInvalid");
}

String SR::get_Lazy_StaticInit_InvalidOperation() {
  return GetResourceString("Lazy_StaticInit_InvalidOperation");
}

String SR::get_Lazy_ToString_ValueNotCreated() {
  return GetResourceString("Lazy_ToString_ValueNotCreated");
}

String SR::get_Lazy_Value_RecursiveCallsToValue() {
  return GetResourceString("Lazy_Value_RecursiveCallsToValue");
}

String SR::get_ManualResetEventSlim_ctor_SpinCountOutOfRange() {
  return GetResourceString("ManualResetEventSlim_ctor_SpinCountOutOfRange");
}

String SR::get_ManualResetEventSlim_ctor_TooManyWaiters() {
  return GetResourceString("ManualResetEventSlim_ctor_TooManyWaiters");
}

String SR::get_ManualResetEventSlim_Disposed() {
  return GetResourceString("ManualResetEventSlim_Disposed");
}

String SR::get_Marshaler_StringTooLong() {
  return GetResourceString("Marshaler_StringTooLong");
}

String SR::get_MissingConstructor_Name() {
  return GetResourceString("MissingConstructor_Name");
}

String SR::get_MissingField() {
  return GetResourceString("MissingField");
}

String SR::get_MissingField_Name() {
  return GetResourceString("MissingField_Name");
}

String SR::get_MissingManifestResource_MultipleBlobs() {
  return GetResourceString("MissingManifestResource_MultipleBlobs");
}

String SR::get_MissingManifestResource_NoNeutralAsm() {
  return GetResourceString("MissingManifestResource_NoNeutralAsm");
}

String SR::get_MissingManifestResource_NoNeutralDisk() {
  return GetResourceString("MissingManifestResource_NoNeutralDisk");
}

String SR::get_MissingMember() {
  return GetResourceString("MissingMember");
}

String SR::get_MissingMember_Name() {
  return GetResourceString("MissingMember_Name");
}

String SR::get_MissingMemberNestErr() {
  return GetResourceString("MissingMemberNestErr");
}

String SR::get_MissingMemberTypeRef() {
  return GetResourceString("MissingMemberTypeRef");
}

String SR::get_MissingMethod_Name() {
  return GetResourceString("MissingMethod_Name");
}

String SR::get_MissingSatelliteAssembly_Culture_Name() {
  return GetResourceString("MissingSatelliteAssembly_Culture_Name");
}

String SR::get_MissingSatelliteAssembly_Default() {
  return GetResourceString("MissingSatelliteAssembly_Default");
}

String SR::get_Multicast_Combine() {
  return GetResourceString("Multicast_Combine");
}

String SR::get_MustUseCCRewrite() {
  return GetResourceString("MustUseCCRewrite");
}

String SR::get_NotSupported_AbstractNonCLS() {
  return GetResourceString("NotSupported_AbstractNonCLS");
}

String SR::get_NotSupported_ActivAttr() {
  return GetResourceString("NotSupported_ActivAttr");
}

String SR::get_NotSupported_AssemblyLoadFromHash() {
  return GetResourceString("NotSupported_AssemblyLoadFromHash");
}

String SR::get_NotSupported_ByRefToByRefLikeReturn() {
  return GetResourceString("NotSupported_ByRefToByRefLikeReturn");
}

String SR::get_NotSupported_ByRefToVoidReturn() {
  return GetResourceString("NotSupported_ByRefToVoidReturn");
}

String SR::get_NotSupported_CallToVarArg() {
  return GetResourceString("NotSupported_CallToVarArg");
}

String SR::get_NotSupported_CannotCallEqualsOnSpan() {
  return GetResourceString("NotSupported_CannotCallEqualsOnSpan");
}

String SR::get_NotSupported_CannotCallGetHashCodeOnSpan() {
  return GetResourceString("NotSupported_CannotCallGetHashCodeOnSpan");
}

String SR::get_NotSupported_ChangeType() {
  return GetResourceString("NotSupported_ChangeType");
}

String SR::get_NotSupported_CreateInstanceWithTypeBuilder() {
  return GetResourceString("NotSupported_CreateInstanceWithTypeBuilder");
}

String SR::get_NotSupported_DBNullSerial() {
  return GetResourceString("NotSupported_DBNullSerial");
}

String SR::get_NotSupported_DynamicAssembly() {
  return GetResourceString("NotSupported_DynamicAssembly");
}

String SR::get_NotSupported_DynamicMethodFlags() {
  return GetResourceString("NotSupported_DynamicMethodFlags");
}

String SR::get_NotSupported_DynamicModule() {
  return GetResourceString("NotSupported_DynamicModule");
}

String SR::get_NotSupported_FileStreamOnNonFiles() {
  return GetResourceString("NotSupported_FileStreamOnNonFiles");
}

String SR::get_NotSupported_FixedSizeCollection() {
  return GetResourceString("NotSupported_FixedSizeCollection");
}

String SR::get_InvalidOperation_SpanOverlappedOperation() {
  return GetResourceString("InvalidOperation_SpanOverlappedOperation");
}

String SR::get_NotSupported_IllegalOneByteBranch() {
  return GetResourceString("NotSupported_IllegalOneByteBranch");
}

String SR::get_NotSupported_KeyCollectionSet() {
  return GetResourceString("NotSupported_KeyCollectionSet");
}

String SR::get_NotSupported_MaxWaitHandles() {
  return GetResourceString("NotSupported_MaxWaitHandles");
}

String SR::get_NotSupported_MemStreamNotExpandable() {
  return GetResourceString("NotSupported_MemStreamNotExpandable");
}

String SR::get_NotSupported_MustBeModuleBuilder() {
  return GetResourceString("NotSupported_MustBeModuleBuilder");
}

String SR::get_NotSupported_NoCodepageData() {
  return GetResourceString("NotSupported_NoCodepageData");
}

String SR::get_InvalidOperation_FunctionMissingUnmanagedCallersOnly() {
  return GetResourceString("InvalidOperation_FunctionMissingUnmanagedCallersOnly");
}

String SR::get_NotSupported_NonReflectedType() {
  return GetResourceString("NotSupported_NonReflectedType");
}

String SR::get_NotSupported_NoParentDefaultConstructor() {
  return GetResourceString("NotSupported_NoParentDefaultConstructor");
}

String SR::get_NotSupported_NoTypeInfo() {
  return GetResourceString("NotSupported_NoTypeInfo");
}

String SR::get_NotSupported_NYI() {
  return GetResourceString("NotSupported_NYI");
}

String SR::get_NotSupported_ObsoleteResourcesFile() {
  return GetResourceString("NotSupported_ObsoleteResourcesFile");
}

String SR::get_NotSupported_OutputStreamUsingTypeBuilder() {
  return GetResourceString("NotSupported_OutputStreamUsingTypeBuilder");
}

String SR::get_NotSupported_RangeCollection() {
  return GetResourceString("NotSupported_RangeCollection");
}

String SR::get_NotSupported_Reading() {
  return GetResourceString("NotSupported_Reading");
}

String SR::get_NotSupported_ReadOnlyCollection() {
  return GetResourceString("NotSupported_ReadOnlyCollection");
}

String SR::get_NotSupported_ResourceObjectSerialization() {
  return GetResourceString("NotSupported_ResourceObjectSerialization");
}

String SR::get_NotSupported_StringComparison() {
  return GetResourceString("NotSupported_StringComparison");
}

String SR::get_NotSupported_SubclassOverride() {
  return GetResourceString("NotSupported_SubclassOverride");
}

String SR::get_NotSupported_SymbolMethod() {
  return GetResourceString("NotSupported_SymbolMethod");
}

String SR::get_NotSupported_Type() {
  return GetResourceString("NotSupported_Type");
}

String SR::get_NotSupported_TypeNotYetCreated() {
  return GetResourceString("NotSupported_TypeNotYetCreated");
}

String SR::get_NotSupported_UmsSafeBuffer() {
  return GetResourceString("NotSupported_UmsSafeBuffer");
}

String SR::get_NotSupported_UnitySerHolder() {
  return GetResourceString("NotSupported_UnitySerHolder");
}

String SR::get_NotSupported_UnknownTypeCode() {
  return GetResourceString("NotSupported_UnknownTypeCode");
}

String SR::get_NotSupported_UnreadableStream() {
  return GetResourceString("NotSupported_UnreadableStream");
}

String SR::get_NotSupported_UnseekableStream() {
  return GetResourceString("NotSupported_UnseekableStream");
}

String SR::get_NotSupported_UnwritableStream() {
  return GetResourceString("NotSupported_UnwritableStream");
}

String SR::get_NotSupported_ValueCollectionSet() {
  return GetResourceString("NotSupported_ValueCollectionSet");
}

String SR::get_NotSupported_Writing() {
  return GetResourceString("NotSupported_Writing");
}

String SR::get_NotSupported_WrongResourceReader_Type() {
  return GetResourceString("NotSupported_WrongResourceReader_Type");
}

String SR::get_ObjectDisposed_FileClosed() {
  return GetResourceString("ObjectDisposed_FileClosed");
}

String SR::get_ObjectDisposed_Generic() {
  return GetResourceString("ObjectDisposed_Generic");
}

String SR::get_ObjectDisposed_ObjectName_Name() {
  return GetResourceString("ObjectDisposed_ObjectName_Name");
}

String SR::get_ObjectDisposed_WriterClosed() {
  return GetResourceString("ObjectDisposed_WriterClosed");
}

String SR::get_ObjectDisposed_ReaderClosed() {
  return GetResourceString("ObjectDisposed_ReaderClosed");
}

String SR::get_ObjectDisposed_ResourceSet() {
  return GetResourceString("ObjectDisposed_ResourceSet");
}

String SR::get_ObjectDisposed_StreamClosed() {
  return GetResourceString("ObjectDisposed_StreamClosed");
}

String SR::get_ObjectDisposed_ViewAccessorClosed() {
  return GetResourceString("ObjectDisposed_ViewAccessorClosed");
}

String SR::get_ObjectDisposed_SafeHandleClosed() {
  return GetResourceString("ObjectDisposed_SafeHandleClosed");
}

String SR::get_OperationCanceled() {
  return GetResourceString("OperationCanceled");
}

String SR::get_Overflow_Byte() {
  return GetResourceString("Overflow_Byte");
}

String SR::get_Overflow_Char() {
  return GetResourceString("Overflow_Char");
}

String SR::get_Overflow_Currency() {
  return GetResourceString("Overflow_Currency");
}

String SR::get_Overflow_Decimal() {
  return GetResourceString("Overflow_Decimal");
}

String SR::get_Overflow_Duration() {
  return GetResourceString("Overflow_Duration");
}

String SR::get_Overflow_Int16() {
  return GetResourceString("Overflow_Int16");
}

String SR::get_Overflow_Int32() {
  return GetResourceString("Overflow_Int32");
}

String SR::get_Overflow_Int64() {
  return GetResourceString("Overflow_Int64");
}

String SR::get_Overflow_NegateTwosCompNum() {
  return GetResourceString("Overflow_NegateTwosCompNum");
}

String SR::get_Overflow_NegativeUnsigned() {
  return GetResourceString("Overflow_NegativeUnsigned");
}

String SR::get_Overflow_SByte() {
  return GetResourceString("Overflow_SByte");
}

String SR::get_Overflow_TimeSpanElementTooLarge() {
  return GetResourceString("Overflow_TimeSpanElementTooLarge");
}

String SR::get_Overflow_TimeSpanTooLong() {
  return GetResourceString("Overflow_TimeSpanTooLong");
}

String SR::get_Overflow_UInt16() {
  return GetResourceString("Overflow_UInt16");
}

String SR::get_Overflow_UInt32() {
  return GetResourceString("Overflow_UInt32");
}

String SR::get_Overflow_UInt64() {
  return GetResourceString("Overflow_UInt64");
}

String SR::get_PlatformNotSupported_ReflectionOnly() {
  return GetResourceString("PlatformNotSupported_ReflectionOnly");
}

String SR::get_PlatformNotSupported_Remoting() {
  return GetResourceString("PlatformNotSupported_Remoting");
}

String SR::get_PlatformNotSupported_SecureBinarySerialization() {
  return GetResourceString("PlatformNotSupported_SecureBinarySerialization");
}

String SR::get_PlatformNotSupported_StrongNameSigning() {
  return GetResourceString("PlatformNotSupported_StrongNameSigning");
}

String SR::get_PlatformNotSupported_ITypeInfo() {
  return GetResourceString("PlatformNotSupported_ITypeInfo");
}

String SR::get_PlatformNotSupported_IExpando() {
  return GetResourceString("PlatformNotSupported_IExpando");
}

String SR::get_PlatformNotSupported_AppDomains() {
  return GetResourceString("PlatformNotSupported_AppDomains");
}

String SR::get_PlatformNotSupported_CAS() {
  return GetResourceString("PlatformNotSupported_CAS");
}

String SR::get_PlatformNotSupported_Principal() {
  return GetResourceString("PlatformNotSupported_Principal");
}

String SR::get_PlatformNotSupported_ThreadAbort() {
  return GetResourceString("PlatformNotSupported_ThreadAbort");
}

String SR::get_PlatformNotSupported_ThreadSuspend() {
  return GetResourceString("PlatformNotSupported_ThreadSuspend");
}

String SR::get_PostconditionFailed() {
  return GetResourceString("PostconditionFailed");
}

String SR::get_PostconditionFailed_Cnd() {
  return GetResourceString("PostconditionFailed_Cnd");
}

String SR::get_PostconditionOnExceptionFailed() {
  return GetResourceString("PostconditionOnExceptionFailed");
}

String SR::get_PostconditionOnExceptionFailed_Cnd() {
  return GetResourceString("PostconditionOnExceptionFailed_Cnd");
}

String SR::get_PreconditionFailed() {
  return GetResourceString("PreconditionFailed");
}

String SR::get_PreconditionFailed_Cnd() {
  return GetResourceString("PreconditionFailed_Cnd");
}

String SR::get_Rank_MultiDimNotSupported() {
  return GetResourceString("Rank_MultiDimNotSupported");
}

String SR::get_Rank_MustMatch() {
  return GetResourceString("Rank_MustMatch");
}

String SR::get_ResourceReaderIsClosed() {
  return GetResourceString("ResourceReaderIsClosed");
}

String SR::get_Resources_StreamNotValid() {
  return GetResourceString("Resources_StreamNotValid");
}

String SR::get_RFLCT_AmbigCust() {
  return GetResourceString("RFLCT_AmbigCust");
}

String SR::get_RFLCT_Ambiguous() {
  return GetResourceString("RFLCT_Ambiguous");
}

String SR::get_InvalidFilterCriteriaException_CritInt() {
  return GetResourceString("InvalidFilterCriteriaException_CritInt");
}

String SR::get_InvalidFilterCriteriaException_CritString() {
  return GetResourceString("InvalidFilterCriteriaException_CritString");
}

String SR::get_RFLCT_InvalidFieldFail() {
  return GetResourceString("RFLCT_InvalidFieldFail");
}

String SR::get_RFLCT_InvalidPropFail() {
  return GetResourceString("RFLCT_InvalidPropFail");
}

String SR::get_RFLCT_Targ_ITargMismatch() {
  return GetResourceString("RFLCT_Targ_ITargMismatch");
}

String SR::get_RFLCT_Targ_StatFldReqTarg() {
  return GetResourceString("RFLCT_Targ_StatFldReqTarg");
}

String SR::get_RFLCT_Targ_StatMethReqTarg() {
  return GetResourceString("RFLCT_Targ_StatMethReqTarg");
}

String SR::get_RuntimeWrappedException() {
  return GetResourceString("RuntimeWrappedException");
}

String SR::get_Security_CannotReadRegistryData() {
  return GetResourceString("Security_CannotReadRegistryData");
}

String SR::get_Security_RegistryPermission() {
  return GetResourceString("Security_RegistryPermission");
}

String SR::get_SemaphoreSlim_ctor_InitialCountWrong() {
  return GetResourceString("SemaphoreSlim_ctor_InitialCountWrong");
}

String SR::get_SemaphoreSlim_ctor_MaxCountWrong() {
  return GetResourceString("SemaphoreSlim_ctor_MaxCountWrong");
}

String SR::get_SemaphoreSlim_Disposed() {
  return GetResourceString("SemaphoreSlim_Disposed");
}

String SR::get_SemaphoreSlim_Release_CountWrong() {
  return GetResourceString("SemaphoreSlim_Release_CountWrong");
}

String SR::get_SemaphoreSlim_Wait_TimeoutWrong() {
  return GetResourceString("SemaphoreSlim_Wait_TimeoutWrong");
}

String SR::get_Serialization_BadParameterInfo() {
  return GetResourceString("Serialization_BadParameterInfo");
}

String SR::get_Serialization_CorruptField() {
  return GetResourceString("Serialization_CorruptField");
}

String SR::get_Serialization_DateTimeTicksOutOfRange() {
  return GetResourceString("Serialization_DateTimeTicksOutOfRange");
}

String SR::get_Serialization_DelegatesNotSupported() {
  return GetResourceString("Serialization_DelegatesNotSupported");
}

String SR::get_Serialization_InsufficientState() {
  return GetResourceString("Serialization_InsufficientState");
}

String SR::get_Serialization_InvalidData() {
  return GetResourceString("Serialization_InvalidData");
}

String SR::get_Serialization_InvalidEscapeSequence() {
  return GetResourceString("Serialization_InvalidEscapeSequence");
}

String SR::get_Serialization_InvalidOnDeser() {
  return GetResourceString("Serialization_InvalidOnDeser");
}

String SR::get_Serialization_InvalidType() {
  return GetResourceString("Serialization_InvalidType");
}

String SR::get_Serialization_KeyValueDifferentSizes() {
  return GetResourceString("Serialization_KeyValueDifferentSizes");
}

String SR::get_Serialization_MissingDateTimeData() {
  return GetResourceString("Serialization_MissingDateTimeData");
}

String SR::get_Serialization_MissingKeys() {
  return GetResourceString("Serialization_MissingKeys");
}

String SR::get_Serialization_MissingValues() {
  return GetResourceString("Serialization_MissingValues");
}

String SR::get_Serialization_NoParameterInfo() {
  return GetResourceString("Serialization_NoParameterInfo");
}

String SR::get_Serialization_NotFound() {
  return GetResourceString("Serialization_NotFound");
}

String SR::get_Serialization_NullKey() {
  return GetResourceString("Serialization_NullKey");
}

String SR::get_Serialization_OptionalFieldVersionValue() {
  return GetResourceString("Serialization_OptionalFieldVersionValue");
}

String SR::get_Serialization_SameNameTwice() {
  return GetResourceString("Serialization_SameNameTwice");
}

String SR::get_Serialization_StringBuilderCapacity() {
  return GetResourceString("Serialization_StringBuilderCapacity");
}

String SR::get_Serialization_StringBuilderMaxCapacity() {
  return GetResourceString("Serialization_StringBuilderMaxCapacity");
}

String SR::get_SpinLock_Exit_SynchronizationLockException() {
  return GetResourceString("SpinLock_Exit_SynchronizationLockException");
}

String SR::get_SpinLock_IsHeldByCurrentThread() {
  return GetResourceString("SpinLock_IsHeldByCurrentThread");
}

String SR::get_SpinLock_TryEnter_ArgumentOutOfRange() {
  return GetResourceString("SpinLock_TryEnter_ArgumentOutOfRange");
}

String SR::get_SpinLock_TryEnter_LockRecursionException() {
  return GetResourceString("SpinLock_TryEnter_LockRecursionException");
}

String SR::get_SpinLock_TryReliableEnter_ArgumentException() {
  return GetResourceString("SpinLock_TryReliableEnter_ArgumentException");
}

String SR::get_SpinWait_SpinUntil_ArgumentNull() {
  return GetResourceString("SpinWait_SpinUntil_ArgumentNull");
}

String SR::get_SpinWait_SpinUntil_TimeoutWrong() {
  return GetResourceString("SpinWait_SpinUntil_TimeoutWrong");
}

String SR::get_StackTrace_InFileLineNumber() {
  return GetResourceString("StackTrace_InFileLineNumber");
}

String SR::get_Task_ContinueWith_ESandLR() {
  return GetResourceString("Task_ContinueWith_ESandLR");
}

String SR::get_Task_ContinueWith_NotOnAnything() {
  return GetResourceString("Task_ContinueWith_NotOnAnything");
}

String SR::get_Task_Delay_InvalidDelay() {
  return GetResourceString("Task_Delay_InvalidDelay");
}

String SR::get_Task_Delay_InvalidMillisecondsDelay() {
  return GetResourceString("Task_Delay_InvalidMillisecondsDelay");
}

String SR::get_Task_Dispose_NotCompleted() {
  return GetResourceString("Task_Dispose_NotCompleted");
}

String SR::get_Task_FromAsync_LongRunning() {
  return GetResourceString("Task_FromAsync_LongRunning");
}

String SR::get_Task_FromAsync_PreferFairness() {
  return GetResourceString("Task_FromAsync_PreferFairness");
}

String SR::get_Task_MultiTaskContinuation_EmptyTaskList() {
  return GetResourceString("Task_MultiTaskContinuation_EmptyTaskList");
}

String SR::get_Task_MultiTaskContinuation_FireOptions() {
  return GetResourceString("Task_MultiTaskContinuation_FireOptions");
}

String SR::get_Task_MultiTaskContinuation_NullTask() {
  return GetResourceString("Task_MultiTaskContinuation_NullTask");
}

String SR::get_Task_RunSynchronously_AlreadyStarted() {
  return GetResourceString("Task_RunSynchronously_AlreadyStarted");
}

String SR::get_Task_RunSynchronously_Continuation() {
  return GetResourceString("Task_RunSynchronously_Continuation");
}

String SR::get_Task_RunSynchronously_Promise() {
  return GetResourceString("Task_RunSynchronously_Promise");
}

String SR::get_Task_RunSynchronously_TaskCompleted() {
  return GetResourceString("Task_RunSynchronously_TaskCompleted");
}

String SR::get_Task_Start_AlreadyStarted() {
  return GetResourceString("Task_Start_AlreadyStarted");
}

String SR::get_Task_Start_ContinuationTask() {
  return GetResourceString("Task_Start_ContinuationTask");
}

String SR::get_Task_Start_Promise() {
  return GetResourceString("Task_Start_Promise");
}

String SR::get_Task_Start_TaskCompleted() {
  return GetResourceString("Task_Start_TaskCompleted");
}

String SR::get_Task_ThrowIfDisposed() {
  return GetResourceString("Task_ThrowIfDisposed");
}

String SR::get_Task_WaitMulti_NullTask() {
  return GetResourceString("Task_WaitMulti_NullTask");
}

String SR::get_TaskCanceledException_ctor_DefaultMessage() {
  return GetResourceString("TaskCanceledException_ctor_DefaultMessage");
}

String SR::get_TaskCompletionSourceT_TrySetException_NoExceptions() {
  return GetResourceString("TaskCompletionSourceT_TrySetException_NoExceptions");
}

String SR::get_TaskCompletionSourceT_TrySetException_NullException() {
  return GetResourceString("TaskCompletionSourceT_TrySetException_NullException");
}

String SR::get_TaskExceptionHolder_UnhandledException() {
  return GetResourceString("TaskExceptionHolder_UnhandledException");
}

String SR::get_TaskExceptionHolder_UnknownExceptionType() {
  return GetResourceString("TaskExceptionHolder_UnknownExceptionType");
}

String SR::get_TaskScheduler_ExecuteTask_WrongTaskScheduler() {
  return GetResourceString("TaskScheduler_ExecuteTask_WrongTaskScheduler");
}

String SR::get_TaskScheduler_FromCurrentSynchronizationContext_NoCurrent() {
  return GetResourceString("TaskScheduler_FromCurrentSynchronizationContext_NoCurrent");
}

String SR::get_TaskScheduler_InconsistentStateAfterTryExecuteTaskInline() {
  return GetResourceString("TaskScheduler_InconsistentStateAfterTryExecuteTaskInline");
}

String SR::get_TaskSchedulerException_ctor_DefaultMessage() {
  return GetResourceString("TaskSchedulerException_ctor_DefaultMessage");
}

String SR::get_TaskT_DebuggerNoResult() {
  return GetResourceString("TaskT_DebuggerNoResult");
}

String SR::get_TaskT_TransitionToFinal_AlreadyCompleted() {
  return GetResourceString("TaskT_TransitionToFinal_AlreadyCompleted");
}

String SR::get_Thread_ApartmentState_ChangeFailed() {
  return GetResourceString("Thread_ApartmentState_ChangeFailed");
}

String SR::get_Thread_GetSetCompressedStack_NotSupported() {
  return GetResourceString("Thread_GetSetCompressedStack_NotSupported");
}

String SR::get_Thread_Operation_RequiresCurrentThread() {
  return GetResourceString("Thread_Operation_RequiresCurrentThread");
}

String SR::get_Threading_AbandonedMutexException() {
  return GetResourceString("Threading_AbandonedMutexException");
}

String SR::get_Threading_WaitHandleCannotBeOpenedException() {
  return GetResourceString("Threading_WaitHandleCannotBeOpenedException");
}

String SR::get_Threading_WaitHandleCannotBeOpenedException_InvalidHandle() {
  return GetResourceString("Threading_WaitHandleCannotBeOpenedException_InvalidHandle");
}

String SR::get_Threading_WaitHandleTooManyPosts() {
  return GetResourceString("Threading_WaitHandleTooManyPosts");
}

String SR::get_Threading_SemaphoreFullException() {
  return GetResourceString("Threading_SemaphoreFullException");
}

String SR::get_ThreadLocal_Disposed() {
  return GetResourceString("ThreadLocal_Disposed");
}

String SR::get_ThreadLocal_Value_RecursiveCallsToValue() {
  return GetResourceString("ThreadLocal_Value_RecursiveCallsToValue");
}

String SR::get_ThreadLocal_ValuesNotAvailable() {
  return GetResourceString("ThreadLocal_ValuesNotAvailable");
}

String SR::get_TimeZoneNotFound_MissingData() {
  return GetResourceString("TimeZoneNotFound_MissingData");
}

String SR::get_TypeInitialization_Default() {
  return GetResourceString("TypeInitialization_Default");
}

String SR::get_TypeInitialization_Type() {
  return GetResourceString("TypeInitialization_Type");
}

String SR::get_TypeLoad_ResolveNestedType() {
  return GetResourceString("TypeLoad_ResolveNestedType");
}

String SR::get_TypeLoad_ResolveType() {
  return GetResourceString("TypeLoad_ResolveType");
}

String SR::get_TypeLoad_ResolveTypeFromAssembly() {
  return GetResourceString("TypeLoad_ResolveTypeFromAssembly");
}

String SR::get_UnauthorizedAccess_IODenied_NoPathName() {
  return GetResourceString("UnauthorizedAccess_IODenied_NoPathName");
}

String SR::get_UnauthorizedAccess_IODenied_Path() {
  return GetResourceString("UnauthorizedAccess_IODenied_Path");
}

String SR::get_UnauthorizedAccess_MemStreamBuffer() {
  return GetResourceString("UnauthorizedAccess_MemStreamBuffer");
}

String SR::get_UnauthorizedAccess_RegistryKeyGeneric_Key() {
  return GetResourceString("UnauthorizedAccess_RegistryKeyGeneric_Key");
}

String SR::get_UnknownError_Num() {
  return GetResourceString("UnknownError_Num");
}

String SR::get_Verification_Exception() {
  return GetResourceString("Verification_Exception");
}

String SR::get_Word_At() {
  return GetResourceString("Word_At");
}

String SR::get_DebugAssertBanner() {
  return GetResourceString("DebugAssertBanner");
}

String SR::get_DebugAssertLongMessage() {
  return GetResourceString("DebugAssertLongMessage");
}

String SR::get_DebugAssertShortMessage() {
  return GetResourceString("DebugAssertShortMessage");
}

String SR::get_LockRecursionException_ReadAfterWriteNotAllowed() {
  return GetResourceString("LockRecursionException_ReadAfterWriteNotAllowed");
}

String SR::get_LockRecursionException_RecursiveReadNotAllowed() {
  return GetResourceString("LockRecursionException_RecursiveReadNotAllowed");
}

String SR::get_LockRecursionException_RecursiveWriteNotAllowed() {
  return GetResourceString("LockRecursionException_RecursiveWriteNotAllowed");
}

String SR::get_LockRecursionException_RecursiveUpgradeNotAllowed() {
  return GetResourceString("LockRecursionException_RecursiveUpgradeNotAllowed");
}

String SR::get_LockRecursionException_WriteAfterReadNotAllowed() {
  return GetResourceString("LockRecursionException_WriteAfterReadNotAllowed");
}

String SR::get_SynchronizationLockException_MisMatchedUpgrade() {
  return GetResourceString("SynchronizationLockException_MisMatchedUpgrade");
}

String SR::get_SynchronizationLockException_MisMatchedRead() {
  return GetResourceString("SynchronizationLockException_MisMatchedRead");
}

String SR::get_SynchronizationLockException_IncorrectDispose() {
  return GetResourceString("SynchronizationLockException_IncorrectDispose");
}

String SR::get_LockRecursionException_UpgradeAfterReadNotAllowed() {
  return GetResourceString("LockRecursionException_UpgradeAfterReadNotAllowed");
}

String SR::get_LockRecursionException_UpgradeAfterWriteNotAllowed() {
  return GetResourceString("LockRecursionException_UpgradeAfterWriteNotAllowed");
}

String SR::get_SynchronizationLockException_MisMatchedWrite() {
  return GetResourceString("SynchronizationLockException_MisMatchedWrite");
}

String SR::get_NotSupported_SignatureType() {
  return GetResourceString("NotSupported_SignatureType");
}

String SR::get_HashCode_HashCodeNotSupported() {
  return GetResourceString("HashCode_HashCodeNotSupported");
}

String SR::get_HashCode_EqualityNotSupported() {
  return GetResourceString("HashCode_EqualityNotSupported");
}

String SR::get_Arg_TypeNotSupported() {
  return GetResourceString("Arg_TypeNotSupported");
}

String SR::get_IO_InvalidReadLength() {
  return GetResourceString("IO_InvalidReadLength");
}

String SR::get_Arg_BasePathNotFullyQualified() {
  return GetResourceString("Arg_BasePathNotFullyQualified");
}

String SR::get_Arg_ElementsInSourceIsGreaterThanDestination() {
  return GetResourceString("Arg_ElementsInSourceIsGreaterThanDestination");
}

String SR::get_Arg_NullArgumentNullRef() {
  return GetResourceString("Arg_NullArgumentNullRef");
}

String SR::get_Argument_OverlapAlignmentMismatch() {
  return GetResourceString("Argument_OverlapAlignmentMismatch");
}

String SR::get_Arg_InsufficientNumberOfElements() {
  return GetResourceString("Arg_InsufficientNumberOfElements");
}

String SR::get_Arg_MustBeNullTerminatedString() {
  return GetResourceString("Arg_MustBeNullTerminatedString");
}

String SR::get_ArgumentOutOfRange_Week_ISO() {
  return GetResourceString("ArgumentOutOfRange_Week_ISO");
}

String SR::get_Argument_BadPInvokeMethod() {
  return GetResourceString("Argument_BadPInvokeMethod");
}

String SR::get_Argument_BadPInvokeOnInterface() {
  return GetResourceString("Argument_BadPInvokeOnInterface");
}

String SR::get_Argument_MethodRedefined() {
  return GetResourceString("Argument_MethodRedefined");
}

String SR::get_Argument_CannotExtractScalar() {
  return GetResourceString("Argument_CannotExtractScalar");
}

String SR::get_Argument_CannotParsePrecision() {
  return GetResourceString("Argument_CannotParsePrecision");
}

String SR::get_Argument_GWithPrecisionNotSupported() {
  return GetResourceString("Argument_GWithPrecisionNotSupported");
}

String SR::get_Argument_PrecisionTooLarge() {
  return GetResourceString("Argument_PrecisionTooLarge");
}

String SR::get_AssemblyDependencyResolver_FailedToLoadHostpolicy() {
  return GetResourceString("AssemblyDependencyResolver_FailedToLoadHostpolicy");
}

String SR::get_AssemblyDependencyResolver_FailedToResolveDependencies() {
  return GetResourceString("AssemblyDependencyResolver_FailedToResolveDependencies");
}

String SR::get_Arg_EnumNotCloneable() {
  return GetResourceString("Arg_EnumNotCloneable");
}

String SR::get_InvalidOp_InvalidNewEnumVariant() {
  return GetResourceString("InvalidOp_InvalidNewEnumVariant");
}

String SR::get_Argument_StructArrayTooLarge() {
  return GetResourceString("Argument_StructArrayTooLarge");
}

String SR::get_IndexOutOfRange_ArrayWithOffset() {
  return GetResourceString("IndexOutOfRange_ArrayWithOffset");
}

String SR::get_Serialization_DangerousDeserialization() {
  return GetResourceString("Serialization_DangerousDeserialization");
}

String SR::get_Serialization_DangerousDeserialization_Switch() {
  return GetResourceString("Serialization_DangerousDeserialization_Switch");
}

String SR::get_Argument_InvalidStartupHookSimpleAssemblyName() {
  return GetResourceString("Argument_InvalidStartupHookSimpleAssemblyName");
}

String SR::get_Argument_StartupHookAssemblyLoadFailed() {
  return GetResourceString("Argument_StartupHookAssemblyLoadFailed");
}

String SR::get_InvalidOperation_NonStaticComRegFunction() {
  return GetResourceString("InvalidOperation_NonStaticComRegFunction");
}

String SR::get_InvalidOperation_NonStaticComUnRegFunction() {
  return GetResourceString("InvalidOperation_NonStaticComUnRegFunction");
}

String SR::get_InvalidOperation_InvalidComRegFunctionSig() {
  return GetResourceString("InvalidOperation_InvalidComRegFunctionSig");
}

String SR::get_InvalidOperation_InvalidComUnRegFunctionSig() {
  return GetResourceString("InvalidOperation_InvalidComUnRegFunctionSig");
}

String SR::get_InvalidOperation_MultipleComRegFunctions() {
  return GetResourceString("InvalidOperation_MultipleComRegFunctions");
}

String SR::get_InvalidOperation_MultipleComUnRegFunctions() {
  return GetResourceString("InvalidOperation_MultipleComUnRegFunctions");
}

String SR::get_InvalidOperation_ResetGlobalComWrappersInstance() {
  return GetResourceString("InvalidOperation_ResetGlobalComWrappersInstance");
}

String SR::get_Argument_SpansMustHaveSameLength() {
  return GetResourceString("Argument_SpansMustHaveSameLength");
}

String SR::get_NotSupported_CannotWriteToBufferedStreamIfReadBufferCannotBeFlushed() {
  return GetResourceString("NotSupported_CannotWriteToBufferedStreamIfReadBufferCannotBeFlushed");
}

String SR::get_GenericInvalidData() {
  return GetResourceString("GenericInvalidData");
}

String SR::get_Argument_ResourceScopeWrongDirection() {
  return GetResourceString("Argument_ResourceScopeWrongDirection");
}

String SR::get_ArgumentNull_TypeRequiredByResourceScope() {
  return GetResourceString("ArgumentNull_TypeRequiredByResourceScope");
}

String SR::get_Argument_BadResourceScopeTypeBits() {
  return GetResourceString("Argument_BadResourceScopeTypeBits");
}

String SR::get_Argument_BadResourceScopeVisibilityBits() {
  return GetResourceString("Argument_BadResourceScopeVisibilityBits");
}

String SR::get_net_emptystringcall() {
  return GetResourceString("net_emptystringcall");
}

String SR::get_Argument_EmptyApplicationName() {
  return GetResourceString("Argument_EmptyApplicationName");
}

String SR::get_Argument_FrameworkNameInvalid() {
  return GetResourceString("Argument_FrameworkNameInvalid");
}

String SR::get_Argument_FrameworkNameInvalidVersion() {
  return GetResourceString("Argument_FrameworkNameInvalidVersion");
}

String SR::get_Argument_FrameworkNameMissingVersion() {
  return GetResourceString("Argument_FrameworkNameMissingVersion");
}

String SR::get_Argument_FrameworkNameTooShort() {
  return GetResourceString("Argument_FrameworkNameTooShort");
}

String SR::get_Arg_SwitchExpressionException() {
  return GetResourceString("Arg_SwitchExpressionException");
}

String SR::get_Arg_ContextMarshalException() {
  return GetResourceString("Arg_ContextMarshalException");
}

String SR::get_Arg_AppDomainUnloadedException() {
  return GetResourceString("Arg_AppDomainUnloadedException");
}

String SR::get_SwitchExpressionException_UnmatchedValue() {
  return GetResourceString("SwitchExpressionException_UnmatchedValue");
}

String SR::GetResourceString(String resourceKey) {
  return GetResourceString(resourceKey, String::in::Empty);
}

String SR::InternalGetResourceString(String key) {
  if (key->get_Length() == 0) {
    return key;
  }
  Boolean lockTaken = false;
  try{
    Monitor::Enter(_lock, lockTaken);
    if (_currentlyLoading != nullptr && _currentlyLoading->get_Count() > 0 && _currentlyLoading->LastIndexOf(key) != -1) {
      if (_infinitelyRecursingCount > 0) {
        return key;
      }
      _infinitelyRecursingCount++;
      String message = "Infinite recursion during resource lookup within System.Private.CoreLib.  This may be a bug in System.Private.CoreLib, or potentially in certain extensibility points such as assembly resolve events or CultureInfo names.  Resource name: " + key;
      Environment::FailFast(message);
    }
    if (_currentlyLoading == nullptr) {
      _currentlyLoading = rt::newobj<List<String>>();
    }
    if (!_resourceManagerInited) {
      RuntimeHelpers::RunClassConstructor(rt::typeof<ResourceManager>()->get_TypeHandle());
      RuntimeHelpers::RunClassConstructor(rt::typeof<ResourceReader>()->get_TypeHandle());
      RuntimeHelpers::RunClassConstructor(rt::typeof<RuntimeResourceSet>()->get_TypeHandle());
      RuntimeHelpers::RunClassConstructor(rt::typeof<BinaryReader>()->get_TypeHandle());
      _resourceManagerInited = true;
    }
    _currentlyLoading->Add(key);
    String string = get_ResourceManager()->GetString(key, nullptr);
    _currentlyLoading->RemoveAt(_currentlyLoading->get_Count() - 1);
    auto default = string;
    if (default != nullptr) default = key;

    return default;
  } catch (...) {
  } finally: {
    if (lockTaken) {
      Monitor::Exit(_lock);
    }
  }
}

Boolean SR::UsingResourceKeys() {
  return false;
}

String SR::GetResourceString(String resourceKey, String defaultString) {
  if (UsingResourceKeys()) {
  }
  String text = nullptr;
  try{
    text = InternalGetResourceString(resourceKey);
  } catch (MissingManifestResourceException) {
  }
  if (defaultString != nullptr && resourceKey->Equals(text)) {
    return defaultString;
  }
  return text;
}

String SR::Format(String resourceFormat, Object p1) {
  if (UsingResourceKeys()) {
  }
  return String::in::Format(resourceFormat, p1);
}

String SR::Format(String resourceFormat, Object p1, Object p2) {
  if (UsingResourceKeys()) {
  }
  return String::in::Format(resourceFormat, p1, p2);
}

String SR::Format(String resourceFormat, Object p1, Object p2, Object p3) {
  if (UsingResourceKeys()) {
  }
  return String::in::Format(resourceFormat, p1, p2, p3);
}

String SR::Format(String resourceFormat, Array<Object> args) {
  if (args != nullptr) {
    if (UsingResourceKeys()) {
    }
    return String::in::Format(resourceFormat, rt::newarr<Array<Object>>(1, args));
  }
  return resourceFormat;
}

String SR::Format(IFormatProvider provider, String resourceFormat, Object p1) {
  if (UsingResourceKeys()) {
  }
  return String::in::Format(provider, resourceFormat, p1);
}

String SR::Format(IFormatProvider provider, String resourceFormat, Object p1, Object p2) {
  if (UsingResourceKeys()) {
  }
  return String::in::Format(provider, resourceFormat, p1, p2);
}

void SR::cctor() {
  _lock = rt::newobj<Object>();
}

} // namespace System::Private::CoreLib::System::SRNamespace
