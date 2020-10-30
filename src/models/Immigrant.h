//
// Immigrant Class Interface
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
  // Get Methods
  string getMethod(void);
  string getGender(void);
  string getSocialClass(void);
  int getAge(void);
  float getInteractionProb(void);

  // Set Methods
  void setMethod(std::string method);
  void setGender(std::string gender);
  void setSocialClass(std::string socialClass);
  void setAge(int age);
  void setInteractionProb(float interactionProb);

  // Non-Default Constructor
  Immigrant(std::string method, std::string gender, std::string socialClass,
            int age, float interactionProb);

  // Immigrant();
  ~Immigrant();

  void Display(void);

 private:
  std::string method;
  std::string gender;
  std::string socialClass;
  int age;
  float interactionProb;
};
#endif /* ifndef IMMIGRANT_H */
