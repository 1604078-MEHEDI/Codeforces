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
const int N = 350001;


/*
https://codeforces.com/contest/452/problem/E

minimum length string dhore, every length er koyta kore string 3ta string ei ase sheita mod kore print korte hobe.

abc
bc
cbc

output:
3 (b er 1ta & c er 2ta)
1 (bc er 1ta)
*/

int P[25][N], n, stp, cnt;
char a[N], cc;

struct Info
{
  int nr[2], p;
  bool operator < (const Info &b) const {
    return nr[0] == b.nr[0] ? (nr[1] < b.nr[1]) : (nr[0] < b.nr[0]);
  }
} L[N];

void SuffixArray() {
  for (int i = 0; i < n; i++)P[0][i] = a[i] - 'a';
  for (stp = 1, cnt = 1; cnt >> 1 < n; ++stp, cnt <<= 1) {
    for (int i = 0; i < n; i++) {
      L[i].nr[0] = P[stp - 1][i];
      L[i].nr[1] = i + cnt < n ? P[stp - 1][i + cnt] : -1;
      L[i].p = i;
    }
    sort(L, L + n);
    for (int i = 0; i < n; i++)
      P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
  }
}

int lcp(int x, int y) {
  int k, ret = 0 ;
  if (x == y) return n - x;
  for (k = stp - 1; k >= 0 && x < n && y < n; k--)
    if (P[k][x] == P[k][y]) {
      x += (1 << k);
      y += (1 << k);
      ret += (1 << k);
    }
  return ret;
}

char ss[3][N];
int LCP[N], seg[1230001];

void Insert(int idx, int s, int e, int p, int v) {
  if (s == e) {
    seg[idx] = v;
    return;
  }
  int mid = (s + e) >> 1;
  if (p <= mid) Insert(idx * 2 + 1, s, mid, p, v);
  else Insert(idx * 2 + 2, mid + 1, e, p, v);
  seg[idx] = min(seg[idx * 2 + 1], seg[idx * 2 + 2]);
}

int Query(int idx, int s, int e, int st, int ed) {
  if (s == st && e == ed) return seg[idx];
  int mid = (s + e) >> 1;
  if (ed <= mid)return Query(idx * 2 + 1, s, mid, st, ed);
  else if (st > mid)return Query(idx * 2 + 2, mid + 1, e, st, ed);
  else {
    int aa = Query(idx * 2 + 1, s, mid, st, mid);
    int b = Query(idx * 2 + 2, mid + 1, e, mid + 1, ed);
    return min(aa, b);
  }
}

int QueryPrime(int idx, int s, int e, int st, int ed, int v) {
  if (seg[idx] > v) return n;
  if (s == e) return s;
  int mid = (s + e) >> 1;
  if (ed <= mid)return QueryPrime(idx * 2 + 1, s, mid, st, ed, v);
  else if (st > mid)return QueryPrime(idx * 2 + 2, mid + 1, e, st, ed, v);
  else {
    int aa = QueryPrime(idx * 2 + 1, s, mid, st, mid, v);
    if (aa < n) return aa;
    return QueryPrime(idx * 2 + 2, mid + 1, e, mid + 1, ed, v);
  }
}

ll dp[N], cn[3][N];

void go(int l, int r, int m) {
  if ((r - l + 1) < 3) return;
  int v = Query(0, 1, n - 1, l + 1, r);
  int p = QueryPrime(0, 1, n - 1, l + 1, r, v);

  ll aa = (cn[0][r] - cn[0][l - 1]) * (cn[1][r] - cn[1][l - 1]) * (cn[2][r] - cn[2][l - 1]);
  dp[m + 1] += aa;
  dp[v + 1] -= aa;

  go(l, p - 1, v);
  while (p < r) {
    int b = QueryPrime(0, 1, n - 1, p + 1, r, v);
    if (b > r) { go(p, r, v); return;}
    else {
      go(p, b - 1, v);
      p = b;
    }
  }
}

//

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
  cin >> ss[0] >> ss[1] >> ss[2];
  n = 0;
  for (int i = 0; i < 3; i++) {
    int ln = strlen(ss[i]);
    for (int j = 0; j < ln; j++)
      a[n++] = ss[i][j];
    if (i == 0)a[n++] = '#';
    if (i == 1) a[n++] = '?';
  }
  SuffixArray();
  int aa = 0;
  int b = strlen(ss[0]) + 1;
  int c = b + strlen(ss[1]) + 1;
  for (int i = 1; i < n; i++) {
    LCP[i] = lcp(L[i].p, L[i - 1].p);
    if (L[i].p >= aa && L[i].p < b)cn[0][i]++;
    if (L[i].p >= b && L[i].p < c)cn[1][i]++;
    if (L[i].p >= c)cn[2][i]++;
    Insert(0, 1, n - 1, i, LCP[i]);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 3; j++)
      cn[j][i] += cn[j][i - 1];

  go(1, n - 1, 0);
  for (int i = 1; i < n; i++)dp[i] = modAdd(dp[i], dp[i - 1]);
  int ln = N;
  for (int i =  0; i < 3; i++)ln = min(ln, (int)strlen(ss[i]));
  for (int i = 1; i <= ln; i++)cout << dp[i] << " ";
  cout << "\n";
  return 0;
}