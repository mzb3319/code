#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count=0,ret=0;
        for(int n:nums)
        {
            if(count==0)
            {
                ret=n;
                count=1;
                continue;
            }
            if(n==ret)
                ++count;
            else
                --count;
        }
        return ret;
    }
    //遇到有序数组时性能严重下降
    int majorityElement1(vector<int> &nums)
    {
        return core(nums,0,nums.size()-1);
    }

private:
    int core(vector<int> &nums,int beg,int end)
    {
        int p=beg-1;
        for(int i=beg;i<=end;++i)
        {
            if(nums[i]<=nums[end])
            {
                int tmp=nums[i];
                nums[i]=nums[++p];
                nums[p]=tmp;
            }
        }
        int mid=nums.size()/2;
        if(p==mid)
            return nums[p];
        else if(p>mid)
            return core(nums,beg,p-1);
        else
            return core(nums,p+1,end);
    }
};