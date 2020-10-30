//
// SCUDEM Main File
// By: RAO, Nakul S
// Date of Last Edit: 29 OCT 2020
//

#include <stdio.h>

#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "generators/ImmigrantGenerator.h"
#include "models/Immigrant.h"

int main() {
  // Number of Immigrants
  int immigrantNumber = 10000;
  std::vector<Immigrant> listOfImmigrants = generateImmigrants(immigrantNumber);
  displayImmigrants(listOfImmigrants);

  return 0;
}
