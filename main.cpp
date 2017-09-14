#include "iostream"
#include "string"
#include "unordered_map"
#include "vector"
#include "algorithm"
#include "queue"
#include "unordered_set"

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> table(26,-1);
        for(int i=0;i<s.length();++i)
        {
            if(table[s[i]-'a']!=-1)
                table[s[i]-'a']=-2;
            else
                table[s[i]-'a']=i;
        }
        for(char c:s)
        {
            if(table[c-'a']>0)
                return table[c-'a'];
        }
        return -1;
    }
};
