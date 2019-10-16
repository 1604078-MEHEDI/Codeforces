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

const int N = 200200;
ll BIT[N];
const int K = 18;

void update(int idx, ll val)
{
  for (; idx < N; idx += (idx & -idx))
    BIT[idx] = max(BIT[idx], val);
}

struct frog
{
  ll l, r, id, cnt;
};

int find(int idx, ll x)
{
  int cur = 0;
  for (int i = K - 1; i >= 0; i--) {
    if (cur + (1 << i) > idx) continue;
    if (BIT[cur + (1 << i)] >= x) continue;
    cur += (1 << i);
  }
  if (cur + 1 > idx) return -1;
  return cur + 1;
}

frog frogs[N];
ll ans[N], fr[N];

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
  memset(BIT, -1, sizeof BIT);

  for (int i = 1; i <= n; i++) {
    frogs[i].id = i;
    frogs[i].cnt = 0;
    cin >> frogs[i].l >> frogs[i].r;
    frogs[i].r += frogs[i].l;
  }
  
  sort(frogs + 1, frogs + n + 1, [](frog a, frog b) {return a.l < b.l;});
  // for (int i = 1; i <= n; i++) {
  //   dbg(frogs[i].l, frogs[i].r);
  // }

  for (int i = 1; i <= n; i++) {

    update(i, frogs[i].r);
  }

  multiset<pair<ll, ll>> st;

  while (q--) {
    ll x, v;
    cin >> x >> v;

    frog dummy = {x, 0, 0, 0};
    int idx = upper_bound(frogs + 1, frogs + n + 1, dummy, [](frog a, frog b) {return a.l < b.l;}) - frogs;
    idx--;
    int f = find(idx, x);

    if (f == -1) {
      st.insert({x, v});
      continue;
    }

    frogs[f].r += v;
    frogs[f].cnt++;

    while (true) {
      auto it = st.lower_bound({frogs[f].l, -1});
      if (it == st.end() || it->first > frogs[f].r) break;
      frogs[f].r += it->second;
      frogs[f].cnt++;
      st.erase(it);
    }
    update(f, frogs[f].r);
  }

  for (int i = 1; i <= n; i++) {
    ans[frogs[i].id] = frogs[i].r - frogs[i].l;
    fr[frogs[i].id] = frogs[i].cnt;
  }

  for (int i = 1; i <= n; i++)
    cout << fr[i] << " " << ans[i] << endl;


  return 0;
}