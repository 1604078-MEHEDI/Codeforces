#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 1005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;


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
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int> >graph(n);
    vector<int> a(m), b(m);

    for (int i = 0; i < m; i++) {
      cin >> a[i] >> b[i];
      --a[i];
      --b[i];
      graph[a[i]].push_back(b[i]);
      graph[b[i]].push_back(a[i]);
    }

    queue<int > Q;
    Q.push(0);
    vector<int > dist(n, INT_MAX);
    dist[0] = 0;

    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      for (auto v : graph[u]) {
        if (dist[v] == INT_MAX) {
          dist[v] = dist[u] + 1;
          Q.push(v);
        }
      }
    }

    vector < vector<int > > inc(n);

    for (int i = 0; i < m; i++) {
      if (dist[a[i]] + 1 == dist[b[i]]) inc[b[i]].push_back(i);
      if (dist[b[i]] + 1 == dist[a[i]]) inc[a[i]].push_back(i);
    }

    vector<int > f(n);
    vector<string > ans;

    for (int i = 0; i < k; i++) {
      string s(m, '0');
      for (int l = 1; l < n; l++) {
        s[inc[l][f[l]]] = '1';
      }
      ans.push_back(s);

      bool ok = false;

      for (int l = 1; l < n; l++) {
        if (f[l] + 1 < (int)inc[l].size()) {
          ok = true;
          f[l]++;
          break;
        }
        else f[l] = 0;
      }
      if (!ok) break;
    }

    cout << ans.size() << endl;
    for (auto x : ans) cout << x << endl;
  }

  //double end_time = clock();
  //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
  return 0;
}