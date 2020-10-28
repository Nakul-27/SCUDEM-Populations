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
double Immigrant::getInteractionProb(void) { return interactionProb; }

// Set Methods
void Immigrant::setMethod(std::string nMethod) { this->method = nMethod; }
void Immigrant::setGender(std::string nGender) { this->gender = nGender; }
void Immigrant::setSocialClass(std::string nSocialClass) {
  this->socialClass = nSocialClass;
}
void Immigrant::setAge(int nAge) { this->age = nAge; }
void Immigrant::setInteractionProb(double nInteractionProb) {
  this->interactionProb = nInteractionProb;
}

// Constructor
Immigrant::Immigrant(void){};
// Destructor
Immigrant::~Immigrant(void) {
  std::cout << "Immigrant Object being deleted" << std::endl;
};

void Immigrant::Display() {
  std::cout << "Values\n";
  std::cout << "Method: " << method << std::endl;
  std::cout << "Gender: " << gender << std::endl;
  std::cout << "Social Class: " << socialClass << std::endl;
  std::cout << "Age: " << age << std::endl;
  std::cout << "Interaction Probability: " << interactionProb << std::endl;
}

// // Constructor
// Immigrant::Immigrant(std::string method, std::string gender,
//                      std ::string socialClass, int age,
//                      double interactionProb) {
//   method = method;
//   gender = gender;
//   age = age;
//   socialClass = socialClass;
//   interactionProb = interactionProb;
// }
