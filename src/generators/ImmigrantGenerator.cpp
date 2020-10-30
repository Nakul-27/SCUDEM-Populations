//
// Immigrant Generator Implementation
// By: RAO, Nakul S
// Date of Last Edit: 29 OCT 2020
//

#include "ImmigrantGenerator.h"

#include <cstdlib>

#include "../models/Immigrant.h"
#include "../templates/rng.cpp"

using std::string;

string getTechnique() {
  //  srand((unsigned)time(NULL));
  string methods[3] = {"negotiation", "arbitration", "mediation"};

  int index = setup(3);

  return methods[index];
}

string getGender() {
  string gender[2] = {"male", "female"};

  int index = setup(2);

  return gender[index];
}

string getSocialClass() {
  string socialClasses[3] = {"lower", "middle", "upper"};

  int index = setup(3);

  return socialClasses[index];
}

int getAge() {
  int minAge = 16;
  int maxAge = 65;

  return rand() % (maxAge - minAge + 1) + minAge;
}

float getProb() { return rand() / (RAND_MAX + 1.); }

std::vector<Immigrant> generateImmigrants(int num) {
  std::vector<Immigrant> loI;
  loI.reserve(num);
  seed = (unsigned int)time(NULL);

  for (int i = 0; i < num; ++i) {
    std::string method = getTechnique();
    std::string gender = getGender();
    std::string socialClass = getSocialClass();
    int age = getAge();
    float interactionProb = getProb();

    loI.push_back(Immigrant(method, gender, socialClass, age, interactionProb));
  }

  return loI;
}

void displayImmigrants(std::vector<Immigrant> listOfImmigrants) {
  string method;
  int count = 1;
  int mediationCount = 0;
  int negotiationCount = 0;
  int arbitrationCount = 0;

  std::vector<Immigrant>::iterator it;
  for (it = listOfImmigrants.begin(); it != listOfImmigrants.end(); ++it) {
    printf("Immigrant number %i \n", count);
    method = it->getMethod();
    it->Display();
    method == "negotiation"
        ? ++negotiationCount
        : method == "arbitration" ? ++arbitrationCount : ++mediationCount;
    std::cout << "" << std::endl << std::endl;
    ++count;
  }

  printf("Negotiation Count: %i \n", negotiationCount);
  printf("Arbitration Count: %i \n", arbitrationCount);
  printf("Mediation Count: %i \n", mediationCount);
}
