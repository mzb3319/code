#include "iostream"
#include "string"
#include "vector"


using namespace std;

class Solution
{
public:
    string findLongestWord(string s,vector<string> &d)
    {
        vector<int> index(d.size());
        string ret;
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j<d.size();j++)
            {
                if(index[j]==-1)
                    continue;
                if(d[j][index[j]]==s[i])
                {
                    index[j]++;
                    if(index[j]==d[j].size())
                    {
                        if(d[j].length()>ret.length()||(d[j].length()==ret.length()&&d[j]<ret))
                        {
                            ret=d[j];
                        }
                        index[j]=-1;
                    }
                }
            }
        }
        return ret;
    }
};