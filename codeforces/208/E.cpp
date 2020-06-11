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
int p[N], n, dp[N][17], vis[N], level[N];
int in_time[N], out_time[N];
int times;
vector<int> g[N], in[N], out[N];

void lca()
{
  memset(dp, 0, sizeof dp);
  for (int i = 1; i <= n; i++) {
    dp[i][0] = p[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 17; j++) {
      if (dp[i][j - 1] != 0) {
        dp[i][j] = dp[dp[i][j - 1]][j - 1];
      }
    }
  }
}

int Parent(int u, int k)
{
  int lg = 0, pq = 1;
  for (int i = 0; i < 17; i++) {
    if (pq <= k) {
      lg++;
      pq *= 2;
    }
    else break;
  }
  for (int i = lg; i >= 0; i--) {
    if ((k >> i) & 1) {
      u = dp[u][i];
    }
  }
  return u;
}

void dfs(int u, int lvl) {
  vis[u] = 1;
  level[u] = lvl;
  times++;
  in_time[u] = times;
  in[lvl].push_back(times);
  for (auto v : g[u]) {
    if (vis[v])continue;
    dfs(v, lvl + 1);
  }
  times++;
  out_time[u] = times;
  out[lvl].push_back(times);
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
  vector<int> roots;
  si(n);
  for (int i = 1; i <= n; i++) {
    si(p[i]);
    if (p[i]) {// gaph banaisi
      g[p[i]].push_back(i);
      g[i].push_back(p[i]);
    }
    else {// new subtree
      roots.push_back(i);
    }
  }
  lca();// LCA ber korechi
  for (auto rt : roots) {
    dfs(rt, 0);// jotogula alada alada subtree root ase, sheigula theke dfs chalaisi
  }
  int m;
  si(m);

  while (m--) {
    int v, Pth;
    sii(v, Pth);
    int lc = Parent(v, Pth);//node v er p'th parent khuje ber korechi
    if (lc == 0)printf("0 ");// jodi p'th parent na thake
    else {
      int a = in_time[lc];// p'th parent a jei node ase tar in_time
      int b = out_time[lc];//p'th parent a jei node ase tar Out_time
      int height = level[v];// node v er level

      int x = upper_bound(out[height].begin(), out[height].end(), b) - out[height].begin();
      int y = upper_bound(in[height].begin(), in[height].end(), a) - in[height].begin();

      // Ans: joto gula node er height v er soman && jader out Time oi P'th parent er out time er cheye kom &
      // In Time P'th parent er in Time er cheye beshi , toto gula node e ans.... 
      int ans = x - y - 1;
      pi(ans);
      printf(" ");
    }
  }
  return 0;
}