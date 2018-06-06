#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false),cin.tie(0);
#define ll long long
//map<ll, ll>m;
ll N[30001], V[30001];
//vector<pair<int, int> >vp;
int main()
{
    IO
    int n;
    cin >>n;
    for(int i = 0; i <n; i++)
    {
        cin >> N[i];
    }
    for(int i =0; i < n; i++)
    {
       cin >> V[i];
    }
    ll ans = 1e10;
    for(int i = 1; i < n; i++)
    {
        ll tot = V[i];
        ll last = 1e10;
        for(int j = 0; j < i; j++) if( N[i] > N[j]) last = min(last, V[j]);
        if(last == 1e10)continue;

        tot += last;
        last = 1e10;
        for(int j = i+ 1; j < n; j++) if(N[j] > N[i]) last = min(last, V[j]);
        if(last == 1e10)continue;

        tot += last;
        ans = min(ans, tot);
    }
    if(ans == 1e10)ans = -1;
    cout<<ans<<endl;
    return 0;

    return 0;

}
