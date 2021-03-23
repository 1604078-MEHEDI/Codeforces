/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
using pii = pair<int, int>;
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
#define REP(i,n) for(int i = 0; i < (n); i++)
#define sline(a) scanf("%[^\n]s",a)
#define Case(t) printf("Case %d:\n",t)

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, -1, 0, 1, -1, 0, 1};
int kx8[] = {1, 1, 2, 2, -1, -1, -2, -2};
int ky8[] = {2, -2, 1, -1, 2, -2, 1, -1};
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
const int N = 200006;
const int M = N * 2 + N * 19 * 2;
vector<pii> g[N * 2], G[N];

inline void add_edge(int u, int v, int w) {
    g[u].push_back({v, w});
}

int T;
void binarize(int u, int p = 0) {
    int last = 0, tmp = 0;
    for (auto &e : G[u]) {
        int v = e.first;
        int w = e.second;
        if (v == p)continue;
        ++tmp;
        if (tmp == 1) {
            add_edge(u, v, w);
            add_edge(v, u, w);
            last = u;
        }
        else if (tmp == ((int)G[u].size() - (u != 1))) {
            add_edge(last, v, w);
            add_edge(v, last, w);
        }
        else {
            T++;
            add_edge(last, T, 0);
            add_edge(T, last, 0);
            last = T;
            add_edge(T, v, w);
            add_edge(v, T, w);
        }

    }
    for (auto &e : G[u]) {
        int v = e.first;
        if (v == p)continue;
        binarize(v, u);
    }
}

int sz[N * 2];
int tot, done[N * 2], cenpar[N * 2];
void calc_sz(int u, int p) {
    tot++;
    sz[u] = 1;
    for (auto &e : g[u]) {
        int v = e.first;
        if (v == p || done[v])continue;
        calc_sz(v, u);
        sz[u] += sz[v];
    }
}

int find_cen(int u, int p) {
    for (auto &e : g[u]) {
        int v = e.first;
        if (v == p || done[v])continue;
        else if (sz[v] > tot / 2)return find_cen(v, u);
    }
    return u;
}

ll dis[20][N * 2];

void go(int u, int p, ll nw, int l) {
    dis[l][u] = nw;
    for (auto &e : g[u]) {
        int v = e.first;
        ll w = e.second;
        if (v == p || done[v])continue;
        go(v, u, nw + w, l);
    }
}

int st[N * 2], en[N * 2], DT;
struct node
{
    vector<int> ct;//adjacent edges in centroid tree
    int level = 0, id = 0, cnt = 0;
    ll sum = 0, parsum = 0;
} t[M];

int decompose(int u, int p = 0, int l = 0) {
    tot = 0;
    calc_sz(u, p);
    int cen = find_cen(u, p);
    cenpar[cen] = p;
    done[cen] = 1;
    u = cen;
    st[u] = ++DT;
    t[u].id = u;
    t[u].level = l;
    go(u, p, 0, l);

    for (auto e : g[u]) {
        int v = e.first;
        if (v == p || done[v])continue;
        int x = decompose(v, u, l + 1);
        t[u].ct.push_back(x);
    }
    en[u] = DT;
    return u;
}

int insub(int r, int c) {
    r = t[r].id;
    c = t[c].id;
    return st[r] <= st[c] && en[c] <= en[r];
}


int upd(int cur, int u) { // update node u in cur tree
    T++; assert(T < M);
    t[T] = t[cur];
    cur = T;
    t[cur].cnt++;
    t[cur].sum += dis[t[cur].level][u];
    for (auto &v : t[cur].ct) if (insub(v, u)) {
            v = upd(v, u);
            t[v].parsum += dis[t[cur].level][u];
        }
    return cur;
}

ll query(int cur, int u) { // query on cur tree

    ll ans = 0;
    while (t[cur].id != t[u].id) {
        int v = 0;
        for (auto x : t[cur].ct) if (insub(x, u)) v = x;
        assert(v);
        ans += dis[t[cur].level][t[u].id] * (t[cur].cnt - t[v].cnt);
        ans += t[cur].sum - t[v].parsum;
        cur = v;
    }
    ans += t[cur].sum;
    return ans;
}

int a[N], root[N];


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
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    T = n;
    binarize(1);
    root[0] = decompose(1);
    for (int i = 1; i <= n; i++)
        root[i] = upd(root[i - 1], a[i]);
    ll ans = 0;
    const ll Mod = 1ll << 30;
    while (q--) {
        int ty;
        cin >> ty;
        if (ty == 1) {
            int l, r, u;
            cin >> l >> r >> u;
            l ^= ans;
            r ^= ans;
            u ^= ans;
            ans = query(root[r], u) - query(root[l - 1], u);
            cout << ans << "\n";
            ans %= Mod;
        }
        else {
            int x;
            cin >> x;
            x ^= ans;
            root[x] = upd(root[x - 1], a[x + 1]);
            swap(a[x], a[x + 1]);
        }
    }
}