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
            return 0;
        }

        unsigned int hash (string toHash) {
            unsigned int h = 2166136261U;
            for (int k = 0; k != s.size(); k++) {
                h += s[k];
                h *= 16777619;
            }

            return 0;
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

    HashTable<string> hash;
    hash.insert("t");
    hash.insert("a");


    hash.print();
    return 0;
}
