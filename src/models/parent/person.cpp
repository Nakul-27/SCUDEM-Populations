//
// Person Class Implementation
// By: RAO, Nakul S
// Date of Last Edit: 29 OCT 2020
//
// Inheritance Reference:
// https://www.educba.com/hierarchical-inheritance-in-c-plus-plus/
//

#include "person.h"

#include <iostream>

// Get Methods
string Person::getClassification(void) { return classification; }
string Person::getMethod(void) { return method; }
string Person::getGender(void) { return gender; }
int Person::getAge(void) { return age; }
float Person::getInteractionProb(void) { return interactionProb; }

// Set Methods
void Person::setMethod(std::string m) { this->method = m; }
void Person::setGender(std::string g) { this->gender = g; }
void Person::setAge(int a) { this->age = a; }
void Person::setInteractionProb(float iP) { this->interactionProb = iP; }

// Display
void Person::Display() {
  std::cout << "Classification: " << getClassification() << std::endl;
  std::cout << "Method: " << getMethod() << std::endl;
  std::cout << "Gender: " << getGender() << std::endl;
  std::cout << "Age: " << getAge() << std::endl;
  printf("Interaction Probability %.2f", getInteractionProb());
}

int Person::getFitness() {
  // Factors to influence are Age, Gender, Interaction Probability
  // Max = 7, Min = 1
  int fitness = 0;
  float interactionProb = getInteractionProb();
  int age = getAge();

  // Rationale for Gender: Heavily Patriarchical Society
  getGender() == "male" ? fitness += 3 : fitness += 1;
  // Rationale for Interaction Prob: Most influential should get 2 points
  interactionProb >= 0.75                             ? fitness += 2
  : interactionProb >= 0.25 && interactionProb < 0.75 ? fitness += 1
                                                      : fitness += 0;
  // Rationale for Age: Those older are wiser and therefore have more influence
  age >= 50               ? fitness += 2
  : age >= 32 && age < 50 ? fitness += 1
                          : fitness += 0;

  return fitness;
}

// Constructor
Person::Person(std::string newClassification, std::string newMethod,
               std::string newGender, int newAge, float newInteractionProb) {
  classification = newClassification;
  method = newMethod;
  gender = newGender;
  age = newAge;
  interactionProb = newInteractionProb;
}

// Destructor
Person::~Person(void) {}
