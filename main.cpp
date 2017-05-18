#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board,vector<int>& click)
    {
        if(board[click[0]][click[1]]=='M')
        {
            board[click[0]][click[1]]='X';
            return board;
        }
        core(board,click);
        return board;
    }
private:
    void core(vector<vector<char>>& board,vector<int> pos)
    {
        int x=pos[0],y=pos[1];
        if(x<0||y<0||x>=board.size()||y>=board[0].size())
            return;
        if(board[x][y]=='E')
        {
            board[x][y] = 'B';
            int count = 0;
            if (x - 1 >= 0 && board[x - 1][y] == 'M')//top
                count++;
            if (x + 1 < board.size() && board[x + 1][y] == 'M')//bottom
                count++;
            if (y - 1 >= 0 && board[x][y - 1] == 'M')//left
                count++;
            if (y + 1 < board[0].size() && board[x][y + 1] == 'M')//right
                count++;
            if (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] == 'M')//left-top
                count++;
            if (x - 1 >= 0 && y + 1 < board[0].size() && board[x - 1][y + 1] == 'M')//right-top
                count++;
            if (x + 1 < board.size() && y - 1 >= 0 && board[x + 1][y - 1] == 'M')//left-bottom
                count++;
            if (x + 1 < board.size() && y + 1 < board[0].size() && board[x + 1][y + 1] == 'M')//right-bottom
                count++;
            if (count)
                board[x][y] = '0' + count;
            else {
                core(board, {x - 1, y});
                core(board, {x + 1, y});
                core(board, {x, y - 1});
                core(board, {x, y + 1});
                core(board, {x - 1, y - 1});
                core(board, {x - 1, y + 1});
                core(board, {x + 1, y - 1});
                core(board, {x + 1, y + 1});
            }
        }
    }
};