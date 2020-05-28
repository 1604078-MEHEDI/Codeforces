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
  for (int cs = 1; cs <= T; cs++) {
    int b, w;
    cin >> w >> b;
    if (max(b, w) > 3 * min(b, w) + 1) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    int x = 100000, y = 100000;
    if (b > w) {
      x--;
      b -= (w - 1);
    }
    else {
      int k = b;
      b = w;
      w = k;
      b -= (w - 1);
    }
    if (b > 0) {
      cout << x - 1 << " " << y << endl;
      b--;
    }
    for (int i = 0; i < w; i++) {
      cout << x << " " << y << endl;
      if (b > 0) {
        cout << x << " " << y - 1 << endl;
        b--;
      }
      if (b > 0) {
        cout << x << " " << y + 1 << endl;
        b--;
      }
      if (i != w - 1) {
        cout << x + 1 << " " << y << endl;
      }
      x += 2;
    }

    if (b > 0) {
      cout << x - 1 << " " << y << endl;
    }
  }

  //double end_time = clock();
  //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
  return 0;
}