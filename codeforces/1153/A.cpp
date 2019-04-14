#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define MAX 10005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;


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

    ll n,t;
    cin >> n >> t;
    ll mn = 1e12;
    int ans = 1;
    for(int i = 1; i <= n; i++){
        int s, d;
        cin >> s >> d;
        if(t >= s){
            ll x = t - s;
            x = (x + d - 1)/d;
            x = x*d;
            //cerr << x << endl;
            x = x - (t-s);
           // cerr << i<< "--->"<<x << endl;
            if(mn > x){
                mn = x;
                ans = i;
            }
        }
        else{
            ll x = s - t;
            if(mn > x){
                mn = x;
                ans = i;
            }
        }
    }
    cout << ans << endl;

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}