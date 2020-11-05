// IDEA: GENETICS WITH RESPECT TO METHODS: THE METHODS CAN BE RANKED IN ORDER OF
// DOMINANCE BASED OFF OF THE SOCIAL STATUS OF THE AREA IN WHICH THE POPULATIONS
// ORIGINATE (VIOLENCE => NEGOTIATION = LESS DOMINANT ETC.)
//
// THREE ASSUMPTIONS:
// 1) NO FITNESS - NO FACTORS HINDERING REPRODUCTION;
// 2) GENETICS IS A GOOD MODEL FOR SOCIAL BEHAVIOR
// 3) LIMITING POPULATION GROWTH - MORE PEOPLE COMING IN
//
// DIPLOID ORGANISMS WITH MULTIPLE GENES:
// (NO AGE), CONFLICT RESOLUTION,
// SOCIABILITY, SKIN COLOR?
//
// SCORE = FITNESS???
// NEED WAY TO MANIPULATE WHICH GENES SHOW UP OVER TIME - FITNESS
// CHILD GENE GENERATION = RANDOM
// WHICH PARENTS REPRODUCE = NOT RANDOM
// WEIGHTED RANDOM NUMBER GENERATOR - FITNESS SCORE = WEIGHTS
//
// CANNOT MANDATE ONLY REPRODUCE WITH OPPOSING SIDE
//
// VARIABLES:
// - N - NUM OF DIPLOID ORGANISMS
// - Theta - N/A BECAUSE THERE IS TOO SMALL OF A POP FOR MUTATION RATE TO HAVE
// AN IMPACT
// - Rho - N/A NO RECOMBINATION RATE
// - g - NUMBER OF GENERATIONS TO SIMULATE
// - n - SAMPLE SIZE TO DRAW AT THE END - 50 - 75% - LAST POPULATION
// - nreps - NUMBER OF REPLICATES TO SIMULATE - GENERALLY 1
// - seed - A RANDOM NUMBER SEED - NEED BASH SHELL SEED
//
// SCUDEM Main Implementation
// By: RAO, Nakul S
// Date of Last Edit: 29 OCT 2020
//
// SCORE!!!! DETERMINE METHOD

#include <gsl/gsl_sf_bessel.h>
#include <stdio.h>
#include <unistd.h>

#include <algorithm>
#include <fstream>
#include <functional>
#include <fwdpp/diploid.hh>
#include <iostream>
#include <string>
#include <vector>

#include "generators/PersonGenerator.h"
#include "models/parent/person.h"

// IDEA  Using the concept of genes in order to model the two populations.
// Use fwdpp: http://molpopgen.github.io/fwdpp/doc/md/overview.html to model
// Pros: Good Library, Accurate Models, Sophisticated
// Cons: Sophisticated and Complex, Advanced, Steep Learning curve.
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
int main(int argc, char** argv) {
  std::ofstream file;

  simulation(file, 100);

  std::vector<int> x{5, 2, 3, 4, 1};
  sort(x.begin(), x.end(), [](int a, int b) { return a < b; });

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
