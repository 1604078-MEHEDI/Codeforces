///Help from Editorial...):-
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n , q;
    cin >> n >> q;
    vector<int> cnt(31);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        ++cnt[__builtin_ctz(x)];
    }
    while(q--){
        int a;
        cin >> a;
        int ans = 0;
        for(int i = 30; i >= 0; i--){
            int mn = min(a >> i, cnt[i]);
            ans += mn;
            a -= (1 << i) * mn;
        }
        if(a > 0)ans = -1;
        cout<<ans<<endl;
    }
    return 0;
}
