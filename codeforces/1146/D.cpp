// Upsolve: Solution 01
#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define maxn 100005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;


int main()
{
    FASTIO
    ///*
    //double start_time = clock();
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif    //*/
    ll m,a,b;
    cin >> m >> a >> b;
    vector<ll> v(a + b, -1);
    ll x = 0;
    ll y = 0;
    while(true){
        v[x] = y;
        //cerr << v[x]<<endl;
        //cerr << x << endl;
        if(x >= b) x -= b;
        else x += a;
        if(x == 0) break;
        y = max(y, x);
    }
    // nicher tuku vlomoto vujhinai....
    ll ans = 0;
    for(int i = 0; i < (a+b); i++){
        //cerr << ans << " "<< m - v[i]+1LL << " "<<v[i]<< " "<<m<<endl;
        if(v[i] != -1) ans += max(0LL, m - v[i] + 1LL);
    }
    if(m >= (a + b)){
        ll p = m - (a + b);
        ll g = __gcd(a, b);
        ll Q = p / g * g;
        ll fisrt = p - 0 + 1;
        ll last = p - Q + 1;
        ll cnt = (fisrt - last) / g + 1;
        ans += (fisrt + last) * cnt / 2;
    }
    cout << ans << endl;

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}