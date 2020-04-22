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
struct data//it will store min 10 id's of each node and size of each node
{
    int sz, v[10];
    data() {for (int i = 0; i < 10; i++) v[i] = 0;}

} seg_tree[N][18], a[N];

data combine(data a, data b) { // to merge to node
    if (b.sz == 0)return a;
    if (a.sz == 0)return b;
    data res;
    int pa = 0, pb = 0;
    res.sz = min(10, a.sz + b.sz);
    for (int i = 0; i < res.sz; i++) {
        if (pa >= a.sz) {
            res.v[i] = b.v[pb++];
            continue;
        }
        if (pb >= b.sz) {
            res.v[i] = a.v[pa++];
            continue;
        }
        if (a.v[pa] > b.v[pb]) {
            res.v[i] = b.v[pb++];
        }
        else res.v[i] = a.v[pa++];
    }
    return res;
}


// array p stores the (2^i)th ancestor of a node and array h stores depth of that node
int P[N][18], h[N], n, m, q;
vector<int> g[N];


// to set parent and depth of each node
void dfs(int u, int p)
{
    P[u][0] = p;
    h[u] = h[p] + 1;
    for (auto v : g[u]) {
        if (v == p)continue;
        dfs(v, u);
    }
}


// to find lowest common ancestor of each node
int lca(int u, int v)
{
    if (h[u] < h[v])swap(v, u);
    for (int i = 17; i >= 0; i--) {
        if (h[P[u][i]] >= h[v]) u = P[u][i];
    }
    if (u == v)return u;
    for (int i = 17; i >= 0; i--) {
        if (P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    }
    return P[u][0];
}

// to query from node u to p (not here p must be ancestor of u)
data query(int u, int p)
{
    data res;
    res.sz = 0;
    for (int i = 17; i >= 0; i--) {
        if (h[P[u][i]] >= h[p]) {
            res = combine(res, seg_tree[u][i]);
            u = P[u][i];
        }
    }
    return res;
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
    siii(n, m, q);
    for (int i = 1; i < n; i++) {
        int a, b;
        sii(a, b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    data tmp;
    for (int i = 1; i <= m; i++) {
        int u;
        si(u);
        tmp.sz = 1;
        tmp.v[0] = i; // create new node with i'th id
        a[u] = combine(a[u], tmp);//merge
    }
    a[0].sz = 0;
    for (int i = 0; i <= n; i++)seg_tree[i][0] = a[i];
    for (int j = 1; j <= 17; j++) {
        for (int i = 1; i <= n; i++) {
            P[i][j] = P[P[i][j - 1]][j - 1];
        }
    }

    for (int j = 1; j <= 17; j++) {
        for (int i = 1; i <= n; i++) {
            seg_tree[i][j] = combine(seg_tree[i][j - 1], seg_tree[P[i][j - 1]][j - 1]);
        }
    }

    while (q--) {
        int u, v, k;
        siii(u, v, k);
        int lc = lca(u, v);
        tmp = combine(query(u, lc), query(v, lc));// combine query [u,LCA)+(LCA,v]
        tmp = combine(tmp, a[lc]);//now combine above with lca
        int x = min(k, tmp.sz);
        pi(x);
        for (int i = 1; i <= x; i++)
            printf(" %d", tmp.v[i - 1]);
        printf("\n");
    }
    return 0;
}