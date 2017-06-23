#include "iostream"
#include "vector"
#include "unordered_map"
#include "unordered_set"

using namespace std;

class Solution
{
public:
    int combinationSum4(vector<int> &nums,int target)
    {
        unordered_map<int,int> table;
        return core(nums,target,table);
    }
private:
    int core(vector<int> &nums,int target,unordered_map<int,int> &table)
    {
        auto f=table.find(target);
        if(f!=table.end())
            return f->second;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
            {
                count++;
                continue;
            }
            else if(nums[i]>target)
                continue;
            count+=core(nums,target-nums[i],table);
        }
        table.insert({target,count});
        return count;
    }
};