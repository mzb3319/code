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
    vector<int> findFrequentTreeSum(TreeNode* root)
    {
        unordered_map<int,int> table;
        core(root,table);
        int max=INT32_MIN;
        for(auto t:table)
        {
            if(t.second>max)
                max=t.second;
        }
        vector<int> ret;
        for(auto t:table)
        {
            if(t.second==max)
                ret.push_back(t.first);
        }
        return ret;
    }
private:
    int core(TreeNode* node,unordered_map<int,int>& table)
    {
        if(node==NULL)
            return 0;
        int left=core(node->left,table);
        int right=core(node->right,table);
        int sum=node->val+left+right;
        table[sum]++;
        return sum;
    }
};