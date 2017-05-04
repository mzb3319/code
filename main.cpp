#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if(numRows==0)
            return {};
        vector<vector<int>> ret{{1}};
        for(int i=1;i<numRows;i++)
        {
            vector<int> tmp;
            for(int j=0;j<ret[i-1].size();j++)
            {
                if(j-1>=0)
                    tmp.push_back(ret[i-1][j-1]+ret[i-1][j]);
                else
                    tmp.push_back(ret[i-1][j]);
            }
            tmp.push_back(1);
            ret.push_back(tmp);
        }
        return ret;
    }
};