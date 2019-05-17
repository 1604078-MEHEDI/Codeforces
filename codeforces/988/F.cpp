#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int maxn = 2005;
int dp[maxn], umb[maxn], rain[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,n,m;
    cin >> a >> n >> m;

    for(int i = 0; i < n; i++)
    {
        int l,r;
        cin >> l >> r;
        for(int j = l; j < r; j++)
            rain[j] = 1;
    }
    for(int i = 0; i <= a; i++) umb[i] = dp[i] = inf;
    for(int i = 0; i < m; i++)
    {
        int x,p;
        cin >> x >> p;
        umb[x] = min(umb[x], p);
    }
    dp[0] = 0;
    for(int i = 1; i <= a; i++)
    {
        if(rain[i - 1] == 0) dp[i] = dp[i-1];
        else
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(umb[j] != inf)
                    dp[i] = min(dp[i], dp[j] + (i - j) * umb[j]);
            }
        }
    }

    int ans = dp[a];
    if(ans == inf) ans = -1;
    cout << ans << endl;
    return 0;
}

