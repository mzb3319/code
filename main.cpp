#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ret;
        core(nums,0,ret);
        return ret;
    }
private:
    void core(vector<int> &nums,int k,vector<vector<int>> &ret)
    {
        if(k==nums.size())
            ret.push_back(nums);
        for(int i=k;i<nums.size();i++)
        {
            swap(nums,k,i);
            core(nums,k+1,ret);
            swap(nums,k,i);
        }
    }
    void swap(vector<int> &nums,int a,int b)
    {
        int tmp=nums[a];
        nums[a]=nums[b];
        nums[b]=tmp;
    }
};