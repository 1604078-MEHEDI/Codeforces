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
        int ans = 0;
        for(int i = 0; i < 9; i++){
        vector<int> a,b;
        for(int k = 0; k < n; k++){
            if((k >> i) & 1) a.push_back(k);
            else b.push_back(k);
        }
        if(a.empty() || b.empty()) continue;
            cout << a.size() << " "<<b.size();
            for(int x: a)cout << " "<< (x + 1);

                for(int x: b) cout << " "<< (x + 1);
        cout << endl;
        cout.flush();
        int mx;
        cin >> mx;
        ans = max(ans, mx);
      }
      cout << "-1 "<<ans << endl;
        cout.flush();
    }
    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}