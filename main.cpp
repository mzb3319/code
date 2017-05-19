#include "iostream"
#include "vector"
#include "algorithm"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums,int k)
    {
        unordered_map<int,int> table;
        for(int num:nums)
        {
            table[num]++;
        }
        vector<pair<int,int>> map(table.begin(),table.end());
        sort(map.begin(),map.end(),[](pair<int,int> &a,pair<int,int>& b){return a.second>b.second;});
        vector<int> ret;
        int i=0;
        for(auto itr:map)
        {
            if(i==k)
                break;
            i++;
            ret.push_back(itr.first);
        }
        return ret;
    }
};

int main()
{
    vector<int> nums{1,2,2,3,3,3};
    Solution s;
    s.topKFrequent(nums,2);
    return 0;
}