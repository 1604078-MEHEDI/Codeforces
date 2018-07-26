#include<bits/stdc++.h>
using namespace std;
int a[1001];

int main()
{
    int n,m;
    cin >> n >> m;
    int ans = m/n;
    for(int i=0; i < m; i++){
        int x;
        cin >> x;
        a[x]++;
    }
    sort(a, a+101);
     if(n > m){
        cout<<0<<endl;
        return 0;
    }
    while(ans > 1){
    int sum =0,cnt=0;
    for(int i = 100; i >0; i--){
        if(a[i] == 0 || a[i] == 1)continue;
        sum += a[i]/ans;
    }
    if(sum >= n)break;
    else ans--;
    }
    cout<<ans<<endl;
    return 0;
}
