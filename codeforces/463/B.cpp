#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int ans = 0,ck = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        ans = max(ans, a);
       // ans += ck - a;
        //ck = a;
    }
    cout<<ans<<endl;
   // cout<<abs(ans)<<endl;
    return 0;
}
