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
    int lo = 0, hi = n/2, mid, ans = 0;

    while(hi > lo){
        mid = (hi + lo  +1)/2;
        bool ok = true;
        for(int i = 0; i < mid; i++){
            if(a[i]*2 > a[n-mid+i]){
                ok = false;
                break;
            }
        }
        if(ok){
            lo = mid;
        }
        else hi = mid - 1;
    }
    cout <<n - lo<<endl;
    return 0;
}
