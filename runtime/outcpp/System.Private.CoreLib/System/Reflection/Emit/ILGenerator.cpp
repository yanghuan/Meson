#include "ILGenerator-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Buffers/Binary/BinaryPrimitives-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/IO/TextWriter-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/__FixupData-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/EnumBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/LineNumberInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/MethodBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ModuleBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/OpCodes-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/OperandType.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ScopeAction.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ScopeTree-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SignatureHelper-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/StackBehaviour.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SymbolMethod-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/TypeBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/FieldAttributes.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::ILGeneratorNamespace {
using namespace System::Buffers::Binary;
using namespace System::IO;

Int32 ILGenerator___::get_CurrExcStackCount() {
  return m_currExcStackCount;
}

Array<__ExceptionInfo> ILGenerator___::get_CurrExcStack() {
  return m_currExcStack;
}

Int32 ILGenerator___::get_ILOffset() {
  return m_length;
}

void ILGenerator___::ctor(MethodInfo methodBuilder) {
}

void ILGenerator___::ctor(MethodInfo methodBuilder, Int32 size) {
  m_ILStream = rt::newarr<Array<Byte>>(Math::Max(size, 16));
  m_ScopeTree = rt::newobj<ScopeTree>();
  m_LineNumberInfo = rt::newobj<LineNumberInfo>();
  m_methodBuilder = methodBuilder;
  MethodBuilder methodBuilder2 = rt::as<MethodBuilder>(m_methodBuilder);
  m_localSignature = SignatureHelper::in::GetLocalVarSigHelper(((Object)methodBuilder2 != nullptr) ? methodBuilder2->GetTypeBuilder()->get_Module() : nullptr);
}

void ILGenerator___::RecordTokenFixup() {
  if (m_RelocFixupList == nullptr) {
    m_RelocFixupList = rt::newarr<Array<Int32>>(8);
  } else if (m_RelocFixupList->get_Length() <= m_RelocFixupCount) {
    m_RelocFixupList = EnlargeArray(m_RelocFixupList);
  }

  m_RelocFixupList[m_RelocFixupCount++] = m_length;
}

void ILGenerator___::InternalEmit(OpCode opcode) {
  Int16 value = opcode.get_Value();
  if (opcode.get_Size() != 1) {
    BinaryPrimitives::WriteInt16BigEndian(MemoryExtensions::AsSpan(m_ILStream, m_length), value);
    m_length += 2;
  } else {
    m_ILStream[m_length++] = (Byte)value;
  }
  UpdateStackSize(opcode, opcode.StackChange());
}

void ILGenerator___::UpdateStackSize(OpCode opcode, Int32 stackchange) {
  m_maxMidStackCur += stackchange;
  if (m_maxMidStackCur > m_maxMidStack) {
    m_maxMidStack = m_maxMidStackCur;
  } else if (m_maxMidStackCur < 0) {
    m_maxMidStackCur = 0;
  }

  if (opcode.EndsUncondJmpBlk()) {
    m_maxStackSize += m_maxMidStack;
    m_maxMidStack = 0;
    m_maxMidStackCur = 0;
  }
}

Int32 ILGenerator___::GetMethodToken(MethodBase method, Array<Type> optionalParameterTypes, Boolean useMethodDef) {
  return ((ModuleBuilder)m_methodBuilder->get_Module())->GetMethodTokenInternal(method, optionalParameterTypes, useMethodDef);
}

SignatureHelper ILGenerator___::GetMemberRefSignature(CallingConventions call, Type returnType, Array<Type> parameterTypes, Array<Type> optionalParameterTypes) {
  return GetMemberRefSignature(call, returnType, parameterTypes, optionalParameterTypes, 0);
}

SignatureHelper ILGenerator___::GetMemberRefSignature(CallingConventions call, Type returnType, Array<Type> parameterTypes, Array<Type> optionalParameterTypes, Int32 cGenericParameters) {
  return ((ModuleBuilder)m_methodBuilder->get_Module())->GetMemberRefSignature(call, returnType, parameterTypes, optionalParameterTypes, cGenericParameters);
}

