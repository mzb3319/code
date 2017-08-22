#include "vector"
#include "iostream"
#include "unordered_set"

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<vector<unordered_set<char>>> grid9(3,vector<unordered_set<char>>(3));
        vector<unordered_set<char>> row(9),col(9);
        for(int i=0;i<board.size();++i)
        {
            for(int j=0;j<board.front().size();++j)
            {
                if(board[i][j]=='.')
                    continue;
                auto pr=row[i].insert(board[i][j]);
                auto pc=col[j].insert(board[i][j]);
                auto p=grid9[i/3][j/3].insert(board[i][j]);
                if(pr.second&&pc.second&&p.second)
                    continue;
                else
                    return false;
            }
        }
        return true;
    }
};
