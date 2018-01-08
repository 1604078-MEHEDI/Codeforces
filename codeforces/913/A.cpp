#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,m,a,p;
    cin>>n>>m;
    if(n>m)
    {
        cout<<m;
        return 0;
    }
    a = pow(2,n);
    if(a>m)
    {
        cout<<m;
        return 0;
    }
    p = m%a;
    cout<<p;
    return 0;
}
