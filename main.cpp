#include "istream"
#include "vector"

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> table;
        vector<int> ret;
        for(int i=0;i<=nums.size();++i)
        {
            core(nums,0,i,ret,table);
        }
        return table;
    }
private:
    void core(vector<int> &nums,int index,int len,vector<int> ret,vector<vector<int>> &table)
    {
        if(ret.size()==len)
        {
            table.push_back(ret);
            return;
        }
        for(int i=index;i<nums.size();++i)
        {
            ret.push_back(nums[i]);
            core(nums,i+1,len,ret,table);
            ret.pop_back();
        }
    }
};

int main()
{
    vector<int> nums{1,2,3};
    Solution s;
    s.subsets(nums);
    return 0;
}
