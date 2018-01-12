#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i,n,p=0,sum=0,x,m,a;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        if(a>p)
        {
            p = a;
        }
        sum +=a;
    }
    x = p * n;
    m = x - sum;
 //   cout<<x<< " "<<sum<<" "<<m<<endl;
    cout<<m;
}
