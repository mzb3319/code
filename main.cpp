#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if(nums.size()<2)
            return true;

        int nextJump=nums.size()-1;
        for(int i=nums.size()-2;i>=0;--i)
        {
            if(nums[i]+i>=nextJump)
                nextJump=i;
        }
        return nums.front()>=nextJump?true:false;
    }
};