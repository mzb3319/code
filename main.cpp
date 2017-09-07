#include "vector"
#include "iostream"

using namespace std;

class MinStack
{
public:
    MinStack()
    {

    }
    void push(int x)
    {
        stack.push_back(x);
        if(minStack.empty()||minStack.back()>x)
            minStack.push_back(x);
        else
        {
            int tmp=minStack.back();
            minStack.push_back(tmp);
        }
    }
    void pop()
    {
        if(stack.empty())
            throw(runtime_error("empty stack"));
        stack.pop_back();
        minStack.pop_back();
    }
    int top()
    {
        if(stack.empty())
            throw(runtime_error("empty stack"));
        return stack.back();
    }
    int getMin()
    {
        if(minStack.empty())
            throw(runtime_error("empty stack"));
        return minStack.back();
    }
private:
    vector<int> stack;
    vector<int> minStack;
};
int main()
{
    MinStack stack;
    try{
        stack.pop();
    }catch(runtime_error(err))
    {
        cout<<err.what()<<endl;
    }
    return 0;
}
