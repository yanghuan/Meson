#include "CalendricalCalculationsHelper-dep.h"

#include <System.Private.CoreLib/System/Globalization/CalendricalCalculationsHelper-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>

namespace System::Private::CoreLib::System::Globalization::CalendricalCalculationsHelperNamespace {
CalendricalCalculationsHelper::EphemerisCorrectionAlgorithmMap::EphemerisCorrectionAlgorithmMap(Int32 year, CorrectionAlgorithm algorithm) {
  _lowestYear = year;
  _algorithm = algorithm;
}

Double CalendricalCalculationsHelper::RadiansFromDegrees(Double degree) {
  return degree * Math::PI / 180;
}

Double CalendricalCalculationsHelper::SinOfDegree(Double degree) {
  return Math::Sin(RadiansFromDegrees(degree));
}

Double CalendricalCalculationsHelper::CosOfDegree(Double degree) {
  return Math::Cos(RadiansFromDegrees(degree));
}

Double CalendricalCalculationsHelper::TanOfDegree(Double degree) {
  return Math::Tan(RadiansFromDegrees(degree));
}

Double CalendricalCalculationsHelper::Angle(Int32 degrees, Int32 minutes, Double seconds) {
  return (seconds / 60 + (Double)minutes) / 60 + (Double)degrees;
}

Double CalendricalCalculationsHelper::Obliquity(Double julianCenturies) {
  return PolynomialSum(s_coefficients, julianCenturies);
}

Int64 CalendricalCalculationsHelper::GetNumberOfDays(DateTime date) {
  return date.get_Ticks() / 864000000000;
}

Int32 CalendricalCalculationsHelper::GetGregorianYear(Double numberOfDays) {
  return DateTime(Math::Min((Int64)(Math::Floor(numberOfDays) * 864000000000), DateTime::MaxValue.get_Ticks())).get_Year();
}

Double CalendricalCalculationsHelper::Reminder(Double divisor, Double dividend) {
  Double num = Math::Floor(divisor / dividend);
  return divisor - dividend * num;
}

Double CalendricalCalculationsHelper::NormalizeLongitude(Double longitude) {
  longitude = Reminder(longitude, 360);
  if (longitude < 0) {
    longitude += 360;
  }
  return longitude;
}

Double CalendricalCalculationsHelper::AsDayFraction(Double longitude) {
  return longitude / 360;
}

Double CalendricalCalculationsHelper::PolynomialSum(Array<Double> coefficients, Double indeterminate) {
  Double num = coefficients[0];
  Double num2 = 1;
  for (Int32 i = 1; i < coefficients->get_Length(); i++) {
    num2 *= indeterminate;
    num += coefficients[i] * num2;
  }
  return num;
}

Double CalendricalCalculationsHelper::CenturiesFrom1900(Int32 gregorianYear) {
  Int64 numberOfDays = GetNumberOfDays(DateTime(gregorianYear, 7, 1));
  return (Double)(numberOfDays - s_startOf1900Century) / 36525;
}

Double CalendricalCalculationsHelper::DefaultEphemerisCorrection(Int32 gregorianYear) {
  Int64 numberOfDays = GetNumberOfDays(DateTime(gregorianYear, 1, 1));
  Double num = numberOfDays - s_startOf1810;
  Double x = 0.5 + num;
  return (Math::Pow(x, 2) / 41048480 - 15) / 86400;
}

Double CalendricalCalculationsHelper::EphemerisCorrection1988to2019(Int32 gregorianYear) {
  return (Double)(gregorianYear - 1933) / 86400;
}

Double CalendricalCalculationsHelper::EphemerisCorrection1900to1987(Int32 gregorianYear) {
  Double indeterminate = CenturiesFrom1900(gregorianYear);
  return PolynomialSum(s_coefficients1900to1987, indeterminate);
}

Double CalendricalCalculationsHelper::EphemerisCorrection1800to1899(Int32 gregorianYear) {
  Double indeterminate = CenturiesFrom1900(gregorianYear);
  return PolynomialSum(s_coefficients1800to1899, indeterminate);
}

Double CalendricalCalculationsHelper::EphemerisCorrection1700to1799(Int32 gregorianYear) {
  Double indeterminate = gregorianYear - 1700;
  return PolynomialSum(s_coefficients1700to1799, indeterminate) / 86400;
}

Double CalendricalCalculationsHelper::EphemerisCorrection1620to1699(Int32 gregorianYear) {
  Double indeterminate = gregorianYear - 1600;
  return PolynomialSum(s_coefficients1620to1699, indeterminate) / 86400;
}

Double CalendricalCalculationsHelper::EphemerisCorrection(Double time) {
  Int32 gregorianYear = GetGregorianYear(time);
  Array<EphemerisCorrectionAlgorithmMap> array = s_ephemerisCorrectionTable;
  for (Int32 i = 0; i < array->get_Length(); i++) {
    EphemerisCorrectionAlgorithmMap ephemerisCorrectionAlgorithmMap = array[i];
    if (ephemerisCorrectionAlgorithmMap._lowestYear <= gregorianYear) {
      switch (ephemerisCorrectionAlgorithmMap._algorithm) {
        case CorrectionAlgorithm::Default:
          return DefaultEphemerisCorrection(gregorianYear);
        case CorrectionAlgorithm::Year1988to2019:
          return EphemerisCorrection1988to2019(gregorianYear);
        case CorrectionAlgorithm::Year1900to1987:
          return EphemerisCorrection1900to1987(gregorianYear);
        case CorrectionAlgorithm::Year1800to1899:
          return EphemerisCorrection1800to1899(gregorianYear);
        case CorrectionAlgorithm::Year1700to1799:
          return EphemerisCorrection1700to1799(gregorianYear);
        case CorrectionAlgorithm::Year1620to1699:
          return EphemerisCorrection1620to1699(gregorianYear);
      }
      break;
    }
  }
  return DefaultEphemerisCorrection(gregorianYear);
}

Double CalendricalCalculationsHelper::JulianCenturies(Double moment) {
  Double num = moment + EphemerisCorrection(moment);
  return (num - 730120.5) / 36525;
}

Boolean CalendricalCalculationsHelper::IsNegative(Double value) {
  return Math::Sign(value) == -1;
}

Double CalendricalCalculationsHelper::CopySign(Double value, Double sign) {
  if (IsNegative(value) != IsNegative(sign)) {
    return 0 - value;
  }
  return value;
}

Double CalendricalCalculationsHelper::EquationOfTime(Double time) {
  Double num = JulianCenturies(time);
  Double num2 = PolynomialSum(s_lambdaCoefficients, num);
  Double num3 = PolynomialSum(s_anomalyCoefficients, num);
  Double num4 = PolynomialSum(s_eccentricityCoefficients, num);
  Double num5 = Obliquity(num);
  Double num6 = TanOfDegree(num5 / 2);
  Double num7 = num6 * num6;
  Double num8 = num7 * SinOfDegree(2 * num2) - 2 * num4 * SinOfDegree(num3) + 4 * num4 * num7 * SinOfDegree(num3) * CosOfDegree(2 * num2) - 0.5 * Math::Pow(num7, 2) * SinOfDegree(4 * num2) - 1.25 * Math::Pow(num4, 2) * SinOfDegree(2 * num3);
  Double num9 = num8 / (Math::PI * 2);
  return CopySign(Math::Min(Math::Abs(num9), 0.5), num9);
}

Double CalendricalCalculationsHelper::AsLocalTime(Double apparentMidday, Double longitude) {
  Double time = apparentMidday - AsDayFraction(longitude);
  return apparentMidday - EquationOfTime(time);
}

Double CalendricalCalculationsHelper::Midday(Double date, Double longitude) {
  return AsLocalTime(date + 0.5, longitude) - AsDayFraction(longitude);
}

Double CalendricalCalculationsHelper::InitLongitude(Double longitude) {
  return NormalizeLongitude(longitude + 180) - 180;
}

Double CalendricalCalculationsHelper::MiddayAtPersianObservationSite(Double date) {
  return Midday(date, InitLongitude(52.5));
}

Double CalendricalCalculationsHelper::PeriodicTerm(Double julianCenturies, Int32 x, Double y, Double z) {
  return (Double)x * SinOfDegree(y + z * julianCenturies);
}

Double CalendricalCalculationsHelper::SumLongSequenceOfPeriodicTerms(Double julianCenturies) {
  Double num = 0;
  num += PeriodicTerm(julianCenturies, 403406, 270.54861, 0.9287892);
  num += PeriodicTerm(julianCenturies, 195207, 340.19128, 35999.1376958);
  num += PeriodicTerm(julianCenturies, 119433, 63.91854, 35999.4089666);
  num += PeriodicTerm(julianCenturies, 112392, 331.2622, 35998.7287385);
  num += PeriodicTerm(julianCenturies, 3891, 317.843, 71998.20261);
  num += PeriodicTerm(julianCenturies, 2819, 86.631, 71998.4403);
  num += PeriodicTerm(julianCenturies, 1721, 240.052, 36000.35726);
  num += PeriodicTerm(julianCenturies, 660, 310.26, 71997.4812);
  num += PeriodicTerm(julianCenturies, 350, 247.23, 32964.4678);
  num += PeriodicTerm(julianCenturies, 334, 260.87, -19.441);
  num += PeriodicTerm(julianCenturies, 314, 297.82, 445267.1117);
  num += PeriodicTerm(julianCenturies, 268, 343.14, 45036.884);
  num += PeriodicTerm(julianCenturies, 242, 166.79, 3.1008);
  num += PeriodicTerm(julianCenturies, 234, 81.53, 22518.4434);
  num += PeriodicTerm(julianCenturies, 158, 3.5, -19.9739);
  num += PeriodicTerm(julianCenturies, 132, 132.75, 65928.9345);
  num += PeriodicTerm(julianCenturies, 129, 182.95, 9038.0293);
  num += PeriodicTerm(julianCenturies, 114, 162.03, 3034.7684);
  num += PeriodicTerm(julianCenturies, 99, 29.8, 33718.148);
  num += PeriodicTerm(julianCenturies, 93, 266.4, 3034.448);
  num += PeriodicTerm(julianCenturies, 86, 249.2, -2280.773);
  num += PeriodicTerm(julianCenturies, 78, 157.6, 29929.992);
  num += PeriodicTerm(julianCenturies, 72, 257.8, 31556.493);
  num += PeriodicTerm(julianCenturies, 68, 185.1, 149.588);
  num += PeriodicTerm(julianCenturies, 64, 69.9, 9037.75);
  num += PeriodicTerm(julianCenturies, 46, 8, 107997.405);
  num += PeriodicTerm(julianCenturies, 38, 197.1, -4444.176);
  num += PeriodicTerm(julianCenturies, 37, 250.4, 151.771);
  num += PeriodicTerm(julianCenturies, 32, 65.3, 67555.316);
  num += PeriodicTerm(julianCenturies, 29, 162.7, 31556.08);
  num += PeriodicTerm(julianCenturies, 28, 341.5, -4561.54);
  num += PeriodicTerm(julianCenturies, 27, 291.6, 107996.706);
  num += PeriodicTerm(julianCenturies, 27, 98.5, 1221.655);
  num += PeriodicTerm(julianCenturies, 25, 146.7, 62894.167);
  num += PeriodicTerm(julianCenturies, 24, 110, 31437.369);
  num += PeriodicTerm(julianCenturies, 21, 5.2, 14578.298);
  num += PeriodicTerm(julianCenturies, 21, 342.6, -31931.757);
  num += PeriodicTerm(julianCenturies, 20, 230.9, 34777.243);
  num += PeriodicTerm(julianCenturies, 18, 256.1, 1221.999);
  num += PeriodicTerm(julianCenturies, 17, 45.3, 62894.511);
  num += PeriodicTerm(julianCenturies, 14, 242.9, -4442.039);
  num += PeriodicTerm(julianCenturies, 13, 115.2, 107997.909);
  num += PeriodicTerm(julianCenturies, 13, 151.8, 119.066);
  num += PeriodicTerm(julianCenturies, 13, 285.3, 16859.071);
  num += PeriodicTerm(julianCenturies, 12, 53.3, -4.578);
  num += PeriodicTerm(julianCenturies, 10, 126.6, 26895.292);
  num += PeriodicTerm(julianCenturies, 10, 205.7, -39.127);
  num += PeriodicTerm(julianCenturies, 10, 85.9, 12297.536);
  return num + PeriodicTerm(julianCenturies, 10, 146.1, 90073.778);
}

Double CalendricalCalculationsHelper::Aberration(Double julianCenturies) {
  return 9.74E-05 * CosOfDegree(177.63 + 35999.01848 * julianCenturies) - 0.005575;
}

Double CalendricalCalculationsHelper::Nutation(Double julianCenturies) {
  Double degree = PolynomialSum(s_coefficientsA, julianCenturies);
  Double degree2 = PolynomialSum(s_coefficientsB, julianCenturies);
  return -0.004778 * SinOfDegree(degree) - 0.0003667 * SinOfDegree(degree2);
}

Double CalendricalCalculationsHelper::Compute(Double time) {
  Double num = JulianCenturies(time);
  Double num2 = 282.7771834 + 36000.76953744 * num + 5.729577951308232E-06 * SumLongSequenceOfPeriodicTerms(num);
  Double longitude = num2 + Aberration(num) + Nutation(num);
  return InitLongitude(longitude);
}

Double CalendricalCalculationsHelper::AsSeason(Double longitude) {
  if (!(longitude < 0)) {
    return longitude;
  }
  return longitude + 360;
}

Double CalendricalCalculationsHelper::EstimatePrior(Double longitude, Double time) {
  Double num = time - 1.0145616361111112 * AsSeason(InitLongitude(Compute(time) - longitude));
  Double num2 = InitLongitude(Compute(num) - longitude);
  return Math::Min(time, num - 1.0145616361111112 * num2);
}

Int64 CalendricalCalculationsHelper::PersianNewYearOnOrBefore(Int64 numberOfDays) {
  Double date = numberOfDays;
  Double d = EstimatePrior(0, MiddayAtPersianObservationSite(date));
  Int64 num = (Int64)Math::Floor(d) - 1;
  Int64 num2 = num + 3;
  Int64 num3;
  for (num3 = num; num3 != num2; num3++) {
    Double time = MiddayAtPersianObservationSite(num3);
    Double num4 = Compute(time);
    if (0 <= num4 && num4 <= 2) {
      break;
    }
  }
  return num3 - 1;
}

void CalendricalCalculationsHelper::cctor() {
  s_startOf1810 = GetNumberOfDays(DateTime(1810, 1, 1));
  s_startOf1900Century = GetNumberOfDays(DateTime(1900, 1, 1));
  s_coefficients1900to1987 = rt::newarr<Array<Double>>(8);
  s_coefficients1800to1899 = rt::newarr<Array<Double>>(11);
  s_coefficients1700to1799 = rt::newarr<Array<Double>>(4);
  s_coefficients1620to1699 = rt::newarr<Array<Double>>(3);
  s_lambdaCoefficients = rt::newarr<Array<Double>>(3);
  s_anomalyCoefficients = rt::newarr<Array<Double>>(4);
  s_eccentricityCoefficients = rt::newarr<Array<Double>>(3);
  s_coefficients = rt::newarr<Array<Double>>(4);
  s_coefficientsA = rt::newarr<Array<Double>>(3);
  s_coefficientsB = rt::newarr<Array<Double>>(3);
  s_ephemerisCorrectionTable = rt::newarr<Array<EphemerisCorrectionAlgorithmMap>>(7);
}

} // namespace System::Private::CoreLib::System::Globalization::CalendricalCalculationsHelperNamespace
