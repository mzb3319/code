#include "iostream"
#include "string"

using namespace std;

class Solution
{
public:
    int countSegments(string s)
    {
        int ret=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' '&&i+1<s.length()&&s[i+1]!=' ')
                ret++;
        }
        return ret;
    }
};