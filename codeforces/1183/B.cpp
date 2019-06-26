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
    //T = 1;
    for(int cs = 1; cs <= T; cs++)
    {
        int n,k;
        cin >> n >> k;
         // vector<pair<int,int> > v;
        int l_mx = 0, h_mn = 1e9;
        for(int i = 0; i < n; i++){
          int x;
          cin >> x;
          int low = max(0, x - k);
          int high = x+k;
          l_mx = max(low, l_mx);
          h_mn = min(h_mn, high);
         // v.push_back({low, high});
        }
        if(l_mx > h_mn){
          cout << "-1\n";
        }
        else cout << h_mn<<endl;
    }

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
    return 0;
}
