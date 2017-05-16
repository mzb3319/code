#include "unordered_set"
#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int distributeCandies(vector<int>& candies)
    {
        int num=candies.size()/2;
        unordered_set<int> gain;
        for(int candy:candies)
        {
            gain.insert(candy);
        }
        return gain.size()>num?num:gain.size();
    }
};