#include <iostream>
using namespace std;

class Program {
    public:
        Program() {
            cout << "[C] Program Default constructor" << endl;
        }
        Program(const Program &other) {
            cout << "[~] Program Copy constructor" << endl;
        }
        Program(const Program *other) {
            cout << "[P] Program Parameterized constructor" << endl;
        }

        Program& operator=(const Program &other) {
            cout << "[=] Program Assignment" << endl;
            return *this;
        }
        Program& operator=(const Program *other) {
            cout << "[=] Program Assignment" << endl;
            return *this;
        }

        ~Program() {
            cout << "[D] Program Destructor" << endl;
        }            

        void run(int input) {
            cout<<"running program with input="<<input<<endl;
        }
};

/*
* Represents program that should be execute for specified input value.
*/
struct InputProgramPair {
    InputProgramPair* next;
    InputProgramPair* prev;
    int input;
    Program* p;    
};

class Obfuscator {
    private:
        InputProgramPair* head;
        InputProgramPair* tail;

    public:
        Obfuscator() {
            cout << "[C] Obfuscator Default constructor" << endl;
            head=nullptr;
            tail=nullptr;
        }          
        Obfuscator(const Obfuscator &other) {
            cout << "[~] Obfuscator Copy constructor" << endl;
        }
        Obfuscator& operator=(const Obfuscator& other) {
            if(this==&other) { 
                return *this;
            }
            return *this;
        }
        ~Obfuscator() {
            cout << "[D] Obfuscator Destructor" << endl;
        }
        /*
        * Push to top of stack
        */
        void pushProgram(int input, Program* p) {

        }
        /*
        * Removes top of stack
        */
        void popProgram() {

        }
        /*
        *
        */
        void evaluateAll() {

        }
        /*
        * Inserts at end of list
        */
        void insert(int input, Program *p) {

        }
        /* Traverses linked list of executable programs and runs on matching input
        *
        */
        void executeInput(int input) {
            
        }
};

int main() {
    Obfuscator o1;
    o1.executeInput(11);

    return 0;
}

