#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        vector<int> ret;
        for(int num:nums)
        {
            if(num<0)
            {
                if(nums[-1-num]<0)
                    ret.push_back(-num);
                else
                    nums[-1-num]=-nums[-1-num];
            }
            else
            {
                if(nums[num-1]<0)
                    ret.push_back(num);
                else
                    nums[num-1]=-nums[num-1];
            }
        }
        return ret;
    }
};