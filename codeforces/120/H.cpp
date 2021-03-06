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
const int N = 400006;
vector<int> g[N];//, Tree[N];
int n, m, match[N], dist[N];

bool bfs() {
  queue<int> Q;
  for (int i = 1; i <= n; i++) {
    if (match[i] == 0) {
      dist[i] = 0;
      Q.push(i);
    }
    else dist[i] = INT_MAX;
  }
  dist[0] = INT_MAX;

  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    if (u != 0) {
      for (auto v : g[u]) {
        if (dist[match[v]] == INT_MAX) {
          dist[match[v]] = dist[u] + 1;
          Q.push(match[v]);
        }
      }
    }
  }
  return (dist[0] != INT_MAX);
}

bool dfs(int u) {
  if (u != 0) {
    for (auto v : g[u]) {
      if (dist[match[v]] == dist[u] + 1) {
        if (dfs(match[v])) {
          match[v] = u;
          match[u] = v;
          return true;
        }
      }
    }
    dist[u] = INT_MAX;
    return false;
  }
  return true;
}


// multiple test case somoy match[] clear korte hobe ):
int hopcroft_karp_max_match() {
  int matching = 0;
  while (bfs()) {
    for (int i = 1; i <= n; i++)
      if (match[i] == 0 && dfs(i))
        matching++;
  }
  return matching;
}

void go(int v, int u) {
// dbg(n);
 // dbg(u, v + n);
  g[u].push_back(v + n);
  g[v + n].push_back(u);
  //dbg(n);
}

unordered_map<string, int>mp;
unordered_map<int, string>pm;
int id;//, n;
string str;


void val(string s)
{
  if (mp.count(s)) return;// mp[s];
  ///dbg(s);
  mp[s] = ++id;
  pm[n + id] = s;
  return;// id;
}

void rec(int pos, string s, int l) {
  if (pos == (int)str.size()) {
    if (s.empty())return;
    // if (mp[s] == 0) {
    //   mp[s] = ++id;
    //   pm[id] = s;
    // }
    val(s);
    go(mp[s], l);
    return;
  }
  if ((int)s.size() < 4)rec(pos + 1, s + str[pos], l);
  rec(pos + 1, s, l);
}

void calc(string S, int i) {
  int l = S.size();
  for (int j = 1; j < 1 << l ; j ++ ) {
    string st;
    for (int k = 0; k < l ; k ++ ) {
      if (j & 1 << k) {
        st.push_back(S[k]);
      }
    }
    if (st.size() <= 4 && st.size() > 0) {
      // G[i].push_back(val(st));
      val(st);
      go(mp[st], i);
    }
  }
}







int main()
{
  FASTIO
  /*
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  //*/

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> str;
    // dbg(str);
    calc(str, i);
    //  rec(0, "", i);
  }
  //dbg(id);
  int ans = hopcroft_karp_max_match();
  //dbg(ans);
// for (auto &x : mp)dbg(x);
  if (ans == n) {
    for (int i = 1; i <= n; i++) {
      int idx = match[i];
      //dbg(idx,pm[idx]);
      cout << pm[idx] << "\n";
    }
  }
  else cout << "-1\n";
}