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
int n, sum;
string s[maxn];
pair<ll, int> ar[maxn];

pair<ll, int> Hash(string str)
{
  ll ret  = 0, cnt = 1;
  for (auto ch : str) {
    ll x = ch - 'a';
    x++;
    ret += (x * cnt);
    cnt *= 31;
  }
  return {ret, str.size()};
}

vector<pair<int, int > > mat[maxn];
int dp[maxn][maxn];

int solve()
{
  for (int pos = 0; pos < n; pos++) {
    for (auto x : mat[pos])
      for (int i = 0; i < n; i++) {
        if (!i) dp[pos][i + 1] = max(dp[pos][i + 1], x.second);
        else dp[pos][i + 1] = max(dp[pos][i + 1], min(dp[x.first][i], x.second));
      }
  }

  int ret = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++)
      ret = max(ret, dp[i][j] * (j + 1));
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
    cin >> n;
    sum = n - 1;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      ar[i] = Hash(s[i]);
      //cerr << ar[i].first << " " << ar[i].second << endl;
      sum += ar[i].second;
    }

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int x = i, y = j, z = 0;
        while (x < j && y < n) {
          if (s[x] == s[y]) {
            if (x != i) z++;
            z += (ar[x].second - 1);
          }
          else break;

          x++;
          y++;
        }
       // cerr << j << " --> {" <<i << " , "<<j << "} " << s[i] << " " << s[j] << endl; 
        mat[j].push_back({i, z});
      }
    }
    cout << sum - solve() << endl;
  }

  //double end_time = clock();
  //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
  return 0;
}