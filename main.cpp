#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i=nums.size()-2;
        for(;i>=0;--i)
        {
            if(nums[i]<nums[i+1])
            {
                int j=nums.size()-1;
                while(nums[j]<nums[i])
                    --j;
                swap(nums,i,j);
                break;
            }

        }
        reverse(nums.begin()+i+1,nums.end());
    }
private:
    void swap(vector<int> &nums,int a,int b)
    {
        int tmp=nums[a];
        nums[a]=nums[b];
        nums[b]=tmp;
    }
};
