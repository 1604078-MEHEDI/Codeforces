#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,a,p=-10000000,x,i;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a;
        x = sqrt(abs(a));
        if(x*x !=a)
        {
            if(a>p)
            {
                p = a;
            }
        }
    }
    cout<<p;
}
