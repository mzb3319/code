#include "iostream"
#include "vector"
#include "unordered_map"
#include "string"

using namespace std;

class Trie
{
public:
    Trie():child(26, nullptr),isLeaf(false)
    {

    }

    void insert(string word)
    {
        insert(word,0);
    }

    bool search(string word)
    {
        return search(word,0,true);
    }

    bool startsWith(string prefix)
    {
        return search(prefix,0,false);
    }

private:
    bool isLeaf;
    vector<Trie*> child;

    void insert(string &word,int index)
    {
        if(index==word.length())
        {
            isLeaf=true;
            return;
        }
        if(child[word[index]-'a']== nullptr)
            child[word[index]-'a']=new Trie;
        child[word[index]-'a']->insert(word,index+1);
    }
    bool search(string &word,int index,bool needLeaf)
    {
        if(index==word.length())
            return needLeaf?isLeaf:true;
        return child[word[index]-'a']==nullptr?false:child[word[index]-'a']->search(word,index+1,needLeaf);
    }
};
