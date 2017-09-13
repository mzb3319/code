#include "iostream"
#include "string"

using namespace std;

class Solution
{
public:
    string reverseString(string s)
    {
        int beg=0,end=s.length()-1;
        while(beg<end)
        {
            char tmp=s[beg];
            s[beg]=s[end];
            s[end]=tmp;
        }
        return s;
    }
};