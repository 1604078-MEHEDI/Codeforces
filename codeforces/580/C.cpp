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
int n, m;
vector<int> graph[maxn];
int cat[maxn];
int deg[maxn];
bool vist[maxn];
int dist[maxn];
int ans = 0;

void dfs(int u, int cats)
{
  if (vist[u]) return;
  vist[u] = true;
  if (cat[u] == 0) cats = 0;
  cats += cat[u];
  if (cats > m) {
    cats--;
    return;
  }
  if (u != 1 && deg[u] == 1) {
    ans++;
    return;
  }
  for (auto v : graph[u]) {
    dfs(v, cats);
  }
}

void bfs(int s, int T)
{
  queue<int> Q;
  dbg(s, T);
  memset(vist, false, sizeof vist);
  memset(dist, 0, sizeof dist);
  Q.push(s);
  vist[s] = true;
  dist[s] = cat[s];
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (auto v : graph[u]) {
      if (vist[v] == false) {
        dbg(v, cat[v]);
        vist[v] = true;
        Q.push(v);
        if (cat[v])dist[v] =  cat[v] + dist[u];
        else dist[v] = 0;//max(dist[u], dist[v]);
        dbg(v, dist[v]);
        //if (dist[v] > m) return;
        if (v == T) {
          // dbg(s, v, dist[v]);
          if (dist[v] <= m) ans++;
          // dbg(ans);
          return;
        }
      }
    }
  }
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
  //scanf("%d", &T);
  T = 1;
  for (int cs = 1; cs <= T; cs++) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> cat[i];
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
      deg[u]++;
      deg[v]++;
    }
    memset(vist, false, sizeof vist);
    dfs(1, 0);
    // for (int i = 1; i <= n; i++) {
    //   if (deg[i] == 1 && i != 1) {
    //     bfs(1, i);
    //     cerr << "-----------------\n";
    //   }
    // }
    cout << ans << endl;
  }
  return 0;
}