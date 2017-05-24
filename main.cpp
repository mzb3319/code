#include "iostream"
#include "vector"

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int a):val(a),next(NULL)
    {}
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2)
    {
        vector<int> num1,num2;
        ListNode* node=l1;
        while(node!=NULL)
        {
            num1.push_back(node->val);
            node=node->next;
        }
        node=l2;
        while(node!=NULL)
        {
            num2.push_back(node->val);
            node=node->next;
        }
        int carry=0;
        ListNode* ret=NULL;
        for(int i=num1.size()-1,j=num2.size()-1;i>=0||j>=0;i--,j--)
        {
            int add=carry;
            if(i>=0)
                add+=num1[i];
            if(j>=0)
                add+=num2[j];
            carry=add/10;
            ListNode* n=new ListNode(add%10);
            n->next=ret;
            ret=n;
        }
        if(carry)
        {
            ListNode* n=new ListNode(carry);
            n->next=ret;
            ret=n;
        }
        return ret;
    }
};