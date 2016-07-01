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
		InputProgramPair* current=head;
		for(;current!=nullptr;current=current->next) {
			if(current->input==input) {
				current->p->run(input);
			}
		}
        }

        /*
        * Inserts at end (queue)
        */
        void insert(int input, Program *p) {
		if(head==nullptr) {
			head=new InputProgramPair();
			head->input=input;
			head->p=p;
			head->next=nullptr;
			head->prev=nullptr;
			tail=head;
		}
		else {
			InputProgramPair* pair=new InputProgramPair();	
			pair->input=input;
			pair->p=p;
			pair->next=nullptr;
			pair->prev=tail;
			tail->next=pair;
			tail=pair;			
		}
        }

        /*
        * Add to head of linked list (stack)
        */
        void pushProgram(int input, Program* p) {
		if(head==nullptr) {
			head=new InputProgramPair();
			head->input=input;
			head->p=p;
			head->next=nullptr;
		}
		else {
			InputProgramPair* pair=new InputProgramPair();	
			pair->input=input;
			pair->p=p;
			pair->next=head;
			head=pair;
		}
        }

        Obfuscator(const Obfuscator &other) {
            cout << "[~] Obfuscator Copy constructor" << endl;
	     this->operator=(other);
        }

        Obfuscator& operator=(const Obfuscator& other) {
        	//same object
		if(&other==this) {
			return *this;
		}
		//handles existing data and avoids memory leaks
		clearall();
		//copy from other to this
		InputProgramPair* tmpp=other.head;
		while(tmpp!=nullptr) {
			insert(tmpp->input,tmpp->p);
			tmpp=tmpp->next;					
		}
       	return *this; 
	}
        
        ~Obfuscator() {
            cout << "[D] Obfuscator Destructor" << endl;
       	clearall(); 
	}

	/* Deletes and removes all items in the list
	*
	*/
	void clearall() {
		InputProgramPair* current=head;
		InputProgramPair* target=head;
		while(target!=nullptr) {
			current=current->next;
			delete target;
			target=current;
		}	
		head=tail=nullptr;
	}
       /*
        * Removes top of stack
        */
        void popProgram() {
  		if(head==nullptr) {
			return;
		}
		InputProgramPair* target=head;
		head=head->next;
		if(head==nullptr) {
			tail=nullptr;
		}
		else {
			head->prev=nullptr;
		}
		delete target;
        }

	  const InputProgramPair& top() const {
		if(head==nullptr) {
			//depends on the specification
		}
		return *head;
	  }

        Obfuscator() {
            cout << "[C] Obfuscator Default constructor" << endl;
            head=nullptr;
            tail=nullptr;
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
    Obfuscator o2(o1);
  
    o1.pushProgram(11,p);
    o1.executeInput(1);

    return 0;
}


