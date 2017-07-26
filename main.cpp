#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(),pairs.end(),[](const vector<int> &a,const vector<int> &b){return a.back()<b.back();});
        int ret=0;
        int end=INT32_MIN;
        for(int i=0;i<pairs.size();++i)
        {
            if(pairs[i].front()>end)
            {
                ++ret;
                end=pairs[i].back();
            }
        }

        return ret;
    }
};