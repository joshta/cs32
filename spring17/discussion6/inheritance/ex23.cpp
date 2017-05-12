#include<iostream>
using namespace std;
  struct AllYourBase {
      // [!] New data member is pointer to
      // dynamically allocated string!
      string* stuff;
      AllYourBase (string s) {
          cout << "[Base] Constructor!" << endl;
          stuff = new string(s);
      }
      virtual ~AllYourBase () {
          cout << "[Base] Destructor!" << endl;
          delete stuff;
      }
  };
  struct AreBelongToUs : public AllYourBase {
      // [!] New data member is pointer to
      // dynamically allocated int array!
      int* i;
      AreBelongToUs (string s, int* j, int size) : AllYourBase(s) {
          cout << "[Derived] Constructor!" << endl;
          i = new int[size];
          for (int k = 0; k < size; k++) {
              i[k] = j[k];
          }
      }
      ~AreBelongToUs () {
          cout << "[Derived] Destructor!" << endl;
          delete[] i;
      }
  };
  int main () {
      int j[] = {1, 2, 3};
      AreBelongToUs a(":D", j, 3);

      AllYourBase b("AIEE!!!");

      AllYourBase* ptr = new AreBelongToUs(":(", j, 3);
      //delete ptr;
  }
