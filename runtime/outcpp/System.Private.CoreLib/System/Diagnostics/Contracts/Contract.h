#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
FORWARDS(Int32)
FORWARD(Predicate, T)
FORWARD(Exception)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Contracts {
enum class ContractFailureKind;
namespace ContractNamespace {
class Contract {
  public: static void Assume(Boolean condition);
  public: static void Assume(Boolean condition, String userMessage);
  public: static void Assert(Boolean condition);
  public: static void Assert(Boolean condition, String userMessage);
  public: static void Requires(Boolean condition);
  public: static void Requires(Boolean condition, String userMessage);
  public: static void Ensures(Boolean condition);
  public: static void Ensures(Boolean condition, String userMessage);
  public: static void Invariant(Boolean condition);
  public: static void Invariant(Boolean condition, String userMessage);
  public: static Boolean ForAll(Int32 fromInclusive, Int32 toExclusive, Predicate<Int32> predicate);
  public: static Boolean Exists(Int32 fromInclusive, Int32 toExclusive, Predicate<Int32> predicate);
  public: static void EndContractBlock();
  private: static void AssertMustUseRewriter(ContractFailureKind kind, String contractKind);
  private: static void ReportFailure(ContractFailureKind failureKind, String userMessage, String conditionText, Exception innerException);
};
} // namespace ContractNamespace
using Contract = ContractNamespace::Contract;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
