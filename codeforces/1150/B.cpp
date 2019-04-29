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
int visit[55][55];

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
    char a[n+2][n+2];
    int cnt = 0;
    //vector<pair<int,int> > dot;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] == '.'){
                //dot.push_back({i,j});
                cnt++;
            }
            else{
                visit[i][j] = 1;
            }
        }
    }
    if(cnt%5){
        cout << "NO\n";
        return 0;
    }
    int dx[5] = {1, 2, 1, 1};
    int dy[5] = {0, 0, -1, 1};
    int ans = 0;
     for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int ct = 0;
            if(a[i][j] == '.' && visit[i][j] == 0){
                visit[i][j] = 1;
                ct++;
                //cerr << i << " "<<j << endl;
                for(int k = 0; k < 4; k++){
                    int x = dx[k] + i;
                    int y = dy[k] + j;
                    if(a[x][y] == '.' && visit[x][y] == 0){
                        ct++;
                        visit[x][y] = 1;
                    }
                }
            }
            if(ct == 5)ans++;
        }
}
//cerr << ans << " "<<cnt<<endl;
if(ans*5 == cnt){
    cout << "YES\n";
}
else{
    cout << "NO\n";
}
    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}