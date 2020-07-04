#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/Interop.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Byte.h>
#include <System.Private.CoreLib/System/DateTime.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/TimeSpan.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections::ObjectModel {
FORWARD(ReadOnlyCollection, T)
} // namespace System::Private::CoreLib::System::Collections::ObjectModel
namespace System::Private::CoreLib::System::Text {
FORWARDS(ValueStringBuilder)
} // namespace System::Private::CoreLib::System::Text
namespace System::Private::CoreLib::System::Globalization {
FORWARDS(DaylightTimeStruct)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::Internal::Win32 {
FORWARD(RegistryKey)
} // namespace System::Private::CoreLib::Internal::Win32
namespace System::Private::CoreLib::System {
enum class DayOfWeek;
FORWARD(Object)
enum class DateTimeKind;
FORWARD(String)
FORWARDS(Char)
FORWARD_(Array, T1, T2)
FORWARDS(DateTimeOffset)
FORWARDS_(Nullable, T1, T2)
enum class TimeZoneInfoOptions;
FORWARDS(Int64)
FORWARD(Exception)
namespace TimeZoneInfoNamespace {
using namespace ::System::Private::CoreLib::Internal::Win32;
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Collections::ObjectModel;
using namespace ::System::Private::CoreLib::System::Globalization;
using namespace ::System::Private::CoreLib::System::Text;
CLASS(TimeZoneInfo) {
  private: enum class TimeZoneInfoResult {
    Success = 0,
    TimeZoneNotFoundException = 1,
    InvalidTimeZoneException = 2,
    SecurityException = 3,
  };
  public: struct TransitionTime {
    public: DateTime get_TimeOfDay();
    public: Int32 get_Month();
    public: Int32 get_Week();
    public: Int32 get_Day();
    public: DayOfWeek get_DayOfWeek();
    public: Boolean get_IsFixedDateRule();
    public: Boolean Equals(Object obj);
    public: Boolean Equals(TransitionTime other);
    public: Int32 GetHashCode();
    public: static TransitionTime CreateFixedDateRule(DateTime timeOfDay, Int32 month, Int32 day);
    public: static TransitionTime CreateFloatingDateRule(DateTime timeOfDay, Int32 month, Int32 week, DayOfWeek dayOfWeek);
    private: static void ValidateTransitionTime(DateTime timeOfDay, Int32 month, Int32 week, Int32 day, DayOfWeek dayOfWeek);
    private: DateTime _timeOfDay;
    private: Byte _month;
    private: Byte _week;
    private: Byte _day;
    private: DayOfWeek _dayOfWeek;
    private: Boolean _isFixedDateRule;
  };
  public: CLASS(AdjustmentRule) {
    public: DateTime get_DateStart();
    public: DateTime get_DateEnd();
    public: TimeSpan get_DaylightDelta();
    public: TransitionTime get_DaylightTransitionStart();
    public: TransitionTime get_DaylightTransitionEnd();
    public: TimeSpan get_BaseUtcOffsetDelta();
    public: Boolean get_NoDaylightTransitions();
    public: Boolean get_HasDaylightSaving();
    public: Boolean Equals(AdjustmentRule other);
    public: Int32 GetHashCode();
    public: static AdjustmentRule CreateAdjustmentRule(DateTime dateStart, DateTime dateEnd, TimeSpan daylightDelta, TransitionTime daylightTransitionStart, TransitionTime daylightTransitionEnd);
    public: static AdjustmentRule CreateAdjustmentRule(DateTime dateStart, DateTime dateEnd, TimeSpan daylightDelta, TransitionTime daylightTransitionStart, TransitionTime daylightTransitionEnd, TimeSpan baseUtcOffsetDelta, Boolean noDaylightTransitions);
    public: Boolean IsStartDateMarkerForBeginningOfYear();
    public: Boolean IsEndDateMarkerForEndOfYear();
    private: static void ValidateAdjustmentRule(DateTime dateStart, DateTime dateEnd, TimeSpan daylightDelta, TransitionTime daylightTransitionStart, TransitionTime daylightTransitionEnd, Boolean noDaylightTransitions);
    private: static void AdjustDaylightDeltaToExpectedRange(TimeSpan& daylightDelta, TimeSpan& baseUtcOffsetDelta);
    private: static TimeSpan DaylightDeltaAdjustment;
    private: static TimeSpan MaxDaylightDelta;
    private: DateTime _dateStart;
    private: DateTime _dateEnd;
    private: TimeSpan _daylightDelta;
    private: TransitionTime _daylightTransitionStart;
    private: TransitionTime _daylightTransitionEnd;
    private: TimeSpan _baseUtcOffsetDelta;
    private: Boolean _noDaylightTransitions;
  };
  private: CLASS(OffsetAndRule) {
    public: Int32 Year;
    public: TimeSpan Offset;
    public: AdjustmentRule Rule;
  };
  private: CLASS(CachedData) {
    public: TimeZoneInfo get_Local();
    private: TimeZoneInfo CreateLocal();
    public: DateTimeKind GetCorrespondingKind(TimeZoneInfo timeZone);
    private: static TimeZoneInfo GetCurrentOneYearLocal();
    public: OffsetAndRule GetOneYearLocalFromUtc(Int32 year);
    private: TimeZoneInfo _localTimeZone;
    public: Dictionary<String, TimeZoneInfo> _systemTimeZones;
    public: ReadOnlyCollection<TimeZoneInfo> _readOnlySystemTimeZones;
    public: Boolean _allSystemTimeZonesRead;
    private: OffsetAndRule _oneYearLocalFromUtc;
  };
  private: struct StringSerializer {
    private: enum class State {
      Escaped = 0,
      NotEscaped = 1,
      StartOfToken = 2,
      EndOfLine = 3,
    };
    public: static String GetSerializedString(TimeZoneInfo zone);
    public: static TimeZoneInfo GetDeserializedTimeZoneInfo(String source);
    private: static void SerializeSubstitute(String text, ValueStringBuilder& serializedText);
    private: static void SerializeTransitionTime(TransitionTime time, ValueStringBuilder& serializedText);
    private: static void VerifyIsEscapableCharacter(Char c);
    private: void SkipVersionNextDataFields(Int32 depth);
    private: String GetNextStringValue();
    private: DateTime GetNextDateTimeValue(String format);
    private: TimeSpan GetNextTimeSpanValue();
    private: Int32 GetNextInt32Value();
    private: Array<AdjustmentRule> GetNextAdjustmentRuleArrayValue();
    private: AdjustmentRule GetNextAdjustmentRuleValue();
    private: TransitionTime GetNextTransitionTimeValue();
    private: String _serializedText;
    private: Int32 _currentTokenStartIndex;
    private: State _state;
  };
  public: String get_Id();
  public: String get_DisplayName();
  public: String get_StandardName();
  public: String get_DaylightName();
  public: TimeSpan get_BaseUtcOffset();
  public: Boolean get_SupportsDaylightSavingTime();
  public: static TimeZoneInfo get_Local();
  public: static TimeZoneInfo get_Utc();
  public: Array<TimeSpan> GetAmbiguousTimeOffsets(DateTimeOffset dateTimeOffset);
  public: Array<TimeSpan> GetAmbiguousTimeOffsets(DateTime dateTime);
  private: AdjustmentRule GetAdjustmentRuleForAmbiguousOffsets(DateTime adjustedTime, Nullable<Int32>& ruleIndex);
  private: AdjustmentRule GetPreviousAdjustmentRule(AdjustmentRule rule, Nullable<Int32> ruleIndex);
  public: TimeSpan GetUtcOffset(DateTimeOffset dateTimeOffset);
  public: TimeSpan GetUtcOffset(DateTime dateTime);
  public: static TimeSpan GetLocalUtcOffset(DateTime dateTime, TimeZoneInfoOptions flags);
  public: TimeSpan GetUtcOffset(DateTime dateTime, TimeZoneInfoOptions flags);
  private: TimeSpan GetUtcOffset(DateTime dateTime, TimeZoneInfoOptions flags, CachedData cachedData);
  public: Boolean IsAmbiguousTime(DateTimeOffset dateTimeOffset);
  public: Boolean IsAmbiguousTime(DateTime dateTime);
  public: Boolean IsAmbiguousTime(DateTime dateTime, TimeZoneInfoOptions flags);
  public: Boolean IsDaylightSavingTime(DateTimeOffset dateTimeOffset);
  public: Boolean IsDaylightSavingTime(DateTime dateTime);
  public: Boolean IsDaylightSavingTime(DateTime dateTime, TimeZoneInfoOptions flags);
  private: Boolean IsDaylightSavingTime(DateTime dateTime, TimeZoneInfoOptions flags, CachedData cachedData);
  public: Boolean IsInvalidTime(DateTime dateTime);
  public: static void ClearCachedData();
  public: static DateTimeOffset ConvertTimeBySystemTimeZoneId(DateTimeOffset dateTimeOffset, String destinationTimeZoneId);
  public: static DateTime ConvertTimeBySystemTimeZoneId(DateTime dateTime, String destinationTimeZoneId);
  public: static DateTime ConvertTimeBySystemTimeZoneId(DateTime dateTime, String sourceTimeZoneId, String destinationTimeZoneId);
  public: static DateTimeOffset ConvertTime(DateTimeOffset dateTimeOffset, TimeZoneInfo destinationTimeZone);
  public: static DateTime ConvertTime(DateTime dateTime, TimeZoneInfo destinationTimeZone);
  public: static DateTime ConvertTime(DateTime dateTime, TimeZoneInfo sourceTimeZone, TimeZoneInfo destinationTimeZone);
  public: static DateTime ConvertTime(DateTime dateTime, TimeZoneInfo sourceTimeZone, TimeZoneInfo destinationTimeZone, TimeZoneInfoOptions flags);
  private: static DateTime ConvertTime(DateTime dateTime, TimeZoneInfo sourceTimeZone, TimeZoneInfo destinationTimeZone, TimeZoneInfoOptions flags, CachedData cachedData);
  public: static DateTime ConvertTimeFromUtc(DateTime dateTime, TimeZoneInfo destinationTimeZone);
  public: static DateTime ConvertTimeToUtc(DateTime dateTime);
  public: static DateTime ConvertTimeToUtc(DateTime dateTime, TimeZoneInfoOptions flags);
  public: static DateTime ConvertTimeToUtc(DateTime dateTime, TimeZoneInfo sourceTimeZone);
  public: Boolean Equals(TimeZoneInfo other);
  public: Boolean Equals(Object obj);
  public: static TimeZoneInfo FromSerializedString(String source);
  public: Int32 GetHashCode();
  public: static ReadOnlyCollection<TimeZoneInfo> GetSystemTimeZones();
  public: Boolean HasSameRules(TimeZoneInfo other);
  public: String ToSerializedString();
  public: String ToString();
  public: static TimeZoneInfo CreateCustomTimeZone(String id, TimeSpan baseUtcOffset, String displayName, String standardDisplayName);
  public: static TimeZoneInfo CreateCustomTimeZone(String id, TimeSpan baseUtcOffset, String displayName, String standardDisplayName, String daylightDisplayName, Array<AdjustmentRule> adjustmentRules);
  public: static TimeZoneInfo CreateCustomTimeZone(String id, TimeSpan baseUtcOffset, String displayName, String standardDisplayName, String daylightDisplayName, Array<AdjustmentRule> adjustmentRules, Boolean disableDaylightSavingTime);
  private: AdjustmentRule GetAdjustmentRuleForTime(DateTime dateTime, Nullable<Int32>& ruleIndex);
  private: AdjustmentRule GetAdjustmentRuleForTime(DateTime dateTime, Boolean dateTimeisUtc, Nullable<Int32>& ruleIndex);
  private: Int32 CompareAdjustmentRuleToDateTime(AdjustmentRule rule, AdjustmentRule previousRule, DateTime dateTime, DateTime dateOnly, Boolean dateTimeisUtc);
  private: DateTime ConvertToUtc(DateTime dateTime, TimeSpan daylightDelta, TimeSpan baseUtcOffsetDelta);
  private: DateTime ConvertFromUtc(DateTime dateTime, TimeSpan daylightDelta, TimeSpan baseUtcOffsetDelta);
  private: DateTime ConvertToFromUtc(DateTime dateTime, TimeSpan daylightDelta, TimeSpan baseUtcOffsetDelta, Boolean convertToUtc);
  private: static DateTime ConvertUtcToTimeZone(Int64 ticks, TimeZoneInfo destinationTimeZone, Boolean& isAmbiguousLocalDst);
  private: DaylightTimeStruct GetDaylightTime(Int32 year, AdjustmentRule rule, Nullable<Int32> ruleIndex);
  private: static Boolean GetIsDaylightSavings(DateTime time, AdjustmentRule rule, DaylightTimeStruct daylightTime);
  private: TimeSpan GetDaylightSavingsStartOffsetFromUtc(TimeSpan baseUtcOffset, AdjustmentRule rule, Nullable<Int32> ruleIndex);
  private: TimeSpan GetDaylightSavingsEndOffsetFromUtc(TimeSpan baseUtcOffset, AdjustmentRule rule);
  private: static Boolean GetIsDaylightSavingsFromUtc(DateTime time, Int32 year, TimeSpan utc, AdjustmentRule rule, Nullable<Int32> ruleIndex, Boolean& isAmbiguousLocalDst, TimeZoneInfo zone);
  private: static Boolean CheckIsDst(DateTime startTime, DateTime time, DateTime endTime, Boolean ignoreYearAdjustment, AdjustmentRule rule);
  private: static Boolean GetIsAmbiguousTime(DateTime time, AdjustmentRule rule, DaylightTimeStruct daylightTime);
  private: static Boolean GetIsInvalidTime(DateTime time, AdjustmentRule rule, DaylightTimeStruct daylightTime);
  private: static TimeSpan GetUtcOffset(DateTime time, TimeZoneInfo zone);
  private: static TimeSpan GetUtcOffsetFromUtc(DateTime time, TimeZoneInfo zone);
  private: static TimeSpan GetUtcOffsetFromUtc(DateTime time, TimeZoneInfo zone, Boolean& isDaylightSavings);
  public: static TimeSpan GetUtcOffsetFromUtc(DateTime time, TimeZoneInfo zone, Boolean& isDaylightSavings, Boolean& isAmbiguousLocalDst);
  public: static DateTime TransitionTimeToDateTime(Int32 year, TransitionTime transitionTime);
  private: static TimeZoneInfoResult TryGetTimeZone(String id, Boolean dstDisabled, TimeZoneInfo& value, Exception& e, CachedData cachedData, Boolean alwaysFallbackToLocalMachine);
  private: static TimeZoneInfoResult TryGetTimeZoneFromLocalMachine(String id, Boolean dstDisabled, TimeZoneInfo& value, Exception& e, CachedData cachedData);
  private: static void ValidateTimeZoneInfo(String id, TimeSpan baseUtcOffset, Array<AdjustmentRule> adjustmentRules, Boolean& adjustmentRulesSupportDst);
  public: static Boolean UtcOffsetOutOfRange(TimeSpan offset);
  private: static TimeSpan GetUtcOffset(TimeSpan baseUtcOffset, AdjustmentRule adjustmentRule);
  private: static Boolean IsValidAdjustmentRuleOffest(TimeSpan baseUtcOffset, AdjustmentRule adjustmentRule);
  public: Array<AdjustmentRule> GetAdjustmentRules();
  private: static void PopulateAllSystemTimeZones(CachedData cachedData);
  private: static Boolean CheckDaylightSavingTimeNotSupported(Interop::Kernel32::TIME_ZONE_INFORMATION& timeZone);
  private: static AdjustmentRule CreateAdjustmentRuleFromTimeZoneInformation(Interop::Kernel32::REG_TZI_FORMAT& timeZoneInformation, DateTime startDate, DateTime endDate, Int32 defaultBaseUtcOffset);
  private: static String FindIdFromTimeZoneInformation(Interop::Kernel32::TIME_ZONE_INFORMATION& timeZone, Boolean& dstDisabled);
  private: static TimeZoneInfo GetLocalTimeZone(CachedData cachedData);
  private: static TimeZoneInfo GetLocalTimeZoneFromWin32Data(Interop::Kernel32::TIME_ZONE_INFORMATION& timeZoneInformation, Boolean dstDisabled);
  public: static TimeZoneInfo FindSystemTimeZoneById(String id);
  public: static TimeSpan GetDateTimeNowUtcOffsetFromUtc(DateTime time, Boolean& isAmbiguousLocalDst);
  private: static Boolean TransitionTimeFromTimeZoneInformation(Interop::Kernel32::REG_TZI_FORMAT& timeZoneInformation, TransitionTime& transitionTime, Boolean readStartDate);
  private: static Boolean TryCreateAdjustmentRules(String id, Interop::Kernel32::REG_TZI_FORMAT& defaultTimeZoneInformation, Array<AdjustmentRule>& rules, Exception& e, Int32 defaultBaseUtcOffset);
  private: static Boolean TryGetTimeZoneEntryFromRegistry(RegistryKey key, String name, Interop::Kernel32::REG_TZI_FORMAT& dtzi);
  private: static Boolean TryCompareStandardDate(Interop::Kernel32::TIME_ZONE_INFORMATION& timeZone, Interop::Kernel32::REG_TZI_FORMAT& registryTimeZoneInfo);
  private: static Boolean TryCompareTimeZoneInformationToRegistry(Interop::Kernel32::TIME_ZONE_INFORMATION& timeZone, String id, Boolean& dstDisabled);
  private: static String TryGetLocalizedNameByMuiNativeResource(String resource);
  private: static String TryGetLocalizedNameByNativeResource(String filePath, Int32 resource);
  private: static void GetLocalizedNamesByRegistryKey(RegistryKey key, String& displayName, String& standardName, String& daylightName);
  private: static TimeZoneInfoResult TryGetTimeZoneFromLocalMachine(String id, TimeZoneInfo& value, Exception& e);
  private: String _id;
  private: String _displayName;
  private: String _standardDisplayName;
  private: String _daylightDisplayName;
  private: TimeSpan _baseUtcOffset;
  private: Boolean _supportsDaylightSavingTime;
  private: Array<AdjustmentRule> _adjustmentRules;
  private: static TimeZoneInfo s_utcTimeZone;
  private: static CachedData s_cachedData;
  private: static DateTime s_maxDateOnly;
  private: static DateTime s_minDateOnly;
  private: static TimeSpan MaxOffset;
  private: static TimeSpan MinOffset;
};
} // namespace TimeZoneInfoNamespace
using TimeZoneInfo = TimeZoneInfoNamespace::TimeZoneInfo;
} // namespace System::Private::CoreLib::System
