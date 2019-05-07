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
int dp[101][101][2][11];
const int Mod = 100000000;
int n1,n2,k1,k2;

int solve(int footman, int horseman, int lasttype, int last)
{
    int & ans = dp[footman][horseman][lasttype][last];

    if(ans == -1){
        ans = 0;

        // footman
        if(footman > 0){
            if(lasttype == 1)
                ans += solve(footman - 1, horseman,0, 1);
            else if(last < k1)
                ans += solve(footman - 1, horseman, 0, last+1);
        }

        // horseman
        if(horseman > 0){
            if(lasttype == 0)
                ans += solve(footman, horseman - 1, 1, 1);
            else if(last < k2)
                ans += solve(footman, horseman - 1, 1, last+1);

            ans %= Mod;
        }
        dp[footman][horseman][lasttype][last] = ans;
    if(footman == 0 && horseman == 0){
        ans = 1;
    }
   }
   return ans;
}


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
    memset(dp, -1, sizeof(dp));
    cin >> n1 >> n2 >> k1 >> k2;
    cout << solve(n1,n2,0,0)<<endl;
    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}