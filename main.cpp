#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution
{
public:
    int titleToNumber(string &s)
    {
        if(s.empty())
            return 0;
        int ret=0;
        for(char c:s)
        {
            ret*=26;
            ret+=c-'A'+1;
        }
        return ret;
    }
};