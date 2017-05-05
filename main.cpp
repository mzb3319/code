#include "iostream"
#include "vector"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution
{
public:
    bool hasPathSum(TreeNode* root,int sum)
    {
        if(root==NULL)
        {
            return false;
        }
        if(root->left==NULL&&root->right==NULL&&sum==root->val)
            return true;
        else
        {
            if(hasPathSum(root->left,sum-root->val))
                return true;
            if(hasPathSum(root->right,sum-root->val))
                return true;
        }
        return false;
    }
};