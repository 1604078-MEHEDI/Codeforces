#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,ar[101],i,x=0,sum=0,p,count=0;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>ar[i];
        sum +=ar[i];
    }
    sort(ar, ar+n);
    for(i=0; i<n; i++)
    {
        //count++;
     //   cout<<count<<" ";
        x +=ar[n-1-i];
        p = sum - x;
        if(x>p)
        {
            cout<<i+1;
            return 0;
        }
    }
}
