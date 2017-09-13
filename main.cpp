#include "iostream"
#include "string"
#include "unordered_map"
#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums,int k)
    {
        unordered_map<int,int> table;
        for(int n:nums)
            ++table[n];
        vector<pair<int,int>> ret;
        for(auto &it:table)
            ret.push_back(it);
        sort(ret.begin(),ret.end(),[](const pair<int,int> &a,const pair<int,int> &b){return a.second>=b.second;});
        vector<int> r;
        for(int i=0;i<k;++i)
            r.push_back(ret[i].first);
        return r;
    }
};
