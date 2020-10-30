//
// Random Number Generator
// By: RAO, Nakul S
// Date of Last Edit: 29 OCT 2020
// Reference and Credit:
// https://blog.demofox.org/2013/07/07/a-super-tiny-random-number-generator/
//

#include <string.h>

#include <cstring>

unsigned int seed = 0;
unsigned int GenerateRandomBit() {
  seed += (seed * seed) | 5;
  return seed & 0x80000000;
}

template <typename T>
void GenerateRandom(T &value) {
  memset(&value, 0, sizeof(T));
  const unsigned int numBits = sizeof(T) * 8;
  unsigned int *dataPointer = (unsigned int *)&value;
  for (unsigned int index = 0; index < numBits; ++index) {
    if (GenerateRandomBit()) {
      unsigned int pointerIndex = index / 32;
      unsigned int mask = 1 << index % 32;
      dataPointer[pointerIndex] |= mask;
    }
  }
}

int setup(int max) {
  unsigned int random;
  GenerateRandom(random);
  int index = random % 10 % max;
  return index;
}
