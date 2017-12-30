#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long ar[100001],p=9000000000,x,n,i,q=9000000000,count=9000000000;
    cin>>n;
    for(i=1; i<=n;i++)
    {
        cin>>ar[i];
        if(q>ar[i])
        {
            //count++;
            q = ar[i];
          //  p = i;
           // a[i] = i;
        }
    }
    for(i=n; i>0; i--)
    {
        if(ar[i]==q)
        {
            x =p - i;
            p = i;
            if(count>x)
            {
                count = x;
                //cout<<count<<endl;
            }
        }
    }
    cout<<count;

}