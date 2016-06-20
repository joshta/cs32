#include<iostream>
using namespace std;

 struct AllYourBase {
      string stuff;
      AllYourBase (string s) {
          cout << "[Base] Constructor!" << endl;
          stuff = s;
      }
  };
    
  struct AreBelongToUs : public AllYourBase {
      int i;
      
      // [!] Member initialization of base class removed
      AreBelongToUs (string s, int j) {
          cout << "[Derived] Constructor!" << endl;
          i = j;
      }
  };
    
  int main () {
      AreBelongToUs a(":D", 3);
      cout << a.i << endl;
      cout << a.stuff << endl;
  }
