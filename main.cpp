#include "iostream"
#include "string"
#include "vector"
#include "string"
#include "deque"

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int a):val(a),left(NULL),right(NULL)
    {};
};

class Codec
{
public:
    string serialize(TreeNode *root)
    {
        string ret;
        f(ret,root);
        return ret;
    }

    TreeNode *deserialize(string data)
    {
        int index=0;
        TreeNode * ret=d(data,index);
        return ret;
    }
private:
    void f(string &str,TreeNode *node)
    {
        if(!node)
        {
            str+="null|";
            return;
        }
        str+=to_string(node->val)+'|';

        f(str,node->left);
        f(str,node->right);
    }
    TreeNode *d(string &str,int &index)
    {
        string next=nextNum(str,index);
        if(next=="null")
        {
            return NULL;
        }
        TreeNode *node=new TreeNode(stoi(next));
        if(index<str.size())
            node->left=d(str,index);
        if(index<str.size())
            node->right=d(str,index);
        return node;
    }
    string nextNum(string &str,int &index)
    {
        string ret;
        int i=str.find_first_of('|',index);
        if(i==str.size()-1)
            return "null";
        ret=str.substr(index,i-index);
        index=i+1;
        return ret;
    }
};

int main()
{
    string str("2|1|null|null|3|null|null|");
    Codec code;
    auto r=code.deserialize(str);
    code.serialize(r);
    return 0;
}