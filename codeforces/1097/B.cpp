#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n+2];
    for(int i = 0; i < n; i++) cin >> a[i];
    int limit = 1 << n;
    for(int i = 0; i < limit; i++){
            int k = 0;
            int sum1 = 0, sum2 = 0;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                    sum1 += a[k++];
            }
            else{
                sum2 += a[k++];
            }
        }
        sum2 *= -1;
        int ans = sum1 + sum2;
       // cout << ans << endl;
       if(ans < 0) ans *= -1;
        if(ans == 0 || ans == 360 || (ans%360 == 0)){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
