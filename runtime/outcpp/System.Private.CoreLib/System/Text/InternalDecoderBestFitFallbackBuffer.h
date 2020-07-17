#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Char.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Text {
FORWARD(InternalDecoderBestFitFallback)
namespace InternalDecoderBestFitFallbackBufferNamespace {
CLASS(InternalDecoderBestFitFallbackBuffer) {
  private: static Object get_InternalSyncObject();
  public: Int32 get_Remaining();
  public: void Ctor(InternalDecoderBestFitFallback fallback);
  public: Boolean Fallback(Array<Byte> bytesUnknown, Int32 index);
  public: Char GetNextChar();
  public: Boolean MovePrevious();
  public: void Reset();
  public: Int32 InternalFallback(Array<Byte> bytes, Byte* pBytes);
  private: Char TryBestFit(Array<Byte> bytesCheck);
  private: Char _cBestFit;
  private: Int32 _iCount;
  private: Int32 _iSize;
  private: InternalDecoderBestFitFallback _oFallback;
  private: static Object s_InternalSyncObject;
};
} // namespace InternalDecoderBestFitFallbackBufferNamespace
using InternalDecoderBestFitFallbackBuffer = InternalDecoderBestFitFallbackBufferNamespace::InternalDecoderBestFitFallbackBuffer;
} // namespace System::Private::CoreLib::System::Text
