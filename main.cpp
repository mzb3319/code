#include "iostream"
#include "vector"
#include "unordered_map"
#include "list"

using namespace std;

struct List
{
    int val;
    int key;
    List *next;
    List *pre;
    List(int k,int v):key(k),val(v),next(nullptr),pre(nullptr){}
};

//class LRUCache
//{
//public:
//    LRUCache(int capacity):cap(capacity){}
//    int get(int key)
//    {
//        auto f=table.find(key);
//        if(f==table.end())
//            return -1;
//        if(table.size()<2)
//            return f->second->val;
//        if(f->second->next== nullptr)
//            return f->second->val;
//        if(f->second->pre== nullptr)
//        {
//            tail->next=f->second;
//            f->second->pre=tail;
//            tail=f->second;
//
//            head=f->second->next;
//            f->second->next= nullptr;
//        }
//        else
//        {
//            f->second->pre->next=f->second->next;
//            f->second->next->pre=f->second->pre;
//            tail->next=f->second;
//            f->second->pre=tail;
//            f->second->next= nullptr;
//            tail=f->second;
//        }
//        return f->second->val;
//    }
//    void put(int key,int value)
//    {
//        auto f=table.find(key);
//        if(f!=table.end())
//        {
//            f->second->val=value;
//            get(key);
//        }
//        if(table.empty())
//        {
//            head=tail=new List(key,value);
//            table.insert({key,head});
//        }
//        else if(table.size()<cap)
//        {
//            tail->next=new List(key,value);
//            table.insert({key,tail->next});
//            tail->next->pre=tail;
//            tail=tail->next;
//        }
//        else
//        {
//            if(cap==1)
//            {
//                table.erase(head->key);
//                head->key=key;
//                head->val=value;
//                table.insert({key,head});
//            }
//            else
//            {
//                List *tmp=head;
//                table.erase(head->key);
//                head=head->next;
//                delete tmp;
//                tmp=new List(key,value);
//                table.insert({key,tmp});
//                tail->next=tmp;
//                tmp->pre=tail;
//                tail=tmp;
//            }
//        }
//    }
//private:
//    int cap;
//    List *head,*tail;
//    unordered_map<int,List*> table;
//};

class LRUCache
{
public:
    LRUCache(int cap):_cap(cap){}
    int get(int key)
    {
        auto f=table.find(key);
        if(f==table.end())
            return -1;
        order.erase(f->second.second);
        order.push_back(key);
        f->second.second=--order.end();
        return f->second.first;
    }
    void put(int key,int value)
    {
        auto f=table.find(key);
        if(f!=table.end())
        {
            f->second.first=value;
            get(key);
            return;
        }
        if(table.size()==_cap)
        {
            table.erase(order.front());
            order.pop_front();
        }
        order.push_back(key);
        table.insert({key,{value,--order.end()}});
    }
private:
    int _cap;
    list<int> order;
    unordered_map<int,pair<int,list<int>::iterator>> table;
};

int main()
{
    LRUCache lru(2);
    lru.put(2,3);
    lru.put(1,4);
    lru.get(2);
    return 0;
}
