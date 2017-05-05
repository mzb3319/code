#include "iostream"
#include "string"
#include "vector"
#include "unordered_map"

using namespace std;



class Solution
{
public:
    vector<int> findAnagrams(string s,string p)
    {
        if(s.length()<p.length())
            return {};
        unordered_map<char,int> table,table1;
        vector<int> ret;
        for(int i=0;i<p.length();i++)
        {
            table[p[i]]++;
            table1[p[i]]++;
        }
        int pL=p.length();
        for(int p=0,l=0;p<s.length();p++)
        {
            while(p==l&&table.find(s[p])==table.end())
            {
                p++;
                l++;
                if(p>=s.length())
                    break;
            }
            auto f=table.find(s[p]);
            if(f==table.end())
            {
                l=p+1;
                table=table1;
                continue;
            }
            if(f->second==0)
            {
                p=l;
                l++;
                table=table1;
                continue;
            }
            int diff=p-l+1;
            f->second--;
            if(diff==pL)
            {
                ret.push_back(l);
                table[s[l]]++;
                l++;
            }
        }
        return ret;
    }
};
