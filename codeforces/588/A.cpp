#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i,n,a,b,p=10000,sum=0,x,y=0;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a>>b;
        if(p>b)
        {
            p = b;
        }
        sum +=p*a;
    }
    cout<<sum;
    return 0;

}
