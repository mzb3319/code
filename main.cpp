#include "vector"
#include "iostream"
#include "deque"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int a):val(a),left(NULL),right(NULL){}
};

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if(nums.empty())
            return NULL;
        return core(nums,0,nums.size()-1);
    }
private:
    TreeNode *core(vector<int> nums,int beg,int end)
    {
        if(beg>end)
            return NULL;
        int mid=beg+end;
        mid=mid/2+mid%2;
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=core(nums,beg,mid-1);
        root->right=core(nums,mid+1,end);
        return root;
    }
};
