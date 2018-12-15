#include<bits/stdc++.h>
using namespace std;
long long a[2000005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long last = 1e18, first = 0;
    for(int i = 1; i <= n/2; i++){
        long long x;
        cin >> x;
        first = max(first, x - last);
        last = min(last, x-first);
        a[i] = first;
        a[n-i+1] = last;
    }
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