Array<Byte> ILGenerator___::BakeByteArray() {
  if (m_currExcStackCount != 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_UnclosedExceptionBlock());
  }
  if (m_length == 0) {
    return nullptr;
  }
  Array<Byte> array = rt::newarr<Array<Byte>>(m_length);
  Array<>::in::Copy(m_ILStream, array, m_length);
  for (Int32 i = 0; i < m_fixupCount; i++) {
    __FixupData _FixupData = m_fixupData[i];
    Int32 num = GetLabelPos(_FixupData.m_fixupLabel) - (_FixupData.m_fixupPos + _FixupData.m_fixupInstSize);
    if (_FixupData.m_fixupInstSize == 1) {
      if (num < -128 || num > 127) {
        rt::throw_exception<NotSupportedException>(SR::Format(SR::get_NotSupported_IllegalOneByteBranch(), _FixupData.m_fixupPos, num));
      }
      array[_FixupData.m_fixupPos] = (Byte)num;
    } else {
      BinaryPrimitives::WriteInt32LittleEndian(MemoryExtensions::AsSpan(array, _FixupData.m_fixupPos), num);
    }
  }
  return array;
}

Array<__ExceptionInfo> ILGenerator___::GetExceptions() {
  if (m_currExcStackCount != 0) {
    rt::throw_exception<NotSupportedException>(SR::get_Argument_UnclosedExceptionBlock());
  }
  if (m_exceptionCount == 0) {
    return nullptr;
  }
  Array<__ExceptionInfo> array = rt::newarr<Array<__ExceptionInfo>>(m_exceptionCount);
  Array<>::in::Copy(m_exceptions, array, m_exceptionCount);
  SortExceptions(array);
  return array;
}

void ILGenerator___::EnsureCapacity(Int32 size) {
  if (m_length + size >= m_ILStream->get_Length()) {
    IncreaseCapacity(size);
  }
}

void ILGenerator___::IncreaseCapacity(Int32 size) {
  Array<Byte> array = rt::newarr<Array<Byte>>(Math::Max(m_ILStream->get_Length() * 2, m_length + size));
  Array<>::in::Copy(m_ILStream, array, m_ILStream->get_Length());
  m_ILStream = array;
}

void ILGenerator___::PutInteger4(Int32 value) {
  BinaryPrimitives::WriteInt32LittleEndian(MemoryExtensions::AsSpan(m_ILStream, m_length), value);
  m_length += 4;
}

Int32 ILGenerator___::GetLabelPos(Label lbl) {
  Int32 labelValue = lbl.GetLabelValue();
  if (labelValue < 0 || labelValue >= m_labelCount || m_labelList == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_BadLabel());
  }
  if (m_labelList[labelValue] < 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_BadLabelContent());
  }
  return m_labelList[labelValue];
}

void ILGenerator___::AddFixup(Label lbl, Int32 pos, Int32 instSize) {
  if (m_fixupData == nullptr) {
    m_fixupData = rt::newarr<Array<__FixupData>>(8);
  } else if (m_fixupData->get_Length() <= m_fixupCount) {
    m_fixupData = EnlargeArray(m_fixupData);
  }

  m_fixupData[m_fixupCount++] = __FixupData();
}

Int32 ILGenerator___::GetMaxStackSize() {
  return m_maxStackSize;
}

void ILGenerator___::SortExceptions(Array<__ExceptionInfo> exceptions) {
  for (Int32 i = 0; i < exceptions->get_Length(); i++) {
    Int32 num = i;
    for (Int32 j = i + 1; j < exceptions->get_Length(); j++) {
      if (exceptions[num]->IsInner(exceptions[j])) {
        num = j;
      }
    }
    __ExceptionInfo _ExceptionInfo = exceptions[i];
    exceptions[i] = exceptions[num];
    exceptions[num] = _ExceptionInfo;
  }
}

Array<Int32> ILGenerator___::GetTokenFixups() {
  if (m_RelocFixupCount == 0) {
    return nullptr;
  }
  Array<Int32> array = rt::newarr<Array<Int32>>(m_RelocFixupCount);
  Array<>::in::Copy(m_RelocFixupList, array, m_RelocFixupCount);
  return array;
}

void ILGenerator___::Emit(OpCode opcode) {
  EnsureCapacity(3);
  InternalEmit(opcode);
}

void ILGenerator___::Emit(OpCode opcode, Byte arg) {
  EnsureCapacity(4);
  InternalEmit(opcode);
  m_ILStream[m_length++] = arg;
}

void ILGenerator___::Emit(OpCode opcode, SByte arg) {
  EnsureCapacity(4);
  InternalEmit(opcode);
  m_ILStream[m_length++] = (Byte)arg;
}

