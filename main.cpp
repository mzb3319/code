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
    bool isBalanced(TreeNode* root)
    {
        int depth=0;
        return core(root,depth);
    }
private:
    bool core(TreeNode* node,int &depth)
    {
        if(node==NULL)
        {
            depth=0;
            return true;
        }
        int leftD=0;
        if(!core(node->left,leftD))
            return false;
        int rightD=0;
        if(!core(node->right,rightD))
            return false;
        int diff=leftD-rightD;
        if(diff>1||diff<-1)
            return false;
        depth=(leftD>rightD?leftD:rightD)+1;
        return true;
    }
};