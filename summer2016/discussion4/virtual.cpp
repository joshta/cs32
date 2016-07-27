#include<iostream>
using namespace std;

struct Basically {
    int a;
    int b;
    Basically() { a = 1; b = 2; }
    // [!] Pure virtual function
    virtual int compute() = 0;
};
struct Best : public Basically {
    int a;
    int c;
    Best() { a = 3; c = 4; }
    virtual int compute() { return a + b; }
};
// [!] Added another class...
struct Example : public Best {
    int a;
    int d;
    Example() { a = 5; d = 6; }
    virtual int compute() { return a + b; }
};

void test(Basically *b) {
    cout << b->compute() << endl;
}

int main() {
    Best best;
    Example ex;
    test(&best);
    test(&ex);
}
