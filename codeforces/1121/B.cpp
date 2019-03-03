#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 10005;
int a[maxn];
map<LL,LL>mp;

int main()
{
    int n;
    cin >>n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i  = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            LL sum = a[i]+a[j];
            //cout << sum << endl;
            mp[sum]++;
        }
    }
    map<LL,LL>:: iterator it;
    int mx = 0;
    for(it = mp.begin(); it != mp.end(); it++){
        int x = it->second;
        mx = max(x, mx);
    }
    cout << mx << endl;
    return 0;
}
