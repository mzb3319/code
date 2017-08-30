#include "string"
#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    int numDecodings(string &s)
    {
        vector<int> table(s.length(),-1);
        if(s.empty())
            return 0;
        return core(s,0,table);
    }
private:
    int core(string &s,int index,vector<int> &table)
    {
        if(index==s.length())
            return 1;
        if(table[index]!=-1)
            return table[index];
        int tmp=stoi(s.substr(index,1));
        int one=0;

        if(tmp>=1&&tmp<=26)
            one=core(s,index+1,table);

        int two=0;
        if(tmp!=0&&index+1<s.length())
        {
            tmp=stoi(s.substr(index,2));
            if(tmp>=1&&tmp<=26)
                two=core(s,index+2,table);
        }
        table[index]=one+two;
        return table[index];
    }
};
