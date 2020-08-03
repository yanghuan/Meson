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
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARDS(Int32)
FORWARD(String)
namespace AggregateExceptionNamespace {
using namespace Collections::Generic;
using namespace Collections::ObjectModel;
using namespace Runtime::ExceptionServices;
using namespace Runtime::Serialization;
using Collections::Generic::IList;
CLASS(AggregateException) : public Exception::in {
  public: ReadOnlyCollection<Exception> get_InnerExceptions();
  public: String get_Message();
  private: Int32 get_InnerExceptionCount();
  public: void Ctor();
  public: void Ctor(String message);
  public: void Ctor(String message, Exception innerException);
  public: void Ctor(IEnumerable<Exception> innerExceptions);
  public: void Ctor(Array<Exception> innerExceptions);
  public: void Ctor(String message, IEnumerable<Exception> innerExceptions);
  public: void Ctor(String message, Array<Exception> innerExceptions);
  private: void Ctor(String message, IList<Exception> innerExceptions);
  public: void Ctor(IEnumerable<ExceptionDispatchInfo> innerExceptionInfos);
  public: void Ctor(String message, IEnumerable<ExceptionDispatchInfo> innerExceptionInfos);
  private: void Ctor(String message, IList<ExceptionDispatchInfo> innerExceptionInfos);
  protected: void Ctor(SerializationInfo info, StreamingContext context);
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
