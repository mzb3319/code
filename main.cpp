#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    vector<pair<int,int>> reconstructQueue(vector<pair<int,int>>& people)
    {
        vector<pair<int,int>> ret(people.size(),{INT32_MAX,INT32_MAX});
        sort(people.begin(),people.end(),[](pair<int,int>& a,pair<int,int>& b){return a.first<b.first;});
        for(auto& p:people)
        {
            int i=0;
            int c=p.second;
            while(c!=0)
            {
                if(ret[i].first>=p.first)
                    c--;
                i++;
            }
            while(ret[i].first!=INT32_MAX)
                i++;
            ret[i].first=p.first;
            ret[i].second=p.second;
        }
        return ret;
    }
};

int main()
{
    vector<pair<int,int>> peo{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    Solution s;
    s.reconstructQueue(peo);
    return 0;
}