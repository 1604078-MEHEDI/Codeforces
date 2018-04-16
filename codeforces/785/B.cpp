#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n,m,a,b,c,d,mn1=1000000007,mx1=0,mn2=1000000007,mx2=0;

    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        mn1 = min(b, mn1);
        mx2  = max(a, mx2);

    }
    cin>>m;
    while(m--)
    {
        cin>>c>>d;
        mx1 = max(c, mx1);
        mn2 = min(d, mn2);

    }

    int dis1 = mx1 - mn1;
    int dis2 = mx2 - mn2;

    int result = max(dis1, dis2);

    if(result>0)cout<<result;
    else cout<<0;
}
