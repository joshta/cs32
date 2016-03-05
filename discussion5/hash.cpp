#include<iostream>
#include<vector>
#include<list>
using namespace std;

template <typename T>
class HashTable {
    private:
        int BUCKETS;
        vector< list<T> > buckets;

        //identity function
        unsigned int hash(int toHash) {
            return toHash % BUCKETS;                
        }

        unsigned int hash (string s) {
            unsigned int h = 2166136261U;
            for (int k = 0; k != s.size(); k++) {
                h += s[k];
                h *= 16777619;
            }

            return h;
        }

    public:
        HashTable() : BUCKETS(5) {
            buckets.resize(BUCKETS);
        }
        void insert (T toInsert) {
            buckets[HashTable::hash(toInsert)].push_back(toInsert);
        }
        void print () {
            for (int i = 0; i < buckets.size(); i++) {
                typename list<T>::iterator it = buckets[i].begin();
                if (buckets[i].empty()) {
                    continue;
                }
                cout << "=== Bucket[ " << i << " ] ===" << endl;
                while (it != buckets[i].end()) {
                    cout << *it++ << endl;
                }
            }
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
