#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL solve(LL n, LL p, LL cnt)
{
    LL ans = 0;
    while(n > 0){
        ans += n/p;
        n /= p;
    }
    return ans/cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   LL n,b;
   cin >> n >> b;
   LL ans = 5e18+5;
   for(LL i = 2; i*i <= b; i++){
    if(b%i) continue;
    LL cnt = 0;
    while(b%i == 0){
        cnt++;
        b /= i;
    }
    ans = min(ans, solve(n,i,cnt));
   }
   if(b > 1) ans = min(ans, solve(n,b,1));
   cout << ans << endl;
}
