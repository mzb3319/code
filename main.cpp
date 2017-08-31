#include "vector"
#include "iostream"
#include "deque"

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        if(root==NULL)
            return ret;
        vector<deque<TreeNode*>> table(2);
        bool direction=true;//true->left2right,false->right2left
        table[1].push_back(root);
        vector<int> currLevel;
        while(!table[direction].empty())
        {
            TreeNode *tmp=table[direction].front();
            table[direction].pop_front();
            currLevel.push_back(tmp->val);
            if(direction)
            {
                if(tmp->left!=NULL)
                    table[!direction].push_front(tmp->left);
                if(tmp->right!=NULL)
                    table[!direction].push_front(tmp->right);
            }
            else
            {
                if(tmp->right!=NULL)
                    table[!direction].push_front(tmp->right);
                if(tmp->left!=NULL)
                    table[!direction].push_front(tmp->left);
            }
            if(table[direction].empty())
            {
                ret.push_back(currLevel);
                currLevel.clear();
                table[direction].clear();
                direction=!direction;
            }
        }
        return ret;
    }
};

int main()
{
    TreeNode test;
    test.val=1;
    test.left=NULL;
    test.right=NULL;
    Solution s;
    s.levelOrder(&test);
    return 0;
}
