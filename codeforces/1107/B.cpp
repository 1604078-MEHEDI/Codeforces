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

    int q;
    cin >> q;
    while(q--){
        ll k,x;
        cin >> k >> x;
        cout << (k-1)*9 + x<<endl;
    }
    

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}