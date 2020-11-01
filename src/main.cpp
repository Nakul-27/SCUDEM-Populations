//
// SCUDEM Main Implementation
// By: RAO, Nakul S
// Date of Last Edit: 29 OCT 2020
//

#include <stdio.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "generators/PersonGenerator.h"
// #include "models/children/Immigrant.h"
#include "models/parent/person.h"

void simulation(std::ofstream& file, int numTimes) {
  file.open("Pre-Results.txt");

  // Number of Immigrants and Ugandans
  int immigrantNumber = 100;
  int ugandanNumber = 50;

  std::vector<Person> listOfImmigrants;
  std::vector<Person> listOfUgandans;
  for (int i = 0; i < numTimes; ++i) {
    // Generate Vectors of Immigrants and Ugandans
    listOfImmigrants = generatePeople(immigrantNumber);
    listOfUgandans = generatePeople(ugandanNumber);

    // Display Data
    // displayPeople(listOfImmigrants, "Immigrants");
    // displayPeople(listOfUgandans, "Ugandan");

    string method = prevailingMethod(listOfImmigrants);
    string method2 = prevailingMethod(listOfUgandans);

    // std::cout << method << "\n" << method2 << std::endl << std::endl;
    file << method << "\n" << method2 << "\n \n";
  }

  file.close();
}

// ToDo: Load the data into a Python Script

// // Construct a graph from the Pre-Results text file.
// ToDo: FIGURE OUT HOW THE IMMIGRANTS AND UGANDANS SHOULD INTERACT.
// // RANDOM PERHAPS?
// // // RANDOM IMMIGRANT poI VS RANDOM UGANDAN poI?
// // // OTHER METHODS

// ToDo: DECIDE HOW THE METHOD SHOULD CHANGE OVER TIME WITH RESPECT TO INFLUENCE
int main() {
  std::ofstream file;

  simulation(file, 100);

  // CHANGES THE METHOD
  // // for (int index = 0; index < listOfImmigrants.size(); ++index) {
  // //   std::cout << listOfImmigrants.at(index).getMethod() << std::endl;
  // // }

  // // for (int index = 0; index < listOfImmigrants.size(); ++index) {
  // //   listOfImmigrants.at(index).setMethod("arbitration");
  // // }

  // // for (int index = 0; index < listOfImmigrants.size(); ++index) {
  // //   std::cout << listOfImmigrants.at(index).getMethod() << std::endl;
  // // }

  return 0;
}
