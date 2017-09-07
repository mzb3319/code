#include "iostream"
#include "string"
#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(),nums.end(),[](const int &a,const int &b){string sa=to_string(a),sb=to_string(b);return sa+sb>sb+sa?true:false;});
        string ret;
        for(int n:nums)
        {
            ret+=to_string(n);
        }
        if(ret.front()=='0')
            return "0";
        return ret;
    }
};