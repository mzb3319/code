#include "iostream"
#include "vector"
#include "unordered_set"

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> table;
        for(int n:nums)
        {
            auto is=table.insert(n);
            if(!is.second)
                return true;
        }
        return false;
    }
};