#include "vector"
#include "iostream"
#include "algorithm"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    int findPairs(vector<int> & nums,int k)
    {
        if(k<0)
            return 0;
        unordered_map<int,int> ret;
        int fast=0,slow=0;
        sort(nums.begin(),nums.end());
        while(fast<nums.size()&&slow<nums.size())
        {
            int diff=nums[fast]-nums[slow];
            if(diff==k&&fast!=slow)
            {
                ret.insert({nums[slow],nums[fast]});
                fast++;
            }
            else if(diff>k)
                slow++;
            else
                fast++;
        }
        return ret.size();
    }
};