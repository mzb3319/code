#include "vector"
#include "iostream"

using namespace std;

class MinStack
{
public:
    MinStack()
    {}

    void push(int x)
    {
        stack.push_back(x);
        if(min.size()>0)
        {
            x>min.back()?min.push_back(min[min.size()-1]):min.push_back(x);
        }
        else
            min.push_back(x);
    }

    void pop()
    {
        if(stack.size()>0)
        {
            stack.pop_back();
            min.pop_back();
        }
    }

    int top()
    {
        int ret=0;
        if(stack.size()>0)
            ret=stack.back();
        return ret;
    }

    int getMin()
    {
        int ret=0;
        if(min.size()>0)
            ret=min.back();
        return ret;
    }
private:
    vector<int> stack;
    vector<int> min;
};