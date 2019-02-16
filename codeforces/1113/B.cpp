#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n+2];
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a+n);
    int ans = sum;
    int res = sum;
    //cout << ans << endl;
    for(int i = n-1; i > 0; i--){
        int x = a[i];
        for(int j = 2; j <= sqrt(x); j++){
            if(x%j == 0){
                int tem = x/j;
                res = (res + tem) + (a[0]*j) - a[0] - x;
               // cout << tem << " " << res << " "<<x<< " "<<a[0]<< endl;
                ans = min(ans, res);
            }
            res = sum;
        }
    }
    cout << ans << endl;
    return 0;
}
