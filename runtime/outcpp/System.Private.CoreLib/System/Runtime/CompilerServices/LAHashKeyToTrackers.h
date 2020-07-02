#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace LAHashKeyToTrackersNamespace {
CLASS(LAHashKeyToTrackers) {
  private: Object _trackerOrTrackerSet;
  private: Object _laLocalKeyValueStore;
};
} // namespace LAHashKeyToTrackersNamespace
using LAHashKeyToTrackers = LAHashKeyToTrackersNamespace::LAHashKeyToTrackers;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
