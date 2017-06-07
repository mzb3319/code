#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int fast=nums[nums[0]],slow=nums[0];
        while(nums[fast]!=nums[slow])
        {
            fast=nums[fast];
            fast=nums[fast];
            slow=nums[slow];
        }
        int ret=0;
        while(nums[ret]!=nums[slow])
        {
            ret=nums[ret];
            slow=nums[slow];
        }
        return nums[ret];
    }
};