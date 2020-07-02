#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::ObjectModel {
FORWARD(ReadOnlyCollection, T)
} // namespace System::Private::CoreLib::System::Collections::ObjectModel
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
FORWARDS(Int32)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)
FORWARDS(Boolean)
namespace AggregateExceptionNamespace {
using namespace ::System::Private::CoreLib::System::Collections::ObjectModel;
using namespace ::System::Private::CoreLib::System::Runtime::Serialization;
CLASS(AggregateException) {
  public: ReadOnlyCollection<Exception> get_InnerExceptions();
  public: String get_Message();
  private: Int32 get_InnerExceptionCount();
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