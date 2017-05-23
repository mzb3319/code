#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> & nums)
    {
        vector<int> table,ret(nums.size(),-1);
        int len=nums.size();
        for(int i=0;i<2*len;i++)
        {
            int num=nums[i%len];
            while(!table.empty()&&nums[table.back()]<num)
            {
                ret[table.back()]=num;
                table.pop_back();
            }
            if(i<len)
                table.push_back(i);
        }
        return ret;
    }
};