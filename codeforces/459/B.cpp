#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,m,a,i,p=0,q=10000000001,x=0,y=0,c=0,r;
    cin>>n;
    r = n;
    for(i=0; i<n; i++)
    {
    cin>>a;
        if(p==a)
        {
            x++;
        }
        if(q==a)
        {
            y++;
        }
        if(a>p)
        {
            p = a;
            x = 1;
        }
        if(q>a)
        {
            q = a;
            y = 1;

        }
    }
    m = p -q;
    if(m==0)
    cout<<(p-q)<<" "<<n*(n-1)/2;
    else
        cout<<(p-q)<<" "<<x*y;
}

