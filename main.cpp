#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum3(int k,int n)
    {
        vector<vector<int>> ret;
        vector<int> tmp;
        core(k,n,1,0,ret,tmp);
        return ret;
    }
private:
    void core(int k,int n,int beg,int add,vector<vector<int>>& ret,vector<int>&tmp)
    {
        if(k==0)
        {
            if(add==n)
                ret.push_back(tmp);
        }
        else
        {
            for(int i=beg;i<=9;i++)
            {
                tmp.push_back(i);
                core(k-1,n,i+1,add+i,ret,tmp);
                tmp.pop_back();
            }
        }
    }
};