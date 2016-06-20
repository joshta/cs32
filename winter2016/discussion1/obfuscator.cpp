#include <iostream>
using namespace std;

class Program {
    private:
        int password;

    public:
        Program() {
            cout << "[C] Program Default constructor" << endl;
            password=11;
        }

        Program(const Program &other) {
            cout << "[~] Program Copy constructor" << endl;
            this->password=other.password;
        }
        Program(const Program *other) {
            cout << "[P] Program Parameterized constructor" << endl;
            this->password=other->password;
        }
        Program& operator=(const Program &other) {
            cout << "[=] Program Assignment" << endl;
            this->password=other.password;
            return *this;
        }
        Program& operator=(const Program *other) {
            cout << "[=] Program Assignment" << endl;
            this->password=other->password;
            return *this;
        }
        ~Program() {
            cout << "[D] Program Destructor" << endl;
        }            

        void verify(int password) {
            if(this->password==password) {
                cout<<"valid password"<<endl;
            }
        }
};

class Obfuscator {
    private:
        Program *p;

    public:
        Obfuscator() {
            cout << "[C] Obfuscator Default constructor" << endl;
            p=new Program();
        }           

        Obfuscator(const Obfuscator &other) {
            cout << "[~] Obfuscator Copy constructor" << endl;
            this->p=new Program(other.p);
        }
        ~Obfuscator() {
            cout << "[D] Obfuscator Destructor" << endl;
            //if(p!=nullptr) delete p;
        }
        void executeInput(int input) {
            p->verify(input);
        }
};

int main() {
    Obfuscator *o;
    for(int i=0;i<2;i++) {
        Obfuscator n[2];
    }

    o=new Obfuscator[2];
    delete o;

//    Obfuscator *o=new Obfuscator();
//    o->executeInput(11);
//    delete o;
//
//
    return 0;
}
