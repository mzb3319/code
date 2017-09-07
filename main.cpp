#include "iostream"

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
    ListNode *getIntersectionNode(ListNode *headA,ListNode *headB)
    {
        if(headA== nullptr||headB== nullptr)
            return nullptr;
        ListNode *h1=headA,*h2=headB;
        int count=2;
        while(count)
        {
            if(h1==h2)
                return h1;
            if(h1)
                h1=h1->next;
            else
            {
                h1=headB;
                --count;
            }
            if(h2)
                h2=h2->next;
            else
                h2=headA;
        }
        return nullptr;
    }
};
