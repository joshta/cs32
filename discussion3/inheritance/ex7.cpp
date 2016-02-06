#include<iostream>
using namespace std;

struct DropTheBase {
      int a;
      string s;
      string m;
      DropTheBase () {
          a = 3;
          s = "[s] Base!";
          m = "[m] Base!";
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
      //DropTheBase b = DerivingMeCrazy();
      DerivingMeCrazy b=DropTheBase(); 
        
      cout << b.a << endl;
      cout << b.s << endl;
      cout << b.m << endl;
  }
