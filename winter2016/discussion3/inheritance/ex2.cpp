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
      DropTheBase b;
      DerivingMeCrazy d;
      cout << d.a << endl;
      cout << b.a << endl;
      
      cout << d.s << endl;
      cout << b.s << endl;
      
      cout << d.m << endl;
      cout << b.m << endl;
  }
