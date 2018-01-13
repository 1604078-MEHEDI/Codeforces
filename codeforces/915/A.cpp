#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,a,i,p=10000,x;
    cin>>n>>k;
    for(i=1; i<=n; i++)
    {
        cin>>a;
        if(k%a==0)
        {
            x = k/a;
            if(p>x)
            {
                p = x;
            }
        }
    }
    cout<<p;
    return 0;
}
