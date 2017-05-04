#include "iostream"
#include "string"
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
    vector<string> binaryTreePaths(TreeNode * root)
    {
        if(root==NULL)
            return {};
        string path;
        vector<string> ret;
        core(root,path,ret);
        return ret;
    }
private:
    void core(TreeNode* node,string & path,vector<string>& ret)
    {
        if(node!=NULL)
            path+="->"+to_string(node->val);
        if(node->left==NULL&&node->right==NULL)
            ret.push_back(string(path.begin()+2,path.end()));
        if(node->left!=NULL)
            core(node->left,path,ret);
        if(node->right!=NULL)
            core(node->right,path,ret);
        path.erase(path.find_last_of("->"));
    }
};