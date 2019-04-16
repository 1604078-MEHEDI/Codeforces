#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define MAX 10005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
ll t[7] = {0, 1, 2, 0, 2, 1, 0};
ll cp[3];
ll inp[3];
ll solve(int i)
{
    ll ans = 0;
    for(int i = 0; i < 3; i++){
        cp[i] = inp[i];
    }

    for(int j = i; ; j = (j+1)%7){
        if(cp[t[j]]){
          //  cerr << ans << endl;
            ans++;
            cp[t[j]]--;
        }
        else break;
    }
    //cerr << ans<<endl;
    return ans;
}

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
    cin >> inp[0] >> inp[1] >> inp[2];
    ll mn = min(inp[0]/3, min(inp[1]/2, inp[2]/2));
    ll mx = 0;
    inp[0] -= mn*3;
    inp[1] -= mn*2;
    inp[2] -= mn*2;
    mn *= 7;
    for(int i = 0; i < 7; i++){
        mx = max(mx, solve(i));
    }
   // cerr << mn << " "<<mx<<endl;

    cout << (mn+mx)<<endl;

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}