#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if(matrix.empty())
            return {};
        vector<int> ret;
        int row_beg=0,row_end=matrix.size()-1,col_beg=0,col_end=matrix.front().size()-1;
        while(row_beg<=row_end&&col_beg<=col_end)
        {
            //print top_left2right
            for(int i=col_beg;i<=col_end;++i)
                ret.push_back(matrix[row_beg][i]);
            ++row_beg;
            if(row_beg>row_end)
                break;
            //print right_top2bottom
            for(int i=row_beg;i<=row_end;++i)
                ret.push_back(matrix[i][col_end]);
            --col_end;
            if(col_beg>col_end)
                break;
            //print bottom_right2left
            for(int i=col_end;i>=col_beg;--i)
                ret.push_back(matrix[row_end][i]);
            --row_end;
            if(row_beg>row_end)
                break;
            //print left_bottom2top
            for(int i=row_end;i>=row_beg;--i)
                ret.push_back(matrix[i][col_beg]);
            ++col_beg;
        }
        return ret;
    }
};