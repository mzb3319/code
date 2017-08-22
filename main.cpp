#include "vector"
#include "iostream"

using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]-1==i)
                continue;
            if(nums[nums[i]-1]==nums[i])
                continue;
            int tmp=nums[nums[i]-1];
            nums[nums[i]-1]=nums[i];
            nums[i]=tmp;
            --i;
        }
        vector<int> ret;
        for(int i=0;i<nums.size();++i)
            if(nums[i]!=i+1)
                ret.push_back(i+1);
        return ret;
    }
};
