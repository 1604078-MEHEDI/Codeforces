#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,minim,maxim;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        int a;
        cin>>a;
        if(a==1) minim=i;
        if(a==n) maxim=i;
    }
    int x;
    x = max(minim, maxim);
    int y;
    y = min(minim, maxim);
    cout<<max((n-y), (x-1));
    return 0;
}
