/// upsolve: Another solution (Binary Search)
#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define maxn 100005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;


int main()
{
    FASTIO
    /*
    //double start_time = clock();
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif    //*/
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int lo = 1, hi = n;
        cout << "1 "<<n - 1<< " 1";
        for(int i = 2; i <= n; i++) cout << " "<<i;
            cout << endl;
        //cout.flush();
        int mx;
        cin >> mx;
        while(lo+1 < hi){
            int m = (lo + hi)/2;
            cout << "1 "<< m - 1 << " 1";
            for(int i  =2; i <= m; i++) cout << " " << i;
                cout << endl;
            int q;
            cin >> q;
            if(q == -1) exit(-1);
            else if(q == mx){
                hi = m;
            }
            else{
                lo = m;
            }
        }
        cout << "1 "<< n - 1 << " "<< hi;
        for(int i  = 1; i <= n; i++)
            if(i != hi)
            cout << " "<<i;
        cout << endl;
        cin >> mx;
        cout << "-1 "<<mx<< endl;
        //cout.flush();
    }
    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}