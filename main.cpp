#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if(nums.empty())
            return 0;
        vector<int> moneys(nums.size(),0);
        int ret=0;
        for(int i=0;i<nums.size();++i)
        {
            int a=0;
            if(i-2>=0)
                a=moneys[i-2];
            int b=0;
            if(i-3>=0)
                b=moneys[i-3];
            moneys[i]=nums[i]+max(a,b);
            ret=max(ret,moneys[i]);
        }
        return ret;
    }
};