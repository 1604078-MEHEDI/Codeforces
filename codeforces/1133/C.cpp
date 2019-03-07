#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n+2];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
   // for(int i = 0; i < n; i++)cout << a[i] <<" ";
    //cout << endl;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x = a[i] + 5;
        int upper = upper_bound(a, a+n, x) - a;
        ans = max(ans, upper - i);
       // int low = lower_bound(a, a+n, x) - a;
       // cout << a[i] <<" ---"<<i<<"----->" << upper<< " "<<a[upper] << endl;
    }
    cout << ans << endl;
}

