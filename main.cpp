#include "vector"
#include "iostream"
#include "unordered_map"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode(int a):val(a),left(NULL),right(NULL),next(NULL){}
};

class Solution
{
public:
    bool isPalindrome(string &s)
    {
        int beg=0,end=s.length()-1;
        while(beg<end)
        {
            if(!isalnum(s[beg]))
            {
                ++beg;
                continue;
            }
            if(!isalnum(s[end]))
            {
                --end;
                continue;
            }
            if(tolower(s[beg])!=tolower(s[end]))
                return false;
            ++beg;
            --end;
        }
        return true;
    }
};
