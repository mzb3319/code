#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums,int k)
    {
        int beg=0,end=nums.size()-1;
        while(beg<end)
            swap(nums,beg++,end--);
        beg=0;
        end=k-1;
        while(beg<end)
            swap(nums,beg++,end--);
        beg=k;
        end=nums.size()-1;
        while(beg<end)
            swap(nums,beg++,end--);
    }
private:
    void swap(vector<int> &nums,int a,int b)
    {
        int tmp=nums[a];
        nums[a]=nums[b];
        nums[b]=tmp;
    }
};