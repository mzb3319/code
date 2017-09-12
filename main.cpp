#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        for(int i=0;i<board.size();++i)
        {
            for(int j=0;j<board.front().size();++j)
            {
                //0->dead;1->live;-1->dead2live;2->live2dead
                int count=0;
                //top
                if(i-1>=0&&board[i-1][j]>0)
                    ++count;
                //bottom
                if(i+1<board.size()&&board[i+1][j]>0)
                    ++count;
                //left
                if(j-1>=0&&board[i][j-1]>0)
                    ++count;
                //right
                if(j+1<board.front().size()&&board[i][j+1]>0)
                    ++count;
                //top-left
                if(i-1>=0&&j-1>=0&&board[i-1][j-1]>0)
                    ++count;
                //top-right
                if(i-1>=0&&j+1<board.front().size()&&board[i-1][j+1]>0)
                    ++count;
                //bottom-left
                if(i+1<board.size()&&j-1>=0&&board[i+1][j-1]>0)
                    ++count;
                //bottom-right
                if(i+1<board.size()&&j+1<board.front().size()&&board[i+1][j+1]>0)
                    ++count;

                if(board[i][j]==0&&count==3)
                    board[i][j]=-1;
                else if(board[i][j]==1&&(count<2||count>3))
                    board[i][j]=2;
            }
        }
        for(int i=0;i<board.size();++i)
        {
            for(int j=0;j<board.front().size();++j)
            {
                if(board[i][j]==-1)
                    board[i][j]=1;
                else if(board[i][j]==2)
                    board[i][j]=0;
            }
        }
    }
};
