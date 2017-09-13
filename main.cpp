#include "iostream"
#include "vector"

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if(head== nullptr)
            return nullptr;
        ListNode *p=head;
        ListNode tmp,*even=&tmp;
        while(p!= nullptr&&p->next!= nullptr)
        {
            even->next=p->next;
            p->next=p->next->next;
            p=p->next;
            even=even->next;
            even->next= nullptr;
        }
        p=head;
        while(p->next!= nullptr)
            p=p->next;
        p->next=tmp.next;
        return head;
    }
};
