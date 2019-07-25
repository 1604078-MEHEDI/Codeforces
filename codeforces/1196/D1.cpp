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
#define dbg4(w,x, y, z) cerr << #w << " = " << w << ", " <<#x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;


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
  cin >> T;
  const string str = "RGB";
  for (int cs = 1; cs <= T; cs++) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int best = INT_MAX;
    for (int i = 0; i < n - k + 1; i++) {
      for (int j = 0; j < 3; j++) {
        int cnt = 0;
        for (int t = 0; t < k; t++) {
          //dbg4(s[i + t], str[(t + j) % 3], i, t)
          cnt += (s[i + t] != str[(t + j) % 3]);
        }
        best = min(best, cnt);
      }
    }
    cout << best << endl;
  }

  //double end_time = clock();
  //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
  return 0;
}