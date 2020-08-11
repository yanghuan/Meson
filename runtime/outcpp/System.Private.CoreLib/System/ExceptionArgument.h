#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System {
enum class ExceptionArgument : int32_t {
  obj = 0,
  dictionary = 1,
  array = 2,
  info = 3,
  key = 4,
  text = 5,
  values = 6,
  value = 7,
  startIndex = 8,
  task = 9,
  bytes = 10,
  byteIndex = 11,
  byteCount = 12,
  ch = 13,
  chars = 14,
  charIndex = 15,
  charCount = 16,
  s = 17,
  input = 18,
  ownedMemory = 19,
  list = 20,
  index = 21,
  capacity = 22,
  collection = 23,
  item = 24,
  converter = 25,
  match = 26,
  count = 27,
  action = 28,
  comparison = 29,
  exceptions = 30,
  exception = 31,
  pointer = 32,
  start = 33,
  format = 34,
  culture = 35,
  comparer = 36,
  comparable = 37,
  source = 38,
  state = 39,
  length = 40,
  comparisonType = 41,
  manager = 42,
  sourceBytesToCopy = 43,
  callBack = 44,
  creationOptions = 45,
  function = 46,
  scheduler = 47,
  continuationAction = 48,
  continuationFunction = 49,
  tasks = 50,
  asyncResult = 51,
  beginMethod = 52,
  endMethod = 53,
  endFunction = 54,
  cancellationToken = 55,
  continuationOptions = 56,
  delay = 57,
  millisecondsDelay = 58,
  millisecondsTimeout = 59,
  stateMachine = 60,
  timeout = 61,
  type = 62,
  sourceIndex = 63,
  sourceArray = 64,
  destinationIndex = 65,
  destinationArray = 66,
  pHandle = 67,
  other = 68,
  newSize = 69,
  lowerBounds = 70,
  lengths = 71,
  len = 72,
  keys = 73,
  indices = 74,
  index1 = 75,
  index2 = 76,
  index3 = 77,
  length1 = 78,
  length2 = 79,
  length3 = 80,
  endIndex = 81,
  elementType = 82,
  arrayIndex = 83,
  year = 84,
  codePoint = 85,
  str = 86,
  options = 87,
  prefix = 88,
  suffix = 89,
};
} // namespace System::Private::CoreLib::System
