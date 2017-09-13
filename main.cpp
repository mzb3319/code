#include "iostream"
#include "string"
#include "unordered_map"
#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1,vector<int> &nums2)
    {
        unordered_map<int,int> table;
        for(int n:nums1)
            ++table[n];
        vector<int> ret;
        for(int i=0;i<nums2.size();++i)
        {
            if(table.find(nums2[i])!=table.end()&&table[nums2[i]]>0)
            {
                ret.push_back(nums2[i]);
                --table[nums2[i]];
            }
        }
        return ret;
    }
};
