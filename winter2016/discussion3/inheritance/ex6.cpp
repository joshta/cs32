#include<iostream>
using namespace std;

struct DropTheBase {
      int a;
      string s;
      string m;
      string t;
      DropTheBase () {
          a = 3;
          s = "[s] Base!";
          m = "[m] Base!";
          t = "[t] Base!";
      }
  };
  
  struct DerivingMeCrazy : public DropTheBase {
      int a;
      string s;
      string t;
      DerivingMeCrazy () {
          a = 1;
          s = "[s] Derived!";
          t = "[t] Derived!";
      }
  };
 
  int main () {
      DerivingMeCrazy d;
      DropTheBase b=d;
      
      cout << b.t << endl;
  }
