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

vector<int> graph[maxn];
vector<int> ord;
bool visit[maxn];
int cnt;
bool flag;

void dfs(int u)
{
  visit[u] = true;
  for (auto v : graph[u]) {
    if (!visit[v]) dfs(v);
  }
  if (flag)
    ord.push_back(u);
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
    flag = true;
    for (int i = 1; i <= n; i++) {
      if (!visit[i]) dfs(i);
    }
    memset(visit, false, sizeof visit);
    flag = false;
    dfs(s);
    reverse(ord.begin(), ord.end());

    int ans = 0;
    for (int i = 0; i < (int) ord.size(); i++) {
      int x = ord[i];
      if (!visit[x])
        ans++;
      dfs(x);
    }
    cout << ans << endl;
  }

  //double end_time = clock();
  //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
  return 0;
}