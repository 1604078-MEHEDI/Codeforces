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
    int n, k;
    cin >> n >> k;
    int a[n + 2];
    int odd = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] & 1)odd++;
    }
    int cnt = odd / k;
    int ext = odd % k;
    //dbg3(ext, cnt, odd);
    if (!(cnt & 1) && cnt > 0) {
      cnt--;
      ext += k;
      //ext += cnt;
    }
    //dbg2(ext, cnt);
    if ((ext % 2 == 0) && (cnt & 1)) {
      cout << "YES\n";
      vector<int> v;
      int t = 0, idx = 1;
      if (ext > 0) {
        for (int i = 1; i <= n; i++) {
          if (a[i] & 1)t++;
          if (t == ext) {
            //cout << i << " ";
           // v.push_back(i);
            idx = i + 1;
            break;
          }
        }
      }
      t = 0;
      for (int i = idx; i <= n; i++) {
        if (a[i] & 1)t++;
        if (t == cnt) {
          v.push_back(i);
          //cout << i << " ";
          t = 0;
        }
      }
      v[(int)v.size() - 1] = n;
      for (auto x : v)cout << x << " ";
      cout << endl;
    }
    else {
      cout << "NO\n";
    }
  }

  //double end_time = clock();
  //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
  return 0;
}