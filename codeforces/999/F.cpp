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

const int N = 520;
const int K = 12;
const int C = 100 * 1000 + 11;

int n, k;
int c[C];
int f[C];
vector<int> h;

int dp[N][520 * 12];

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
    cin >> n >> k;
    h = vector<int> (k + 1);
    for (int i = 0; i < n * k; i++) {
      int x;
      cin >> x;
      ++c[x];
    }

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      f[x]++;
    }

    for (int i = 1; i <= k; i++) cin >> h[i];

    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= n * k; j++) {
        for (int x = 0; x <=  k; x++) {
          dp[i + 1][j + x] = max(dp[i + 1][j + x], dp[i][j] + h[x]);
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < C; i++) {
      if (f[i]) ans += dp[f[i]][c[i]];
    }
    cout << ans << endl;
  }

  //double end_time = clock();
  //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
  return 0;
}