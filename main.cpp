#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> left2right,right2left;
        int num=1;
        for(int n:nums)
        {
            num*=n;
            left2right.push_back(num);
        }
        num=1;
        for(int i=nums.size()-1;i>=0;--i)
        {
            num*=nums[i];
            right2left.push_back(num);
        }
        vector<int> ret;
        for(int i=0;i<nums.size();++i)
        {
            int a=1;
            if(i-1>=0)
                a=left2right[i-1];
            int b=1;
            int index=nums.size()-i-1;
            if(index-1>=0)
                b=right2left[index-1];
            ret.push_back(a*b);
        }
        return ret;
    }
};
