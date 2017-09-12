#include "istream"
#include "vector"

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix,int target)
    {
        if(matrix.empty()||matrix.front().empty())
            return false;
        int row=0,col=matrix.front().size()-1;
        while(row<matrix.size()&&col>=0)
        {
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]<target)
                ++row;
            else
                --col;
        }

        return false;
    }
};