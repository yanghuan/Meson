#pragma once

#include "DynamicILGenerator.h"

#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/SymbolStore/ISymbolDocumentWriter.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Reflection/CallingConventions.h>
#include <System.Private.CoreLib/System/Reflection/ConstructorInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/DynamicMethod-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/DynamicScope-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ILGenerator-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/LocalBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/OpCode-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SignatureHelper-dep.h>
#include <System.Private.CoreLib/System/Reflection/FieldInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodBase-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeConstructorInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeFieldInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeMethodInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/RuntimeModule-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/CallingConvention.h>
#include <System.Private.CoreLib/System/RuntimeType-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
