#include <vector>
#include "iostream"
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
    vector<int> largestValues(TreeNode* root)
    {
        if(root==NULL)
            return {};
        int currC=1,nextC=0;
        vector<int> ret;
        deque<TreeNode*> tree{root};
        int max=root->val;
        while(!tree.empty())
        {
            if(currC>0)
            {
                if(tree.front()->val>max)
                    max=tree.front()->val;
                if(tree.front()->left!=NULL)
                {
                    nextC++;
                    tree.push_back(tree.front()->left);
                }
                if(tree.front()->right!=NULL)
                {
                    nextC++;
                    tree.push_back(tree.front()->right);
                }
                currC--;
                if(currC==0)
                    ret.push_back(max);
                tree.pop_front();
            }
            else
            {
                max=INT32_MIN;
                currC=nextC;
                nextC=0;
            }
        }
        return ret;
    }
};