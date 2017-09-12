#include "iostream"
#include "vector"
#include "deque"

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums,int k)
    {
        vector<int> ret;
        deque<int> window;
        for(int i=0;i<nums.size();++i)
        {
            while(!window.empty()&&(nums[i]>nums[window.front()]||i-window.front()>=k))
                window.pop_front();
            while(!window.empty()&&(nums[i]>nums[window.back()]))
                window.pop_back();
            window.push_back(i);
            if(i>=k-1)
                ret.push_back(nums[window.front()]);
        }
        return ret;
    }
};
