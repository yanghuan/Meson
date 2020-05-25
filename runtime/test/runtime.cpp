// runtime.cpp: 定义应用程序的入口点。
//

//#include "runtime.h"
#include <iostream>

#if 0
namespace System {
	namespace Collections {
		struct A {};
	}
}

namespace System {
	namespace {
		using namespace System::Collections;
	}

}

namespace System {
	namespace Collections {
		namespace Generic {
			struct A {};
		}
	}
}

namespace System {
	

	namespace Other {
		namespace {
			using namespace System::Collections::Generic;
		}
		
		

		struct B {
			A a;
		};
	}
}
#endif

void f() {
}

int main()
{
  f();
  return 0;
}