void ILGenerator___::Emit(OpCode opcode, Int16 arg) {
  EnsureCapacity(5);
  InternalEmit(opcode);
  BinaryPrimitives::WriteInt16LittleEndian(MemoryExtensions::AsSpan(m_ILStream, m_length), arg);
  m_length += 2;
}

void ILGenerator___::Emit(OpCode opcode, Int32 arg) {
  if (opcode.Equals(OpCodes::in::Ldc_I4)) {
    OpCode opCode;
    switch (arg.get()) {
      case -1:
        opCode = OpCodes::in::Ldc_I4_M1;
        goto IL_009b;
      case 0:
        opCode = OpCodes::in::Ldc_I4_0;
        goto IL_009b;
      case 1:
        opCode = OpCodes::in::Ldc_I4_1;
        goto IL_009b;
      case 2:
        opCode = OpCodes::in::Ldc_I4_2;
        goto IL_009b;
      case 3:
        opCode = OpCodes::in::Ldc_I4_3;
        goto IL_009b;
      case 4:
        opCode = OpCodes::in::Ldc_I4_4;
        goto IL_009b;
      case 5:
        opCode = OpCodes::in::Ldc_I4_5;
        goto IL_009b;
      case 6:
        opCode = OpCodes::in::Ldc_I4_6;
        goto IL_009b;
      case 7:
        opCode = OpCodes::in::Ldc_I4_7;
        goto IL_009b;
      case 8:
        {
          opCode = OpCodes::in::Ldc_I4_8;
          goto IL_009b;
        }
      IL_009b:
        opcode = opCode;
        Emit(opcode);
        return;
    }
    if (arg >= -128 && arg <= 127) {
      Emit(OpCodes::in::Ldc_I4_S, (SByte)arg);
      return;
    }
  } else if (opcode.Equals(OpCodes::in::Ldarg)) {
    if ((UInt32)arg <= 3u) {
      OpCode opCode;
      switch (arg.get()) {
        case 0:
          opCode = OpCodes::in::Ldarg_0;
          break;
        case 1:
          opCode = OpCodes::in::Ldarg_1;
          break;
        case 2:
          opCode = OpCodes::in::Ldarg_2;
          break;
        default:
          opCode = OpCodes::in::Ldarg_3;
          break;
      }
      Emit(opCode);
      return;
    }
    if ((UInt32)arg <= 255u) {
      Emit(OpCodes::in::Ldarg_S, (Byte)arg);
      return;
    }
    if ((UInt32)arg <= 65535u) {
      Emit(OpCodes::in::Ldarg, (Int16)arg);
      return;
    }
  } else if (opcode.Equals(OpCodes::in::Ldarga)) {
    if ((UInt32)arg <= 255u) {
      Emit(OpCodes::in::Ldarga_S, (Byte)arg);
      return;
    }
    if ((UInt32)arg <= 65535u) {
      Emit(OpCodes::in::Ldarga, (Int16)arg);
      return;
    }
  } else if (opcode.Equals(OpCodes::in::Starg)) {
    if ((UInt32)arg <= 255u) {
      Emit(OpCodes::in::Starg_S, (Byte)arg);
      return;
    }
    if ((UInt32)arg <= 65535u) {
      Emit(OpCodes::in::Starg, (Int16)arg);
      return;
    }
  }



  EnsureCapacity(7);
  InternalEmit(opcode);
  PutInteger4(arg);
}

void ILGenerator___::Emit(OpCode opcode, MethodInfo meth) {
  if (meth == nullptr) {
    rt::throw_exception<ArgumentNullException>("meth");
  }
  if (opcode.Equals(OpCodes::in::Call) || opcode.Equals(OpCodes::in::Callvirt) || opcode.Equals(OpCodes::in::Newobj)) {
    EmitCall(opcode, meth, nullptr);
    return;
  }
  Boolean useMethodDef = opcode.Equals(OpCodes::in::Ldtoken) || opcode.Equals(OpCodes::in::Ldftn) || opcode.Equals(OpCodes::in::Ldvirtftn);
  Int32 methodToken = GetMethodToken(meth, nullptr, useMethodDef);
  EnsureCapacity(7);
  InternalEmit(opcode);
  UpdateStackSize(opcode, 0);
  RecordTokenFixup();
  PutInteger4(methodToken);
}

