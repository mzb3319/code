#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int findPaths(int m,int n,int N,int i,int j)
    {
        return core2(m,n,N,i,j);
    }

private:
    int core2(int m,int n,int N,int i,int j)
    {
        long long mod=1000000007;
        vector<vector<long long>> table(N+1,vector<long long>(m*n,-1));
        for(int ii=0;ii<table[0].size();++ii)
        {
            table[0][ii]=0;
        }
        for(int step=1;step<=N;++step)
        {
            for(int index=0;index<m*n;++index)
            {
                long long ret=0;
                long long c=index%n,r=index/n;
                //up
                r-1<0?ret++:ret+=table[step-1][(r-1)*n+c];
                //down
                r+1>=m?++ret:ret+=table[step-1][(r+1)*n+c];
                //left
                c-1<0?++ret:ret+=table[step-1][index-1];
                //right
                c+1>=n?++ret:ret+=table[step-1][index+1];
                table[step][index]=ret%mod;
            }
        }
        return table[N][i*n+j];
    }
    void core(int m,int n,int N,int i,int j,int &ret)
    {
        if(i<0||i>=m||j<0||j>=n)
        {
            ret++;
            return;
        }
        if(N<=0)
            return;
        core(m,n,N-1,i-1,j,ret);
        core(m,n,N-1,i+1,j,ret);
        core(m,n,N-1,i,j-1,ret);
        core(m,n,N-1,i,j+1,ret);
    }
};


int main()
{
    Solution s;
    cout<<s.findPaths(2,3,8,1,0)<<endl;
    return 0;
}