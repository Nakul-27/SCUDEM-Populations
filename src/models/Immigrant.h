//
// Immigrant Class HELPER
// By: RAO, Nakul S
// Date of Last Edit: 28 OCT 2020
//
// Class Building Reference:
// https://codingadventures1.blogspot.com/2020/02/advanced-classes-and-objects-part-i.html

#ifndef IMMIGRANT_H
#define IMMIGRANT_H value
#include <string>
using std::string;
class Immigrant {
 public:
  Immigrant(std::string method, std::string gender, std ::string socialClass,
            int age, double interactionProb);
  string getMethod();
  string getGender();
  string getSocialClass();
  int getAge();
  double getInteractionProb();

 private:
  std::string method;
  std::string gender;
  std::string socialClass;
  int age;
  double interactionProb;
};
#endif /* ifndef IMMIGRANT_H */
