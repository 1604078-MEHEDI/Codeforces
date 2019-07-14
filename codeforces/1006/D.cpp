/** upsolve: - if map size = 1, than ans += 0;
            - if four letter is uniqe ans += 2;
            - otherwise add 2,1 or zero (whene mp.size() == 2 && s[i] == s[n - i - 1]).
**/ 
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
    int n;
    string s, t;
    cin >> n >> s >> t;
    int ans = 0;

    for (int i = 0; i < n / 2; i++) {
      map<char, int > mp;
      mp[s[i]]++;
      mp[s[n - i - 1]]++;
      mp[t[i]]++;
      mp[t[n - i - 1]]++;
      if ((int)mp.size() == 4) ans += 2;
      else if ((int)mp.size() == 3) ans += 1 + (s[i] == s[n - i - 1]);
      else if ((int)mp.size() == 2) ans += (mp[s[i]] != 2);
    }

    if ((n & 1) && s[n / 2] != t[n / 2]) ans++;
    cout << ans << endl;
  }

  //double end_time = clock();
  //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
  return 0;
}