#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
LL a[maxn], ans[maxn];
map<LL,LL>mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    LL n;
    cin >> n;
    LL mx = 0;
    for(LL i = 1LL; i <= n; i++){
        cin >> a[i];
        mx = max(a[i], mx);
        mp[a[i]]++;
    }
     ans[0] = 0LL;
    ans[1] = mp[1];
    for(LL i = 2LL; i <= mx; i++){
        ans[i] = max(ans[i - 1],ans[i - 2]+ i*mp[i]);
        //cout << ans[i] << endl;
    }
    cout << ans[mx]<<endl;
    return 0;
}