void ILGenerator___::EmitCalli(OpCode opcode, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, Array<Type> optionalParameterTypes) {
  Int32 num = 0;
  if (optionalParameterTypes != nullptr && (callingConvention & CallingConventions::VarArgs) == 0) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_NotAVarArgCallingConvention());
  }
  ModuleBuilder moduleBuilder = (ModuleBuilder)m_methodBuilder->get_Module();
  SignatureHelper memberRefSignature = GetMemberRefSignature(callingConvention, returnType, parameterTypes, optionalParameterTypes);
  EnsureCapacity(7);
  Emit(OpCodes::in::Calli);
  if (returnType != typeof<void>()) {
    num++;
  }
  if (parameterTypes != nullptr) {
    num -= parameterTypes->get_Length();
  }
  if (optionalParameterTypes != nullptr) {
    num -= optionalParameterTypes->get_Length();
  }
  if ((callingConvention & CallingConventions::HasThis) == CallingConventions::HasThis) {
    num--;
  }
  num--;
  UpdateStackSize(OpCodes::in::Calli, num);
  RecordTokenFixup();
  PutInteger4(moduleBuilder->GetSignatureToken(memberRefSignature).get_Token());
}

void ILGenerator___::EmitCalli(OpCode opcode, CallingConvention unmanagedCallConv, Type returnType, Array<Type> parameterTypes) {
  Int32 num = 0;
  Int32 num2 = 0;
  ModuleBuilder moduleBuilder = (ModuleBuilder)m_methodBuilder->get_Module();
  if (parameterTypes != nullptr) {
    num2 = parameterTypes->get_Length();
  }
  SignatureHelper methodSigHelper = SignatureHelper::in::GetMethodSigHelper(moduleBuilder, unmanagedCallConv, returnType);
  if (parameterTypes != nullptr) {
    for (Int32 i = 0; i < num2; i++) {
      methodSigHelper->AddArgument(parameterTypes[i]);
    }
  }
  if (returnType != typeof<void>()) {
    num++;
  }
  if (parameterTypes != nullptr) {
    num -= num2;
  }
  num--;
  UpdateStackSize(OpCodes::in::Calli, num);
  EnsureCapacity(7);
  Emit(OpCodes::in::Calli);
  RecordTokenFixup();
  PutInteger4(moduleBuilder->GetSignatureToken(methodSigHelper).get_Token());
}

void ILGenerator___::EmitCall(OpCode opcode, MethodInfo methodInfo, Array<Type> optionalParameterTypes) {
  if (methodInfo == nullptr) {
    rt::throw_exception<ArgumentNullException>("methodInfo");
  }
  if (!opcode.Equals(OpCodes::in::Call) && !opcode.Equals(OpCodes::in::Callvirt) && !opcode.Equals(OpCodes::in::Newobj)) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_NotMethodCallOpcode(), "opcode");
  }
  Int32 num = 0;
  Int32 methodToken = GetMethodToken(methodInfo, optionalParameterTypes, false);
  EnsureCapacity(7);
  InternalEmit(opcode);
  if (methodInfo->get_ReturnType() != typeof<void>()) {
    num++;
  }
  Array<Type> parameterTypes = methodInfo->GetParameterTypes();
  if (parameterTypes != nullptr) {
    num -= parameterTypes->get_Length();
  }
  if (!rt::is<SymbolMethod>(methodInfo) && !methodInfo->get_IsStatic() && !opcode.Equals(OpCodes::in::Newobj)) {
    num--;
  }
  if (optionalParameterTypes != nullptr) {
    num -= optionalParameterTypes->get_Length();
  }
  UpdateStackSize(opcode, num);
  RecordTokenFixup();
  PutInteger4(methodToken);
}

void ILGenerator___::Emit(OpCode opcode, SignatureHelper signature) {
  if (signature == nullptr) {
    rt::throw_exception<ArgumentNullException>("signature");
  }
  Int32 num = 0;
  ModuleBuilder moduleBuilder = (ModuleBuilder)m_methodBuilder->get_Module();
  Int32 token = moduleBuilder->GetSignatureToken(signature).get_Token();
  EnsureCapacity(7);
  InternalEmit(opcode);
  if (opcode.get_StackBehaviourPop() == StackBehaviour::Varpop) {
    num -= signature->get_ArgumentCount();
    num--;
    UpdateStackSize(opcode, num);
  }
  RecordTokenFixup();
  PutInteger4(token);
}

