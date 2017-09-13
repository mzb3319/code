#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        vector<int> left2right,right2left;
        for(int i=0;i<nums.size();++i)
        {
            if(left2right.empty())
                left2right.push_back(nums[i]);
            else if(nums[i]<left2right.back())
                left2right.push_back(nums[i]);
            else
                left2right.push_back(left2right[left2right.size()-1]);
        }
        for(int i=nums.size()-1;i>=0;--i)
        {
            if(right2left.empty())
                right2left.push_back(nums[i]);
            else if(nums[i]>right2left.back())
                right2left.push_back(nums[i]);
            else
                right2left.push_back(right2left[right2left.size()-1]);
        }
        for(int i=1;i<nums.size()-1;++i)
        {
            if(left2right[i-1]<nums[i]&&nums[i]<right2left[nums.size()-2-i])
                return true;
        }
        return false;
    }
};