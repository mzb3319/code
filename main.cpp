#include "vector"
#include "string"
#include "unordered_set"
#include "algorithm"

using namespace std;

class Solution
{
public:
    bool wordBreak(string s,vector<string> &wordDict)
    {
        unordered_set<string> Dict(wordDict.begin(),wordDict.end());
        vector<int> table(s.length(),-1);
        return core(s,0,table,Dict);
    }
private:
    bool core(string &s,int index,vector<int> &table,unordered_set<string> &dict)
    {
        if(index==s.length())
            return true;
        if(table[index]!=-1)
            return table[index]==0?false:true;
        for(int i=index;i<s.length();++i)
        {
            string tmp=s.substr(index,i-index+1);
            auto f=dict.find(tmp);
            if(f==dict.end())
                continue;
            if(core(s,i+1,table,dict))
            {
                table[index]=1;
                return true;
            }
        }
        table[index]=0;
        return false;
    }
};

int main()
{
    string s="leetcode";
    vector<string> dict{"leet","code"};
    Solution ss;
    ss.wordBreak(s,dict);
    return 0;
}
