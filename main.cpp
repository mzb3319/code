#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int ret=0;
        vector<int> table(nums.size(),0);
        for(int i=nums.size()-1;i>=0;--i)
        {
            int n=0;
            for(int j=i+1;j<nums.size();++j)
            {
                if(nums[i]<nums[j])
                    n=max(table[j],n);
            }
            table[i]=n+1;
            ret=max(table[i],ret);
        }
        return ret;
    }
};