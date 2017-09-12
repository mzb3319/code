#include "iostream"
#include "vector"
#include "queue"

using namespace std;

class MedianFinder
{
public:
    MedianFinder()
    {

    }

    void addNum(int num)
    {
        if(!left.empty()&&num<=left.top())
            left.push(num);
        else if(!right.empty()&&num>=right.top())
            right.push(num);
        else
            left.push(num);
        while(left.size()<right.size())
        {
            int n=right.top();
            left.push(n);
            right.pop();
        }
        while(left.size()>right.size()+1)
        {
            int n=left.top();
            right.push(n);
            left.pop();
        }
    }

    double findMedian()
    {
        if(left.size()>right.size())
            return left.top();
        double a=left.top(),b=right.top();
        return (a+b)/2;
    }

private:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
};

int main()
{
    MedianFinder m;
    m.addNum(1);
    m.addNum(2);
    cout<<m.findMedian()<<endl;
    return 0;
}