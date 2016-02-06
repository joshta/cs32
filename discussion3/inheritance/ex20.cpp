#include<iostream>
using namespace std;

  struct AllYourBase {
      // [!] Note the virtual keyword
      virtual void yell () {
          cout << "[Base] AIEEE!" << endl;
      }
  };
        
  struct AreBelongToUs : public AllYourBase {
      virtual void yell () {
          cout << "[Derived] AIEEE!" << endl;
      }
  };

    struct GrandChild: public AreBelongToUs {

    };

  int main () {
      AllYourBase base;
      AreBelongToUs derived;
      AllYourBase* basePtr = &derived;
      AreBelongToUs* derPtr = &derived;
      GrandChild gc;
    AllYourBase* basegrandchildPtr = new GrandChild();      
      base.yell();
      derived.yell();
      basePtr->yell();
      derPtr->yell();
      basegrandchildPtr->yell();
  }
