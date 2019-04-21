// Upsolve: Solution 02
#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define maxn 1110005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

ll cost[maxn];

// sum i = 0 to n - 1 of floor(i/M)+1;
ll prefSum(ll n, ll M)
{
    ll sum = n;
    sum += (n % M) * (n / M);
    sum += (n / M - 1) * (n - n % M)/2;
    return sum;
}

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
    memset(cost, -1, sizeof(cost));
    ll x = 0;
    ll y = 0;
    while(true){
        cost[x] = y;
        //cerr << v[x]<<endl;
        //cerr << x << endl;
        if(x >= b) x -= b;
        else x += a;
        if(x == 0) break;
        y = max(y, x);
    }
    ll ans = 0;
    for(ll i = 0; i < a; i++){
        if(cost[i] == -1) continue;
        //assert(cost[i] >= i);
        if(cost[i] > m) continue;
       // assert(m >= cost[i]);
        ans += prefSum(m+1 - i, a) - prefSum(cost[i] - i, a);
    }
    cout << ans << endl;

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}