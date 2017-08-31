#include "vector"
#include "iostream"
#include "unordered_map"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode(int a):val(a),left(NULL),right(NULL),next(NULL){}
};

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int ret=INT32_MIN;
        core(root,ret);
        return ret;
    }
private:
    int core(TreeNode *node,int &ret)
    {
        if(node==NULL)
            return 0;
        int left=core(node->left,ret);
        int right=core(node->right,ret);
        int tmp=node->val;
        if(left>0)
            tmp+=left;
        if(right>0)
            tmp+=right;
        ret=max(tmp,ret);
        tmp=max(left,right);
        return tmp>0?tmp+node->val:node->val;
    }
};
