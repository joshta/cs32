#include<iostream>
using namespace std;

  // Too good to just have in one example:
  // (read: I'm too lazy to think of another)
  struct AllYourBase {
      void yell () {
          cout << "[Base] AIEEE!" << endl;
      }
  };
      
  struct AreBelongToUs : public AllYourBase {
      void yell () {
          cout << "[Derived] AIEEE!" << endl;
      }
  };
      
  int main () {
      AllYourBase base;
      AreBelongToUs derived;
      AllYourBase* basePtr = &derived;
  
      base.yell();
      derived.yell();
      basePtr->yell();
  }
