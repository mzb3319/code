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
    void deleteNode(ListNode *node)
    {
        if(node== nullptr)
            return;
        node->val=node->next->val;
        node->next=node->next->next;
        delete node->next;
    }
};
