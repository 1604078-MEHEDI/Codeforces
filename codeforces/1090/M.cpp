#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    int cnt = 1;
    int a[n+2];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        if(a[i] != a[i+1])cnt++;
        else{
            ans = max(cnt, ans);
            cnt = 1;
        }
    }
    cout << max(cnt, ans)<<endl;
    return 0;
}
