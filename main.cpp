#include "vector"
#include "iostream"

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==i)
                continue;
            if(nums[i]>=nums.size())
                continue;
            int tmp=nums[nums[i]];
            nums[nums[i]]=nums[i];
            nums[i]=tmp;
            --i;
        }
        for(int i=0;i<nums.size();++i)
            if(nums[i]==nums.size())
                return i;
        return nums.size();
    }
};
