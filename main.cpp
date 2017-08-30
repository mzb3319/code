#include "vector"
#include "iostream"

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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<TreeNode*> table;
        vector<int> ret;
        while(root||!table.empty())
        {
            if(root)
            {
                table.push_back(root);
                root=root->left;
            }
            else
            {
                root=table.back();
                ret.push_back(root->val);
                root=root->right;
                table.pop_back();
            }
        }
        return ret;
    }
};
