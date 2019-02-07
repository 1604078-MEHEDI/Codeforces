#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m,k;
    cin >> n >> m >> k;
    int a[n+2];
    for(int i = 0; i < n; i++)cin >> a[i];
    vector<int>v;
    for(int i = 1; i < n; i++){
        int x = a[i] - a[i-1];
        v.push_back(x);
    }
    sort(v.rbegin(), v.rend());
    long long ans = 0;
    for(int i = k-1; i < v.size(); i++){
        ans += (long long) v[i];
    }
    ans += 1LL;
    cout << (ans + (k-1))<<endl;
    return 0;
}
