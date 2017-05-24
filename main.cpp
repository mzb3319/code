#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    vector<int> killProcess(vector<int>& pid,vector<int>& ppid,int kill)
    {
        unordered_map<int,vector<int>> table;
        for(int i=0;i<pid.size();i++)
        {
            table[ppid[i]].push_back(pid[i]);
        }
        vector<int> ret{kill};
        core(table,kill,ret);
        return ret;
    }
private:
    void core(unordered_map<int,vector<int>>& table,int kill,vector<int>& ret)
    {
        auto kl=table[kill];
        for(int i=0;i<kl.size();i++)
        {
            ret.push_back(kl[i]);
            core(table,kl[i],ret);
        }
    }
};

int main()
{
    vector<int> pid{1,3,10,5};
    vector<int> ppid{3,0,5,3};
    Solution s;
    s.killProcess(pid,ppid,5);
    return 0;
}