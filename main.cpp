#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        int base=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            base^=nums[i];
        }
        int a=0,b=0;
        base=(base&(base-1))^base;
        for(int num:nums)
        {
            if(base&num)
            {
                a^=num;
            }
            else
            {
                b^=num;
            }
        }
        return {a,b};
    }
};