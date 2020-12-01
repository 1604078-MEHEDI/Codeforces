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



const ll N = 100006;
ll n;
ll dp[N][21], depth[N];
vector<ll> g[N];

void dfs(ll u, ll parent)
{
    dp[u][0] = parent;
    for (auto v : g[u]) {
        if (v == parent) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}


void init() {
    //memset(dp, -1, sizeof dp);
    dfs(1, -1);
    for (ll k = 1; k <= 18; k++) {
        for (ll u = 1; u <= n; u++) {
            if (dp[u][k - 1] == -1)continue;
            dp[u][k] = dp[dp[u][k - 1]][k - 1];
        }
    }
}

ll lca(ll u, ll v)
{
    if (depth[u] < depth[v]) swap(u, v);
    for (ll k = 18; k >= 0; k--) {
        if (depth[u] - (1 << k) >= depth[v]) {
            u = dp[u][k];
        }
    }

    if (u == v) return u;
    for (ll k = 18; k >= 0; k--) {
        if (dp[u][k] != dp[v][k]) {
            u = dp[u][k];
            v = dp[v][k];
        }
    }
    return dp[u][0];
}

ll dist(ll a, ll b) {
    return (depth[a] + depth[b] - 2 * depth[lca(a, b)]);
}


int main()
{
    FASTIO
    //*
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    //*/
    ll  q;
    cin >> n;// >> q;
    for (ll i = 2; i <= n; i++) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    init();
    cin >> q;
    while (q--) {
        ll a, b, x, y, k;
        cin >> x >> y >> a >> b >> k;
        bool ok = false;
        ll without = dist(a, b);
        ll with = min(dist(a, x) + dist(y, b), dist(a, y) + dist(x, b)) + 1;
        ll ans = mod;
        if (without % 2 == k % 2)ans = without;
        if (with % 2 == k % 2)ans = min(ans, with);
        ok = (ans <= k);
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
