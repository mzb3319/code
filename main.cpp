#include "vector"
#include "iostream"
#include "deque"

using namespace std;

struct TreeLinkNode
{
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int a):val(a),left(NULL),right(NULL),next(NULL){}
};

class Solution
{
public:
    void connect(TreeLinkNode *root)
    {
        if(root==NULL)
            return;
        if(root->left!=NULL)
        {
            root->left->next=root->right;

            if(root->next!=NULL)
            {
                root->right->next=root->next->left;
            }
        }
        connect(root->left);
        connect(root->right);
    }
};
