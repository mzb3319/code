#include "iostream"
#include "map"
#include "vector"
#include "unordered_set"

using namespace std;

struct Point
{
    int x;
    int y;
    Point():x(0),y(0){}
    Point(int a,int b):x(a),y(b){}
};

class Solution
{
public:
    int maxPoints(vector<Point> &points)
    {
        int ret=0;
        for(int i=0;i<points.size();++i)
        {
            map<pair<int,int>,int> line;//这里很重要,必须在这里统计数量
            int overlap=0,currMax=0,vertical=0;
            //以第i个点为起点计算和之后个点组成的直线的斜率
            for(int j=i+1;j<points.size();++j)
            {
                //和起点相同的点,在最后一起加到总节点数上
                if(points[i].x==points[j].x&&points[i].y==points[j].y)
                {
                    ++overlap;
                }
                else if(points[i].x==points[j].x)// x=b;竖线单独计算
                {
                    ++vertical;
                }
                else//正常的直线,因为起点都一样,所以只用斜率就能单独表示一条直线
                {
                    int a=points[i].x-points[j].x;
                    int b=points[i].y-points[j].y;
                    int c=help(a,b);//求最大公约数,用分数表示斜率
                    a/=c;
                    b/=c;
                    ++line[make_pair(a,b)];//斜率为b/a的直线上的点加1
                    currMax=max(currMax,line[make_pair(a,b)]);//line中最多点的直线
                }
                currMax=max(currMax,vertical);//考虑竖线
            }
            ret=max(ret,currMax+overlap+1);//+voerlap包含和点相同的点,+1包含起点本身
        }
        return ret;
    }
private:
    int help(int a,int b)
    {
        if(b==0)
            return a;
        int c=a%b;
        while(c)
        {
            a=b;
            b=c;
            c=a%b;
        }
        return b;
    }
};
