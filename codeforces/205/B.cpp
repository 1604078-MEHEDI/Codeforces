#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long mn = 1e10, mx = 0,t=0;
    for(int i = 1; i <= n; i++){
        long long x;
        cin >> x;
        if(i > 1){
                long long p = t - x;
            if(p > 0){
                mx += p;
            }
        t = x;
        }
        else
        t = x;
    }
        cout<<mx<<endl;
    return 0;
}
