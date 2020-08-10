#pragma once

#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Text/EncoderFallbackBuffer.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(InternalEncoderBestFitFallback)
namespace InternalEncoderBestFitFallbackBufferNamespace {
CLASS(InternalEncoderBestFitFallbackBuffer) : public EncoderFallbackBuffer::in {
  private: static Object get_InternalSyncObject();
  public: Int32 get_Remaining();
  public: void ctor(InternalEncoderBestFitFallback fallback);
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
