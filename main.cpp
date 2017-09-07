#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if(grid.empty()||grid.front().empty())
            return 0;
        int ret=0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid.front().size();++j)
            {
                if(grid[i][j]=='1')
                {
                    ++ret;
                    check(grid,i,j);
                }
            }
        }
        return ret;
    }
private:
    void check(vector<vector<char>> &grid,int i,int j)
    {
        if(i<0||i>=grid.size()||j<0||j>=grid.front().size()||grid[i][j]=='0')
            return;
        grid[i][j]='0';
        check(grid,i-1,j);
        check(grid,i+1,j);
        check(grid,i,j-1);
        check(grid,i,j+1);
    }
};

int main()
{
    vector<vector<char>> grid{{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    Solution s;
    s.numIslands(grid);
    return 0;
}