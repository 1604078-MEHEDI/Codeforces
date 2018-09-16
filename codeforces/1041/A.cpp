#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin >> n;
    int mx = 0,mn = 1e9+10;
    for(int i=0; i < n; i++){
        int x;
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }
    cout<<(mx - mn + 1) - n<<endl;
    return 0;
}
