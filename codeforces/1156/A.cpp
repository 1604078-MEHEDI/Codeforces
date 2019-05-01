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


/// array globaly declare korbo, kokhon a[n+2] evabe korbona
/// loop check korbo koto porjunto choltese
///n & m thakle duitai ki n & n nki porer ta m likhsi cheak korbo
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

    int n;
    cin >> n;
    int a[105];
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    int cnt = 0;//ext = 0;
    int x = a[0];
    for(int i = 1; i < n; i++){
      if(a[i]+a[i - 1] == 5){
        cout << "Infinite\n";
        return 0;
      }
      if(i >= 2){
       // cerr << a[i - 2] << " "<<a[i - 1] << " "<< a[i]<<endl;
        if(a[i - 2] == 3 && a[i - 1] == 1 && a[i] == 2)cnt -= 1;
      }
      cnt += a[i] + a[i-1];
    }
    cout << "Finite\n";
    //cerr << cnt << "------"<<ext<<endl;
    cout << cnt << endl;
    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}