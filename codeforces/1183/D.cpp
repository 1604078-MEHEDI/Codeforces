#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 100005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

const ll mod = 1e9 + 7;


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
    //T = 1;
    for(int cs = 1; cs <= T; cs++)
    {
      int n;
      cin >> n;
      vector<int> cnt(n + 1);
      for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        cnt[x]++;
      }
      sort(cnt.rbegin(), cnt.rend());
      int ans = cnt[0];
      int lst = cnt[0];
      for(int i = 1; i <= n; i++){
        if(lst <= 0) break;
        if(cnt[i] >= lst){
          ans += lst - 1;
          lst -= 1;
        }
        else{
          ans += cnt[i];
          lst = cnt[i];
        }
      }
      cout << ans << endl;
    }

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
    return 0;
}
