#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<pair<int,int>> &points)
    {
        sort(points.begin(),points.end(),[](pair<int,int> &a,pair<int,int> &b){return a.first<b.first;});
        vector<pair<int,int>> arrows;
        for(int i=0;i<points.size();i++)
        {
            if(arrows.empty())
            {
                arrows.push_back(points[i]);
            }
            else
            {
                if(points[i].first<=arrows.back().second)
                {
                    arrows.back().first=points[i].first;
                    if(arrows.back().second>points[i].second)
                        arrows.back().second=points[i].second;
                }
                else
                {
                    arrows.push_back(points[i]);
                }
            }
        }
        return arrows.size();
    }
};

int main()
{
    vector<pair<int,int>> points{{3,9},{7,12},{3,8},{7,12}};
    Solution s;
    cout<<s.findMinArrowShots(points)<<endl;
    return 0;
}