#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 9;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    LL n,m,k;
    cin >> n >> m >> k;
    LL a[n+5];
    for(int i = 0; i < n; i++){
            cin >> a[i];
    }
    sort(a,a+n);
    LL mx = a[n-1];
    LL sec_mx = a[n-2];
    LL cnt = m/(k+1);
    LL ans = (mx*cnt)*k + (cnt*sec_mx) + (m%(k+1))*mx;
    cout << ans << endl;
}

