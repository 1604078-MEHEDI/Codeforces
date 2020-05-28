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
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define dbg4(w,x, y, z) cerr << #w << " = " << w << ", " <<#x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
typedef pair<ll, ll> pl;
typedef vector<pl> vpl;

struct data
{
  ll weight;
  int start, last, idx;
  data(ll w, int s, int l, int I)
  {
    weight = w;
    start = s;
    last = l;
    idx = I;
  }
  bool operator<(data other)const
  {
    return weight > other.weight;
  }
};

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
    vector<vpl>graph(n);
    for (int i = 0; i < m; i++) {
      ll u, v, w;
      cin >> u >> v >> w;
      u--;
      v--;
      graph[u].push_back({w, v});
      graph[v].push_back({w, u});
    }
    for (int i = 0; i < n; i++) {
      sort(graph[i].begin(), graph[i].end());
    }

    priority_queue<data> PQ;//w, edge_idx, next-to-last
    k *= 2;

    set<pl>visited;
    for (int i = 0; i < n; i++) {
      PQ.push(data(graph[i][0].first, i, i, 0));
      visited.insert({i, i});
    }
    while (!PQ.empty()) {
      data cur = PQ.top();
      PQ.pop();
      int nxt = graph[cur.last][cur.idx].second;
      if (!visited.count({cur.start, nxt})) {
        visited.insert({cur.start, nxt});
        k--;
        if (k == 0) {
          cout << cur.weight << endl;
          return 0;
        }
        PQ.push(data(cur.weight + graph[nxt][0].first, cur.start, nxt, 0));
      }
      if (cur.idx + 1 < (int)graph[cur.last].size()) {
        PQ.push(data(cur.weight - graph[cur.last][cur.idx].first + graph[cur.last][cur.idx + 1].first, cur.start, cur.last, cur.idx + 1));
      }
    }
  }

  //double end_time = clock();
  //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
  return 0;
}