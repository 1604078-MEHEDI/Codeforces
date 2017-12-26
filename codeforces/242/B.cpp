#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,i,a,b,p=900000000,q=0;
    long long a1[100001],a2[100001];
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a>>b;
        a1[i] = a;
        a2[i] = b;
        if(p>a)
        {
            p = a;
         //   x = i;
        }
        if(b>q)
        {
            q = b;
          //  y = i;
        }
    }
    //cout<<p<<" "<<q<<endl;
    //cout<<x<<" "<<y;
    for(i=0; i<n; i++)
    {
        if(a1[i]==p && a2[i]==q)
        {
            printf("%lld",i+1);
            return 0;
        }
    }
    if(n==1)
    {
        printf("1");
        return 0;
    }
    else
    {
    printf("-1");
    return 0;
    }
}