void ILGenerator___::Emit(OpCode opcode, ConstructorInfo con) {
  if (con == nullptr) {
    rt::throw_exception<ArgumentNullException>("con");
  }
  Int32 num = 0;
  Int32 methodToken = GetMethodToken(con, nullptr, true);
  EnsureCapacity(7);
  InternalEmit(opcode);
  if (opcode.get_StackBehaviourPush() == StackBehaviour::Varpush) {
    num++;
  }
  if (opcode.get_StackBehaviourPop() == StackBehaviour::Varpop) {
    Array<Type> parameterTypes = con->GetParameterTypes();
    if (parameterTypes != nullptr) {
      num -= parameterTypes->get_Length();
    }
  }
  UpdateStackSize(opcode, num);
  RecordTokenFixup();
  PutInteger4(methodToken);
}

void ILGenerator___::Emit(OpCode opcode, Type cls) {
  ModuleBuilder moduleBuilder = (ModuleBuilder)m_methodBuilder->get_Module();
  Int32 value = (!(opcode == OpCodes::in::Ldtoken) || !(cls != nullptr) || !cls->get_IsGenericTypeDefinition()) ? moduleBuilder->GetTypeTokenInternal(cls).get_Token() : moduleBuilder->GetTypeToken(cls).get_Token();
  EnsureCapacity(7);
  InternalEmit(opcode);
  RecordTokenFixup();
  PutInteger4(value);
}

void ILGenerator___::Emit(OpCode opcode, Int64 arg) {
  EnsureCapacity(11);
  InternalEmit(opcode);
  BinaryPrimitives::WriteInt64LittleEndian(MemoryExtensions::AsSpan(m_ILStream, m_length), arg);
  m_length += 8;
}

void ILGenerator___::Emit(OpCode opcode, Single arg) {
  EnsureCapacity(7);
  InternalEmit(opcode);
  BinaryPrimitives::WriteInt32LittleEndian(MemoryExtensions::AsSpan(m_ILStream, m_length), BitConverter::SingleToInt32Bits(arg));
  m_length += 4;
}

void ILGenerator___::Emit(OpCode opcode, Double arg) {
  EnsureCapacity(11);
  InternalEmit(opcode);
  BinaryPrimitives::WriteInt64LittleEndian(MemoryExtensions::AsSpan(m_ILStream, m_length), BitConverter::DoubleToInt64Bits(arg));
  m_length += 8;
}

void ILGenerator___::Emit(OpCode opcode, Label label) {
  EnsureCapacity(7);
  InternalEmit(opcode);
  if (OpCodes::in::TakesSingleByteArgument(opcode)) {
    AddFixup(label, m_length++, 1);
    return;
  }
  AddFixup(label, m_length, 4);
  m_length += 4;
}

void ILGenerator___::Emit(OpCode opcode, Array<Label> labels) {
  if (labels == nullptr) {
    rt::throw_exception<ArgumentNullException>("labels");
  }
  Int32 num = labels->get_Length();
  EnsureCapacity(num * 4 + 7);
  InternalEmit(opcode);
  PutInteger4(num);
  Int32 num2 = num * 4;
  Int32 num3 = 0;
  while (num2 > 0) {
    AddFixup(labels[num3], m_length, num2);
    m_length += 4;
    num2 -= 4;
    num3++;
  }
}

void ILGenerator___::Emit(OpCode opcode, FieldInfo field) {
  ModuleBuilder moduleBuilder = (ModuleBuilder)m_methodBuilder->get_Module();
  Int32 token = moduleBuilder->GetFieldToken(field).get_Token();
  EnsureCapacity(7);
  InternalEmit(opcode);
  RecordTokenFixup();
  PutInteger4(token);
}

void ILGenerator___::Emit(OpCode opcode, String str) {
  ModuleBuilder moduleBuilder = (ModuleBuilder)m_methodBuilder->get_Module();
  Int32 token = moduleBuilder->GetStringConstant(str).get_Token();
  EnsureCapacity(7);
  InternalEmit(opcode);
  PutInteger4(token);
}

