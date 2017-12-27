#include<bits/stdc++.h>
using namespace std;

int main()

{
    long long y,k,n,x=0,i,sum=0,count=0;
    scanf("%lld %lld %lld",&y,&k,&n);
    if(y>=n)
    {
        cout<<"-1";
        return 0;
    }
    for(i=1; k*i<=n; i++)
    {
            x =k*i - y;
            if(x>0)
            {
                count = 1;;
                printf("%lld ",x);
            }
    }
    if(count==0)
    {
        cout<<"-1";
        return 0;
    }
}

