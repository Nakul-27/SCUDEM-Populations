//
// Immigrant Generator Interface
// By: RAO, Nakul S
// Date of Last Edit: 29 OCT 2020
//

#ifndef IMMIGRANT_GENERATOR_H
#define IMMIGRANT_GENERATOR_H value

#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "../models/Immigrant.h"

using std::string;

string getTechnique();
string getGender();
string getSocialClass();
int getAge();
float getProb();

std::vector<Immigrant> generateImmigrants(int num);
void displayImmigrants(std::vector<Immigrant> listOfImmigrants);

#endif /* ifndef IMMIGRANT_GENERATOR_H */
