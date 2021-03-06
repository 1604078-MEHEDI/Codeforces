/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
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
#define pi(x) printf("%d",x)
#define pii(x,y) printf("%d %d",x,y)
#define piii(x,y,z) printf("%d %d %d",x,y,z)
#define pl(x) printf("%lld",x)
#define pll(x,y) printf("%lld %lld",x,y)
#define plll(x,y,z) printf("%lld %lld %lld",x,y,z)
#define ps(ch) printf("%s",ch)
#define F(i,a,b)      for(int i= a; i <= b; i++)
#define R(i,b,a)      for(int i= b; i >= a; i--)

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
template <typename T>void faltu( T a[], int n ) {for (int i = 0; i < n; ++i) cerr << a[i] << ' '; cerr << endl;}
template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) { cerr << arg << ' '; faltu(rest...); }

// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less 
using namespace __gnu_pbds;

// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;
// find_by_order(k) – ফাংশনটি kth ordered element এর একটা পয়েন্টার রিটার্ন করে। অর্থাৎ তুমি চাইলেই kth ইন্ডেক্সে কি আছে, সেটা জেনে ফেলতে পারছো!
// order_of_key(x) – ফাংশনটি x এলিমেন্টটা কোন পজিশনে আছে সেটা বলে দেয়।
//*//**___________________________________________________**/
const int N = 100006;
vector<int> g[N];
int r[N];
int dp[N][20];
int Q[N][2];
int l[N];
int p[N][2];
int n, m;
int c, qc;

int root(int x)
{
    if (r[x] == x)return x;
    else return r[x] = root(r[x]);
}

void dfs(int u, int p = -1)
{
    dp[u][0] = p;
    l[u] = (p == -1) ? 1 : l[p] + 1;
    for (auto v : g[u]) {
        if (v == p)continue;
        dfs(v, u);
    }
}

int lca(int u, int v)
{
    if (l[u] < l[v])return lca(v, u);
    for (int i = 19;  i >= 0; i--) {
        if (l[u] - (1 << i) >= l[v])
            u = dp[u][i];
    }
    if (u == v)return u;
    for (int i = 19; i >= 0; i--) {
        if (dp[u][i] != dp[v][i] && dp[u][i] != -1) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return dp[u][0];
}

int main()
{
    //FASTIO
    ///*
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
//*/
    sii(n, m);
    c = 1;
    qc = 0;
    for (int i = 1; i <= n; i++) r[i] = i;
    for (int i = 0; i < m; i++) {
        int t;
        si(t);
        if (t == 1) {
            int a, b;
            sii(a, b);
            g[a].push_back(b);
            g[b].push_back(a);
            r[a] = root(b);
        }
        else if (t == 2) {
            int x;
            si(x);
            p[c][0] = x;
            p[c][1] = root(x);
            c++;
        }
        else if (t == 3) {
            int x, y;
            sii(x, y);
            Q[qc][0] = x;
            Q[qc][1] = y;
            qc++;
        }
    }
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; i++)
        if (dp[i][0] == -1) dfs(root(i));
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= n; i++) {
            if (dp[i][j - 1] != -1) {
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }
    }

    for (int i = 0; i < qc; i++) {
        if (root(Q[i][0]) != root(p[Q[i][1]][0]))
            printf("NO\n");
        else if (lca(Q[i][0], p[Q[i][1]][0]) == Q[i][0] && lca(Q[i][0], p[Q[i][1]][1]) == p[Q[i][1]][1])
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}