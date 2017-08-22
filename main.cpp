#include "vector"
#include "iostream"

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums,int target)
    {
        int p=bs(nums,target,0,nums.size()-1);
        if(p==-1)
            return {-1,-1};
        int l=left(nums,target,0,p);
        int r=right(nums,target,p,nums.size()-1);
        return {l,r};
    }
private:
    int left(vector<int> &nums,int target,int beg,int end)
    {
        if(beg==end)
            return beg;
        if(end==0||nums[end]!=nums[end-1])
            return end;
        --end;
        int l=bs(nums,target,beg,end);
        return left(nums,target,beg,l);
    }
    int right(vector<int> &nums,int target,int beg,int end)
    {
        if(beg==end)
            return beg;
        if(beg==nums.size()-1||nums[beg]!=nums[beg+1])
            return beg;
        ++beg;
        int r=bs(nums,target,beg,end);
        return right(nums,target,r,end);
    }

    int bs(vector<int> &nums,int target,int beg,int end)
    {
        while(beg<=end)
        {
            int mid=(beg+end)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                end=mid-1;
            else
                beg=mid+1;
        }
        return -1;
    }
};