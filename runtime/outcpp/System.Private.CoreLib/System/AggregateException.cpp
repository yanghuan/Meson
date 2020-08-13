#include "AggregateException-dep.h"

#include <System.Private.CoreLib/System/AggregateException-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/List-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilderCache-dep.h>

namespace System::Private::CoreLib::System::AggregateExceptionNamespace {
using namespace System::Collections::Generic;
using namespace System::Text;

ReadOnlyCollection<Exception> AggregateException___::get_InnerExceptions() {
  return m_innerExceptions;
}

String AggregateException___::get_Message() {
  if (m_innerExceptions->get_Count() == 0) {
  }
  StringBuilder stringBuilder = StringBuilderCache::Acquire();
}

Int32 AggregateException___::get_InnerExceptionCount() {
  return get_InnerExceptions()->get_Count();
}

void AggregateException___::ctor() {
  m_innerExceptions = rt::newobj<ReadOnlyCollection<Exception>>(Array<>::in::Empty<Exception>());
}

void AggregateException___::ctor(String message) {
  m_innerExceptions = rt::newobj<ReadOnlyCollection<Exception>>(Array<>::in::Empty<Exception>());
}

void AggregateException___::ctor(String message, Exception innerException) {
  if (innerException == nullptr) {
    rt::throw_exception<ArgumentNullException>("innerException");
  }
  m_innerExceptions = rt::newobj<ReadOnlyCollection<Exception>>(rt::newarr<Array<Exception>>(1));
}

void AggregateException___::ctor(IEnumerable<Exception> innerExceptions) {
}

void AggregateException___::ctor(Array<Exception> innerExceptions) {
}

void AggregateException___::ctor(String message, IEnumerable<Exception> innerExceptions) {
}

void AggregateException___::ctor(String message, Array<Exception> innerExceptions) {
}

void AggregateException___::ctor(String message, IList<Exception> innerExceptions) {
  if (innerExceptions == nullptr) {
    rt::throw_exception<ArgumentNullException>("innerExceptions");
  }
  Array<Exception> array = rt::newarr<Array<Exception>>(innerExceptions->get_Count());
  for (Int32 i = 0; i < array->get_Length(); i++) {
    array[i] = innerExceptions[i];
    if (array[i] == nullptr) {
      rt::throw_exception<ArgumentException>(SR::get_AggregateException_ctor_InnerExceptionNull());
    }
  }
  m_innerExceptions = rt::newobj<ReadOnlyCollection<Exception>>(array);
}

void AggregateException___::ctor(IEnumerable<ExceptionDispatchInfo> innerExceptionInfos) {
}

void AggregateException___::ctor(String message, IEnumerable<ExceptionDispatchInfo> innerExceptionInfos) {
}

void AggregateException___::ctor(String message, IList<ExceptionDispatchInfo> innerExceptionInfos) {
  if (innerExceptionInfos == nullptr) {
    rt::throw_exception<ArgumentNullException>("innerExceptionInfos");
  }
  Array<Exception> array = rt::newarr<Array<Exception>>(innerExceptionInfos->get_Count());
  for (Int32 i = 0; i < array->get_Length(); i++) {
    ExceptionDispatchInfo exceptionDispatchInfo = innerExceptionInfos[i];
    if (exceptionDispatchInfo != nullptr) {
      array[i] = exceptionDispatchInfo->get_SourceException();
    }
    if (array[i] == nullptr) {
      rt::throw_exception<ArgumentException>(SR::get_AggregateException_ctor_InnerExceptionNull());
    }
  }
  m_innerExceptions = rt::newobj<ReadOnlyCollection<Exception>>(array);
}

void AggregateException___::ctor(SerializationInfo info, StreamingContext context) {
  if (info == nullptr) {
    rt::throw_exception<ArgumentNullException>("info");
  }
}

void AggregateException___::GetObjectData(SerializationInfo info, StreamingContext context) {
}

Exception AggregateException___::GetBaseException() {
  Exception ex = (AggregateException)this;
  AggregateException ex2 = (AggregateException)this;
  while (ex2 != nullptr && ex2->get_InnerExceptions()->get_Count() == 1) {
    ex = ex->get_InnerException();
    ex2 = (rt::as<AggregateException>(ex));
  }
  return ex;
}

void AggregateException___::Handle(Func<Exception, Boolean> predicate) {
  if (predicate == nullptr) {
    rt::throw_exception<ArgumentNullException>("predicate");
  }
  List<Exception> list = nullptr;
  for (Int32 i = 0; i < m_innerExceptions->get_Count(); i++) {
    if (!predicate(m_innerExceptions[i])) {
      if (list == nullptr) {
        list = rt::newobj<List<Exception>>();
      }
      list->Add(m_innerExceptions[i]);
    }
  }
  if (list != nullptr) {
    rt::throw_exception<AggregateException>(get_Message(), list);
  }
}

AggregateException AggregateException___::Flatten() {
  List<Exception> list = rt::newobj<List<Exception>>();
  List<AggregateException> list2 = rt::newobj<List<AggregateException>>();
  Int32 num = 0;
  while (list2->get_Count() > num) {
    ReadOnlyCollection<Exception> innerExceptions = list2[num++]->get_InnerExceptions();
    for (Int32 i = 0; i < innerExceptions->get_Count(); i++) {
      Exception ex = innerExceptions[i];
      if (ex != nullptr) {
        AggregateException ex2 = rt::as<AggregateException>(ex);
        if (ex2 != nullptr) {
          list2->Add(ex2);
        } else {
          list->Add(ex);
        }
      }
    }
  }
}

String AggregateException___::ToString() {
  StringBuilder stringBuilder = rt::newobj<StringBuilder>();
}

} // namespace System::Private::CoreLib::System::AggregateExceptionNamespace
