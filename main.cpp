#include "iostream"
#include "vector"
#include "algorithm"
#include "set"
#include "unordered_set"

using namespace std;

class Solution
{
public:
    int longestConsecutive1(vector<int> &nums)
    {
        if(nums.empty())
            return 0;
        set<int> table;
        for(int n:nums)
            table.insert(n);
        vector<int> _nums(table.begin(),table.end());
        int maxLen=1,currLen=1;
        for(int i=1;i<_nums.size();++i)
        {
            if(_nums[i]==_nums[i-1]+1)
            {
                ++currLen;
                maxLen=max(maxLen,currLen);
            }
            else
            {
                maxLen=max(maxLen,currLen);
                currLen=1;
            }
        }
        return maxLen;
    }
    int longestConsecutive(vector<int> &nums)
    {
        if(nums.empty())
            return 0;
        unordered_set<int> table(nums.begin(),nums.end());
        int maxLen=0;
        for(int i=0;i<nums.size();++i)
        {
            auto f=table.find(nums[i]);
            if(f==table.end())
                continue;
            table.erase(nums[i]);
            int pre=nums[i]-1,next=nums[i]+1;
            while(table.find(pre)!=table.end())
                table.erase(pre--);
            while(table.find(next)!=table.end())
                table.erase(next++);
            maxLen=max(maxLen,next-pre-1);
        }
        return maxLen;
    }
};
