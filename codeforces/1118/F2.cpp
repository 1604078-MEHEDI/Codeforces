/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
//const ll mod = 1e9 + 7;
const ll mod = 998244353;


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

int dx[]  = {0, 0, 1, -1};
int dy[]  = {1, -1, 0, 0};
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
const int N = 300006;
const int LG = 19;

int a[N];
vector<int>g[N];
int up[N][LG];
int d[N];

void init(int u, int p = -1)
{
  for (auto v : g[u]) {
    if (v == p)continue;
    up[v][0] = u;
    for (int i = 1; i < LG; i++) {
      up[v][i] = up[up[v][i - 1]][i - 1];
    }
    d[v] = d[u] + 1;
    init(v, u);
  }
}

int lca(int v, int u)
{
  if (d[v] < d[u])swap(v, u);
  for (int i = LG - 1; i >= 0; i--)
    if (d[up[v][i]] >= d[u])
      v = up[v][i];
  if (v == u)return v;

  for (int i = LG - 1; i >= 0; i--) {
    if (up[v][i] != up[u][i]) {
      v = up[v][i];
      u = up[u][i];
    }
  }
  return up[v][0];
}

int l[N];
ll dp[N][2];

ll dfs(int v, int p = -1)
{
  vector<pair<int, int>> cur;
  for (auto u : g[v]) {
    if (u == p)continue;
    int c = dfs(u, v);
    if (c != 0)
      cur.push_back({c, u});
  }

  vector<int> vals;
  for (auto it : cur) {
    if (it.first > 0) {
      vals.push_back(it.first);
    }
  }

  sort(vals.begin(), vals.end());
  vals.resize(unique(vals.begin(), vals.end()) - vals.begin());

  if ((int)vals.size() > 1) {
    cout << "0\n";
    exit(0);
  }

  if (a[v] != 0 && !vals.empty() && vals[0] != a[v]) {
    cout << "0\n";
    exit(0);
  }

  if (a[v] == 0 && cur.empty()) return 0;

  if (a[v] == 0 && vals.empty()) {
    vector<int> pr(1, 1), su(1, 1);
    for (auto it : cur) {
      pr.push_back(modMul(pr.back(), modAdd(dp[it.second][0], dp[it.second][1])));
    }

    for (int i = int(cur.size()) - 1; i >= 0; --i) {
      su.push_back(modMul(su.back(), modAdd(dp[cur[i].second][0], dp[cur[i].second][1])));
    }

    reverse(su.begin(), su.end());
    dp[v][1] = 0;

    for (int i = 0; i < (int)cur.size(); i++) {
      dp[v][1] = modAdd(dp[v][1], modMul(modMul(pr[i], su[i + 1]), dp[cur[i].second][1]));
    }

    dp[v][0] = modAdd(dp[v][0], pr[cur.size()]);
    return -1;
  }
  dp[v][1] = 1;
  for (auto it : cur) {
    if (it.first == -1)
      dp[v][1] = modMul(dp[v][1], modAdd(dp[it.second][0], dp[it.second][1]));
    else
      dp[v][1] = modMul(dp[v][1], dp[it.second][1]);
  }
  if (a[v] == 0)return vals[0];
  return (l[a[v]] == v ? -1 : a[v]);
}

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
  int T;
  T = 1;
  //scanf("%d", &T);
  for (int cs = 1; cs <= T; cs++) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 1; i < n; i++) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }

    init(0);
    memset(l, -1, sizeof l);

    for (int i = 0; i < n; i++) {
      if (a[i])
        l[a[i]] = (l[a[i]] == -1 ? i : lca(l[a[i]], i));
    }

    for (int i = 1; i <= k; i++) {
      if (a[l[i]] != 0 && a[l[i]] != i) {
        cout << 0 << "\n";
        return 0;
      }
      a[l[i]] = i;
    }

    dfs(0);
    cout << dp[0][1] << "\n";
  }
  return 0;
}