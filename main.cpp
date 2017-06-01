#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        unordered_map<int,int> edges;
        for(int i=0;i<wall.size();i++)
        {
            int add=0;
            for(int j=0;j<wall[i].size()-1;j++)
            {
                add+=wall[i][j];
                edges[add]++;
            }
        }
        int max=INT32_MIN;
        for(auto edge:edges)
        {
            if(max<edge.second)
                max=edge.second;
        }
        return max==INT32_MIN?wall.size():wall.size()-max;
    }
};

int main()
{
    vector<vector<int>> wall{{9,1},{6,3,1},{2,4,1,3}};
    Solution s;

    s.leastBricks(wall);
    return 0;
}