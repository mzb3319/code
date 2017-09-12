#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int fast=0,slow=0;
        while(fast<nums.size())
        {
            while(slow<fast&&nums[slow]!=0)
                ++slow;
            if(nums[fast]!=0)
            {
                int tmp=nums[slow];
                nums[slow]=nums[fast];
                nums[fast]=tmp;
            }
            ++fast;
        }
    }
};
