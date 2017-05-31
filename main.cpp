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
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<TreeNode*> table{root};
        vector<int> ret;
        core(table,ret);
        return ret;
    }
private:
    void core(vector<TreeNode*>& table,vector<int>& ret)
    {
        while(!table.empty())
        {
            TreeNode* node=table.back();
            table.pop_back();
            if(node==NULL)
                continue;
            ret.push_back(node->val);
            table.push_back(node->right);
            table.push_back(node->left);
        }
    }
};
