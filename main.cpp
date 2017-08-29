#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board,string &word)
    {
        vector<vector<bool>> status(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();++i)
        {
            for(int j=0;j<board[0].size();++j)
            {
                if(search(board,word,i,j,0,status))
                {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool search(vector<vector<char>> &board,string &word,int i,int j,int index,vector<vector<bool>> &status)
    {
        if(index==word.size())
            return true;
        if(i<0||i>=board.size()||j<0||j>=board[0].size())
            return false;
        if(status[i][j])
            return false;
        if(board[i][j]!=word[index])
            return false;
        status[i][j]=true;
        if(
                search(board,word,i+1,j,index+1,status)||
                search(board,word,i-1,j,index+1,status)||
                search(board,word,i,j+1,index+1,status)||
                search(board,word,i,j-1,index+1,status)
                )
        {
            status[i][j]=false;
            return true;
        }
        status[i][j]=false;
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board{{'C','A','A'},{'A','A','A'},{'B','C','D'}};
    string word="AAB";
    s.exist(board,word);
    return 0;
}
