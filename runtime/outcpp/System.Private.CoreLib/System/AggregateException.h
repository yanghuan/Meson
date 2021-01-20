#pragma once

#include <System.Private.CoreLib/System/Exception.h>

namespace System::Private::CoreLib::System::Collections::ObjectModel {
FORWARD(ReadOnlyCollection, T)
} // namespace System::Private::CoreLib::System::Collections::ObjectModel
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IList, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::ExceptionServices {
FORWARD(ExceptionDispatchInfo)
} // namespace System::Private::CoreLib::System::Runtime::ExceptionServices
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARD_(Func)
FORWARDS(Int32)
FORWARD(String)
namespace AggregateExceptionNamespace {
using namespace System::Collections::Generic;
using namespace System::Collections::ObjectModel;
using namespace System::Runtime::ExceptionServices;
using namespace System::Runtime::Serialization;
CLASS(AggregateException) : public Exception::in {
  public: ReadOnlyCollection<Exception> get_InnerExceptions();
  public: String get_Message();
  private: Int32 get_InnerExceptionCount();
  public: void ctor();
  public: void ctor(String message);
  public: void ctor(String message, Exception innerException);
  public: void ctor(IEnumerable<Exception> innerExceptions);
  public: void ctor(Array<Exception> innerExceptions);
  public: void ctor(String message, IEnumerable<Exception> innerExceptions);
  public: void ctor(String message, Array<Exception> innerExceptions);
  public: void ctor(String message, IList<Exception> innerExceptions);
  public: void ctor(IEnumerable<ExceptionDispatchInfo> innerExceptionInfos);
  public: void ctor(String message, IEnumerable<ExceptionDispatchInfo> innerExceptionInfos);
  public: void ctor(String message, IList<ExceptionDispatchInfo> innerExceptionInfos);
  public: void ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  public: Exception GetBaseException();
  public: void Handle(Func<Exception, Boolean> predicate);
  public: AggregateException Flatten();
  public: String ToString();
  private: ReadOnlyCollection<Exception> m_innerExceptions;
};
} // namespace AggregateExceptionNamespace
using AggregateException = AggregateExceptionNamespace::AggregateException;
} // namespace System::Private::CoreLib::System
