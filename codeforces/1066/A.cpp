#include<bits/stdc++.h>
using namespace std;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
  #endif
    int t;
    cin >> t;
    while(t--)
    {
        int L, V, l, r;
        cin >> L >> V >> l >> r;
        int total = L/V;
        int range = (r/V) - (l-1)/V;
        int ans = total - range;
        cout<<ans<<endl;
    }
    return 0;
}
