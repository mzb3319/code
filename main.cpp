#include "vector"
#include "iostream"

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
    bool isValidBST(TreeNode *root)
    {
        vector<TreeNode*> table;
        long long preVal=INT64_MIN;
        while(root||!table.empty())
        {
            if(root)
            {
                table.push_back(root);
                root=root->left;
            }
            else
            {
                root=table.back();
                long long tmp=root->val;
                if(tmp<=preVal)
                    return false;
                preVal=root->val;
                root=root->right;
                table.pop_back();
            }
        }
        return true;
    }
};
