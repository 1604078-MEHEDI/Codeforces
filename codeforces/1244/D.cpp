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

const int nx = 1e6 + 100;
int deg[nx];
int cost[nx][3];
vector<int> graph[nx];
vector<int> nodes;

void dfs(int u, int p)
{
  nodes.push_back(u);
  for (auto v : graph[u]) {
    if (v == p) continue;
    dfs(v, u);
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
    int n;
    cin >> n;
    for (int i = 0; i < 3; i++) {
      for (int j = 1; j <= n; j++)
        cin >> cost[j][i];
    }

    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
      deg[u]++;
      deg[v]++;
    }

    int leaf = -1;
    for (int i = 1; i <= n; i++) {
      if (deg[i] > 2) {
        cout << "-1\n";
        return 0;
      }
      if (deg[i] == 1) leaf = i;
    }

    dfs(leaf, -1);
    vector<int> p = {0, 1, 2};
    vector<int> ans;

    ll ret = 1e18;
    do {
      vector<int> cur_col(n + 1, 0);
      ll cur = 0;
      for (int i = 0; i < 3; i++) {
        for (int j = i; j < n; j += 3) {
          cur += cost[nodes[j]][p[i]];
          cur_col[nodes[j]] = p[i] + 1;
        }
      }
      if (ret > cur) {
        ret = cur;
        ans = cur_col;
      }
    } while (next_permutation(p.begin(), p.end()));

    cout << ret << endl;
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << " ";
    }
  }
  return 0;
}