//
// SCUDEM Main Implementation
// By: RAO, Nakul S
// Date of Last Edit: 29 OCT 2020
//

#include <stdio.h>

#include <iostream>
#include <string>
#include <vector>

#include "generators/PersonGenerator.h"
// #include "models/children/Immigrant.h"
#include "models/parent/person.h"

// ToDo: DECIDE HOW THE METHOD SHOULD CHANGE OVER TIME WITH RESPECT TO INFLUENCE
int main() {
  // Number of Immigrants and Ugandans
  int immigrantNumber = 100;
  int ugandanNumber = 50;

  // Generate Vectors of Immigrants and Ugandans
  std::vector<Person> listOfImmigrants = generatePeople(immigrantNumber);
  std::vector<Person> listOfUgandans = generatePeople(ugandanNumber);

  // Display Data
  displayPeople(listOfImmigrants, "Immigrants");
  displayPeople(listOfUgandans, "Ugandan");

  // CHANGES THE METHOD
  // // for (int index = 0; index < listOfImmigrants.size(); ++index) {
  // //   std::cout << listOfImmigrants.at(index).getMethod() << std::endl;
  // // }

  // // printf("\n");

  // // for (int index = 0; index < listOfImmigrants.size(); ++index) {
  // //   listOfImmigrants.at(index).setMethod("arbitration");
  // // }

  // // printf("\n");

  // // for (int index = 0; index < listOfImmigrants.size(); ++index) {
  // //   std::cout << listOfImmigrants.at(index).getMethod() << std::endl;
  // // }

  return 0;
}
