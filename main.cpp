#include "vector"
#include "iostream"
#include "string"

using namespace std;

class Solution
{
public:
    string optimalDivision(vector<int>& nums)
    {
        if(nums.empty())
            return "";
        string ret=to_string(nums.front());
        if(nums.size()>2)
            ret+="/(";
        else
            ret+="/";
        for(int i=1;i<nums.size();i++)
        {
            ret+=to_string(nums[i])+"/";
        }
        ret.pop_back();
        if(nums.size()>2)
            ret+=")";
        return ret;
    }
};