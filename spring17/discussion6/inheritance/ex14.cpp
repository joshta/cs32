#include<iostream>
using namespace std;

  struct AllYourBase {
      void yell () {
          cout << "[Base] AIEEE!" << endl;
      }
  };
      
  struct AreBelongToUs : public AllYourBase {
      // >_> <_<
  };
      
  int main () {
      AllYourBase base;
      AreBelongToUs derived;
      AllYourBase* basePtr = &derived;
  
      base.yell();
      derived.yell();
      basePtr->yell();
  }
