#include "iostream"
#include "vector"

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
    int kthSmallest(TreeNode *root,int k)
    {
        vector<int> table;
        core(root,k,table);
        return table.back();
    }
private:
    void core(TreeNode *node,int k,vector<int> &table)
    {
        if(node->left!=NULL)
            core(node->left,k,table);
        table.push_back(node->val);
        if(node->right!=NULL)
            core(node->right,k,table);
    }
};