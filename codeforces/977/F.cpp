#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 200005;
int n;
int a[maxn];
void longestConsecutiveSubsequence()
{
    map<int,int>dp;
    int last = 0;
    int mx = 0;
    for(int i = 0; i < n; i++)
    {
        int x = a[i];
        dp[x] = dp[x - 1] + 1;
        if(dp[x] > mx)
        {
            mx = dp[x];
            last = x;
        }
    }
    set<int>idx;
    for(int i = n - 1; i >= 0; i--)
    {
        if(a[i] == last)
        {
            idx.insert(i);
            last--;
        }
    }
    cout << mx << endl;
    for(auto x: idx)
    {
        cout << x+ 1 << " ";
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    longestConsecutiveSubsequence();
    return 0;
}

