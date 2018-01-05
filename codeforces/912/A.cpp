#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,x,y,z,p,q,r,t;
    cin>>a>>b>>x>>y>>z;
    //  p = a+b;
    q  = (x*2)+y;
    r = (z*3)+y;
    t = (q-a);
    if(t<0)
    {
        t=0;
    }
    p = (r-b);
    if(p<0)
    {
        p=0;
    }
    if(p>=0 && t>=0)
    {
        cout<<p+t;
        return 0;
    }
    else
        cout<<"0";
    return 0;
}

