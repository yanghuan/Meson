#include "__ExceptionInfo-dep.h"

namespace System::Private::CoreLib::System::Reflection::Emit::__ExceptionInfoNamespace {
void __ExceptionInfo___::MarkHelper(Int32 catchorfilterAddr, Int32 catchEndAddr, Type catchClass, Int32 type) {
};
void __ExceptionInfo___::MarkFilterAddr(Int32 filterAddr) {
};
void __ExceptionInfo___::MarkFaultAddr(Int32 faultAddr) {
};
void __ExceptionInfo___::MarkCatchAddr(Int32 catchAddr, Type catchException) {
};
void __ExceptionInfo___::MarkFinallyAddr(Int32 finallyAddr, Int32 endCatchAddr) {
};
void __ExceptionInfo___::Done(Int32 endAddr) {
};
Int32 __ExceptionInfo___::GetStartAddress() {
  return Int32();
};
Int32 __ExceptionInfo___::GetEndAddress() {
  return Int32();
};
Int32 __ExceptionInfo___::GetFinallyEndAddress() {
  return Int32();
};
Label __ExceptionInfo___::GetEndLabel() {
  return Label();
};
Array<Int32> __ExceptionInfo___::GetFilterAddresses() {
  return Array<Int32>();
};
Array<Int32> __ExceptionInfo___::GetCatchAddresses() {
  return Array<Int32>();
};
Array<Int32> __ExceptionInfo___::GetCatchEndAddresses() {
  return Array<Int32>();
};
Array<Type> __ExceptionInfo___::GetCatchClass() {
  return Array<Type>();
};
Int32 __ExceptionInfo___::GetNumberOfCatches() {
  return Int32();
};
Array<Int32> __ExceptionInfo___::GetExceptionTypes() {
  return Array<Int32>();
};
void __ExceptionInfo___::SetFinallyEndLabel(Label lbl) {
};
Boolean __ExceptionInfo___::IsInner(__ExceptionInfo exc) {
  return Boolean();
};
Int32 __ExceptionInfo___::GetCurrentState() {
  return Int32();
};
} // namespace System::Private::CoreLib::System::Reflection::Emit::__ExceptionInfoNamespace
