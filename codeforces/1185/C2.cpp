///upsolve: minmum valuta n/2 er cheye beshi thaklei Bob win otherwise Alice
#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 105
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

int a[maxn];
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
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        int sum = x, cnt = 0;
        for(int j = 1 ; j <= 100; j++){
            int Q = min(a[j], (m - sum)/j);
            sum += Q * j;
            cnt += Q;
        }
        cout << (i - cnt)<< " ";
        a[x]++;
    }    
    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}