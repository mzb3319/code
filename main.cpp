#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> ret{{1},{1,1}};
        for(int i=2;i<=rowIndex;i++)
        {
            ret.push_back({1});
            for(int j=1;j<i;j++)
            {
                ret[i].push_back(ret[i-1][j]+ret[i-1][j-1]);
            }
            ret[i].push_back(1);
        }
        return ret[rowIndex];
    }
};