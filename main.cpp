#include "iostream"

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
    TreeNode* convertBST(TreeNode* root)
    {
        core(root,0);
        return root;
    }
private:
    int core(TreeNode* node,int carry)
    {
        if(node==NULL)
            return carry;
        node->val+=core(node->right,carry);
        int left=core(node->left,node->val);
        return left;
    }
};
