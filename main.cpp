#include "iostream"
#include "vector"
#include "map"
#include "queue"

using namespace std;

class Solution
{
public:
    vector<pair<int,int>> getSkyline(vector<vector<int>> &buildings)
    {
        if(buildings.empty())
            return {};
        multimap<int,pair<int,int>> table;
        for(auto &it:buildings)
            table.insert({it[0],{it[1],it[2]}});
        int x=0,y=buildings.back()[1],h=0;
        vector<pair<int,int>> ret;
        while(!table.empty())
        {
            int a=table.begin()->first,b=table.begin()->second.first,c=table.begin()->second.second;
            table.erase(table.begin());
            if(a<y)
            {
                if(c>h)
                {
                    if(!ret.empty()&&ret.back().first==a)
                        ret.back().second=max(ret.back().second,c);
                    else
                        ret.push_back({a,c});
                    if(b<y)
                        table.insert({b,{y,h}});
                    x=a;y=b;h=c;
                }
                else if(c<h)
                {
                    if(b>y)
                        table.insert({y,{b,c}});
                    x=a;
                }
                else
                {
                    x=a;
                    y=max(y,b);
                }
            }
            else if(a==y)
            {
                if(c!=h)
                {
                    if(!ret.empty()&&ret.back().first==a)
                        ret.back().second=max(ret.back().second,a);
                    else
                        ret.push_back({a,c});
                }
                x=a,y=b;h=c;
            }
            else
            {
                if(!ret.empty())
                    ret.back().second=max(ret.back().second,a);
                else
                    ret.push_back({a,0});
                x=a;y=b;h=c;
            }
        }
        ret.push_back({y,0});
        return ret;
    }
};

int main()
{
    vector<vector<int>> buildings{{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    Solution s;
    s.getSkyline(buildings);

    return 0;
}