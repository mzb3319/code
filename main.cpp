#include "iostream"
#include "string"
#include "deque"

using namespace std;

class Solution
{
public:
    string toHex(int num)
    {
        if(!num)
            return "0";
        char table[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        deque<char> ret;
        unsigned int n=num;
        while(n)
        {
            ret.push_front(table[n%16]);
            n/=16;
        }
        return string(ret.begin(),ret.end());
    }
};