#include<iostream>
#include<vector>
#include<list>
using namespace std;

template <typename T>
class HashTable {
    private:
        int BUCKETS;
        vector< list<T> > buckets;

        unsigned int hash(int toHash) {

        }

        unsigned int hash (string s) {

        }

    public:
        HashTable() : BUCKETS(5) {

        }
        void insert (T toInsert) {

        }
        void print () {

        }    
};

int main() {
    HashTable<int> hash;
    hash.insert(5);
    hash.insert(15);
    hash.insert(25);
    hash.insert(1);
    hash.insert(5);
    hash.insert(11);
    hash.print();
    return 0;
}
