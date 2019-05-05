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


/// array globaly declare korbo, kokhon a[n+2] evabe korbona
/// loop check korbo koto porjunto choltese
///n & m thakle duitai ki n & n nki porer ta m likhsi cheak korbo
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
    int mn = 1e9;
    int cnt = 0;
    for(int i = 0; i < n; i++){
      int x;
      cin >> x;
      if(mn > x){
        mn = x;
        cnt = 0;
      }
      if(mn == x)cnt++;
    }
    if(cnt > n/2) cout << "Bob\n";
    else cout << "Alice\n";

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}