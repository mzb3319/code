#include "iostream"
#include "set"
#include "vector"

using namespace std;

class Solution
{
public:
    int thirdMax(vector<int>& nums)
    {
        set<int> table;
        for(int num:nums)
        {
            table.insert(num);
            if(table.size()>3)
                table.erase(table.begin());
        }
        return table.size()==3?*table.begin():*(--table.end());
    }
};

int main()
{
    vector<int> nums{3,2,1};
    Solution s;
    s.thirdMax(nums);
    return 0;
}