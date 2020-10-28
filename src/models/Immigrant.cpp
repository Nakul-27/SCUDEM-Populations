//
// Immigrant Class
// By: RAO, Nakul S
// Date of Last Edit: 28 OCT 2020
//
// Class Building Reference:
// https://codingadventures1.blogspot.com/2020/02/advanced-classes-and-objects-part-i.html

#include "Immigrant.h"

string Immigrant::getMethod() { return method; }

string Immigrant::getGender() { return gender; }

string Immigrant::getSocialClass() { return socialClass; }

int Immigrant::getAge() { return age; }

double Immigrant::getInteractionProb() { return interactionProb; }

Immigrant::Immigrant(std::string method, std::string gender,
                     std ::string socialClass, int age,
                     double interactionProb) {
  method = method;
  gender = gender;
  age = age;
  socialClass = socialClass;
  interactionProb = interactionProb;
}
