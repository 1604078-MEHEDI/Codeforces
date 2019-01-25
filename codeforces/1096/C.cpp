#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define MAX 10005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const ll MOD = 998244353;

int main()
{
    FASTIO
   // /*
    //double start_time = clock();
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
   #endif
    //*/

    int t;
    cin >> t;
    while(t--){
      int gcd,x,y,ans;
      int ang;
      cin >> ang;
      gcd = __gcd(ang, 180);
      ans = 180/gcd;
      x = ang/gcd;
      if(ans-1 == x)ans = ans*2;
      cout << ans << endl;
    }


      //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
   return 0;
}