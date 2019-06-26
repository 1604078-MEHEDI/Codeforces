#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 100005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

const ll mod = 1e9 + 7;

int main()
{
    FASTIO
    ///*
    //double start_time = clock();
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
//*/
    int T;
    cin >> T;
    for(int cs = 1; cs <= T; cs++)
    {
        ll n;
        cin >> n;
        map<ll,ll> mp, vis;
        for(ll i = 1; i <= n; i++){
            ll x;
            cin >> x;
            mp[x]++;
            vis[i] = 0;
        }
        ll ans = 0;
        for(auto x: mp){
            if(vis[mp[x.first]] == 0){
                ans += mp[x.first];
                vis[mp[x.first]]  = 1;
            }
            else{
                while(mp[x.first] > 0){
                    mp[x.first]--;
                    if(vis[mp[x.first]] == 0){
                        ans += mp[x.first];
                        vis[mp[x.first]] = 1;
                        break;
                    }
                }
            }
           // cerr << x.first << " "<<x.second << endl;
        }
        cout << ans << endl;
    }

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}
