#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    long long a,b,x,y;
    cin >> a >> b >> x >> y;

    while(1){
        long long p = __gcd(x,y);
        if(p == 1){
                break;
        }
        else{
            x = x / p;
            y = y / p;
        }
    }
    long long ans = min(a/x, b/y);
    cout<<ans<<endl;
    return 0;
}
