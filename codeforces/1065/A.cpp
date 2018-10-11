#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        long long s,a,b,c;
        cin >> s >> a >> b >> c;
        long long x = (s/c);
        long long ans = x + (x/a)*b;
        cout<<ans<<endl;
    }
    return 0;
}
