//
// Immigrant Generator Implementation
// By: RAO, Nakul S
// Date of Last Edit: 29 OCT 2020
//

#include "PersonGenerator.h"

#include <cstdlib>
#include <random>

#include "../models/parent/person.h"
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

std::vector<Person> generatePeople(int num) {
  std::vector<Person> loP;
  loP.reserve(num);

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 9999);

  seed = dis(gen);

  // seed = (unsigned int)time(NULL);

  for (int i = 0; i < num; ++i) {
    std::string method = getTechnique();
    std::string gender = getGender();
    std::string socialClass = getSocialClass();
    int age = getAge();
    float interactionProb = getProb();

    loP.push_back(Person(method, gender, socialClass, age, interactionProb));
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
    std::cout << personType << " number " << count << std::endl;
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
    method == "negotiation"
        ? ++negotiationCount
        : method == "arbitration" ? ++arbitrationCount : ++mediationCount;
  }

  negotiationCount > mediationCount&& negotiationCount > arbitrationCount
      ? prevailingMethod = "negotiation"
      : mediationCount > negotiationCount&& mediationCount > arbitrationCount
            ? prevailingMethod = "mediation"
            : prevailingMethod = "arbitration";

  return prevailingMethod;
}

