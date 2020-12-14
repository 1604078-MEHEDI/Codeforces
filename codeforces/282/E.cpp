#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 100005
#define tc printf("Case %d: ", cs)
#define tcn printf("Case %d:\n", cs);
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);

#define dbg1(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define dbg4(w,x, y, z) cerr << #w << " = " << w << ", " <<#x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

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

/**___________________________________________________**/

bool Check(ll num, ll pos) {
  return (bool) (num & (1ll << pos));
}

ll id = 1;
ll Trie[50 * maxn + 5][2], mark[50 * maxn + 5];

void Insert(ll x) {
  //dbg(id);
  ll cur = 1;
  for (ll i = 49; i >= 0; i--) {
     ll nxt = (x >> i) & 1ll;
    if (!Trie[cur][nxt]) Trie[cur][nxt] = ++id;
    cur = Trie[cur][nxt];
  }
}

ll Search(ll x)
{
  ll cur = 1, val = 0;
  for (ll i = 49; i >= 0; i--) {
    ll nxt = (x >> i) & 1ll;
    if (Trie[cur][1 - nxt]) {
      val += (1ll << i);
      cur = Trie[cur][1 - nxt];
    }
    else cur = Trie[cur][nxt];

  }
  return val;
}



ll n;
ll a, Pref[maxn];

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
  //scanf("%d", &T);
  T = 1;
  for (int cs = 1; cs <= T; cs++) {
    cin >> n;
    ll X = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a;
      X ^= a;
      Pref[i] = X;
    }

    ll ans = X;
    Insert(0);
    for (int i = 1; i <= n; i++) {
      ll got = X ^ Pref[i];
      ll val = Search(got);
      ans = max(ans, val);
      Insert(Pref[i]);
    }
    cout << ans << endl;
  }
  return 0;
}