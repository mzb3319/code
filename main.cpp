#include "iostream"

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if(head== nullptr)
            return true;
        return core(head,&head);
    }
private:
    bool core(ListNode *curr,ListNode **head)
    {
        if(curr->next)
        {
            if(!core(curr->next,head))
                return false;
            *head=(*head)->next;
        }
        return curr->val==(*head)->val;
    }
};
