#include "Contract-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Contracts::ContractNamespace {
void Contract::Assume(Boolean condition) {
  return void();
};
void Contract::Assume(Boolean condition, String userMessage) {
  return void();
};
void Contract::Assert(Boolean condition) {
  return void();
};
void Contract::Assert(Boolean condition, String userMessage) {
  return void();
};
void Contract::Requires(Boolean condition) {
  return void();
};
void Contract::Requires(Boolean condition, String userMessage) {
  return void();
};
void Contract::Ensures(Boolean condition) {
  return void();
};
void Contract::Ensures(Boolean condition, String userMessage) {
  return void();
};
void Contract::Invariant(Boolean condition) {
  return void();
};
void Contract::Invariant(Boolean condition, String userMessage) {
  return void();
};
Boolean Contract::ForAll(Int32 fromInclusive, Int32 toExclusive, Predicate<Int32> predicate) {
  return Boolean();
};
Boolean Contract::Exists(Int32 fromInclusive, Int32 toExclusive, Predicate<Int32> predicate) {
  return Boolean();
};
void Contract::EndContractBlock() {
  return void();
};
void Contract::AssertMustUseRewriter(ContractFailureKind kind, String contractKind) {
  return void();
};
void Contract::ReportFailure(ContractFailureKind failureKind, String userMessage, String conditionText, Exception innerException) {
  return void();
};
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts::ContractNamespace
