#include "vector"
#include "iostream"

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> table;
        core(nums,0,table);
        return table;
    }
private:
    void core(vector<int> &nums,int index,vector<vector<int>> &table)
    {
        if(index==nums.size())
        {
            table.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();++i)
        {
            swap(nums,index,i);
            core(nums,index+1,table);
            swap(nums,index,i);
        }
    }
    void swap(vector<int> &nums,int a,int b)
    {
        int tmp=nums[a];
        nums[a]=nums[b];
        nums[b]=tmp;
    }
};
