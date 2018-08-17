#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,k;
    cin >> n >> k;
    long long ans = k/2;
    long long res = n + (n-1);
    if(k > res)
    {
        cout<<0<<endl;
        return 0;
    }
    if(n >= k)
    {
        if(k% 2 == 0)ans -= 1;
        cout<<ans<<endl;
    }
    else
    {
        long long ans1 = n - ans;
        cout<<ans1<<endl;
    }
    return 0;
}
