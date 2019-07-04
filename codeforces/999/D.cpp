// upsolve
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
    int n, m;
    cin >> n >> m;
    int k = n / m;
    vector<int> v(n);
    vector<vector<int> > val(m);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      val[v[i] % m].push_back(i);
    }

    ll ans = 0;
    vector<pair<int, int> > fre;

    for (int i = 0; i < 2 * m; i++) {
      int cur = i % m;
      while ((int)val[cur].size() > k) {
        int x = val[cur].back();
        val[cur].pop_back();
        fre.push_back({x, i});
      }

      while ((int) val[cur].size() < k && !fre.empty())
      {
        int x = fre.back().first;
        int mod = fre.back().second;

        fre.pop_back();
        val[cur].push_back(x);
        v[x] += i - mod;
        ans += i - mod;
      }
    }
    cout << ans << endl;
    for (auto x : v) cout << x << " ";
    cout << endl;
  }

  //double end_time = clock();
  //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
  return 0;
}