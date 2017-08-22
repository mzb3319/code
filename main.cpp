#include "vector"
#include "iostream"

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int fast=0,slow=0;
        do{
            fast=nums[fast];
            fast=nums[fast];

            slow=nums[slow];
        }
        while(fast!=slow);
        fast=0;
        do{
            fast=nums[fast];
            slow=nums[slow];
        }
        while(fast!=slow);
        return slow;
    }
};

int main()
{
    vector<int> nums{1,3,4,2,2};
    Solution s;
    cout<<s.findDuplicate(nums);
    return 0;
}