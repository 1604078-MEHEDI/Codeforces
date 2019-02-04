#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long  b[n+2];
    long long sum = 0;
    for(int i = 0; i < n; i++){
        long long a;
        cin >> a;
        sum += a;
    }
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(b, b+n);
    long long ans = b[n-1] + b[n-2];
    if(ans >= sum)cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
