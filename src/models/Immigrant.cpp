//
// Immigrant Class Implementation
// By: RAO, Nakul S
// Date of Last Edit: 28 OCT 2020
//
// Class Building Reference:
// https://codingadventures1.blogspot.com/2020/02/advanced-classes-and-objects-part-i.html

#include "Immigrant.h"

#include <iostream>

// Get Methods
string Immigrant::getMethod(void) { return method; }
string Immigrant::getGender(void) { return gender; }
string Immigrant::getSocialClass(void) { return socialClass; }
int Immigrant::getAge(void) { return age; }
float Immigrant::getInteractionProb(void) { return interactionProb; }

// Set Methods void Immigrant::setMethod(std::string nMethod) { this->method =
// nMethod; }
void Immigrant::setGender(std::string nGender) { this->gender = nGender; }
void Immigrant::setSocialClass(std::string nSocialClass) {
  this->socialClass = nSocialClass;
}
void Immigrant::setAge(int nAge) { this->age = nAge; }
void Immigrant::setInteractionProb(float nInteractionProb) {
  this->interactionProb = nInteractionProb;
}

// Destructor
Immigrant::~Immigrant(void){};

void Immigrant::Display() {
  std::cout << "Method: " << method << std::endl;
  std::cout << "Gender: " << gender << std::endl;
  std::cout << "Social Class: " << socialClass << std::endl;
  std::cout << "Age: " << age << std::endl;
  printf("Interaction Probability %.2f", interactionProb);
}

// Constructor
Immigrant::Immigrant(std::string newMethod, std::string newGender,
                     std ::string newSocialClass, int newAge,
                     float newInteractionProb) {
  method = newMethod;
  gender = newGender;
  age = newAge;
  socialClass = newSocialClass;
  interactionProb = newInteractionProb;
}
