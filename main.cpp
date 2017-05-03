#include "iostream"
#include "string"

using namespace std;

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        for(int i=1;i<=s.length()/2;i++)
        {
            if(s[i]==s[0])
                if(check(s,i))
                    return true;
        }
        return false;
    }
private:
    bool check(string &s,int index)
    {
        if(s.length()%index)
            return false;
        for(int i=0;i<index;i++)
        {
            for(int j=index+i;j<s.length();j+=index)
            {
                if(s[j]!=s[i])
                    return false;
            }
        }
        return true;
    }
};