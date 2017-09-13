#include "iostream"
#include "string"
#include "unordered_map"
#include "vector"
#include "algorithm"
#include "queue"
#include "unordered_set"

using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(table.find(val)!=table.end())
            return false;
        table_v.push_back(val);
        table[val]=table_v.size()-1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(table.find(val)==table.end())
            return false;
        table_v[table[val]]=table_v.back();
        table[table_v.back()]=table[val];
        table_v.pop_back();
        table.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int r=random()%(table_v.size());
        return table_v[r];
    }
private:
    unordered_map<int,int> table;
    vector<int> table_v;
};

int main()
{
    cout<<random()%5<<endl;
    return 0;
}