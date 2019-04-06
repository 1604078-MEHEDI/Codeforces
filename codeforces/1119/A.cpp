#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n+5];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int t = a[1];
    int mx = 0;
    for(int i = n; i >= 1; i--){
        if(a[i] != t){
            mx = max(mx, i - 1);
        }
    }
    t = a[n];
    for(int i = 1; i <= n; i++){
        if(a[i] != t){
            mx = max(mx, n - i);
        }
    }
    cout << mx << endl;
    return 0;
}
