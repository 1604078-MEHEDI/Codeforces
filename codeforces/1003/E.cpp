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
int n, d, k;
bool flag = false;
int cnt = 1;
vector<pair<int, int > > ans;

int ok(int v, int l)
{
  if (v == n) {
    flag = true;
    return 0;
  }

  int diameter = l;
  int ret = 0;

  for (int i = 1; i <= k - 1 + ((v == 1) ? 1 : 0) && !flag && diameter < d; i++) {
    if (diameter < d) {
      cnt++;
      ans.push_back({v, cnt});
      ret = max(ret, 1 + ok(cnt, diameter + 1));
      diameter = max(diameter, ret);
    }
  }
  return ret;
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
    cin >> n >> d >> k;
    ok(1, 0);

   // cerr << flag << endl;
    if (!flag || d >= n) {
      cout << "NO\n";
      return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < (int)ans.size(); i++) {
      cout << ans[i].first << " " << ans[i].second << endl;
    }

  }

  //double end_time = clock();
  //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
  return 0;
}