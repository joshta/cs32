#include<iostream>
using namespace std;

 struct Basically {
      int a;
      int b;
      Basically () {a = 1; b = 2;}
      // [!] Pure virtual function
      virtual int compute () = 0;
  };
  struct Best : public Basically {
      int a;
      int c;
      Best () {a = 3; c = 4;}
      virtual int compute () {return a + b;}
  };
  
  int main () {
      //Basically base;
      Best best;
      cout << best.compute() << endl;
  }
