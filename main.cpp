#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int maximalSquare(vector<string> &matrix)
    {
        if(matrix.empty()||matrix.front().empty())
            return 0;
        vector<vector<pair<int,int>>> table(matrix.size()+1,vector<pair<int,int>>(matrix.front().size()+1));
        for(int i=matrix.size()-1;i>=0;--i)
        {
            for(int j=matrix.front().size()-1;j>=0;--j)
            {
                if(matrix[i][j]=='1')
                {
                    table[i][j].first+=table[i][j+1].first+1;
                    table[i][j].second+=table[i+1][j].second+1;
                }
            }
        }
        int ret=0;
        for(int i=0;i<matrix.size();++i)
        {
            for(int j=0;j<matrix.front().size();++j)
            {
                if(matrix[i][j]=='1')
                {
                    int len=1;
                    while(i+len<matrix.size()&&j+len<matrix.front().size()&&table[i+len][j].first>len&&table[i][j+len].second>len)
                        ++len;
                    ret=max(ret,len*len);
                }
            }
        }
        return ret;
    }
};

int main()
{
    vector<string> matrix{"10100","10111","11111","10010"};
    Solution s;
    s.maximalSquare(matrix);
    return 0;
}