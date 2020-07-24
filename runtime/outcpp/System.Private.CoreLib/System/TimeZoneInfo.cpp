#include "TimeZoneInfo-dep.h"

#include <System.Private.CoreLib/System/TimeZoneInfo-dep.h>

namespace System::Private::CoreLib::System::TimeZoneInfoNamespace {
DateTime TimeZoneInfo___::TransitionTime::get_TimeOfDay() {
  return DateTime();
};

Int32 TimeZoneInfo___::TransitionTime::get_Month() {
  return Int32();
};

Int32 TimeZoneInfo___::TransitionTime::get_Week() {
  return Int32();
};

Int32 TimeZoneInfo___::TransitionTime::get_Day() {
  return Int32();
};

DayOfWeek TimeZoneInfo___::TransitionTime::get_DayOfWeek() {
  return DayOfWeek::Saturday;
};

Boolean TimeZoneInfo___::TransitionTime::get_IsFixedDateRule() {
  return Boolean();
};

Boolean TimeZoneInfo___::TransitionTime::Equals(Object obj) {
  return Boolean();
};

Boolean TimeZoneInfo___::TransitionTime::op_Equality(TransitionTime t1, TransitionTime t2) {
  return Boolean();
};

Boolean TimeZoneInfo___::TransitionTime::op_Inequality(TransitionTime t1, TransitionTime t2) {
  return Boolean();
};

Boolean TimeZoneInfo___::TransitionTime::Equals(TransitionTime other) {
  return Boolean();
};

Int32 TimeZoneInfo___::TransitionTime::GetHashCode() {
  return Int32();
};

TimeZoneInfo___::TransitionTime::TransitionTime(DateTime timeOfDay, Int32 month, Int32 week, Int32 day, DayOfWeek dayOfWeek, Boolean isFixedDateRule) {
};

TimeZoneInfo::in::TransitionTime TimeZoneInfo___::TransitionTime::CreateFixedDateRule(DateTime timeOfDay, Int32 month, Int32 day) {
  return TimeZoneInfo::in::TransitionTime();
};

TimeZoneInfo::in::TransitionTime TimeZoneInfo___::TransitionTime::CreateFloatingDateRule(DateTime timeOfDay, Int32 month, Int32 week, DayOfWeek dayOfWeek) {
  return TimeZoneInfo::in::TransitionTime();
};

void TimeZoneInfo___::TransitionTime::ValidateTransitionTime(DateTime timeOfDay, Int32 month, Int32 week, Int32 day, DayOfWeek dayOfWeek) {
};

TimeZoneInfo___::TransitionTime::TransitionTime(SerializationInfo info, StreamingContext context) {
};

DateTime TimeZoneInfo___::AdjustmentRule___::get_DateStart() {
  return DateTime();
};

DateTime TimeZoneInfo___::AdjustmentRule___::get_DateEnd() {
  return DateTime();
};

TimeSpan TimeZoneInfo___::AdjustmentRule___::get_DaylightDelta() {
  return TimeSpan();
};

TimeZoneInfo::in::TransitionTime TimeZoneInfo___::AdjustmentRule___::get_DaylightTransitionStart() {
  return TimeZoneInfo::in::TransitionTime();
};

TimeZoneInfo::in::TransitionTime TimeZoneInfo___::AdjustmentRule___::get_DaylightTransitionEnd() {
  return TimeZoneInfo::in::TransitionTime();
};

TimeSpan TimeZoneInfo___::AdjustmentRule___::get_BaseUtcOffsetDelta() {
  return TimeSpan();
};

Boolean TimeZoneInfo___::AdjustmentRule___::get_NoDaylightTransitions() {
  return Boolean();
};

Boolean TimeZoneInfo___::AdjustmentRule___::get_HasDaylightSaving() {
  return Boolean();
};

Boolean TimeZoneInfo___::AdjustmentRule___::Equals(AdjustmentRule other) {
  return Boolean();
};

Int32 TimeZoneInfo___::AdjustmentRule___::GetHashCode() {
  return Int32();
};

void TimeZoneInfo___::AdjustmentRule___::Ctor(DateTime dateStart, DateTime dateEnd, TimeSpan daylightDelta, TransitionTime daylightTransitionStart, TransitionTime daylightTransitionEnd, TimeSpan baseUtcOffsetDelta, Boolean noDaylightTransitions) {
};

TimeZoneInfo::in::AdjustmentRule TimeZoneInfo___::AdjustmentRule___::CreateAdjustmentRule(DateTime dateStart, DateTime dateEnd, TimeSpan daylightDelta, TransitionTime daylightTransitionStart, TransitionTime daylightTransitionEnd) {
  return nullptr;
};

TimeZoneInfo::in::AdjustmentRule TimeZoneInfo___::AdjustmentRule___::CreateAdjustmentRule(DateTime dateStart, DateTime dateEnd, TimeSpan daylightDelta, TransitionTime daylightTransitionStart, TransitionTime daylightTransitionEnd, TimeSpan baseUtcOffsetDelta, Boolean noDaylightTransitions) {
  return nullptr;
};

Boolean TimeZoneInfo___::AdjustmentRule___::IsStartDateMarkerForBeginningOfYear() {
  return Boolean();
};

Boolean TimeZoneInfo___::AdjustmentRule___::IsEndDateMarkerForEndOfYear() {
  return Boolean();
};

void TimeZoneInfo___::AdjustmentRule___::ValidateAdjustmentRule(DateTime dateStart, DateTime dateEnd, TimeSpan daylightDelta, TransitionTime daylightTransitionStart, TransitionTime daylightTransitionEnd, Boolean noDaylightTransitions) {
};

void TimeZoneInfo___::AdjustmentRule___::AdjustDaylightDeltaToExpectedRange(TimeSpan& daylightDelta, TimeSpan& baseUtcOffsetDelta) {
};

void TimeZoneInfo___::AdjustmentRule___::Ctor(SerializationInfo info, StreamingContext context) {
};

void TimeZoneInfo___::AdjustmentRule___::SCtor() {
};

void TimeZoneInfo___::OffsetAndRule___::Ctor(Int32 year, TimeSpan offset, AdjustmentRule rule) {
};

TimeZoneInfo TimeZoneInfo___::CachedData___::get_Local() {
  return nullptr;
};

TimeZoneInfo TimeZoneInfo___::CachedData___::CreateLocal() {
  return nullptr;
};

DateTimeKind TimeZoneInfo___::CachedData___::GetCorrespondingKind(TimeZoneInfo timeZone) {
  return DateTimeKind::Local;
};

TimeZoneInfo TimeZoneInfo___::CachedData___::GetCurrentOneYearLocal() {
  return nullptr;
};

TimeZoneInfo::in::OffsetAndRule TimeZoneInfo___::CachedData___::GetOneYearLocalFromUtc(Int32 year) {
  return nullptr;
};

void TimeZoneInfo___::CachedData___::Ctor() {
};

String TimeZoneInfo___::StringSerializer::GetSerializedString(TimeZoneInfo zone) {
  return nullptr;
};

TimeZoneInfo TimeZoneInfo___::StringSerializer::GetDeserializedTimeZoneInfo(String source) {
  return nullptr;
};

TimeZoneInfo___::StringSerializer::StringSerializer(String str) {
};

void TimeZoneInfo___::StringSerializer::SerializeSubstitute(String text, ValueStringBuilder& serializedText) {
};

void TimeZoneInfo___::StringSerializer::SerializeTransitionTime(TransitionTime time, ValueStringBuilder& serializedText) {
};

void TimeZoneInfo___::StringSerializer::VerifyIsEscapableCharacter(Char c) {
};

void TimeZoneInfo___::StringSerializer::SkipVersionNextDataFields(Int32 depth) {
};

String TimeZoneInfo___::StringSerializer::GetNextStringValue() {
  return nullptr;
};

DateTime TimeZoneInfo___::StringSerializer::GetNextDateTimeValue(String format) {
  return DateTime();
};

TimeSpan TimeZoneInfo___::StringSerializer::GetNextTimeSpanValue() {
  return TimeSpan();
};

Int32 TimeZoneInfo___::StringSerializer::GetNextInt32Value() {
  return Int32();
};

Array<TimeZoneInfo::in::AdjustmentRule> TimeZoneInfo___::StringSerializer::GetNextAdjustmentRuleArrayValue() {
  return Array<TimeZoneInfo::in::AdjustmentRule>();
};

TimeZoneInfo::in::AdjustmentRule TimeZoneInfo___::StringSerializer::GetNextAdjustmentRuleValue() {
  return nullptr;
};

TimeZoneInfo::in::TransitionTime TimeZoneInfo___::StringSerializer::GetNextTransitionTimeValue() {
  return TimeZoneInfo::in::TransitionTime();
};

String TimeZoneInfo___::get_Id() {
  return nullptr;
};

String TimeZoneInfo___::get_DisplayName() {
  return nullptr;
};

String TimeZoneInfo___::get_StandardName() {
  return nullptr;
};

String TimeZoneInfo___::get_DaylightName() {
  return nullptr;
};

TimeSpan TimeZoneInfo___::get_BaseUtcOffset() {
  return TimeSpan();
};

Boolean TimeZoneInfo___::get_SupportsDaylightSavingTime() {
  return Boolean();
};

TimeZoneInfo TimeZoneInfo___::get_Local() {
  return nullptr;
};

TimeZoneInfo TimeZoneInfo___::get_Utc() {
  return nullptr;
};

Array<TimeSpan> TimeZoneInfo___::GetAmbiguousTimeOffsets(DateTimeOffset dateTimeOffset) {
  return Array<TimeSpan>();
};

Array<TimeSpan> TimeZoneInfo___::GetAmbiguousTimeOffsets(DateTime dateTime) {
  return Array<TimeSpan>();
};

TimeZoneInfo::in::AdjustmentRule TimeZoneInfo___::GetAdjustmentRuleForAmbiguousOffsets(DateTime adjustedTime, Nullable<Int32>& ruleIndex) {
  return nullptr;
};

TimeZoneInfo::in::AdjustmentRule TimeZoneInfo___::GetPreviousAdjustmentRule(AdjustmentRule rule, Nullable<Int32> ruleIndex) {
  return nullptr;
};

TimeSpan TimeZoneInfo___::GetUtcOffset(DateTimeOffset dateTimeOffset) {
  return TimeSpan();
};

TimeSpan TimeZoneInfo___::GetUtcOffset(DateTime dateTime) {
  return TimeSpan();
};

TimeSpan TimeZoneInfo___::GetLocalUtcOffset(DateTime dateTime, TimeZoneInfoOptions flags) {
  return TimeSpan();
};

TimeSpan TimeZoneInfo___::GetUtcOffset(DateTime dateTime, TimeZoneInfoOptions flags) {
  return TimeSpan();
};

TimeSpan TimeZoneInfo___::GetUtcOffset(DateTime dateTime, TimeZoneInfoOptions flags, CachedData cachedData) {
  return TimeSpan();
};

Boolean TimeZoneInfo___::IsAmbiguousTime(DateTimeOffset dateTimeOffset) {
  return Boolean();
};

Boolean TimeZoneInfo___::IsAmbiguousTime(DateTime dateTime) {
  return Boolean();
};

Boolean TimeZoneInfo___::IsAmbiguousTime(DateTime dateTime, TimeZoneInfoOptions flags) {
  return Boolean();
};

Boolean TimeZoneInfo___::IsDaylightSavingTime(DateTimeOffset dateTimeOffset) {
  return Boolean();
};

Boolean TimeZoneInfo___::IsDaylightSavingTime(DateTime dateTime) {
  return Boolean();
};

Boolean TimeZoneInfo___::IsDaylightSavingTime(DateTime dateTime, TimeZoneInfoOptions flags) {
  return Boolean();
};

Boolean TimeZoneInfo___::IsDaylightSavingTime(DateTime dateTime, TimeZoneInfoOptions flags, CachedData cachedData) {
  return Boolean();
};

Boolean TimeZoneInfo___::IsInvalidTime(DateTime dateTime) {
  return Boolean();
};

void TimeZoneInfo___::ClearCachedData() {
};

DateTimeOffset TimeZoneInfo___::ConvertTimeBySystemTimeZoneId(DateTimeOffset dateTimeOffset, String destinationTimeZoneId) {
  return DateTimeOffset();
};

DateTime TimeZoneInfo___::ConvertTimeBySystemTimeZoneId(DateTime dateTime, String destinationTimeZoneId) {
  return DateTime();
};

DateTime TimeZoneInfo___::ConvertTimeBySystemTimeZoneId(DateTime dateTime, String sourceTimeZoneId, String destinationTimeZoneId) {
  return DateTime();
};

DateTimeOffset TimeZoneInfo___::ConvertTime(DateTimeOffset dateTimeOffset, TimeZoneInfo destinationTimeZone) {
  return DateTimeOffset();
};

DateTime TimeZoneInfo___::ConvertTime(DateTime dateTime, TimeZoneInfo destinationTimeZone) {
  return DateTime();
};

DateTime TimeZoneInfo___::ConvertTime(DateTime dateTime, TimeZoneInfo sourceTimeZone, TimeZoneInfo destinationTimeZone) {
  return DateTime();
};

DateTime TimeZoneInfo___::ConvertTime(DateTime dateTime, TimeZoneInfo sourceTimeZone, TimeZoneInfo destinationTimeZone, TimeZoneInfoOptions flags) {
  return DateTime();
};

DateTime TimeZoneInfo___::ConvertTime(DateTime dateTime, TimeZoneInfo sourceTimeZone, TimeZoneInfo destinationTimeZone, TimeZoneInfoOptions flags, CachedData cachedData) {
  return DateTime();
};

DateTime TimeZoneInfo___::ConvertTimeFromUtc(DateTime dateTime, TimeZoneInfo destinationTimeZone) {
  return DateTime();
};

DateTime TimeZoneInfo___::ConvertTimeToUtc(DateTime dateTime) {
  return DateTime();
};

DateTime TimeZoneInfo___::ConvertTimeToUtc(DateTime dateTime, TimeZoneInfoOptions flags) {
  return DateTime();
};

DateTime TimeZoneInfo___::ConvertTimeToUtc(DateTime dateTime, TimeZoneInfo sourceTimeZone) {
  return DateTime();
};

Boolean TimeZoneInfo___::Equals(TimeZoneInfo other) {
  return Boolean();
};

Boolean TimeZoneInfo___::Equals(Object obj) {
  return Boolean();
};

TimeZoneInfo TimeZoneInfo___::FromSerializedString(String source) {
  return nullptr;
};

Int32 TimeZoneInfo___::GetHashCode() {
  return Int32();
};

ReadOnlyCollection<TimeZoneInfo> TimeZoneInfo___::GetSystemTimeZones() {
  return nullptr;
};

Boolean TimeZoneInfo___::HasSameRules(TimeZoneInfo other) {
  return Boolean();
};

String TimeZoneInfo___::ToSerializedString() {
  return nullptr;
};

String TimeZoneInfo___::ToString() {
  return nullptr;
};

void TimeZoneInfo___::Ctor(String id, TimeSpan baseUtcOffset, String displayName, String standardDisplayName, String daylightDisplayName, Array<AdjustmentRule> adjustmentRules, Boolean disableDaylightSavingTime) {
};

TimeZoneInfo TimeZoneInfo___::CreateCustomTimeZone(String id, TimeSpan baseUtcOffset, String displayName, String standardDisplayName) {
  return nullptr;
};

TimeZoneInfo TimeZoneInfo___::CreateCustomTimeZone(String id, TimeSpan baseUtcOffset, String displayName, String standardDisplayName, String daylightDisplayName, Array<AdjustmentRule> adjustmentRules) {
  return nullptr;
};

TimeZoneInfo TimeZoneInfo___::CreateCustomTimeZone(String id, TimeSpan baseUtcOffset, String displayName, String standardDisplayName, String daylightDisplayName, Array<AdjustmentRule> adjustmentRules, Boolean disableDaylightSavingTime) {
  return nullptr;
};

void TimeZoneInfo___::Ctor(SerializationInfo info, StreamingContext context) {
};

TimeZoneInfo::in::AdjustmentRule TimeZoneInfo___::GetAdjustmentRuleForTime(DateTime dateTime, Nullable<Int32>& ruleIndex) {
  return nullptr;
};

TimeZoneInfo::in::AdjustmentRule TimeZoneInfo___::GetAdjustmentRuleForTime(DateTime dateTime, Boolean dateTimeisUtc, Nullable<Int32>& ruleIndex) {
  return nullptr;
};

Int32 TimeZoneInfo___::CompareAdjustmentRuleToDateTime(AdjustmentRule rule, AdjustmentRule previousRule, DateTime dateTime, DateTime dateOnly, Boolean dateTimeisUtc) {
  return Int32();
};

DateTime TimeZoneInfo___::ConvertToUtc(DateTime dateTime, TimeSpan daylightDelta, TimeSpan baseUtcOffsetDelta) {
  return DateTime();
};

DateTime TimeZoneInfo___::ConvertFromUtc(DateTime dateTime, TimeSpan daylightDelta, TimeSpan baseUtcOffsetDelta) {
  return DateTime();
};

DateTime TimeZoneInfo___::ConvertToFromUtc(DateTime dateTime, TimeSpan daylightDelta, TimeSpan baseUtcOffsetDelta, Boolean convertToUtc) {
  return DateTime();
};

DateTime TimeZoneInfo___::ConvertUtcToTimeZone(Int64 ticks, TimeZoneInfo destinationTimeZone, Boolean& isAmbiguousLocalDst) {
  return DateTime();
};

DaylightTimeStruct TimeZoneInfo___::GetDaylightTime(Int32 year, AdjustmentRule rule, Nullable<Int32> ruleIndex) {
  return DaylightTimeStruct();
};

Boolean TimeZoneInfo___::GetIsDaylightSavings(DateTime time, AdjustmentRule rule, DaylightTimeStruct daylightTime) {
  return Boolean();
};

TimeSpan TimeZoneInfo___::GetDaylightSavingsStartOffsetFromUtc(TimeSpan baseUtcOffset, AdjustmentRule rule, Nullable<Int32> ruleIndex) {
  return TimeSpan();
};

TimeSpan TimeZoneInfo___::GetDaylightSavingsEndOffsetFromUtc(TimeSpan baseUtcOffset, AdjustmentRule rule) {
  return TimeSpan();
};

Boolean TimeZoneInfo___::GetIsDaylightSavingsFromUtc(DateTime time, Int32 year, TimeSpan utc, AdjustmentRule rule, Nullable<Int32> ruleIndex, Boolean& isAmbiguousLocalDst, TimeZoneInfo zone) {
  return Boolean();
};

Boolean TimeZoneInfo___::CheckIsDst(DateTime startTime, DateTime time, DateTime endTime, Boolean ignoreYearAdjustment, AdjustmentRule rule) {
  return Boolean();
};

Boolean TimeZoneInfo___::GetIsAmbiguousTime(DateTime time, AdjustmentRule rule, DaylightTimeStruct daylightTime) {
  return Boolean();
};

Boolean TimeZoneInfo___::GetIsInvalidTime(DateTime time, AdjustmentRule rule, DaylightTimeStruct daylightTime) {
  return Boolean();
};

TimeSpan TimeZoneInfo___::GetUtcOffset(DateTime time, TimeZoneInfo zone) {
  return TimeSpan();
};

TimeSpan TimeZoneInfo___::GetUtcOffsetFromUtc(DateTime time, TimeZoneInfo zone) {
  return TimeSpan();
};

TimeSpan TimeZoneInfo___::GetUtcOffsetFromUtc(DateTime time, TimeZoneInfo zone, Boolean& isDaylightSavings) {
  return TimeSpan();
};

TimeSpan TimeZoneInfo___::GetUtcOffsetFromUtc(DateTime time, TimeZoneInfo zone, Boolean& isDaylightSavings, Boolean& isAmbiguousLocalDst) {
  return TimeSpan();
};

DateTime TimeZoneInfo___::TransitionTimeToDateTime(Int32 year, TransitionTime transitionTime) {
  return DateTime();
};

TimeZoneInfo::in::TimeZoneInfoResult TimeZoneInfo___::TryGetTimeZone(String id, Boolean dstDisabled, TimeZoneInfo& value, Exception& e, CachedData cachedData, Boolean alwaysFallbackToLocalMachine) {
  return TimeZoneInfo::in::TimeZoneInfoResult::SecurityException;
};

TimeZoneInfo::in::TimeZoneInfoResult TimeZoneInfo___::TryGetTimeZoneFromLocalMachine(String id, Boolean dstDisabled, TimeZoneInfo& value, Exception& e, CachedData cachedData) {
  return TimeZoneInfo::in::TimeZoneInfoResult::SecurityException;
};

void TimeZoneInfo___::ValidateTimeZoneInfo(String id, TimeSpan baseUtcOffset, Array<AdjustmentRule> adjustmentRules, Boolean& adjustmentRulesSupportDst) {
};

Boolean TimeZoneInfo___::UtcOffsetOutOfRange(TimeSpan offset) {
  return Boolean();
};

TimeSpan TimeZoneInfo___::GetUtcOffset(TimeSpan baseUtcOffset, AdjustmentRule adjustmentRule) {
  return TimeSpan();
};

Boolean TimeZoneInfo___::IsValidAdjustmentRuleOffest(TimeSpan baseUtcOffset, AdjustmentRule adjustmentRule) {
  return Boolean();
};

Array<TimeZoneInfo::in::AdjustmentRule> TimeZoneInfo___::GetAdjustmentRules() {
  return Array<TimeZoneInfo::in::AdjustmentRule>();
};

void TimeZoneInfo___::PopulateAllSystemTimeZones(CachedData cachedData) {
};

void TimeZoneInfo___::Ctor(Interop::Kernel32::TIME_ZONE_INFORMATION& zone, Boolean dstDisabled) {
};

Boolean TimeZoneInfo___::CheckDaylightSavingTimeNotSupported(Interop::Kernel32::TIME_ZONE_INFORMATION& timeZone) {
  return Boolean();
};

TimeZoneInfo::in::AdjustmentRule TimeZoneInfo___::CreateAdjustmentRuleFromTimeZoneInformation(Interop::Kernel32::REG_TZI_FORMAT& timeZoneInformation, DateTime startDate, DateTime endDate, Int32 defaultBaseUtcOffset) {
  return nullptr;
};

String TimeZoneInfo___::FindIdFromTimeZoneInformation(Interop::Kernel32::TIME_ZONE_INFORMATION& timeZone, Boolean& dstDisabled) {
  return nullptr;
};

TimeZoneInfo TimeZoneInfo___::GetLocalTimeZone(CachedData cachedData) {
  return nullptr;
};

TimeZoneInfo TimeZoneInfo___::GetLocalTimeZoneFromWin32Data(Interop::Kernel32::TIME_ZONE_INFORMATION& timeZoneInformation, Boolean dstDisabled) {
  return nullptr;
};

TimeZoneInfo TimeZoneInfo___::FindSystemTimeZoneById(String id) {
  return nullptr;
};

TimeSpan TimeZoneInfo___::GetDateTimeNowUtcOffsetFromUtc(DateTime time, Boolean& isAmbiguousLocalDst) {
  return TimeSpan();
};

Boolean TimeZoneInfo___::TransitionTimeFromTimeZoneInformation(Interop::Kernel32::REG_TZI_FORMAT& timeZoneInformation, TransitionTime& transitionTime, Boolean readStartDate) {
  return Boolean();
};

Boolean TimeZoneInfo___::TryCreateAdjustmentRules(String id, Interop::Kernel32::REG_TZI_FORMAT& defaultTimeZoneInformation, Array<AdjustmentRule>& rules, Exception& e, Int32 defaultBaseUtcOffset) {
  return Boolean();
};

Boolean TimeZoneInfo___::TryGetTimeZoneEntryFromRegistry(RegistryKey key, String name, Interop::Kernel32::REG_TZI_FORMAT& dtzi) {
  return Boolean();
};

Boolean TimeZoneInfo___::TryCompareStandardDate(Interop::Kernel32::TIME_ZONE_INFORMATION& timeZone, Interop::Kernel32::REG_TZI_FORMAT& registryTimeZoneInfo) {
  return Boolean();
};

Boolean TimeZoneInfo___::TryCompareTimeZoneInformationToRegistry(Interop::Kernel32::TIME_ZONE_INFORMATION& timeZone, String id, Boolean& dstDisabled) {
  return Boolean();
};

String TimeZoneInfo___::TryGetLocalizedNameByMuiNativeResource(String resource) {
  return nullptr;
};

String TimeZoneInfo___::TryGetLocalizedNameByNativeResource(String filePath, Int32 resource) {
  return nullptr;
};

void TimeZoneInfo___::GetLocalizedNamesByRegistryKey(RegistryKey key, String& displayName, String& standardName, String& daylightName) {
};

TimeZoneInfo::in::TimeZoneInfoResult TimeZoneInfo___::TryGetTimeZoneFromLocalMachine(String id, TimeZoneInfo& value, Exception& e) {
  return TimeZoneInfo::in::TimeZoneInfoResult::SecurityException;
};

void TimeZoneInfo___::SCtor() {
};

} // namespace System::Private::CoreLib::System::TimeZoneInfoNamespace