void ILGenerator___::Emit(OpCode opcode, LocalBuilder local) {
  if (local == nullptr) {
    rt::throw_exception<ArgumentNullException>("local");
  }
  Int32 localIndex = local->GetLocalIndex();
  if (local->GetMethodBuilder() != m_methodBuilder) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_UnmatchedMethodForLocal(), "local");
  }
  if (opcode.Equals(OpCodes::in::Ldloc)) {
    switch (localIndex.get()) {
      case 0:
        opcode = OpCodes::in::Ldloc_0;
        break;
      case 1:
        opcode = OpCodes::in::Ldloc_1;
        break;
      case 2:
        opcode = OpCodes::in::Ldloc_2;
        break;
      case 3:
        opcode = OpCodes::in::Ldloc_3;
        break;
      default:
        if (localIndex <= 255) {
          opcode = OpCodes::in::Ldloc_S;
        }
        break;
    }
  } else if (opcode.Equals(OpCodes::in::Stloc)) {
    switch (localIndex.get()) {
      case 0:
        opcode = OpCodes::in::Stloc_0;
        break;
      case 1:
        opcode = OpCodes::in::Stloc_1;
        break;
      case 2:
        opcode = OpCodes::in::Stloc_2;
        break;
      case 3:
        opcode = OpCodes::in::Stloc_3;
        break;
      default:
        if (localIndex <= 255) {
          opcode = OpCodes::in::Stloc_S;
        }
        break;
    }
  } else if (opcode.Equals(OpCodes::in::Ldloca) && localIndex <= 255) {
    opcode = OpCodes::in::Ldloca_S;
  }


  EnsureCapacity(7);
  InternalEmit(opcode);
  if (opcode.get_OperandType() == OperandType::InlineNone) {
    return;
  }
  if (!OpCodes::in::TakesSingleByteArgument(opcode)) {
    BinaryPrimitives::WriteInt16LittleEndian(MemoryExtensions::AsSpan(m_ILStream, m_length), (Int16)localIndex);
    m_length += 2;
    return;
  }
  if (localIndex > 255) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_BadInstructionOrIndexOutOfBound());
  }
  m_ILStream[m_length++] = (Byte)localIndex;
}

Label ILGenerator___::BeginExceptionBlock() {
  if (m_exceptions == nullptr) {
    m_exceptions = rt::newarr<Array<__ExceptionInfo>>(2);
  }
  if (m_currExcStack == nullptr) {
    m_currExcStack = rt::newarr<Array<__ExceptionInfo>>(2);
  }
  if (m_exceptionCount >= m_exceptions->get_Length()) {
    m_exceptions = EnlargeArray(m_exceptions);
  }
  if (m_currExcStackCount >= m_currExcStack->get_Length()) {
    m_currExcStack = EnlargeArray(m_currExcStack);
  }
  Label label = DefineLabel();
  __ExceptionInfo _ExceptionInfo = rt::newobj<__ExceptionInfo>(m_length, label);
  m_exceptions[m_exceptionCount++] = _ExceptionInfo;
  m_currExcStack[m_currExcStackCount++] = _ExceptionInfo;
  return label;
}

void ILGenerator___::EndExceptionBlock() {
  if (m_currExcStackCount == 0) {
    rt::throw_exception<NotSupportedException>(SR::get_Argument_NotInExceptionBlock());
  }
  __ExceptionInfo _ExceptionInfo = m_currExcStack[m_currExcStackCount - 1];
  m_currExcStack[--m_currExcStackCount] = nullptr;
  Label endLabel = _ExceptionInfo->GetEndLabel();
  switch (_ExceptionInfo->GetCurrentState().get()) {
    case 0:
    case 1:
      rt::throw_exception<InvalidOperationException>(SR::get_Argument_BadExceptionCodeGen());
    case 2:
      Emit(OpCodes::in::Leave, endLabel);
      break;
    case 3:
    case 4:
      Emit(OpCodes::in::Endfinally);
      break;
  }
  Label loc = (m_labelList[endLabel.GetLabelValue()] != -1) ? _ExceptionInfo->m_finallyEndLabel : endLabel;
  MarkLabel(loc);
  _ExceptionInfo->Done(m_length);
}

void ILGenerator___::BeginExceptFilterBlock() {
  if (m_currExcStackCount == 0) {
    rt::throw_exception<NotSupportedException>(SR::get_Argument_NotInExceptionBlock());
  }
  __ExceptionInfo _ExceptionInfo = m_currExcStack[m_currExcStackCount - 1];
  Emit(OpCodes::in::Leave, _ExceptionInfo->GetEndLabel());
  _ExceptionInfo->MarkFilterAddr(m_length);
}

