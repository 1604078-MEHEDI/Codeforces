#include<bits/stdc++.h>
using namespace std;
int main()

{
    int i,n,count=0,b=0,p=0,m,q=100000;
    int a[1001];
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(i=0; i<n-1; i++)
    {
        if(a[i]>p)
        {
            p = a[i];
        }
        if(q>a[i])
        {
            q = a[i];
        }
        if(a[i]<a[i+1])
        {
            if(a[i+1]>p)
            {
                count++;
                //cout<<" a "<<count<<" I "<<i<<" "<<p<<endl;
            }
        }
        if(a[i]>a[i+1])
        {
            if(a[i+1]<q)
            {
                count++;
             //   cout<<" b "<<count<<" I "<<i<<" "<<q<<endl;
            }
        }

    }
    cout<<count;
}
