#pragma once

#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
namespace GCGenerationInfoNamespace {
struct GCGenerationInfo : public valueType<GCGenerationInfo> {
  public: Int64 get_SizeBeforeBytes() { return SizeBeforeBytes; }
  public: Int64 get_FragmentationBeforeBytes() { return FragmentationBeforeBytes; }
  public: Int64 get_SizeAfterBytes() { return SizeAfterBytes; }
  public: Int64 get_FragmentationAfterBytes() { return FragmentationAfterBytes; }
  private: Int64 SizeBeforeBytes;
  private: Int64 FragmentationBeforeBytes;
  private: Int64 SizeAfterBytes;
  private: Int64 FragmentationAfterBytes;
};
} // namespace GCGenerationInfoNamespace
using GCGenerationInfo = GCGenerationInfoNamespace::GCGenerationInfo;
} // namespace System::Private::CoreLib::System
