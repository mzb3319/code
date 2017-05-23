#include "iostream"
#include "random"

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

};

class Solution
{
public:
    Solution(ListNode* head)
    {
        int len=0;
        node=head;
        while(node!=NULL)
        {
            len++;
            node=node->next;
        }
        node=head;
        uniform_int_distribution<unsigned >::param_type param(0,len-1);
        u.param(param);
        e.seed(time(0));
    }
    int getRandom()
    {
        ListNode* h=node;
        int step=u(e);
        while(step)
        {
            h=h->next;
            step--;
        }
        return h->val;
    }
private:
    uniform_int_distribution<unsigned > u;
    default_random_engine e;
    ListNode* node;
};