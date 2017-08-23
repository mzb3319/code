#include "string"
#include "vector"
#include "unordered_map"
#include "algorithm"

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string,vector<string>> table;
        for(string &str:strs)
        {
            string tmp=str;
            sort(tmp.begin(),tmp.end());
            table[tmp].push_back(str);
        }
        vector<vector<string>> ret;
        for(const auto &it:table)
            ret.push_back(it.second);
        return ret;
    }
};