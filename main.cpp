#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> & nums,int r,int c)
    {
        if(nums.empty()||nums[0].empty()||nums.size()*nums[0].size()!=r*c)
            return nums;
        vector<vector<int>> ret;
        vector<int> tmp;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[0].size();j++)
            {
                tmp.push_back(nums[i][j]);
                count++;
                if(count==c)
                {
                    ret.push_back(tmp);
                    tmp.clear();
                    count=0;
                }
            }
        }
        return ret;
    }
};

int main()
{
    vector<vector<int>> table{{1,2},{3,4}};
    Solution s;
    s.matrixReshape(table,4,1);
    return 0;
}