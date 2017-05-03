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
    vector<int> findMode(TreeNode * root)
    {
        unordered_map<int,int> ret;
        core(root,ret);
        vector<int> r;
        int maxCount=0;
        for(auto itr:ret)
        {
            if(itr.second>maxCount)
                maxCount=itr.second;
        }
        for(auto itr:ret)
        {
            if(itr.second==maxCount)
                r.push_back(itr.first);
        }
        return r;
    }
private:
    void core(TreeNode* node,unordered_map<int,int> &ret)
    {
        if(node==NULL)
            return;
        ret[node->val]++;
        core(node->left,ret);
        core(node->right,ret);
    }
};
