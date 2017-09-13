#include "iostream"
#include "vector"
#include "deque"

using namespace std;

  // This is the interface that allows for creating nested lists.
  // You should not implement it, or speculate about its implementation
  class NestedInteger {
    public:
     // Return true if this NestedInteger holds a single integer, rather than a nested list.
      bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

      // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single integer
      const vector<NestedInteger> &getList() const;
  };
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList):index(0){
        core(nestedList);
    }

    int next() {
        return table[index++];
    }

    bool hasNext() {
        return index<table.size();
    }
private:
    vector<int> table;
    int index;
    void core(const vector<NestedInteger> &list)
    {
        for(int i=0;i<list.size();++i)
        {
            if(list[i].isInteger())
                table.push_back(list[i].getInteger());
            else
            {
                core(list[i].getList());
            }
        }
    }
};

class NestedIterator1 {
public:
    NestedIterator1(vector<NestedInteger> &nestedList):list(nestedList.begin(),nestedList.end()){

    }

    int next() {
        int tmp=list.front().getInteger();
        list.pop_front();
        return tmp;
    }

    bool hasNext() {
        while(!list.empty()&&!(list.front().isInteger()))
        {
            auto tmp=list.front().getList();
            list.pop_front();
            for(int i=tmp.size()-1;i>=0;--i)
            {
                list.push_front(tmp[i]);
            }
        }
        return list.empty()?false:true;;
    }
private:
    deque<NestedInteger> list;
};