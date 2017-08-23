#include "vector"
#include "iostream"

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max=INT32_MIN,add=0;
        for(int n:nums)
        {
            add+=n;
            if(add>max)
                max=add;
            if(add<0)
                add=0;
        }
        return max;
    }
};