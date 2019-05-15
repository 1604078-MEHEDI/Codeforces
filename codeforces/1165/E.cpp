#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int Mod = 998244353;
const int maxn = 200005;
int a[maxn], b[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    sort(b, b+n);
    reverse(b, b+n);

    vector<LL>ans;
    for(int i = 0; i < n; i++)
    {
        LL x = 1LL * (i + 1) * (n - i) * a[i];
        ans.push_back(x);
    }

    sort(ans.begin(), ans.end());
    LL res = 0;
    for(int i = 0; i < n; i++)
    {
        res += ans[i] % Mod * b[i];
        res %= Mod;
    }

    cout << res << endl;
    return 0;

}
