#include "Program-dep.h"

#include <Test/Test/A-dep.h>
#include <Test/Test/Program-dep.h>

namespace Test::Test::ProgramNamespace {
void Program___::Main(Array<String> args) {
  A::Print(2);
};

void Program___::Ctor() {
};

} // namespace Test::Test::ProgramNamespace
int main(int argc, char* argv[]) {
  return rt::init(argc, argv, &Test::Test::Program::in::Main);
};
