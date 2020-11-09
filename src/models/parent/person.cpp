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
string Person::getSocialClass(void) { return socialClass; }
int Person::getAge(void) { return age; }
float Person::getInteractionProb(void) { return interactionProb; }

// Set Methods
void Person::setMethod(std::string m) { this->method = m; }
void Person::setGender(std::string g) { this->gender = g; }
void Person::setSocialClass(std::string sC) { this->socialClass = sC; }
void Person::setAge(int a) { this->age = a; }
void Person::setInteractionProb(float iP) { this->interactionProb = iP; }

// Display
void Person::Display() {
  std::cout << "Classification: " << getClassification() << std::endl;
  std::cout << "Method: " << getMethod() << std::endl;
  std::cout << "Gender: " << getGender() << std::endl;
  std::cout << "Social Class: " << getSocialClass() << std::endl;
  std::cout << "Age: " << getAge() << std::endl;
  printf("Interaction Probability %.2f", getInteractionProb());
}

// Constructor
Person::Person(std::string newClassification, std::string newMethod,
               std::string newGender, std ::string newSocialClass, int newAge,
               float newInteractionProb) {
  classification = newClassification;
  method = newMethod;
  gender = newGender;
  age = newAge;
  socialClass = newSocialClass;
  interactionProb = newInteractionProb;
}

// Destructor
Person::~Person(void) {}
