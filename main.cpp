#include "iostream"

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
};

class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        if(head==NULL)
            return true;
        int len=0;
        bool step=false;
        ListNode* h=head;
        while(h!=NULL)
        {
            len++;
            h=h->next;
        }
        if(len%2)
            step=true;
        len/=2;
        if(len>=2)
        {
            ListNode*h_old=head,*pre=NULL,*curr=head,*nex=head->next;
            int count=1;
            while(count<len)
            {
                curr->next=pre;
                pre=curr;
                curr=nex;
                nex=nex->next;
                count++;
            }
            curr->next=pre;
            head=curr;
            h_old->next=nex;
        }
        h=head;
        while(len)
        {
            h=h->next;
            len--;
        }
        if(step)
            h=h->next;
        while(h!=NULL)
        {
            if(head->val!=h->val)
                return false;
            h=h->next;
            head=head->next;
        }
        return true;
    }
};

int main()
{
    ListNode *head,a,b,c,d,e;
    a.val=1;b.val=2;c.val=3;d.val=2;e.val=1;
    a.next=&b;b.next=&c;c.next=&d;d.next=&e;e.next=NULL;
    head=&a;
    Solution s;
    s.isPalindrome(head);
    return 0;
}
