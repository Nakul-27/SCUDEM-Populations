#include <stdio.h>

#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "models/Immigrant.h"

using std::string;

// Randomly Generates Negotiation Techniques
string getTechnique() {
  string methods[3] = {"negotiation", "arbitration", "mediation"};

  return methods[rand() % 3];
}

string getGender() {
  string gender[2] = {"male", "female"};

  return gender[rand() % 2];
}

string getSocialClass() {
  string socialClasses[3] = {"lower", "middle", "upper"};

  return socialClasses[rand() % 3];
}

int getAge() {
  int minAge = 16;
  int maxAge = 65;

  return rand() % (maxAge - minAge + 1) + minAge;
}

int main() {
  // Number of Immigrants
  int immigrantNumber = 100000;
  std::vector<Immigrant> listOfImmigrants;
  listOfImmigrants.reserve(immigrantNumber);

  for (int i = 0; i < immigrantNumber; ++i) {
    std::string method = getTechnique();
    std::string gender = getGender();
    std::string socialClass = getSocialClass();
    int age = getAge();
    double interactionProb = 0.98;

    listOfImmigrants.push_back(
        Immigrant(method, gender, socialClass, age, interactionProb));
  }

  std::vector<Immigrant>::iterator it;
  for (it = listOfImmigrants.begin(); it != listOfImmigrants.end(); ++it) {
    it->Display();
    std::cout << "" << std::endl;
  }

  return 0;
}
