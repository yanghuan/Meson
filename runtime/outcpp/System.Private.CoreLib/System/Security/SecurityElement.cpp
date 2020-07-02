#include "SecurityElement-dep.h"

#include <System.Private.CoreLib/System/Security/SecurityElement-dep.h>

namespace System::Private::CoreLib::System::Security::SecurityElementNamespace {
String SecurityElement___::get_Tag() {
  return nullptr;
};
void SecurityElement___::set_Tag(String value) {
  return void();
};
Hashtable SecurityElement___::get_Attributes() {
  return nullptr;
};
void SecurityElement___::set_Attributes(Hashtable value) {
  return void();
};
String SecurityElement___::get_Text() {
  return nullptr;
};
void SecurityElement___::set_Text(String value) {
  return void();
};
ArrayList SecurityElement___::get_Children() {
  return nullptr;
};
void SecurityElement___::set_Children(ArrayList value) {
  return void();
};
void SecurityElement___::ConvertSecurityElementFactories() {
  return void();
};
void SecurityElement___::AddAttributeSafe(String name, String value) {
  return void();
};
void SecurityElement___::AddAttribute(String name, String value) {
  return void();
};
void SecurityElement___::AddChild(SecurityElement child) {
  return void();
};
Boolean SecurityElement___::Equal(SecurityElement other) {
  return Boolean();
};
SecurityElement SecurityElement___::Copy() {
  return nullptr;
};
Boolean SecurityElement___::IsValidTag(String tag) {
  return Boolean();
};
Boolean SecurityElement___::IsValidText(String text) {
  return Boolean();
};
Boolean SecurityElement___::IsValidAttributeName(String name) {
  return Boolean();
};
Boolean SecurityElement___::IsValidAttributeValue(String value) {
  return Boolean();
};
String SecurityElement___::GetEscapeSequence(Char c) {
  return nullptr;
};
String SecurityElement___::Escape(String str) {
  return nullptr;
};
String SecurityElement___::GetUnescapeSequence(String str, Int32 index, Int32& newIndex) {
  return nullptr;
};
String SecurityElement___::Unescape(String str) {
  return nullptr;
};
String SecurityElement___::ToString() {
  return nullptr;
};
void SecurityElement___::ToString(String indent, Object obj, Action<Object, String> write) {
  return void();
};
String SecurityElement___::Attribute(String name) {
  return nullptr;
};
SecurityElement SecurityElement___::SearchForChildByTag(String tag) {
  return nullptr;
};
String SecurityElement___::SearchForTextOfTag(String tag) {
  return nullptr;
};
SecurityElement SecurityElement___::FromString(String xml) {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Security::SecurityElementNamespace
