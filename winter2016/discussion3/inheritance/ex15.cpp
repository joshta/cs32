#include<iostream>
using namespace std;

 struct AllYourBase {
      void yell () {
          cout << "[Base] AIEEE!" << endl;
      }
  };
      
  struct AreBelongToUs : public AllYourBase {
      void yell () {
          AllYourBase::yell();
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
