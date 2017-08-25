#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int uniquePaths(int m,int n)
    {
        if(m<=0||n<=0)
            return 0;
        vector<vector<int>> table(m+1,vector<int>(n+1,0));
        table[m-1][n]=1;
        for(int i=n-1;i>=0;--i)
        {
            for(int j=m-1;j>=0;--j)
            {
                table[j][i]=table[j+1][i]+table[j][i+1];
            }
        }
        return table[0][0];
    }
};
