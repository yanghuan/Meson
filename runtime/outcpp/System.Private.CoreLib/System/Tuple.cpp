#include "Tuple-dep.h"

namespace System::Private::CoreLib::System::TupleNamespace {
Int32 Tuple<>::CombineHashCodes(Int32 h1, Int32 h2) {
  return ((h1 << 5) + h1) ^ h2;
}

Int32 Tuple<>::CombineHashCodes(Int32 h1, Int32 h2, Int32 h3) {
  return CombineHashCodes(CombineHashCodes(h1, h2), h3);
}

Int32 Tuple<>::CombineHashCodes(Int32 h1, Int32 h2, Int32 h3, Int32 h4) {
  return CombineHashCodes(CombineHashCodes(h1, h2), CombineHashCodes(h3, h4));
}

Int32 Tuple<>::CombineHashCodes(Int32 h1, Int32 h2, Int32 h3, Int32 h4, Int32 h5) {
  return CombineHashCodes(CombineHashCodes(h1, h2, h3, h4), h5);
}

Int32 Tuple<>::CombineHashCodes(Int32 h1, Int32 h2, Int32 h3, Int32 h4, Int32 h5, Int32 h6) {
  return CombineHashCodes(CombineHashCodes(h1, h2, h3, h4), CombineHashCodes(h5, h6));
}

Int32 Tuple<>::CombineHashCodes(Int32 h1, Int32 h2, Int32 h3, Int32 h4, Int32 h5, Int32 h6, Int32 h7) {
  return CombineHashCodes(CombineHashCodes(h1, h2, h3, h4), CombineHashCodes(h5, h6, h7));
}

Int32 Tuple<>::CombineHashCodes(Int32 h1, Int32 h2, Int32 h3, Int32 h4, Int32 h5, Int32 h6, Int32 h7, Int32 h8) {
  return CombineHashCodes(CombineHashCodes(h1, h2, h3, h4), CombineHashCodes(h5, h6, h7, h8));
}

} // namespace System::Private::CoreLib::System::TupleNamespace
