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
    TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        vector<TreeNode*>path,path1,path2;
        core(root,p,q,path,path1,path2);
        TreeNode* curr,*pre;
        for(int i=0;i<path1.size();i++)
        {
            if(path1[i]!=path2[i])
            {
                return pre;
            }
            if(i==path1.size()-1||i==path2.size()-1)
                return path1[i];
            pre=path1[i];
        }
        return root;
    }
private:
    void core(TreeNode* node,TreeNode* p,TreeNode* q,vector<TreeNode*>& path,vector<TreeNode*>& path1,vector<TreeNode*>& path2)
    {
        if(node==NULL)
            return;
        path.push_back(node);
        if(node->val==p->val||node->val==q->val)
        {
            if(find)
            {
                path2=path;
                findAll=true;
                return;
            }
            else
            {
                path1=path;
                find=true;
            }
        }
        if(!findAll)
            core(node->left,p,q,path,path1,path2);
        if(!findAll)
            core(node->right,p,q,path,path1,path2);
        path.pop_back();
    }
    bool find=false;
    bool findAll=false;
};

TreeNode* lowestCommonAncestor(TreeNode*root,TreeNode* p,TreeNode* q)
{
    if(root==NULL)
        return NULL;
    if(p->val>root->val&&q->val>root->val)
        return lowestCommonAncestor(root->right,p,q);
    if(p->val<root->val&&q->val<root->val)
        return lowestCommonAncestor(root->left,p,q);
    return root;
}