#include "string"
#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    bool repeatedSubstringPattern(string &s)
    {
        vector<int> table(s.length(),0);
        for(int i=1;i<s.length();++i)
        {
            int index=i;
            while(table[index-1]!=0&&s[i]!=s[table[index-1]])
                index=table[index-1];
            if(s[i]==s[table[index-1]])
                table[i]=table[index-1]+1;
            else
                table[i]=table[index-1];
        }
        return table.back()&&s.length()%(s.length()-table.back())==0;
    }
};