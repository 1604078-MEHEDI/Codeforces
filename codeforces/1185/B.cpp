///upsolve: minmum valuta n/2 er cheye beshi thaklei Bob win otherwise Alice
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
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
      string x,y;
      cin >> x >> y;

      int p = x.length();
      int q = y.length();
      if(p > q) cout << "NO\n";
      else if(p == q){
        if(x == y) cout << "YES\n";
        else cout << "NO\n";
      }
      else{
        int ans = 0;
        int idx = 0;
        for(int j = 0; j < q; j++){
          if(y[j] == x[idx]){
            idx++;
            ans++;
          }
          else if(y[j] == x[idx - 1]){
           // if(n == 4) cerr << y[j] << " "<<x[idx - 1]<<endl;
            continue;
          }
          else{
            ans = 0;
            break;
          }
          
        }
       // cerr << ans << " "<<p<<endl;
        if(ans == p) cout << "YES\n";
        else cout << "NO\n";
      }
    }
    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}