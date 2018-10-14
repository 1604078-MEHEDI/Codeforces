#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int mx = max(a,max(b,c));
    int others = (a+b+c) - mx;
    int ans = mx - others + 1;
    if(ans> 0)cout<<ans<<endl;
    else cout<<0<<endl;
    return 0;
}
