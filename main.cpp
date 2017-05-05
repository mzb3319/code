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
     int minDepth(TreeNode* root)
     {
         if(root==NULL)
             return 0;
         if(root->left==NULL&&root->right==NULL)
             return 1;
         int leftD=INT32_MAX;
         int rightD=INT32_MAX;
         if(root->left!=NULL)
             leftD=minDepth(root->left);
         if(root->right!=NULL)
             rightD=minDepth(root->right);
         return leftD>rightD?rightD+1:leftD+1;
     }
};