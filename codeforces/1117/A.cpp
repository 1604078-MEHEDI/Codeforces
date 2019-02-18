
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 9;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n+2];
    int mx = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int ans = 1;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == mx){
            cnt++;
            ans = max(ans, cnt);
        }
        else cnt = 0;
    }
    cout << ans << endl;
    return 0;
}

