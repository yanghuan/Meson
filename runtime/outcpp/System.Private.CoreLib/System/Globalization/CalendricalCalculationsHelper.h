#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(DateTime)
FORWARDS(Double)
FORWARDS(Int64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
namespace CalendricalCalculationsHelperNamespace {
CLASS(CalendricalCalculationsHelper) {
  private: enum class CorrectionAlgorithm {
    Default = 0,
    Year1988to2019 = 1,
    Year1900to1987 = 2,
    Year1800to1899 = 3,
    Year1700to1799 = 4,
    Year1620to1699 = 5,
  };
  private: struct EphemerisCorrectionAlgorithmMap {
    public: Int32 _lowestYear;
    public: CorrectionAlgorithm _algorithm;
  };
  private: static Double RadiansFromDegrees(Double degree);
  private: static Double SinOfDegree(Double degree);
  private: static Double CosOfDegree(Double degree);
  private: static Double TanOfDegree(Double degree);
  public: static Double Angle(Int32 degrees, Int32 minutes, Double seconds);
  private: static Double Obliquity(Double julianCenturies);
  public: static Int64 GetNumberOfDays(DateTime date);
  private: static Int32 GetGregorianYear(Double numberOfDays);
  private: static Double Reminder(Double divisor, Double dividend);
  private: static Double NormalizeLongitude(Double longitude);
  public: static Double AsDayFraction(Double longitude);
  private: static Double PolynomialSum(Array<Double> coefficients, Double indeterminate);
  private: static Double CenturiesFrom1900(Int32 gregorianYear);
  private: static Double DefaultEphemerisCorrection(Int32 gregorianYear);
  private: static Double EphemerisCorrection1988to2019(Int32 gregorianYear);
  private: static Double EphemerisCorrection1900to1987(Int32 gregorianYear);
  private: static Double EphemerisCorrection1800to1899(Int32 gregorianYear);
  private: static Double EphemerisCorrection1700to1799(Int32 gregorianYear);
  private: static Double EphemerisCorrection1620to1699(Int32 gregorianYear);
  private: static Double EphemerisCorrection(Double time);
  public: static Double JulianCenturies(Double moment);
  private: static Boolean IsNegative(Double value);
  private: static Double CopySign(Double value, Double sign);
  private: static Double EquationOfTime(Double time);
  private: static Double AsLocalTime(Double apparentMidday, Double longitude);
  public: static Double Midday(Double date, Double longitude);
  private: static Double InitLongitude(Double longitude);
  public: static Double MiddayAtPersianObservationSite(Double date);
  private: static Double PeriodicTerm(Double julianCenturies, Int32 x, Double y, Double z);
  private: static Double SumLongSequenceOfPeriodicTerms(Double julianCenturies);
  private: static Double Aberration(Double julianCenturies);
  private: static Double Nutation(Double julianCenturies);
  public: static Double Compute(Double time);
  public: static Double AsSeason(Double longitude);
  private: static Double EstimatePrior(Double longitude, Double time);
  public: static Int64 PersianNewYearOnOrBefore(Int64 numberOfDays);
  private: static Int64 s_startOf1810;
  private: static Int64 s_startOf1900Century;
  private: static Array<Double> s_coefficients1900to1987;
  private: static Array<Double> s_coefficients1800to1899;
  private: static Array<Double> s_coefficients1700to1799;
  private: static Array<Double> s_coefficients1620to1699;
  private: static Array<Double> s_lambdaCoefficients;
  private: static Array<Double> s_anomalyCoefficients;
  private: static Array<Double> s_eccentricityCoefficients;
  private: static Array<Double> s_coefficients;
  private: static Array<Double> s_coefficientsA;
  private: static Array<Double> s_coefficientsB;
  private: static Array<EphemerisCorrectionAlgorithmMap> s_ephemerisCorrectionTable;
};
} // namespace CalendricalCalculationsHelperNamespace
using CalendricalCalculationsHelper = CalendricalCalculationsHelperNamespace::CalendricalCalculationsHelper;
} // namespace System::Private::CoreLib::System::Globalization
