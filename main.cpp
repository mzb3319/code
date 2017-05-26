#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution
{
public:
    bool isSubsequence(string &s,string &t)
    {
        int i=0,j=0;
        for(;i<s.length();)
        {
            if(j==t.length())
                break;
            for(;j<t.length();j++)
            {
                if(s[i]==t[j])
                {
                    j++;
                    i++;
                    break;
                }
            }
        }
        return i==s.length();
    }
};