void ILGenerator___::BeginCatchBlock(Type exceptionType) {
  if (m_currExcStackCount == 0) {
    rt::throw_exception<NotSupportedException>(SR::get_Argument_NotInExceptionBlock());
  }
  __ExceptionInfo _ExceptionInfo = m_currExcStack[m_currExcStackCount - 1];
  if (_ExceptionInfo->GetCurrentState() == 1) {
    if (exceptionType != nullptr) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_ShouldNotSpecifyExceptionType());
    }
    Emit(OpCodes::in::Endfilter);
  } else {
    if (exceptionType == nullptr) {
      rt::throw_exception<ArgumentNullException>("exceptionType");
    }
    Emit(OpCodes::in::Leave, _ExceptionInfo->GetEndLabel());
  }
  _ExceptionInfo->MarkCatchAddr(m_length, exceptionType);
}

void ILGenerator___::BeginFaultBlock() {
  if (m_currExcStackCount == 0) {
    rt::throw_exception<NotSupportedException>(SR::get_Argument_NotInExceptionBlock());
  }
  __ExceptionInfo _ExceptionInfo = m_currExcStack[m_currExcStackCount - 1];
  Emit(OpCodes::in::Leave, _ExceptionInfo->GetEndLabel());
  _ExceptionInfo->MarkFaultAddr(m_length);
}

void ILGenerator___::BeginFinallyBlock() {
  if (m_currExcStackCount == 0) {
    rt::throw_exception<NotSupportedException>(SR::get_Argument_NotInExceptionBlock());
  }
  __ExceptionInfo _ExceptionInfo = m_currExcStack[m_currExcStackCount - 1];
  Int32 currentState = _ExceptionInfo->GetCurrentState();
  Label endLabel = _ExceptionInfo->GetEndLabel();
  Int32 num = 0;
  if (currentState != 0) {
    Emit(OpCodes::in::Leave, endLabel);
    num = m_length;
  }
  MarkLabel(endLabel);
  Label label = DefineLabel();
  _ExceptionInfo->SetFinallyEndLabel(label);
  Emit(OpCodes::in::Leave, label);
  if (num == 0) {
    num = m_length;
  }
  _ExceptionInfo->MarkFinallyAddr(m_length, num);
}

Label ILGenerator___::DefineLabel() {
  if (m_labelList == nullptr) {
    m_labelList = rt::newarr<Array<Int32>>(4);
  }
  if (m_labelCount >= m_labelList->get_Length()) {
    m_labelList = EnlargeArray(m_labelList);
  }
  m_labelList[m_labelCount] = -1;
  return Label(m_labelCount++);
}

void ILGenerator___::MarkLabel(Label loc) {
  Int32 labelValue = loc.GetLabelValue();
  if (m_labelList == nullptr || labelValue < 0 || labelValue >= m_labelList->get_Length()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidLabel());
  }
  if (m_labelList[labelValue] != -1) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_RedefinedLabel());
  }
  m_labelList[labelValue] = m_length;
}

void ILGenerator___::ThrowException(Type excType) {
  if (excType == nullptr) {
    rt::throw_exception<ArgumentNullException>("excType");
  }
  if (!excType->IsSubclassOf(typeof<Exception>()) && excType != typeof<Exception>()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_NotExceptionType());
  }
  ConstructorInfo constructor = excType->GetConstructor(Type::in::EmptyTypes);
  if (constructor == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_MissingDefaultConstructor());
  }
  Emit(OpCodes::in::Newobj, constructor);
  Emit(OpCodes::in::Throw);
}

void ILGenerator___::EmitWriteLine(String value) {
  Emit(OpCodes::in::Ldstr, value);
  Array<Type> types = rt::newarr<Array<Type>>(1);
  Type type = Type::in::GetType("System.Console, System.Console", true);
  MethodInfo method = type->GetMethod("WriteLine", types);
  Emit(OpCodes::in::Call, method);
}

