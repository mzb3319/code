#include "iostream"
#include "vector"
#include "deque"

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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        if(root==NULL)
            return {};
        deque<vector<int>> ret;
        deque<TreeNode*> tree;
        tree.push_back(root);
        int countCurr=1,countNext=0;
        vector<int> tmp;
        while(tree.size()!=0)
        {
            tmp.push_back(tree.front()->val);
            countCurr--;
            if(tree.front()->left!=NULL)
            {
                tree.push_back(tree.front()->left);
                countNext++;
            }
            if(tree.front()->right!=NULL)
            {
                tree.push_back(tree.front()->right);
                countNext++;
            }
            tree.pop_front();
            if(countCurr==0)
            {
                ret.push_front(tmp);
                tmp.clear();
                countCurr=countNext;
                countNext=0;
            }
        }
        return vector<vector<int>>(ret.begin(),ret.end());
    }
};