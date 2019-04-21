// Upsolve: Solution 03
#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define maxn 1110005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;

ll cost[maxn], visit[maxn];
ll m,a,b;
ll last, mx, n;

void go_up(int pos, int val)
{
    while(pos <= last){
        cost[pos] += val;
        pos += (pos & -pos);
    }
}

ll go_down(int pos)
{
    ll res = 0;
    while(pos > 0){
        res += cost[pos];
        pos -= (pos & -pos);
    }
    return res;
}

void dfs(ll u)
{
    if(u <= 0 || u > mx || visit[u]) return;
    //cerr << u << endl;
    go_up(u, +1);
    visit[u] = 1LL;
    dfs(u+a);
    dfs(u-b);
}

ll solve(ll mx)
{
    ll up = ((b+a-1)/a)*1LL*a;
    if(up > mx) n = a;
    else n = __gcd(a,b);
    ll d = mx/n;
    ll to = d * n;
    ll t = (mx - to + 1LL)*1LL*(d+1LL);
    t += (d*1LL*(d+1)/2)*n;
    return t;
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
    cin >> m >> a >> b;
    last = 1e6;
    last = min(last, m);
    visit[0] = 1;
    ll ans = 1LL;
    for(ll i = 1LL; i <= last; i++)
    {
        mx = i;
        if(i >= a && visit[i - a] && !visit[i]){
            dfs(i);
        }
        ll res = go_down(i);
        ans += res + 1;
    }
    if(m <= last){
        cout << ans << endl;
        return 0;
    }
    ans += solve(m) - solve(last);
    cout << ans << endl;

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}