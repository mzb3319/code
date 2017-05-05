#include "string"
#include "iostream"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s,string t)
    {
        if(s.length()!=t.length())
            return false;
        unordered_map<char,char> table1,table2;
        for(int i=0;i<s.length();i++)
        {
            auto f1=table1.find(s[i]);
            auto f2=table2.find(t[i]);
            if(f1==table1.end()&&f2==table2.end())
            {
                table1[s[i]]=t[i];
                table2[t[i]]=s[i];
            }
            else if(f1!=table1.end()&&f1->second==t[i]&&f2!=table2.end()&&f2->second==s[i])
            {
                continue;
            }
            else
                return false;
        }
        return true;
    }
};