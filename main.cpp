#include "iostream"
#include "vector"
#include "unordered_set"
#include "unordered_map"
#include "algorithm"

using namespace std;

class Solution
{
public:
    //和之前版本的区别在于递归时不是传递引用,并且交换后不换回
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> table;
        sort(nums.begin(),nums.end());
        core(nums,0,table);
        return table;
    }
    vector<vector<int>> permuteUnique1(vector<int> &nums)
    {
        unordered_map<int,int> table;
        for(int n:nums)
            ++table[n];
        vector<int> tmp;
        vector<vector<int>> ret;
        core(table,tmp,nums.size(),ret);
        return ret;
    }
private:
    void core(unordered_map<int,int> &table,vector<int> &tmp,int len,vector<vector<int>> &ret)
    {
        if(len==tmp.size())
        {
            ret.push_back(tmp);
            return;
        }
        for(auto &it:table)
        {
            if(it.second>0)
            {
                --it.second;
                tmp.push_back(it.first);
                core(table,tmp,len+1,ret);
                tmp.pop_back();
                ++it.second;
            }
        }
    }
    //这里传递的不是引用
    void core(vector<int> nums,int index,vector<vector<int>> &table)
    {
        if(index==nums.size())
        {
            table.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();++i)
        {
            if((i!=index)&&nums[i]==nums[index])
                continue;
            swap(nums,index,i);
            core(nums,index+1,table);
//            swap(nums,index,i);
        }
    }
    void swap(vector<int> &nums,int a,int b)
    {
        int tmp=nums[a];
        nums[a]=nums[b];
        nums[b]=tmp;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1,1,2};
    s.permuteUnique(nums);
    return 0;
}
