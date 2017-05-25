#include "iostream"
#include "vector"
#include "unordered_map"

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
    vector<int> inorderTraversal(TreeNode* root)
    {
        if(root==NULL)
            return {};
        vector<int> ret;
        vector<TreeNode*> tree{root};
        vector<pair<bool,bool>> help{{1,1}};
        while(!tree.empty())
        {
            while(help.back().first&&tree.back()->left!=NULL)
            {
                tree.push_back(tree.back()->left);
                help.back().first=0;
                help.push_back({1,1});
                continue;
            }
            help.back().first=0;
            if(help.back().second)
                ret.push_back(tree.back()->val);
            if(help.back().second&&tree.back()->right!=NULL)
            {
                tree.push_back(tree.back()->right);
                help.back().second=0;
                help.push_back({1,1});
                continue;
            }
            tree.pop_back();
            help.pop_back();
        }
        return ret;
    }
};