#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 100005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

const ll mod = 1e9 + 7;

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

ll reset(ll n, ll pos)
{
    return n = n & ~(1LL << pos);
}

bool check(ll n, ll pos)
{
    return (bool)(n & (1LL << pos));
}

ll msb(ll mask)
{
    return (mask & (-mask));
}

struct lca
{
    ll u, v, lc;
} LCA[105];

ll edge[22];
ll n,m,q;
ll dp[15][(1LL << 13) + 2];
bool vis[15][(1LL << 13) + 2];

bool checkEdge(ll childMask, ll childRoot, ll root)
{
    if( (edge[childRoot] & (childMask | (1 << root))) == edge[childRoot])
        return true;

    return false;
}

bool checkLCA(ll childMask)
{
    for(ll i = 1; i <= q; i++)
    {
        if(childMask & (1 << LCA[i].lc))
        {
            if((~childMask & (1 << LCA[i].u)) || (~childMask & (1 << LCA[i].v)))
                return false;
        }
        else
        {
            if((childMask & (1<<LCA[i].u)) && (childMask & (1<<LCA[i].v)))
                return false;
        }
    }
    return true;
}



ll solve(ll root, ll mask)
{
    ll &ret = dp[root][mask];
    bool &v = vis[root][mask];
    if(v) return ret;
    v = true;
    if(check(mask, root) == 0) return ret = 0;
    if(__builtin_popcountll(mask) == 1) return ret = 1;
    ret = 0;

    ll xmask = reset(mask, root);
    ll temp = msb(xmask);

    for(ll nmask = xmask; nmask; nmask = (nmask - 1) & xmask)
    {
        if(!(nmask & temp)) continue;

        for(ll nroot = 0; nroot < n; nroot++)
        {
            if(!check(nmask, nroot)) continue;
            if(checkEdge(nmask, nroot, root) && checkLCA(nmask))
            {
                ret += (solve(nroot, nmask) * solve(root, nmask ^ mask));
            }
        }
    }
    return ret;
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
#endif
//*/
    int T;
//    cin >> T;
    T = 1;
    for(int cs = 1; cs <= T; cs++)
    {
        cin >> n >> m >> q;
        for(int i = 1; i <= m; i++)
        {
            ll u,v;
            cin >> u >> v;
            u--;
            v--;
            edge[u] = Set(edge[u], v);
            edge[v] = Set(edge[v], u);
        }

        for(int i = 1; i <= q; i++)
        {
            cin >> LCA[i].u >> LCA[i].v >>  LCA[i].lc;
            LCA[i].u--;
            LCA[i].v--;
            LCA[i].lc--;
        }
        cout << solve(0, ((1LL << n) - 1));
    }

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}
