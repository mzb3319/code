#include "deque"
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
    int findBottomLeftValue(TreeNode* root)
    {
        deque<TreeNode*> table;
        TreeNode* first=NULL;
        table.push_back(root);
        int count=1;
        while(!table.empty())
        {
            int c=0;
            first=table.front();
            for(;count>0;count--)
            {
                if(table.front()->left!=NULL)
                {
                    table.push_back(table.front()->left);
                    c++;
                }
                if(table.front()->right!=NULL)
                {
                    table.push_back(table.front()->right);
                    c++;
                }
                table.pop_front();
            }
            count=c;
        }
        return first->val;
    }
};