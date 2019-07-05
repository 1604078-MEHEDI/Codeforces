#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 100005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

vector<int> graph[maxn];
bool visit[maxn];
bool ok[maxn];
int cnt;
void dfs(int u)
{
  //cerr << u << endl;
  cnt++;
  visit[u] = true;
  for (auto v : graph[u]) {
    if (!visit[v] && !ok[v]) dfs(v);
  }
}

void dfs1(int u)
{
  ok[u] = true;
  for (auto v : graph[u]) {
    if (!ok[v]) dfs1(v);
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
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
    }
    dfs1(s);
    //cout << (n - cnt)<<endl;
    //cerr <<n - cnt<< " "<<cnt<<endl;
    vector<pair<int, int> > v;
    for (int i = 1; i <= n; i++) {
      if (!ok[i]) {
        cnt = 0;
        memset(visit, false, sizeof visit);
        dfs(i);
        v.push_back({cnt, i});
      }
    }
    sort(v.rbegin(), v.rend());

    int ans = 0;
    for (auto x : v) {
      if (!ok[x.second]) {
        ans++;
        dfs1(x.second);
      }
    }
    cout << ans << endl;
  }

  //double end_time = clock();
  //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
  return 0;
}