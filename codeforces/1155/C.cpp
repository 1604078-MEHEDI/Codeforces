#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 100005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
const int dx4[] = { -1, 0, 1, 0 }; // 4 direction i
const int dy4[] = { 0, 1, 0, -1 }; // 4 direction j
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; // 8 direction i
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; // 8 direction j
const int dxk[] = { -2, -2, -1, -1, 1, 1, 2, 2 }; // knight direction i
const int dyk[] = { -1, 1, -2, 2, -2, 2, -1, 1 }; // knight direction j
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

int main()
{
    FASTIO
    ///*
    //double start_time = clock();
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif    //*/

    ll n,m;
    cin >> n >> m;
    ll P[n+5];
    ll Q[m+5];
    for(int i = 0; i < n; i++){
      cin >> P[i];
    }
    for(int i = 0; i < m; i++){
        cin >> Q[i];
    }
    ll g;
    for(int i = 1; i <n; i++){
        ll x = P[i] - P[i-1];
        if(i > 1){
            g = __gcd(g, x);
        }
        else g = x;
    }
    //cerr << g << endl;
    for(int i = 0; i < m; i++){
        if(g%Q[i] == 0){
            cout << "YES\n";
            cout << P[0]<< " "<<i+1<<endl;
            return 0;
        }
    }
    cout << "NO\n";
    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
    return 0;
}