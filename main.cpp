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
    bool isSymmetric(TreeNode *root)
    {
        if(root==NULL)
            return true;
        if(root->left==NULL&&root->right==NULL)
            return true;
        if(root->left==NULL||root->right==NULL)
            return false;
        if(root->left->val!=root->right->val)
            return false;
        return core(root->left->left,root->right->right)&&core(root->left->right,root->right->left);
    }
private:
    bool core(TreeNode *node1,TreeNode *node2)
    {
        if(node1==NULL&&node2==NULL)
            return true;
        if(node1==NULL||node2==NULL)
            return false;
        if(node1->val!=node2->val)
            return false;
        return core(node1->left,node2->right)&&core(node1->right,node2->left);
    }
};
