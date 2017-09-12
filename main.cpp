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
    TreeNode* lowestCommonAncestor(TreeNode *root,TreeNode *p,TreeNode *q)
    {
        if(root== nullptr)
            return nullptr;
        vector<vector<TreeNode*>> ret;
        vector<TreeNode *> path;

        core(root,path,ret,p,q);

        if(ret.size()<2)
            return nullptr;
        int i=0;
        while(i<ret[0].size()&&i<ret[1].size()&&ret[0][i]==ret[1][i])
            ++i;
        return ret[0][i-1];
    }
private:
    void core(TreeNode *node,vector<TreeNode*> &path,vector<vector<TreeNode*>> &ret,TreeNode *p,TreeNode *q)
    {
        if(ret.size()==2)
            return;
        if(node== nullptr)
            return;
        path.push_back(node);
        if(node==p||node==q)
            ret.push_back(path);
        core(node->left,path,ret,p,q);
        core(node->right,path,ret,p,q);
        path.pop_back();
    }
};
