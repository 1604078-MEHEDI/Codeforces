#include<bits/stdc++.h>
using  namespace std;
int solve(int a[], int l, int r)
{
    int cnt = 0;
    bool flag = true;
    for(int i = l; i < r - 1; i++){
        if(a[i] > a[i+ 1]) flag = false;
    }
    if(flag) return (r - l);
    else{
        int c1 = solve(a, l, (l+r)/2);
        int c2 = solve(a, (l+r)/2, r);
        cnt = max(cnt, max(c1, c2));
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    int a[n+2];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << solve(a, 0, n)<<endl;
    return 0;
}
