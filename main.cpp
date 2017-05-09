#include "iostream"

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL)
    {}
};

class Solution
{
public:
    ListNode* removeElements(ListNode* head,int val)
    {
        ListNode p(0);
        p.next=head;
        ListNode *curr=head,*pre=&p;
        while(curr!=NULL)
        {
            if(curr->val==val)
            {
                pre->next=curr->next;
                delete curr;
            }
            else
            {
                pre=curr;
            }
            curr=pre->next;
        }
        return p.next;
    }
};
