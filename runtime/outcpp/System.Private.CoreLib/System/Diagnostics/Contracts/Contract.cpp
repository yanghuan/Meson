#include "Contract-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Contracts::ContractNamespace {
void Contract::Assume(Boolean condition) {
};

void Contract::Assume(Boolean condition, String userMessage) {
};

void Contract::Assert(Boolean condition) {
};

void Contract::Assert(Boolean condition, String userMessage) {
};

void Contract::Requires(Boolean condition) {
};

void Contract::Requires(Boolean condition, String userMessage) {
};

void Contract::Ensures(Boolean condition) {
};

void Contract::Ensures(Boolean condition, String userMessage) {
};

void Contract::Invariant(Boolean condition) {
};

void Contract::Invariant(Boolean condition, String userMessage) {
};

Boolean Contract::ForAll(Int32 fromInclusive, Int32 toExclusive, Predicate<Int32> predicate) {
  return Boolean();
};

Boolean Contract::Exists(Int32 fromInclusive, Int32 toExclusive, Predicate<Int32> predicate) {
  return Boolean();
};

void Contract::EndContractBlock() {
};

void Contract::AssertMustUseRewriter(ContractFailureKind kind, String contractKind) {
};

void Contract::ReportFailure(ContractFailureKind failureKind, String userMessage, String conditionText, Exception innerException) {
};

} // namespace System::Private::CoreLib::System::Diagnostics::Contracts::ContractNamespace
