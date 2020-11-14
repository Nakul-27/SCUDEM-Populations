// Using the Premises from Genetic and Evolutionary to demonstrate the evolution
// of two populations.
//
// TWO ASSUMPTIONS:
// 1) GENETICS/EVOLUTION IS A GOOD MODEL FOR SOCIAL BEHAVIOR
// 2) LIMITING POPULATION GROWTH - MORE PEOPLE COMING IN
//
// SCUDEM Main Implementation
// By: RAO, Nakul S
// Date of Last Edit: 29 OCT 2020
//

#include <stdio.h>
#include <unistd.h>

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>
#include <string>
#include <vector>

#include "generators/PersonGenerator.h"
#include "models/parent/person.h"

void simulation(std::ofstream& file, std::ofstream& file2, int numImmigrants,
                int numUgandans, int numTimes, int numInteractions) {
  unsigned int seed = 0;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 9999);

  string method;
  string method2;

  seed = dis(gen);

  file.open("Pre-Results.txt");
  file2.open("Post-Results.txt");

  // Number of Immigrants and Ugandans
  int immigrantNumber = numImmigrants;
  int ugandanNumber = numUgandans;
  int iteratorCount = 0;

  int immigrantCount = 0;

  auto rng = std::default_random_engine{};

  std::vector<Person> listOfImmigrants;
  std::vector<Person> newListofImmigrants;
  std::vector<Person> listOfUgandans;
  std::vector<Person> Combined;
  for (int i = 1; i <= numTimes; ++i) {
    // Generates a new RNG seed each time a new population is created
    srand(seed);

    // Generate Vectors of Immigrants and Ugandans
    listOfImmigrants = generatePeople(immigrantNumber, "Immigrant");
    listOfUgandans = generatePeople(ugandanNumber, "Ugandan");

    // Shuffle the vectors into one another

    Combined = listOfImmigrants;

    for (auto it : listOfUgandans) {
      Combined.push_back(it);
    }

    std::shuffle(std::begin(Combined), std::end(Combined), rng);

    std::cout << "Iteration: " << i << std::endl;

    method = prevailingMethod(listOfImmigrants);
    method2 = prevailingMethod(listOfUgandans);

    listOfImmigrants.clear();
    listOfUgandans.clear();

    file << "Immigrant Prevailing Method: " << method
         << "\nUgandan Prevailing Method: " << method2 << "\n \n ";

    for (int i = 0; i < numInteractions; ++i) {
      if ((rand() % 100 / 10) >= 9) {
        // std::cout << int(immigrantNumber * 0.03) << std::endl;
        // Generate a random number of immigrants between 0 and
        // 100 and insert them into the combined list.
        newListofImmigrants =
            generatePeople(int(immigrantNumber * 0.03), "Immigrant");
        for (auto it : newListofImmigrants) {
          Combined.push_back(it);
        }

        // Clear the new List after all of the members have been
        // generated and added.
        newListofImmigrants.clear();

        // Combined.insert(Combined.end(), newListofImmigrants.begin(),
        //               newListofImmigrants.end());

        // Shuffle the combined list
        std::shuffle(std::begin(Combined), std::end(Combined),
                     std::default_random_engine());
      }

      // Picks two random people from Combined
      int at1 = rand() % Combined.size();
      int at2 = rand() % Combined.size();
      Person person1 = Combined.at(at1);
      Person person2 = Combined.at(at2);

      // Cannot make var for rand() % Combined.size() because
      // need to generate new Random Number for each index.
      //
      // Do not need to check if the indexes are the same
      // because of how large Combined.size() is and will be.

      if (person1.getFitness() > person2.getFitness()) {
        person2.setMethod(person1.getMethod());
        Combined.erase(Combined.begin() + at2);
        Combined.push_back(person2);

      } else if (person1.getFitness() < person2.getFitness()) {
        person1.setMethod(person2.getMethod());
        Combined.erase(Combined.begin() + at1);
        Combined.push_back(person1);
      }
    }

    for (auto it : Combined) {
      if (it.getClassification() == "Ugandan") {
        listOfUgandans.push_back(Combined.at(iteratorCount));
      } else
        listOfImmigrants.push_back(Combined.at(iteratorCount));
      ++iteratorCount;
    }
    iteratorCount = 0;

    method = prevailingMethod(listOfImmigrants);
    method2 = prevailingMethod(listOfUgandans);

    file2 << "Immigrant Prevailing Method: " << method
          << "\nUgandan Prevailing Method: " << method2 << "\n \n";

    listOfImmigrants.clear();
    listOfUgandans.clear();
    Combined.clear();
  }

  file.close();
  file2.close();
}

int main(int argc, char** argv) {
  std::ofstream file;
  std::ofstream file2;

  // Parameters
  // Pre-Results File, Post-Results File, Number of Immigrants, Number of
  // Ugandans, Number of Time the Simulation should Run, Number of Interactions
  // per Simulation, Number of Interactions for Population Increase
  // Need Ratio of about 1:525 Immigrants to Ugandans.
  simulation(file, file2, 25, 13125, 100, 25000);

  return 0;
}
