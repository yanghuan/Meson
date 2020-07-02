#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(InternalEncoderBestFitFallback)
namespace InternalEncoderBestFitFallbackBufferNamespace {
CLASS(InternalEncoderBestFitFallbackBuffer) {
  private: static Object get_InternalSyncObject();
  public: Int32 get_Remaining();
  public: Boolean Fallback(Char charUnknown, Int32 index);
  public: Boolean Fallback(Char charUnknownHigh, Char charUnknownLow, Int32 index);
  public: Char GetNextChar();
  public: Boolean MovePrevious();
  public: void Reset();
  private: Char TryBestFit(Char cUnknown);
  private: Char _cBestFit;
  private: InternalEncoderBestFitFallback _oFallback;
  private: Int32 _iCount;
  private: Int32 _iSize;
  private: static Object s_InternalSyncObject;
};
} // namespace InternalEncoderBestFitFallbackBufferNamespace
using InternalEncoderBestFitFallbackBuffer = InternalEncoderBestFitFallbackBufferNamespace::InternalEncoderBestFitFallbackBuffer;
} // namespace System::Private::CoreLib::System::Text
