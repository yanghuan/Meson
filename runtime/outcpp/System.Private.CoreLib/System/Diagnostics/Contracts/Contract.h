#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Exception)
FORWARDS(Int32)
FORWARD(Predicate, T)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Diagnostics::Contracts {
enum class ContractFailureKind;
namespace ContractNamespace {
using namespace Collections::Generic;
class Contract : public Object::in {
  public: static void Assume(Boolean condition);
  public: static void Assume(Boolean condition, String userMessage);
  public: static void Assert(Boolean condition);
  public: static void Assert(Boolean condition, String userMessage);
  public: static void Requires(Boolean condition);
  public: static void Requires(Boolean condition, String userMessage);
  public: template <class TException>
  static void Requires(Boolean condition);
  public: template <class TException>
  static void Requires(Boolean condition, String userMessage);
  public: static void Ensures(Boolean condition);
  public: static void Ensures(Boolean condition, String userMessage);
  public: template <class TException>
  static void EnsuresOnThrow(Boolean condition);
  public: template <class TException>
  static void EnsuresOnThrow(Boolean condition, String userMessage);
  public: template <class T>
  static T Result();
  public: template <class T>
  static T ValueAtReturn(T& value);
  public: template <class T>
  static T OldValue(T value);
  public: static void Invariant(Boolean condition);
  public: static void Invariant(Boolean condition, String userMessage);
  public: static Boolean ForAll(Int32 fromInclusive, Int32 toExclusive, Predicate<Int32> predicate);
  public: template <class T>
  static Boolean ForAll(IEnumerable<T> collection, Predicate<T> predicate);
  public: static Boolean Exists(Int32 fromInclusive, Int32 toExclusive, Predicate<Int32> predicate);
  public: template <class T>
  static Boolean Exists(IEnumerable<T> collection, Predicate<T> predicate);
  public: static void EndContractBlock();
  private: static void AssertMustUseRewriter(ContractFailureKind kind, String contractKind);
  private: static void ReportFailure(ContractFailureKind failureKind, String userMessage, String conditionText, Exception innerException);
};
} // namespace ContractNamespace
using Contract = ContractNamespace::Contract;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
