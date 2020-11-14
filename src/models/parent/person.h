//
// Person Class Interface: Parent to Immigrant and Ugandan Class
// By: RAO, Nakul S
// Date of Last Edit: 29 OCT 2020
//
// Inheritance Reference:
// https://www.w3schools.in/cplusplus-tutorial/inheritance/

#ifndef PERSON_H
#define PERSON_H value
#include <string>
using std::string;
class Person {
 public:
  // Get Methods
  string getClassification(void);
  string getMethod(void);
  string getGender(void);
  int getAge(void);
  int getFitness();
  float getInteractionProb(void);

  // Set Methods
  void setMethod(std::string m);
  void setGender(std::string g);
  void setAge(int a);
  void setInteractionProb(float iP);

  // Non-Default Constructor
  Person(std::string classification, std::string method, std::string gender,
         int age, float interactionProb);

  // Immigrant();
  ~Person();

  void Display(void);

 private:
  std::string classification;
  std::string method;
  std::string gender;
  int age;
  float interactionProb;
};
#endif /* ifndef PERSON_H */
