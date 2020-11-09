// Using the Premises from Genetic and Evolutionary to demonstrate the evolution
// of two populations.
//
// IDEA: GENETICS WITH RESPECT TO METHODS: THE METHODS CAN BE RANKED IN ORDER OF
// DOMINANCE BASED OFF OF THE SOCIAL STATUS OF THE AREA IN WHICH THE POPULATIONS
// ORIGINATE (VIOLENCE => NEGOTIATION = LESS DOMINANT ETC.)
//
// TWO ASSUMPTIONS:
// 1) GENETICS/EVOLUTION IS A GOOD MODEL FOR SOCIAL BEHAVIOR
// 2) LIMITING POPULATION GROWTH - MORE PEOPLE COMING IN
//
// NEED TO CHANGE GENERATION TO BE
//
// HAPLOID ORGANISMS WITH MULTIPLE GENES:
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
// - N - NUM OF HAPLOID ORGANISMS
// - Theta - N/A BECAUSE THERE IS TOO SMALL OF A POP FOR MUTATION RATE TO HAVE
// AN IMPACT
// - Rho - N/A NO RECOMBINATION RATE
// - g - NUMBER OF GENERATIONS TO SIMULATE
// - n - SAMPLE SIZE TO DRAW AT THE END - 50 - 75% - LAST POPULATION
// - nreps - NUMBER OF REPLICATES TO SIMULATE - GENERALLY 1
// - seed - A RANDOM NUMBER SEED - NEED BASH SHELL SCRIPT
//
// SCUDEM Main Implementation
// By: RAO, Nakul S
// Date of Last Edit: 29 OCT 2020
//

#include <gsl/gsl_sf_bessel.h>
#include <stdio.h>
#include <unistd.h>

#include <algorithm>
#include <fstream>
#include <functional>
#include <fwdpp/diploid.hh>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "generators/PersonGenerator.h"
#include "models/parent/person.h"

// IDEA  Using the concept of genes in order to model the two populations.
// Use fwdpp: http://molpopgen.github.io/fwdpp/doc/md/overview.html to model
// Pros: Good Library, Accurate Models, Sophisticated
// Cons: Sophisticated and Complex, Advanced, Steep Learning curve.

// TODO: NEED TO IMPLEMENT FUNCTION IN PARALLEL
void simulation(std::ofstream& file, int numTimes, int numInteractions) {
  unsigned int seed = 0;
  // std::random_device rd;
  // std::mt19937 = gen(rd());
  // std::uniform_int_distribution<> dis(1, 9999);

  // seed = dis(gen);
  file.open("Pre-Results.txt");

  // Number of Immigrants and Ugandans
  int immigrantNumber = 100;
  int ugandanNumber = 5000;

  std::vector<Person> listOfImmigrants;
  std::vector<Person> listOfUgandans;
  std::vector<Person> Combined;
  for (int i = 0; i < numTimes; ++i) {
    // Generates a new RNG seed each time a new population is created
    // srand(seed);
    // Generate Vectors of Immigrants and Ugandans
    listOfImmigrants = generatePeople(immigrantNumber, "Immigrant");
    listOfUgandans = generatePeople(ugandanNumber, "Ugandan");

    // Shuffle the vectors into one another
    Combined.reserve(listOfImmigrants.size() + listOfUgandans.size());
    Combined.insert(Combined.end(), listOfImmigrants.begin(),
                    listOfImmigrants.end());
    Combined.insert(Combined.end(), listOfUgandans.begin(),
                    listOfUgandans.end());
    std::shuffle(std::begin(Combined), std::end(Combined),
                 std::default_random_engine());

    // std::cout << Combined.at(1).getClassification() << std::endl;

    std::cout << "Iteration: " << i << std::endl;
    for (int i = 0; i < 10; ++i) {
      // Cannot make var for rand() % Combined.size() because need to generate
      // new Random Number for each index.
      // Do not need to check if the indexes are the same because of how large
      // Combined.size() is and will be.
      // TODO: REPLACE Combined.size() with the Fitness Score.
      if (Combined.at(rand() % Combined.size()).getAge() >
          Combined.at(rand() % Combined.size()).getAge()) {
        std::cout << "x" << std::endl;
      } else {
        std::cout << "y" << std::endl;
      }
    }

    // Display Data
    // displayPeople(listOfImmigrants, "Immigrants");
    // displayPeople(listOfUgandans, "Ugandan");

    string method = prevailingMethod(listOfImmigrants);
    string method2 = prevailingMethod(listOfUgandans);

    file << method << "\n" << method2 << "\n \n";
  }

  file.close();
}

int main(int argc, char** argv) {
  std::ofstream file;

  simulation(file, 100, 1000);

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
