#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Threading::Tasks {
namespace VoidTaskResultNamespace {
struct VoidTaskResult : public valueType<VoidTaskResult> {
};
} // namespace VoidTaskResultNamespace
using VoidTaskResult = VoidTaskResultNamespace::VoidTaskResult;
} // namespace System::Private::CoreLib::System::Threading::Tasks
