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
int a[1001][1001];
int b[1001][1001];
bool ca[1001][1001];
bool cb[1001][1001];
bool va[1001];
bool vb[1001];
int x, y, m;
int maxDeg;

int dega[1001], degb[1001];

void adjust(int node, int side, int c1, int c2)
{
  if (side == 0) {
    va[node] = true;
    for (int i = 1; i <= y; i++) {
      if (vb[i]) continue;
      if (a[node][i] == c1) {
        a[node][i] = c2;
        b[i][node] = c2;

        ca[node][c2] = true;
        cb[i][c1] = false;
        cb[i][c2] = true;
        adjust(i, side ^ 1, c2, c1);
        break;
      }
    }
  }
  else {
    vb[node] = true;
    for (int i = 1; i <= x; i++) {
      if (va[i]) continue;
      if (b[node][i] == c1) {
        b[node][i] = c2;
        a[i][node] = c2;

        cb[node][c2] = true;
        ca[i][c1] = false;
        ca[i][c2] = true;

        adjust(i, side ^ 1, c2, c1);
        break;
      }
    }
  }
}

void addEdge(int u, int v)
{
  for (int i = 1; i <= maxDeg; i++) {
    if (ca[u][i] == false && cb[v][i] == false) {
      a[u][v] = i;
      b[v][u] = i;
      ca[u][i] = true;
      cb[v][i] = true;
      return;
    }
  }
  int c1 = 0, c2 = 0;
  for (int i = 1; i <= maxDeg; i++) {
    if (ca[u][i] == true && cb[v][i] == false) {
      c1 = i;
    }
    if (ca[u][i] == false && cb[v][i] == true) {
      c2 = i;
    }
  }

  a[u][v] = c2;
  b[v][u] = c2;
  ca[u][c2] = true;
  cb[v][c2] = true;

  memset(va, false, sizeof va);
  memset(vb, false, sizeof vb);
  va[u] = true;
  adjust(v, 1, c2, c1);
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
    memset(a, -1, sizeof a);
    memset(b, -1, sizeof b);

    cin >> x >> y >> m;
    vector<int> to, from;

    for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      to.push_back(u);
      from.push_back(v);
      ++dega[u];
      ++degb[v];
    }

    for (int i = 1; i <= x; i++) {
      maxDeg = max(maxDeg, dega[i]);
    }
    for (int i = 1; i <= y; i++) {
      maxDeg = max(maxDeg, degb[i]);
    }

    for (int i = 0; i < (int) to.size(); i++) {
      addEdge(to[i], from[i]);
    }
    cout << maxDeg << endl;
    for (int i = 0; i < (int)to.size(); i++) {
      cout << a[to[i]][from[i]] << " ";
    }
  }
  return 0;
}