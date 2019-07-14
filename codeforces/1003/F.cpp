#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 305
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

bool eq[maxn][maxn];
int dp[maxn][maxn];
string s[maxn];

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
    int n;
    cin >> n;
    int allSum = n - 1;

    for (int i = 0; i < n ; i++) {
      cin >> s[i];
      allSum += (int)s[i].size();
    }

    for (int i = 0; i < n; i++) {
      eq[i][i] = true;
      for (int j = 0; j < i; j++) {
        eq[i][j] = eq[j][i] = (s[i] == s[j]);
      }
    }

    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (eq[i][j]) {
          if (i + 1 < n && j + 1 < n)
            dp[i][j] = dp[i + 1][j + 1] + 1;
          else dp[i][j] = 1;
        }
      }
    }

    int ans = allSum;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = 0; i + j < n; j++) {
        sum += s[i + j].size();
        int cnt = 1;
        for (int pos = i + j + 1; pos < n; pos++) {
          if (dp[i][pos] > j) {
            cnt++;
            pos += j;
          }
        }
        int cur = allSum - sum * cnt + (j + 1) * cnt - j * cnt;
        if (cnt > 1 && ans > cur) {
          ans = cur;
        }
      }
    }
    cout << ans << endl;
  }

  //double end_time = clock();
  //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
  return 0;
}