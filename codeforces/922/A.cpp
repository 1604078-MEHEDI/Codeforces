#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long x,y;
    cin>>x>>y;
    if(x==0 && y==1)
    {
        cout<<"Yes";
        return 0;
    }
    long long p = y - 1;
     if(x==0 && y==0)
    {
        cout<<"No";
        return 0;
    }
    if(x<p || p<=0)
    {
        cout<<"No";
        return 0;
    }
    long long m = abs(p-x);
    if(m%2==0)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    return 0;
}
