#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        if(matrix.empty()||matrix.front().empty())
            return 0;
        vector<vector<int>> table(matrix.size(),vector<int>(matrix.front().size(),-1));

        int ret=1;

        for(int i=0;i<matrix.size();++i)
        {
            for(int j=0;j<matrix.front().size();++j)
            {
                ret=max(ret,check(matrix,i,j,table));
            }
        }
        return ret;
    }
private:
    int check(vector<vector<int>> &matrix,int i,int j,vector<vector<int>> &table)
    {
        if(i<0||j<0||i>=matrix.size()||j>=matrix.front().size())
            return 0;
        if(table[i][j]!=-1)
            return table[i][j];

        int top=0;
        if(i-1>=0&&matrix[i-1][j]>matrix[i][j])
            top=check(matrix,i-1,j,table);

        int bottom=0;
        if(i+1<matrix.size()&&matrix[i+1][j]>matrix[i][j])
            bottom=check(matrix,i+1,j,table);

        int left=0;
        if(j-1>=0&&matrix[i][j-1]>matrix[i][j])
            left=check(matrix,i,j-1,table);

        int right=0;
        if(j+1<matrix.front().size()&&matrix[i][j+1]>matrix[i][j])
            right=check(matrix,i,j+1,table);

        int currMax=max(top,bottom);
        currMax=max(currMax,left);
        currMax=max(currMax,right);

        table[i][j]=currMax+1;
        return table[i][j];
    }
};


int main()
{
    vector<vector<int>> matrix{{9,9,4}};
    Solution s;
    cout<<s.longestIncreasingPath(matrix)<<endl;
    return 0;
}