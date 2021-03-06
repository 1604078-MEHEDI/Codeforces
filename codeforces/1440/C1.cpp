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
const int N = 106;

int a[N][N];
vector<pii> ans;
int n, m;

void print() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cerr << a[i][j];
    }
    cerr << "\n";
  }

  cerr << "\n";
}

int Count(int i, int j) {
  int ret = a[i][1] + a[i][2] + a[j][1] + a[j][2];
  return ret;
}
void Three(int i, int j) {
  if (a[i][1])ans.push_back({i, 1});
  if (a[i][2])ans.push_back({i, 2});
  if (a[j][1])ans.push_back({j, 1});
  if (a[j][2])ans.push_back({j, 2});
  a[i][1] = a[i][2]  = a[j][1]  = a[j][2] = 0;
}

void Two(int i, int j) {
  int r = 0, c = 0;
  //dbg(Count(i,j));
  bool flag = true;
  if (a[i][1]) {
    if (flag) {
      flag = false;
      ans.push_back({i, 1});
      r = i; c = 1;
      // dbg(r, c);
    }
  }
  else if (a[i][2]) {
    if (flag) {
      flag = false;
      ans.push_back({i, 2});
      r = i; c = 2;
      // dbg(r, c);
    }

  }
  else if (a[j][1]) {
    if (flag) {
      flag = false;
      ans.push_back({j, 1});
      r = j; c = 1;
      // dbg(r, c);
    }

  }
  else if (a[j][2]) {
    if (flag) {
      flag = false;
      ans.push_back({j, 2});
      r = j; c = 2;
      // dbg(r, c);
    }
  }
  // dbg(r, c);
  if (!a[i][1])ans.push_back({i, 1}), a[i][1] = 1;
  if (!a[i][2])ans.push_back({i, 2}), a[i][2] = 1;
  if (!a[j][1])ans.push_back({j, 1}), a[j][1] = 1;
  if (!a[j][2])ans.push_back({j, 2}), a[j][2] = 1;
  // print();
  a[r][c] = 0;
  // print();
  // dbg(Count(i, j));
  assert(Count(i, j) == 3);
  Three(i, j);
}

void One(int i, int j) {
  int zero = 0;
  int r, c;

  if (a[i][1])ans.push_back({i, 1}), r = i, c = 1;
  if (a[i][2])ans.push_back({i, 2}), r = i, c = 2;
  if (a[j][1])ans.push_back({j, 1}), r = j, c = 1;
  if (a[j][2])ans.push_back({j, 2}), r = j, c = 2;

  if (!a[i][1] && zero < 2) {
    zero++;
    a[i][1] = 1;
    ans.push_back({i, 1});
  }
  if (!a[i][2] && zero < 2) {
    zero++;
    a[i][2]  = 1;
    ans.push_back({i, 2});

  }
  if (!a[j][1] && zero < 2) {
    zero++;
    ans.push_back({j, 1});
    a[j][1]  = 1;
  }
  if (!a[j][2] && zero < 2) {
    zero++;
    ans.push_back({j, 2});
    a[j][2] = 1;
  }
  a[r][c] = 0;
  assert(Count(i, j) == 2);
  Two(i, j);
}

void Four(int i, int j) {
  ans.push_back({i, 1});
  ans.push_back({i, 2});
  ans.push_back({j, 1});
  a[i][1] = a[i][2]  = a[j][1] = 0;
  One(i, j);
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
  cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    //int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        char ch;
        cin >> ch;
        a[i][j] = ch - '0';
      }
    }

    // print();

    for (int j = m; j > 2; j--) {
      for (int i = 1; i <= n; i++) {

        if (i == 1) {
          if (a[i][j] == 1) {
            ans.push_back({i, j});
            ans.push_back({i, j - 1});
            ans.push_back({i + 1, j - 1});
            a[i][j] = 1 - a[i][j];
            a[i][j - 1] = 1 - a[i][j - 1];
            a[i + 1][j - 1] = 1 - a[i + 1][j - 1];
          }
        }
        else {
          if (a[i][j] == 1) {
            ans.push_back({i, j});
            ans.push_back({i, j - 1});
            ans.push_back({i - 1, j - 1});
            a[i][j] = 1 - a[i][j];
            a[i][j - 1] = 1 - a[i][j - 1];
            a[i - 1][j - 1] = 1 - a[i - 1][j - 1];
          }
        }

      }
    }

    // print();

    if (n & 1) {
      if (a[n][1] == 1) {
        ans.push_back({n, 1});
        ans.push_back({n - 1, 1});
        ans.push_back({n - 1, 2});
        a[n][1] = 1 - a[n][1];
        a[n - 1][1] = 1 - a[n - 1][1];
        a[n - 1][2] = 1 - a[n - 1][2];
      }
      if (a[n][2]) {
        ans.push_back({n, 2});
        ans.push_back({n - 1, 1});
        ans.push_back({n - 1, 2});
        a[n][2] = 1 - a[n][2];
        a[n - 1][1] = 1 - a[n - 1][1];
        a[n - 1][2] = 1 - a[n - 1][2];
      }
      n--;
    }

    // print();

    for (int i = 1; i <= n; i += 2) {
      int cnt = Count(i, i + 1);
      if (cnt == 4)Four(i, i + 1);
      else if (cnt == 3) Three(i, i + 1);
      else if (cnt == 2) Two(i, i + 1);
      else if (cnt == 1)One(i, i + 1);
    }
    // print();
    int sz = (int)ans.size();
    cout << sz / 3 << "\n";
    int cnt = 0;
    for (int i = 0; i < sz; i++) {
      cout << ans[i].first << " " << ans[i].second;
      //// cout << ans[i + 1].first << " " << ans[i + 1].second << " ";
      //cout << ans[i + 2].first << " " << ans[i + 2].second << "\n";
      cnt++;
      if (cnt % 3)cout << " ";
      else cout << "\n";
    }
    ans.clear();
    //print();
  }
  return 0;
}