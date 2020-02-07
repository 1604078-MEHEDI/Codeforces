#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 1000005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;

inline void normal(ll &a) { a %= mod; (a < 0) && (a += mod); }
inline ll modMul(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a * b) % mod; }
inline ll modAdd(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a + b) % mod; }
inline ll modSub(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while (p) { if (p & 1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }


///**
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
  return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if ( it != v.begin() ) os << ", ";
    os << *it;
  }
  return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if ( it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if ( it != v.begin() ) os << ", ";
    os << it -> first << " = " << it -> second ;
  }
  return os << "]";
}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)

void faltu () { cerr << endl; }

template <typename T>
void faltu( T a[], int n ) {
  for (int i = 0; i < n; ++i) cerr << a[i] << ' ';
  cerr << endl;
}

template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) { cerr << arg << ' '; faltu(rest...); }
// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less 
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

// find_by_order(k) – ফাংশনটি kth ordered element এর একটা পয়েন্টার রিটার্ন করে। অর্থাৎ তুমি চাইলেই kth ইন্ডেক্সে কি আছে, সেটা জেনে ফেলতে পারছো!
// order_of_key(x) – ফাংশনটি x এলিমেন্টটা কোন পজিশনে আছে সেটা বলে দেয়।

//*//**___________________________________________________**/

const int N = 5000 + 10;
const int lg = log2(N) + 1;
const int inf = 2e9;

int par[N][lg], depth[N];
vector<int> g[N];

void dfs(int u, int p, int lvl)
{
  par[u][0] = p;
  depth[u] = lvl;
  for (auto v : g[u]) {
    if (v == p)continue;
    dfs(v, u, lvl + 1);
  }
}

void init(int root, int n)
{
  dfs(root, -1, 1);

  for (int k = 1; k < lg; k++) {
    for (int i = 1; i <= n; i++) {
      if (par[i][k - 1] != -1)
        par[i][k] = par[par[i][k - 1]][k - 1];
      else par[i][k] = -1;
    }
  }
}

int lca(int u, int v)
{
  if (depth[u] < depth[v]) swap(u, v);
  int dif = depth[u] - depth[v];
  for (int i = lg - 1; i >= 0; i--) {
    if (dif >= (1 << i)) {
      dif -= (1 << i);
      u = par[u][i];
    }
  }
  if (u == v) return u;
  for (int i = lg - 1; i >= 0; i--) {
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  }
  return par[v][0];
}

int dp[N];

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
  int n;
  cin >> n;
  vector<pair<int, int>> serial;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    serial.push_back({u, v});
  }
  for (int i = 1; i <= n; i++) dp[i] = 1;
  init(1, n);
  int m;
  cin >> m;
  vector<pair<pair<int, int>, int> > pot;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    pot.push_back({{u, v}, c});
    int w = lca(u, v);
    while (u != w) {
      dp[u] = max(dp[u], c);
      u = par[u][0];
    }
    while (v != w) {
      dp[v] = max(dp[v], c);
      v = par[v][0];
    }
  }

  bool flag = true;
  for (auto it : pot)
  {
    int u = it.first.first;
    int v = it.first.second;
    int c = it.second;
    int w = lca(u, v);
    int ret = inf;
    while (u != w) {
      ret = min(dp[u], ret);
      u = par[u][0];
    }
    while (v != w) {
      ret = min(dp[v], ret);
      v = par[v][0];
    }

    if (ret != c) flag  = false;
  }
  if (!flag) cout << "-1\n";
  else {
    for (auto it : serial) {
      if (par[it.first][0] == it.second)
        cout << dp[it.first] << " ";
      else cout << dp[it.second] << " ";
    }
  }
  return 0;
}