#include "iostream"
#include "vector"

using namespace std;
class Solution
{
public:
    int search(vector<int> &nums,int target)
    {
        if(nums.empty())
            return -1;
        int beg=0,end=nums.size()-1;
        while(beg<=end)
        {
            int mid=(beg+end)/2;
            if(target==nums[mid])
                return mid;
            if(nums[mid]>=nums[0])//left
            {
                if(target<nums[mid]&&target>=nums[beg])
                    end=mid-1;
                else
                    beg=mid+1;
            }
            else if(nums[mid]<nums[0])//right
            {
                if(target>nums[mid]&&target<=nums[end])
                    beg=mid+1;
                else
                    end=mid-1;
            }
        }
        return -1;
    }
};
