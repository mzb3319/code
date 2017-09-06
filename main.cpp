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
    bool hasCycle(ListNode *head)
    {
        if(head== nullptr)
            return false;
        ListNode *fast=head;
        while(head!= nullptr)
        {
            head=head->next;
            if(fast->next== nullptr)
                return false;
            fast=fast->next;
            if(fast->next== nullptr)
                return false;
            fast=fast->next;
            if(fast==head)
                return true;
        }
        return false;
    }
};
