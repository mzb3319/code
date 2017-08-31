#include "vector"
#include "iostream"
#include "deque"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int a):val(a),left(NULL),right(NULL){}
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder,vector<int> &inorder)
    {
        if(preorder.empty())
            return NULL;
        return core(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
private:
    TreeNode *core(vector<int> &preorder,int beg1,int end1,vector<int> &inorder,int beg2,int end2)
    {
        if(beg1>end1)
            return NULL;
        TreeNode *root=new TreeNode(preorder[beg1]);
        int count=0,index=beg2;
        while(inorder[index]!=preorder[beg1])
        {
            ++count;
            ++index;
        }
        root->left=core(preorder,beg1+1,beg1+count,inorder,beg2,index-1);
        root->right=core(preorder,beg1+count+1,end1,inorder,index+1,end2);
        return root;
    }
};
