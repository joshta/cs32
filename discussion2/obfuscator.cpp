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
* (Node)
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
        /* Traverses linked list of executable programs and runs on matching input
        *
        */
        void executeInput(int input) {
            	InputProgramPair* tmp=head;
		while(tmp!=nullptr) {
			if(tmp->input==input) {
				tmp->p->run(input);
			}
			tmp=tmp->next;
		}
        }

        /*
        * Inserts at end (queue)
        */
        void insert(int input, Program *p) {
		InputProgramPair* val=new InputProgramPair();
		val->input=input;
		val->p=p;
		val->next=nullptr;
		val->prev=nullptr;
		//empty list
		if(head==nullptr) {
			head=tail=val;
		}
		else {
			val->prev=tail;
			tail->next=val;
			tail=val;
		}
		
        }
       /*
        * Removes top of stack
        */
        void popProgram() {
		if(head==nullptr) {
			return;
		}
		if(head->next==nullptr) {
			delete head;
			head=tail=nullptr;
		}
		else {
			head=head->next;
			delete head->prev;
			head->prev=nullptr;
		}		
        }

        /*
        * Add to head of linked list
        */
        void pushProgram(int input, Program* p) {
		InputProgramPair* val=new InputProgramPair();
		val->input=input;
		val->p=p;
		val->next=nullptr;
		val->prev=nullptr;
		//empty list
		if(head==nullptr) {
			head=tail=val;
		}
		else {
			val->next=head;
			val->prev=nullptr;
			head->prev=val;
			//tail=head;
			head=val;
		}



        }

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
        *
        */
        void evaluateAll() {

        }


};

int main() {
   Program* p=new Program();
    Obfuscator o1;
    o1.pushProgram(11,p);
    o1.executeInput(1);

    return 0;
}

