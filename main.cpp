#include "bitset"
#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        vector<bitset<26>> table(words.size(),0);
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                table[i].set(words[i][j]-'a');
            }
        }

        int ret=0;
        for(int i=0;i<table.size();i++)
        {
            for(int j=i+1;j<table.size();j++)
            {
                if((table[i]&table[j]).none())
                {
                    int len=words[i].length()*words[j].length();
                    if(ret<len)
                        ret=len;
                }
            }
        }
        return ret;
    }
};