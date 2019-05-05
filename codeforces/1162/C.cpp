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
    int n,k;
    cin >> n >> k;
    vector<int> first(n+1,INF), last(n+1, 0);
    for(int i = 1; i <= k; i++){
      int x;
      cin >> x;
      first[x] = min(first[x], i);// x er first position
      last[x] = max(last[x], i); // x er last position
    }

    int ans = 0;
    for(int i = 1; i < n; i++){
      if(first[i] == INF && last[i] == 0)ans ++;
      if(first[i] > last[i+1])ans++;
      if(first[i+1] > last[i])ans++;
    }
    if(first[n] == INF && last[n] == 0)ans ++;
    cout <<ans <<endl;
    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}