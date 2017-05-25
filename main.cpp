#include "iostream"
#include "string"
#include "vector"
#include "algorithm"

using namespace std;

class Solution
{
public:
    int findMinDifference(vector<string>& timePoints)
    {
        sort(timePoints.begin(),timePoints.end());
        int diff=INT32_MAX;
        for(int i=1;i<timePoints.size();i++)
        {
            if(timePoints[i]==timePoints[i-1])
                return 0;
            int h1=stoi(timePoints[i]);
            int h2=stoi(timePoints[i-1]);
            int m1=stoi(timePoints[i].substr(3,2));
            int m2=stoi(timePoints[i-1].substr(3,2));
            int d=(h1-h2)*60+m1-m2;
            if(d<diff)
                diff=d;
        }
        int d=(23-stoi(timePoints.back()))*60+60-stoi(timePoints.back().substr(3,2))+stoi(timePoints.front())*60+stoi(timePoints.front().substr(3,2));
        if(d<diff)
            diff=d;
        return diff;
    }
};

int main()
{
    Solution s;
    vector<string> time{"12:12","00:13"};
    s.findMinDifference(time);
    return 0;
}