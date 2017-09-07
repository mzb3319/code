#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        if(nums.empty())
            -1;
        long long a=INT64_MIN,b=INT64_MIN;
        for(int i=0;i<nums.size();++i)
        {
            a=i-1<0?INT32_MIN:nums[i-1];
            b=i+1>=nums.size()?INT32_MIN:nums[i+1];
            if(nums[i]>a&&nums[i]>b)
                return i;
        }
        return -1;
    }
};