void ILGenerator___::EmitWriteLine(LocalBuilder localBuilder) {
  if (m_methodBuilder == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_InvalidOperation_BadILGeneratorUsage());
  }
  Type type = Type::in::GetType("System.Console, System.Console", true);
  MethodInfo method = type->GetMethod("get_Out");
  Emit(OpCodes::in::Call, method);
  Emit(OpCodes::in::Ldloc, localBuilder);
  Array<Type> array = rt::newarr<Array<Type>>(1);
  Type localType = localBuilder->get_LocalType();
  if (rt::is<TypeBuilder>(localType) || rt::is<EnumBuilder>(localType)) {
    rt::throw_exception<ArgumentException>(SR::get_NotSupported_OutputStreamUsingTypeBuilder());
  }
  array[0] = localType;
  MethodInfo method2 = typeof<TextWriter>()->GetMethod("WriteLine", array);
  if (method2 == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmitWriteLineType(), "localBuilder");
  }
  Emit(OpCodes::in::Callvirt, method2);
}

void ILGenerator___::EmitWriteLine(FieldInfo fld) {
  if (fld == nullptr) {
    rt::throw_exception<ArgumentNullException>("fld");
  }
  Type type = Type::in::GetType("System.Console, System.Console", true);
  MethodInfo method = type->GetMethod("get_Out");
  Emit(OpCodes::in::Call, method);
  if ((fld->get_Attributes() & FieldAttributes::Static) != 0) {
    Emit(OpCodes::in::Ldsfld, fld);
  } else {
    Emit(OpCodes::in::Ldarg, (?)(Int32)0);
    Emit(OpCodes::in::Ldfld, fld);
  }
  Array<Type> array = rt::newarr<Array<Type>>(1);
  Type fieldType = fld->get_FieldType();
  if (rt::is<TypeBuilder>(fieldType) || rt::is<EnumBuilder>(fieldType)) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_OutputStreamUsingTypeBuilder());
  }
  array[0] = fieldType;
  MethodInfo method2 = typeof<TextWriter>()->GetMethod("WriteLine", array);
  if (method2 == nullptr) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmitWriteLineType(), "fld");
  }
  Emit(OpCodes::in::Callvirt, method2);
}

LocalBuilder ILGenerator___::DeclareLocal(Type localType) {
  return DeclareLocal(localType, false);
}

LocalBuilder ILGenerator___::DeclareLocal(Type localType, Boolean pinned) {
  MethodBuilder methodBuilder = rt::as<MethodBuilder>(m_methodBuilder);
  if (methodBuilder == nullptr) {
    rt::throw_exception<NotSupportedException>();
  }
  if (methodBuilder->IsTypeCreated()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_TypeHasBeenCreated());
  }
  if (localType == nullptr) {
    rt::throw_exception<ArgumentNullException>("localType");
  }
  if (methodBuilder->m_bIsBaked) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_MethodBaked());
  }
  m_localSignature->AddArgument(localType, pinned);
  return rt::newobj<LocalBuilder>(m_localCount++, localType, methodBuilder, pinned);
}

void ILGenerator___::UsingNamespace(String usingNamespace) {
  if (usingNamespace == nullptr) {
    rt::throw_exception<ArgumentNullException>("usingNamespace");
  }
  if (usingNamespace->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "usingNamespace");
  }
  MethodBuilder methodBuilder = rt::as<MethodBuilder>(m_methodBuilder);
  if (methodBuilder == nullptr) {
    rt::throw_exception<NotSupportedException>();
  }
  Int32 currentActiveScopeIndex = methodBuilder->GetILGenerator()->m_ScopeTree->GetCurrentActiveScopeIndex();
  if (currentActiveScopeIndex == -1) {
    methodBuilder->m_localSymInfo->AddUsingNamespace(usingNamespace);
  } else {
    m_ScopeTree->AddUsingNamespaceToCurrentScope(usingNamespace);
  }
}

void ILGenerator___::MarkSequencePoint(ISymbolDocumentWriter document, Int32 startLine, Int32 startColumn, Int32 endLine, Int32 endColumn) {
  if (startLine == 0 || startLine < 0 || endLine == 0 || endLine < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("startLine");
  }
  m_LineNumberInfo->AddLineNumberInfo(document, m_length, startLine, startColumn, endLine, endColumn);
}

void ILGenerator___::BeginScope() {
  m_ScopeTree->AddScopeInfo(ScopeAction::Open, m_length);
}

void ILGenerator___::EndScope() {
  m_ScopeTree->AddScopeInfo(ScopeAction::Close, m_length);
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::ILGeneratorNamespace
