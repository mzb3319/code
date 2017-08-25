#include "istream"
#include "vector"
#include "algorithm"

using namespace std;

struct Interval
{
    int start;
    int end;

};

class Solution
{
public:
    vector<Interval> merge(vector<Interval> &intervals)
    {
        if(intervals.size()<2)
            return intervals;
        sort(intervals.begin(),intervals.end(),[](const Interval &a,const Interval &b){return a.start<b.start;});
        vector<Interval> ret;
        Interval tmp=intervals.front();
        for(int i=1;i<intervals.size();++i)
        {
            if(intervals[i].start<=tmp.end)
                tmp.end=max(tmp.end,intervals[i].end);
            else
            {
                ret.push_back(tmp);
                tmp=intervals[i];
            }
        }
        ret.push_back(tmp);
        return ret;
    }
};
