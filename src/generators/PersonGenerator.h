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

#include "../models/parent/person.h"

using std::string;

string getTechnique(string classification);
string getGender();
int getAge();
float getProb();

std::vector<Person> generatePeople(int num, string classification);
void displayPeople(std::vector<Person> listOfPeople, string personType);
string prevailingMethod(std::vector<Person> listOfPeople);

#endif /* ifndef IMMIGRANT_GENERATOR_H */
