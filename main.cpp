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
    int maxDepth(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
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
