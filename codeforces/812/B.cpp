#include<bits/stdc++.h>
using namespace std;
const int N = 20;
const  int M = 105;
int n,m;
string b[N];
int dp[N][2], dist[N][2];
int flag;

int solve(int n, int lr)
{
    if(n == flag) return dist[n][lr];
    if(dp[n][lr] != -1) return dp[n][lr];

    dp[n][lr] = min(m+2 + solve(n+1, 1 - lr), 2* dist[n][lr] + 1 + solve(n+1, lr));
    return dp[n][lr];
}

int main()
{
    cin >> n >> m;
    for(int i = n - 1; i >= 0; i--)
    {
        cin >> b[i];
    }

    flag = -1;
    memset(dist, 0, sizeof dist);

    for(int i = 0; i < n; i++){
        int mn = INT_MAX, mx = 0;
        for(int j = 0; j < m+2; j++){
            if(b[i][j] == '1'){
                flag = i;
                mn = min(mn, j);
                mx = max(mx, j);
            }
        }
        dist[i][0] = mx;
        dist[i][1] = mx == 0 ? 0 : ( (m + 2) - (mn + 1) );
    }
    memset(dp, -1, sizeof dp);
    if(flag < 0) cout << "0\n";
    else cout << solve(0, 0)<<endl;
    return 0;
}
