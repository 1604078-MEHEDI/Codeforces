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
    int n;
    cin >> n;
    int x, y, a, b, c, d;
    int mx_x = 100000;
    int mx_y = 100000;
    int mn_x = -100000;
    int mn_y = -100000;
    for (int i = 0; i < n; i++) {
      cin >> x >> y >> a >> b >> c >> d;
      //v.push_back({x, y});
      if (!a) {
        //L = max(x, L);
        mn_x = max(x, mn_x);
        //dbg2(L, mx_x);
      }
      if (!b) {
        mx_y = min(mx_y, y);
       // U = min(U, y);
      }
      if (!c) {
       // R = min(R, x);
        mx_x = min(mx_x, x);
      }
      if (!d) {
        //D = max(D, y);
        mn_y = max(y, mn_y);
      }
    }

    if (mn_y > mx_y || mn_x > mx_x)cout << 0 << endl;
    else cout << 1 << " " << mn_x << " " << mn_y << endl;
  }

  //double end_time = clock();
  //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
  return 0;
}