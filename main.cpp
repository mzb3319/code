#include "iostream"
#include "vector"
#include "string"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x):val(x),left(nullptr),right(nullptr){}
};

class Codec
{
public:
    string serialize(TreeNode *root)
    {
        string str;
        code(root,str);
        return str;
    }

    TreeNode *deserialize(string data)
    {
        int index=0;
        TreeNode *head=decode(data,index);
        return head;
    }
private:
    void code(TreeNode *node,string &str)
    {
        if(node== nullptr)
        {
            if(!str.empty())
                str+=",";
            str+="#";
            return;
        }
        if(!str.empty())
            str+=",";
        str+=to_string(node->val);
        code(node->left,str);
        code(node->right,str);
    }
    TreeNode *decode(string &str,int &index)
    {
        if(index==str.length())
            return nullptr;
        if(str[index]==',')
            ++index;
        if(str[index]=='#')
        {
            ++index;
            return nullptr;
        }
        int i=index;
        while(str[index]!=',')
            ++index;

        int n=stoi(str.substr(i,index-i));
        TreeNode *node=new TreeNode(n);
        node->left=decode(str,index);
        node->right=decode(str,index);
        return node;
    }
};

int main()
{
    Codec m;
    string data="1,2,#,#,3,#,#";
    m.deserialize(data);
    return 0;
}