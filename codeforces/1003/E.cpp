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
    int n, d, k;
    cin >> n >> d >> k;
    if (d >= n) {
      cout << "NO\n";
      return 0;
    }

    vector<int> deg(n);
    vector<pair<int, int > > ans;

    set<pair<int, int > > Q;

    for (int i = 0; i < d; i++) {
      ++deg[i];
      ++deg[i + 1];

      if (deg[i] > k || deg[i + 1] > k) {
        cout << "NO\n";
        return 0;
      }
      ans.push_back({i, i + 1});
    }

    for (int i = 1; i < d; i++) {
      Q.insert({max(i, d - i), i});
    }

    for (int i = d + 1; i < n; i++) {
      while (!Q.empty() && deg[Q.begin()->second] == k)
        Q.erase(Q.begin());

      if (Q.empty() || Q.begin()->first == d) {
        cout << "NO\n";
        return 0;
      }

      ++deg[i];
      ++deg[Q.begin()->second];
      ans.push_back({i, Q.begin()->second});
      Q.insert({Q.begin()->first + 1, i});
    }
    assert(int(ans.size()) == n - 1);
    cout << "YES\n";
    vector<int > v(n);
    for (int i = 0; i < n; i++) v[i] = i;

    random_shuffle(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++) {
      if (rand() % 2) cout << v[ans[i].first] + 1 << " " << v[ans[i].second] + 1 << endl;
      else cout << v[ans[i].second] + 1 << " " << v[ans[i].first] + 1 << endl;
    }
  }

  //double end_time = clock();
  //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
  return 0;
}