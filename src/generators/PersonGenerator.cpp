//
// Immigrant Generator Implementation
// By: RAO, Nakul S; WOOD, Ethan
// Date of Last Edit: 14 NOV 2020
//
#include "PersonGenerator.h"

#include <array>
#include <cstdlib>
#include <random>

#include "../models/parent/person.h"
#include "../templates/rng.cpp"

using std::string;

string getTechnique(string classification) {
  unsigned int seed = 0;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 9999);

  seed = dis(gen);

  string method;
  // 40% Mediation, 30% Negotiation, 30% Arbitration
  std::array<string, 10> immigrantMethods{
      "negotiation", "negotiation", "negotiation", "arbitration", "arbitration",
      "arbitration", "mediation",   "mediation",   "mediation",   "mediation",
  };
  // 40% Arbitration, 30% Negotiation, 30% Mediation
  std::array<string, 10> ugandanMethods{
      "negotiation", "negotiation", "negotiation", "arbitration", "arbitration",
      "arbitration", "arbitration", "mediation",   "mediation",   "mediation",
  };
  int index = setup(10);

  std::shuffle(immigrantMethods.begin(), immigrantMethods.end(),
               std::default_random_engine(seed));

  std::shuffle(ugandanMethods.begin(), ugandanMethods.end(),
               std::default_random_engine(seed));

  // Not a good technique but I couldn't think of another way to do this.
  if (classification == "Immigrant") {
    method = immigrantMethods[index];
  } else {
    method = ugandanMethods[index];
  }
  return method;
}

string getGender() {
  string genders[2] = {"male", "female"};

  int index = setup(2);

  return genders[index];
}

int getAge() {
  int minAge = 16;
  int maxAge = 65;

  return rand() % (maxAge - minAge + 1) + minAge;
}

float getProb() { return rand() / (RAND_MAX + 1.); }

std::vector<Person> generatePeople(int num, string classification) {
  std::vector<Person> loP;
  loP.reserve(num);

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 9999);

  seed = dis(gen);

  for (int i = 0; i < num; ++i) {
    std::string method = getTechnique(classification);
    std::string gender = getGender();
    int age = getAge();
    float interactionProb = getProb();

    loP.push_back(Person(classification, method, gender, age, interactionProb));
  }

  return loP;
}

void displayPeople(std::vector<Person> listOfPeople, string personType) {
  string method;
  string prevailingMethod;
  int count = 1;
  int negotiationCount = 0;
  int arbitrationCount = 0;
  int mediationCount = 0;

  for (auto it = listOfPeople.begin(); it != listOfPeople.end(); ++it) {
    method = it->getMethod();
    method == "negotiation"   ? ++negotiationCount
    : method == "arbitration" ? ++arbitrationCount
                              : ++mediationCount;
    ++count;
  }

  printf("Negotiation Count: %i \n", negotiationCount);
  printf("Arbitration Count: %i \n", arbitrationCount);
  printf("Mediation Count: %i \n", mediationCount);

  negotiationCount > mediationCount&& negotiationCount > arbitrationCount
      ? prevailingMethod = "negotiation"
  : mediationCount > negotiationCount&& mediationCount > arbitrationCount
      ? prevailingMethod = "mediation"
      : prevailingMethod = "arbitration";

  std::cout << "Prevailing Method: " << prevailingMethod << std::endl;
}

string prevailingMethod(std::vector<Person> listOfPeople) {
  string method;
  string prevailingMethod;
  int negotiationCount = 0;
  int arbitrationCount = 0;
  int mediationCount = 0;

  std::vector<Person>::iterator it;
  for (it = listOfPeople.begin(); it != listOfPeople.end(); ++it) {
    method = it->getMethod();
    method == "negotiation"   ? ++negotiationCount
    : method == "arbitration" ? ++arbitrationCount
                              : ++mediationCount;
  }

  negotiationCount > mediationCount&& negotiationCount > arbitrationCount
      ? prevailingMethod = "negotiation"
  : mediationCount > negotiationCount&& mediationCount > arbitrationCount
      ? prevailingMethod = "mediation"
      : prevailingMethod = "arbitration";

  return prevailingMethod;
}
