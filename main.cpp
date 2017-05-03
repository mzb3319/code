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
    int pathSum(TreeNode* root,int sum)
    {
        vector<int> path;
        int ret=0;
        core(root,path,ret,sum);
        return ret;
    }
private:
    void core(TreeNode* node,vector<int>& path,int &ret,int k)
    {
        if(node==NULL)
            return;
        path.push_back(node->val);
        ret+=findSum(path,k);
        core(node->left,path,ret,k);
        core(node->right,path,ret,k);
        path.pop_back();
    }
    int findSum(vector<int>& path,int k)
    {
        int sum=0;
        int ret=0;
        for(int i=path.size()-1;i>=0;i--)
        {
            sum+=path[i];
            if(sum==k)
                ret++;
        }
        return ret;
    }
};