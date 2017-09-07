#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        if(tokens.empty())
            return -1;
        vector<int> stack;
        for(int i=0;i<tokens.size();++i)
        {
            if(tokens[i]=="+")
            {
                int a=stack.back();
                stack.pop_back();
                int b=stack.back();
                stack.pop_back();
                stack.push_back(a+b);
            }
            else if(tokens[i]=="-")
            {
                int a=stack.back();
                stack.pop_back();
                int b=stack.back();
                stack.pop_back();
                stack.push_back(b-a);
            }
            else if(tokens[i]=="*")
            {
                int a=stack.back();
                stack.pop_back();
                int b=stack.back();
                stack.pop_back();
                stack.push_back(a*b);
            }
            else if(tokens[i]=="/")
            {
                int a=stack.back();
                stack.pop_back();
                int b=stack.back();
                stack.pop_back();
                stack.push_back(b/a);
            }
            else
            {
                stack.push_back(stoi(tokens[i]));
            }
        }
        return stack.back();
    }
};
