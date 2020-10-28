#include <stdio.h>

#include <iostream>

#include "models/Immigrant.h"

int main() {
  Immigrant immigrant;
  immigrant.setMethod("mediation");
  immigrant.setGender("male");
  immigrant.setSocialClass("lower");
  immigrant.setAge(20);
  immigrant.setInteractionProb(0.98);

  immigrant.Display();

  return 0;
}
