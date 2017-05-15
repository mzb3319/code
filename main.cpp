#include "iostream"
#include "string"

using namespace std;


class Solution
{
public:
    string complexNumberMultiply(string a,string b)
    {
        int a1=0,b1=0,a2=0,b2=0;
        auto f=a.find('+');
        string tmp;
        tmp=a.substr(0,f);
        a1=stoi(tmp);
        tmp=a.substr(f+1,a.size()-f-2);
        a2=stoi(tmp);
        f=b.find('+');
        tmp=b.substr(0,f);
        b1=stoi(tmp);
        tmp=b.substr(f+1,b.size()-f-2);
        b2=stoi(tmp);
        int r=a1*b1-a2*b2;
        int i=a1*b2+a2*b1;
        return to_string(r)+'+'+to_string(i)+'i';
    }
};