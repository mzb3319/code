#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==i+1)
                continue;
            if((nums[i]-1<nums.size())&&(nums[nums[i]-1]==nums[i]))
                continue;
            if(nums[i]-1>=nums.size())
                continue;
            int tmp=nums[nums[i]-1];
            nums[nums[i]-1]=nums[i];
            nums[i]=tmp;
            --i;
        }
        for(int i=0;i<nums.size();++i)
            if(nums[i]!=(i+1))
                return i+1;
        return nums.size()+1;
    }
};

int main()
{
    vector<int> nums{1,1};
    Solution s;
    s.firstMissingPositive(nums);
    return 0;
}