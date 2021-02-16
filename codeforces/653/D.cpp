/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
using pii = pair<ll, ll>;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
//const ll mod = 998244353;


inline void normal(ll &a) { a %= mod; (a < 0) && (a += mod); }
inline ll modMul(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a * b) % mod; }
inline ll modAdd(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a + b) % mod; }
inline ll modSub(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while (p) { if (p & 1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define slll(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ss(ch) scanf("%s",ch)
#define pi(x) prllf("%d",x)
#define pii(x,y) prllf("%d %d",x,y)
#define piii(x,y,z) prllf("%d %d %d",x,y,z)
#define pl(x) prllf("%lld",x)
#define pll(x,y) prllf("%lld %lld",x,y)
#define plll(x,y,z) prllf("%lld %lld %lld",x,y,z)
#define ps(ch) prllf("%s",ch)
#define F(i,a,b)      for(ll i= a; i <= b; i++)
#define R(i,b,a)      for(ll i= b; i >= a; i--)
#define REP(i,n) for(ll i = 0; i < (n); i++)
#define sline(a) scanf("%[^\n]s",a)
#define Case(t) prllf("Case %d:\n",t)

ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};
ll dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
ll dy8[] = {1, -1, -1, 0, 1, -1, 0, 1};
ll kx8[] = {1, 1, 2, 2, -1, -1, -2, -2};
ll ky8[] = {2, -2, 1, -1, 2, -2, 1, -1};
/* for Random Number generate
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
*/
///**
template < typename F, typename S >ostream& operator << ( ostream& os, const pair< F, S > & p ) {return os << "(" << p.first << ", " << p.second << ")";}
template < typename T >ostream &operator << ( ostream & os, const vector< T > &v ) {os << "{"; for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin() ) os << ", "; os << *it;} return os << "}";}
template < typename T >ostream &operator << ( ostream & os, const set< T > &v ) {os << "["; for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin()) os << ", "; os << *it;} return os << "]";}
template < typename F, typename S >ostream &operator << ( ostream & os, const map< F, S > &v ) {os << "["; for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin() ) os << ", "; os << it -> first << " = " << it -> second ;} return os << "]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
void faltu () { cerr << endl; }
template <typename T>void faltu( T a[], ll n ) {for (ll i = 0; i < n; ++i) cerr << a[i] << ' '; cerr << endl;}
template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) { cerr << arg << ' '; faltu(rest...); }

// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less 
using namespace __gnu_pbds;

// GNU link : https://goo.gl/WVDL6g
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;
// find_by_order(k) – ফাংশনটি kth ordered element এর একটা পয়েন্টার রিটার্ন করে। অর্থাৎ তুমি চাইলেই kth ইন্ডেক্সে কি আছে, সেটা জেনে ফেলতে পারছো!
// order_of_key(x) – ফাংশনটি x এলিমেন্টটা কোন পজিশনে আছে সেটা বলে দেয়।
//*//**___________________________________________________**/
const ll N = 505;



struct Edge
{
    ll to, rev;
    ll f, cap;
    Edge();
    Edge(ll to, ll rev, ll f, ll cap): to(to), rev(rev), f(f), cap(cap) {}
};

vector<Edge> g[N];

void addEdge(ll u, ll v, ll cap)
{
    Edge a = Edge(v, (ll)g[v].size(), 0, cap); // s to t
    Edge b = Edge(u, (ll)g[u].size(), 0, 0); // for directed grap capacity 0
    g[u].push_back(a);
    g[v].push_back(b);
}

ll nodes, start[N], level[N];
queue<ll> Q;

bool dinic_bfs(ll s, ll t)
{
    fill(level, level + nodes, -1);
    Q.push(s);
    level[s] = 0;
    while (!Q.empty()) {
        ll u = Q.front();
        Q.pop();
        for (ll i = 0; i < (ll)g[u].size(); i++) {
            Edge &E = g[u][i];
            ll v = E.to;
            if (level[v] < 0 && E.f < E.cap) {
                Q.push(v);
                level[v] = level[u] + 1;
            }
        }
    }
    return level[t] >= 0;
}

ll dinic_dfs(ll u, ll dst, ll flow)
{
    if (u == dst) return flow;
    for (ll &i = start[u]; i < (ll)g[u].size(); i++) {
        Edge &E = g[u][i];
        ll v = E.to;
        if (level[v] == level[u] + 1 && E.f < E.cap) {
            ll cur_flow = dinic_dfs(v, dst, min(flow, E.cap - E.f));
            if (cur_flow > 0) {
                E.f += cur_flow;
                g[v][E.rev].f -= cur_flow;
                return cur_flow;
            }
        }
    }
    return 0;
}

ll dinic_flow(ll s, ll t)
{
    //dbg(s, t);
    ll flow = 0;
    //nodes = 210;
    while ((dinic_bfs(s, t))) {
        //dbg(flow);
        fill(start, start + nodes, 0);
        ll delta;
        while ((delta = dinic_dfs(s, t, INT_MAX))) flow += delta;
    }
    return flow;
}

#define eps 1e-12
ll u[N], v[N], w[N];
int main()
{
    FASTIO
    ///*
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
//*/
    ll T;
    T = 1;
    //scanf("%d", &T);
    for (ll cs = 1; cs <= T; cs++) {
        ll n, m, x;
        cin >> n >> m >> x;
        nodes = n +100;
        for (ll i = 1; i <= m; i++) {
            cin >> u[i] >> v[i] >> w[i];
        }
        ll s = 1, t = n;
        double ans = eps, l = 0.0, r = 100000000, mid, tm;
        for (ll i = 1; i <= 200; i++) {
            mid = (l + r) / 2.0;
            // dbg(mid);
            for (ll j = 1; j <= n; j++)g[j].clear();
            for (ll j = 1; j <= m; j++) {
                tm = (w[j] * 1.0) / mid;
                addEdge(u[j], v[j], tm);
            }
            ll flow = dinic_flow(s, t);
            // dbg(flow);
            if (flow >= x) {
                ans = mid;
                l = mid + eps;
            }
            else r = mid - eps;
        }
        ans *= x;
        cout << fixed << setprecision(10) << ans << "\n";
        // cout << ans << "\n";
    }
    return 0;
}