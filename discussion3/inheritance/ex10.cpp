#include<iostream>
using namespace std;

  // Ugh this joke is bad...
  struct AllYourBase {
      string stuff;
      AllYourBase (string s) {
          cout << "[Base] Constructor!" << endl;
          stuff = s;
      }
  };
    
  struct AreBelongToUs : public AllYourBase {
      int i;
      AreBelongToUs (string s, int j) : AllYourBase(s) {
          cout << "[Derived] Constructor!" << endl;
          i = j;
      }
  };
    
  int main () {
      AreBelongToUs a(":D", 3);
      cout << a.i << endl;
      cout << a.stuff << endl;
  }
