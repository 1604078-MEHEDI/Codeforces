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

    int n;
    string s;
    cin >> n >> s;
    ll cntl = 0, cntr = 0;
    for(int i = 0; i <n; i++){
      if(s[0] == s[i])cntl++;
      else break;
    }
    for(int i = n-1; i >= 0; i--){
      if(s[n-1] == s[i])cntr++;
      else break;
    }

    if(s[0] == s[n-1])
      cout << (cntl + 1LL)* (cntr + 1LL) % MOD<<endl;
    else
      cout << (cntl + cntr + 1LL) % MOD;


      //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
   return 0;
}