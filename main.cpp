#include "vector"
#include "string"
#include "unordered_set"
#include "algorithm"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    vector<string> wordBreak(string s,vector<string> &wordDict)
    {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<vector<int>> table(s.length());
        for(int i=s.length()-1;i>=0;--i)
        {
            for(int j=i;j<s.length();++j)
            {
                int len=j-i+1;
                string tmp=s.substr(i,len);
                auto f=dict.find(tmp);
                if(f==dict.end())
                    continue;
                if(j+1==s.length()||!table[j+1].empty())
                    table[i].push_back(len);
            }
        }
        vector<string> ret;
        string tmp;
        core(s,table,0,tmp,ret);
        return ret;
    }
private:
    void core(string &s,vector<vector<int>> &table,int index,string &tmp,vector<string> &ret)
    {
        if(index==s.length())
        {
            ret.push_back(tmp);
            return;
        }
        for(int i=0;i<table[index].size();++i)
        {
            int len=table[index][i];
            if(!tmp.empty())
                tmp+=" ";
            string str=s.substr(index,len);
            tmp+=str;
            core(s,table,index+len,tmp,ret);
            tmp.erase(tmp.size()-str.length(),str.length());
            if(tmp.back()==' ')
                tmp.pop_back();
        }
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
