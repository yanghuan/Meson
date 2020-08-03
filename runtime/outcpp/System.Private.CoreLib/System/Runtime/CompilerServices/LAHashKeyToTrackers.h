#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace LAHashKeyToTrackersNamespace {
CLASS(LAHashKeyToTrackers) : public Object::in {
  private: Object _trackerOrTrackerSet;
  private: Object _laLocalKeyValueStore;
};
} // namespace LAHashKeyToTrackersNamespace
using LAHashKeyToTrackers = LAHashKeyToTrackersNamespace::LAHashKeyToTrackers;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
