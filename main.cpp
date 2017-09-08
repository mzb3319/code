#include "iostream"
#include "vector"

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int a):val(a),next(nullptr){}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *p= nullptr;
        while(head)
        {
            ListNode *tmp=head->next;
            head->next=p;
            p=head;
            head=tmp;
        }
        return p;
    }
};