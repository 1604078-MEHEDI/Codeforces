#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i=0,p=0;
    int t1 = 1, t2 = 1, nextTerm = 0;
    cin>>n;
    nextTerm = t1 + t2;
    if(n==1)
    {
        cout<<"O";
        return 0;
    }
    for(i=2; i<=n; i++)
    {
        if(p==0)
        {
            cout<<"O";
            p++;
        }
        if(nextTerm==i)
        {
            cout<<"O";
            t1 = t2;
            t2 = nextTerm;
            nextTerm = t1 + t2;
        }
        else
        {
            cout<<"o";
        }
        //cout << nextTerm << ", ";

    }
    return 0;
}
