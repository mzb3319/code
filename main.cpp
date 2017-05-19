#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int findCircleNum(vector<vector<int>>& M)
    {
        vector<int> flag(M.size(),0);
        int ret=0;
        for(int i=0;i<M.size();i++)
        {
            if(flag[i])
                continue;
            ret++;
            core(M,i,flag);
        }
        return ret;
    }
private:
    void core(vector<vector<int>>& M,int i,vector<int>& flag)
    {
        if(flag[i])
            return;
        flag[i]=1;
        for(int j=0;j<M[i].size();j++)
        {
            if(M[i][j])
                core(M,j,flag);
        }
    }
};