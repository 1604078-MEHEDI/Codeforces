#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 5005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

vector<int> graph1[maxn];
vector<int> graph2[maxn];
vector<int> graph3[maxn];
vector<int> ord;
int indeg[maxn];
bool visit[maxn];
bool ok[maxn];
int comp[maxn];
int cnt;

void dfs1(int u)
{
  visit[u] = true;
  for (auto v : graph1[u]) {
    if (!visit[v]) dfs1(v);
  }
  ord.push_back(u);
}

void dfs2(int u)
{
  comp[u] = cnt;
  for (auto v : graph2[u]) {
    if (comp[v] == -1) dfs2(v);
  }
}

void dfs3(int u)
{
  //cerr << u << endl;
  ok[u] = true;
  for (auto v : graph3[u]) {
    if (!ok[v]) dfs3(v);
  }
}

int main()
{
  FASTIO
  ///*
  //double start_time = clock();
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
//*/
  int T;
  //cin >> T;
  T = 1;
  for (int cs = 1; cs <= T; cs++) {
    int n, m, s;
    cin >> n >> m >> s;
    --s;
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      --u;
      --v;
      graph1[u].push_back(v);
      graph2[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
      if (!visit[i]) dfs1(i);
    }

    reverse(ord.begin(), ord.end());
    memset(comp, -1, sizeof(comp));
    for (int i = 0; i < n; ++i) {
      if (comp[ord[i]] == -1) {
        dfs2(ord[i]);
        ++cnt;
      }
    }

    for (int v  = 0; v < n; v++) {
      for (auto to : graph1[v]) {
        if (comp[v] != comp[to]) {
          graph3[comp[v]].push_back(comp[to]);
          indeg[comp[to]]++;
        }
      }
    }
    dfs3(comp[s]);
    int ans = 0;
    for (int i = 0; i < cnt; i++) {
      if (!ok[i] && indeg[i] == 0)
        ans++;
    }
    cout << ans << endl;
  }

  //double end_time = clock();
  //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
  return 0;
}