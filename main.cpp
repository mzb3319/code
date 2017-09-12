#include "istream"
#include "vector"

using namespace std;

class Solution
{
public:
    bool isAnagram(string &s,string &t)
    {
        vector<int> table(26,0);
        for(char c:s)
            ++table[c-'a'];
        for(char c:t)
            --table[c-'a'];
        for(int n:table)
            if(n!=0)
                return false;
        return true;
    }
};
