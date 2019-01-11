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
    sort(a,a+n);
    int half = n/2;
    int i = n - 1;
    int ans = n;
    for(int k = half - 1; k >= 0; k--){
        if(a[i] >= a[k]*2){
            ans--;
            i--;
        }
    }
    cout << ans<<endl;
    return 0;
}
