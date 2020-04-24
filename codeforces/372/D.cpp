/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

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
int n, k; // no. of vertices & max subtree size
vector<int> a[N];//store adjacency list of given tree
int parent[N];// store each node parent
int depth[N]; //store depth of each node
int order[N]; // to store dfs order of arrival of each node
int timer = 1; // timer for dfs order
int dp[N][20]; // pre processed array for lca
set<pair<int, int>> sub; // {order[i], i}
int cur = 1;//store no. of vertices in current set
int ans = 1; // store the final ans


///dfs order, parent and depth for each node
void dfs(int node, int par, int dep)
{
    order[node] = timer;
    timer++;
    parent[node] = par;
    depth[node] = dep;

    for (auto v : a[node]) {
        if (v == par)continue;
        dfs(v, node, dep + 1);
    }
}

//pre processing for LCA
void preprocess()
{
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; i++)
        dp[i][0] = parent[i];

    for (int j = 1; j < 20; j++)
        for (int i = 0; i <= n; i++)
            if (dp[i][j - 1] != -1)
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
}

// gives lca of two node
int lca(int x, int y)
{
    if (depth[x] < depth[y])swap(x, y);
    int dis = depth[x] - depth[y];
    for (int j = 19; j >= 0; j--)
        if (dis >= (1 << j)) {
            x = dp[x][j];
            dis -= (1 << j);
        }

    if (x == y)return x;
    for (int i = 19; i >= 0; i--)
        if (dp[x][i] != dp[y][i] && dp[x][i] != -1) {
            x = dp[x][i];
            y = dp[y][i];
        }
    return parent[x];
}

// returns the distance between two node
int dist(int x, int y)
{
    int lc = lca(x, y);
    return depth[x] + depth[y] - 2 * depth[lc];
}

int Left(set < pair<int, int>>:: iterator it)
{
    if (it == sub.begin())it = sub.end();
    it--;
    return it->second;
}

int Right(set < pair<int, int>>:: iterator it)
{
    it++;
    if (it == sub.end()) it = sub.begin();
    return it->second;
}


//insert a node in the subtree
void Insert(int x)
{
    if (sub.empty()) {
        sub.insert({order[x], x});
        return;
    }
    sub.insert({order[x], x});
    auto it = sub.find({order[x], x});
    int prv = Left(it); // previous node in the set
    int next = Right(it); // next node in the set

    cur += (-dist(prv, next) + dist(x, next) + dist(x, prv)) / 2;
}


//Erase a node on the subtree
void Erase(int x)
{
    if ((int)sub.size() == 1) {
        sub.erase({order[x], x});
        return;
    }

    auto it = sub.find({order[x], x});
    if (it == sub.end())return;
    int prv = Left(it); // previous node in the set
    int next = Right(it); // next node in the set

    cur += (dist(prv, next) - dist(x, next) - dist(x, prv)) / 2;
    sub.erase(it);

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
    sii(n, k);
    for (int i = 1; i < n; i++) {
        int x, y;
        sii(x, y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 1, 0); // dfs on tree
    order[n + 1] = timer;// node does not exit
    preprocess(); // for lca

    int r = 1;
    for (int l = 1; l < n; l++) {
        while (r <= n) {
            Insert(r);
            if (cur <= k)r++;
            else {
                Erase(r);
                break;
            }
        }
        ans = max(ans, r - l);
        Erase(l);
    }
    pi(ans);
    return 0;
}