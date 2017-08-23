#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution
{
public:
    bool isMatch(string &s,string &p)
    {
        vector<vector<int>> table(s.length()+1,vector<int>(p.length()+1,-1));
        return matchCore(s,0,p,0,table);
    }
private:
    bool matchCore(string &s,int index1,string &p,int index2,vector<vector<int>> &table)
    {
        if(table[index1][index2]!=-1)
            return table[index1][index2];
        if(index1==s.length()&&index2==p.length())
        {
            table[index1][index2]=1;
            return true;
        }
        if(index2==p.length())
        {
            table[index1][index2]=0;
            return false;
        }
        if(index1==s.length())
        {
            int i=index2;
            while(index2<p.length())
            {
                if(p[index2]!='*')
                {
                    table[index1][index2]=0;
                    return false;
                }
                ++index2;
            }
            table[index1][i]=true;
            return true;
        }
        if(p[index2]=='?')
        {
            table[index1][index2]=matchCore(s,index1+1,p,index2+1,table);
            return table[index1][index2];
        }
        else if(p[index2]=='*')
        {
            for (int i = index1; i <= s.length(); ++i)
                if (matchCore(s, i, p, index2 + 1,table))
                {
                    table[index1][index2]=true;
                    return true;
                }
        }
        else if(p[index2]==s[index1])
        {
            table[index1][index2]=matchCore(s,index1+1,p,index2+1,table);
            return table[index1][index2];
        }
        table[index1][index2]=false;
        return false;
    }
};

int main()
{
    Solution s;
    string str("aa"),p("*");
    s.isMatch(str,p);
    return 0;
}