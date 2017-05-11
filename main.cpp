#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution
{
public:
    string convertToTitle(int n)
    {
        string ret;
        while(n)
        {
            char tmp='A'+(n-1)%26;
            ret=tmp+ret;
            n=(n-1)/26;
        }
        return ret;
    }
};