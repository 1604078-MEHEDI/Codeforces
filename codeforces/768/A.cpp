#include<bits/stdc++.h>
using namespace std;

long long ar[1000000];

int main()
{
    ios_base::sync_with_stdio(0);

    long long n,i,j,p=0,q=999999999,count=0;
    cin>>n;

    for(i=0; i<n; i++)
    {
        cin>>ar[i];

        if(ar[i] > p)
            p = ar[i];

        if(q > ar[i])
            q = ar[i];
    }

    for(j=0; j<n; j++)
    {
        if(p==ar[j])count++;
        if(q==ar[j])count++;
    }
    int result = n - count;
    if(result>0)
        cout<<result;
    else
        cout<<0;
}
