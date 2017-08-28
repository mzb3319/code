#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        if(matrix.empty()||matrix.front().empty())
            return;
        int m=matrix.size(),n=matrix.front().size();
        bool row0_hasZero=false,col0_hasZero=false;
        for(int i=0;i<m;++i)
            if(matrix[i][0]==0)
            {
                col0_hasZero=true;
                break;
            }
        for(int i=0;i<n;++i)
            if(matrix[0][i]==0)
            {
                row0_hasZero=true;
                break;
            }
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                    break;
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(matrix[j][i]==0)
                {
                    matrix[0][i]=0;
                    break;
                }
            }
        }
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                if(matrix[0][j]==0||matrix[i][0]==0)
                    matrix[i][j]=0;
            }
        }
        if(row0_hasZero)
        {
            for(int i=0;i<n;++i)
                matrix[0][i]=0;
        }
        if(col0_hasZero)
        {
            for(int i=0;i<m;++i)
                matrix[i][0]=0;
        }
    }
};

int main()
{
    vector<vector<int>> matrix{{0}};
    Solution s;
    s.setZeroes(matrix);
    return 0;
}
