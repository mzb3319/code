#include "vector"
#include "iostream"
#include "deque"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        if(root==NULL)
            return ret;
        deque<TreeNode*> table{root};
        int currCount=1,nextCount=0;
        vector<int> currLevel;
        while(!table.empty())
        {
            TreeNode *tmp=table.front();
            table.pop_front();
            currLevel.push_back(tmp->val);
            --currCount;
            if(tmp->left!=NULL)
            {
                table.push_back(tmp->left);
                ++nextCount;
            }
            if(tmp->right!=NULL)
            {
                table.push_back(tmp->right);
                ++nextCount;
            }
            if(currCount==0)
            {
                ret.push_back(currLevel);
                currLevel.clear();
                currCount=nextCount;
                nextCount=0;
            }
        }
        return ret;
    }
};

int main()
{
    TreeNode test;
    test.val=1;
    test.left=NULL;
    test.right=NULL;
    Solution s;
    s.levelOrder(&test);
    return 0;
}
