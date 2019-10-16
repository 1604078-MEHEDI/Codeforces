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

typedef pair<ll, int> pli;
const int N = 200200;
int n, m;
ll a[N];
ll x[N];
int cnt[N];
ll pos[N];
ll b[N];
set <pli> c, d, e;

void tryErase(int id)
{
  if (c.find({x[id], id}) == c.end())return;
  while (true) {
    auto it = c.lower_bound({x[id] + 1, -1});
    if (it == c.end()) break;
    int p = it->second;
    if (x[id] + a[id] < x[p] + a[p]) break;
    c.erase(it);
    d.erase({x[p] + a[p], p});
  }
}

void Read()
{
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &x[i], &a[i]);
    c.insert({x[i], i});
    d.insert({x[i] + a[i], i});
  }
  for (int i = 0; i < n; i++)
    tryErase(i);
  return;
}

void tryEat(int id)
{
  while (true) {
    auto it = e.lower_bound({x[id] + a[id] + 1, -1});
    if (it == e.begin()) break;
    it--;
    if (it->first < x[id]) break;
    a[id] += b[it->second];
    cnt[id]++;
    e.erase(it);
  }
  return;
}


int main()
{
  Read();
  for (int i = 0; i < m; i++) {
    scanf("%lld %lld", &pos[i], &b[i]);
    auto it = d.lower_bound({pos[i], -1});
    if (it == d.end() || x[it->second] > pos[i]) {
      e.insert({pos[i], i});
      continue;
    }

    int id = it->second;
    d.erase({x[id] + a[id], id});
    a[id] += b[i];
    cnt[id]++;
    tryEat(id);
    d.insert({x[id] + a[id], id});
    tryErase(id);
  }
  for (int i = 0; i < n; i++) {
    printf("%d %lld\n", cnt[i], a[i]);
  }
  return 0;
}