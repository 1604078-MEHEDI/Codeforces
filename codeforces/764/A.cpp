#include<bits/stdc++.h>
using namespace std;

int ar[1000000];

int main()
{
    ios_base::sync_with_stdio(false);

    int n,m,z,p,q,count=0;
    cin>>n>>m>>z;


    for(int i=1; i<=z; i++)
    {
        p = i*n;
        if(p > z)break;
        ar[p]++;
    }
    for(int i=1; i<=z; i++)
    {
        q = i*m;
        if(q > z)break;
        ar[q]++;
    }

    for(int i=1; i<=z; i++)
    {
        if(ar[i] > 1)count++;
    }

    cout<<count<<endl;
    return 0;
}
