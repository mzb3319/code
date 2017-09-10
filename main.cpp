#include "iostream"
#include "vector"
#include "unordered_set"
#include "string"

using namespace std;

class Trie
{
public:
    Trie():child(26, nullptr),isLeaf(false)
    {

    }

    void insert(const string &word)
    {
        insert(word,0);
    }

    Trie* search(char c)
    {
        return child[c-'a'];
    }

    bool isWord()
    {
        return isLeaf;
    }

private:
    bool isLeaf;
    vector<Trie*> child;

    void insert(const string &word,int index)
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
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board,vector<string> &words)
    {
        Trie wordTree;
        for(const string &word:words)
            wordTree.insert(word);
        unordered_set<string> ret;
        vector<vector<bool>> visited(board.size(),vector<bool>(board.front().size(),false));
        string path;
        for(int i=0;i<board.size();++i)
        {
            for(int j=0;j<board.front().size();++j)
            {
                check(board,i,j,ret,&wordTree,path,visited);
            }
        }
        return vector<string>(ret.begin(),ret.end());
    }
private:
    void check(vector<vector<char>> &board,int x,int y,unordered_set<string> &ret,Trie *curr,string &path,vector<vector<bool>> &visited)
    {
        if(x<0||y<0||x>=board.size()||y>=board.front().size()||visited[x][y])
            return;

        Trie *tmp= nullptr;
        tmp=curr->search(board[x][y]);

        if(tmp== nullptr)
            return;

        path.push_back(board[x][y]);

        visited[x][y]=true;
        check(board,x+1,y,ret,tmp,path,visited);
        check(board,x-1,y,ret,tmp,path,visited);
        check(board,x,y+1,ret,tmp,path,visited);
        check(board,x,y-1,ret,tmp,path,visited);
        visited[x][y]=false;

        if(tmp->isWord())
            ret.insert(path);
        path.pop_back();
    }
};
