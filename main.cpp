#include "vector"
#include "iostream"
#include "deque"

using namespace std;

struct TreeLinkNode
{
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int a):val(a),left(NULL),right(NULL),next(NULL){}
};

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if(numRows<1)
            return {};
        vector<vector<int>> ret{{1}};
        for(int i=1;i<numRows;++i)
        {
            int a=0,b=0;
            vector<int> curr;
            for(int j=0;j<=ret[i-1].size();++j)
            {
                a=b;
                if(j<ret[i-1].size())
                    b=ret[i-1][j];
                else
                    b=0;
                curr.push_back(a+b);
            }
            ret.push_back(curr);
        }
        return ret;
    }
};
