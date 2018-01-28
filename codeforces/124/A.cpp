#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b,p;
    cin>>n>>a>>b;
    if((a+b)==n)
    {
        cout<<b;
        return 0;
    }
    if((a+b)>n)
    {
        cout<<n-a;
        return 0;
    }
    else
    {
        cout<<b+1;
        return 0;
    }
}
