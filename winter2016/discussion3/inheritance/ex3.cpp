#include <iostream>
using namespace std;

struct Basically {
      int a;
      int b;
      Basically () {a = 1; b = 2;}
  };
  struct Best : public Basically {
      int a;
      int c;
      Best () {a = 3; c = 4;}
  };
  struct Example : public Basically {
      int a;
      int d;
      Example () {a = 5; d = 6;}
  };
  
  int main () {
      Basically base;
      Best best;
      Example ex;
      cout << base.a << endl; // 1
      cout << best.a << endl; // 2
      cout << ex.a << endl;   // 3
      cout << best.b << endl; // 4
      //cout << ex.c << endl;   // 5
      cout << ex.d << endl;   // 6
      //cout << base.d << endl; // 7
  }
