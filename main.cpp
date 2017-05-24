#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
    {
        if(matrix.empty()||matrix[0].empty())
            return {};
        int row=0,col=0;
        int count=matrix.size()*matrix[0].size();
        vector<int> ret;
        while(count)
        {
            getPos(row,col,matrix);
            ret.push_back(matrix[row][col]);
            count--;
            if(downOrUp)
            {
                row--;col++;
            }
            else
            {
                row++;col--;
            }
        }
        return ret;
    }

private:
    void getPos(int &i,int &j,vector<vector<int>>& matrix)
    {
        if(i>=0&&i<matrix.size()&&j>=0&&j<matrix[0].size())
            return;
        if(downOrUp)
        {
            i++;j--;
            if(j+1<matrix[0].size())
            {
                j++;
                downOrUp=false;
                return;
            }
            else
            {
                i++;
                downOrUp=false;
                return;
            }
        }
        else
        {
            i--;j++;
            if(i+1<matrix.size())
            {
                i++;
                downOrUp=true;
                return;
            }
            else
            {
                j++;
                downOrUp=true;
                return;
            }
        }
    }

private:
    bool downOrUp=true;//true->up,false->down
};

int main()
{
    vector<vector<int>> m{{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    s.findDiagonalOrder(m);
    return 0;
}