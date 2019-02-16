#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,v;
    cin >> n >> v;
    int ans = min(v,n);
    int cnt = 2;for(int i = min(v,n)+1; i <n; i++){
        ans += cnt++;
    }
    if(v >= n)cout << n-1<<endl;
    else
    cout << ans << endl;
    return 0;
}

