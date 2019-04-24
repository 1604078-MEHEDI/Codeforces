#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 100005
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
    int n,m;
    cin >> n >> m;
    int odd_a = 0, even_a = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x&1)odd_a++;
        else even_a++;
    }

    int odd_b = 0, even_b = 0;
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        if(x&1)odd_b++;
        else even_b++;
    }
    cout << min(odd_a,even_b) + min(even_a , odd_b)<<endl;
    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}