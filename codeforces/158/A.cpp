#include<bits/stdc++.h>
using namespace std;
int ar[10001];

int main()
{
    int n,k,count=0,sum=0;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>ar[i];
        //sum +=ar[i];
    }
    int p =ar[k];
    for(int i=1; i<=n; i++)
    {
        if(ar[i]==0)continue;
        if(ar[i] >= p)count++;
    }

    if(count > 0 )
    cout<<count<<endl;
    else
        cout<<0<<endl;
}
