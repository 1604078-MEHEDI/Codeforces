#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,minimum,maximum;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        int a;
        cin>>a;
        if(a==1) minimum=i;
        if(a==n) maximum=i;
    }
    int x;
    x = max(minimum, maximum);
    int y;
    y = min(minimum, maximum);
    cout<<max((n-y), (x-1));
    return 0;
}
