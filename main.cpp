#include "iostream"
#include "vector"
#include "unordered_map"

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
    int rob(TreeNode *root)
    {
        unordered_map<TreeNode*,int> table;
        return core(root,table);
    }
private:
    int core(TreeNode *node,unordered_map<TreeNode*,int> &table)
    {
        if(node==NULL)
            return 0;
        auto f=table.find(node);
        if(f!=table.end())
            return f->second;
        //case1
        int ret1=node->val;
        auto left=node->left;
        auto right=node->right;
        if(left!=NULL)
        {
            ret1+=core(left->left,table)+core(left->right,table);
        }
        if(right!=NULL)
        {
            ret1+=core(right->left,table)+core(right->right,table);
        }
        //case2
        int ret2=0;
        ret2+=core(left,table)+core(right,table);

        if(ret1<ret2)
            ret1=ret2;
        table.insert({node,ret1});

        return ret1;
    }
};