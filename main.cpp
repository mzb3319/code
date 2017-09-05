#include "iostream"
#include "vector"

using namespace std;

struct RandomListNode
{
    int label;
    RandomListNode *next,*random;
    RandomListNode(int x):label(x),next(nullptr),random(nullptr){}
};

class Solution
{
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        if(head==nullptr)
            return nullptr;
        RandomListNode *node=head;
        while(node)
        {
            RandomListNode *tmp=new RandomListNode(node->label);
            tmp->next=node->next;
            node->next=tmp;
            node=tmp->next;
        }
        node=head;
        while(node)
        {
            if(node->random)
                node->next->random=node->random->next;
            node=node->next->next;
        }
        RandomListNode h(1),* node1=&h;
        node=head;
        while(node)
        {
            node1->next=node->next;
            node1=node1->next;
            node->next=node1->next;
            node=node->next;
        }
        return h.next;
    }
};

int main()
{
    RandomListNode head(-1),*ret;
    Solution s;
    ret=s.copyRandomList(&head);
    return 0;
}
