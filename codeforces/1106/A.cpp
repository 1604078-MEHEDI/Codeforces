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

    int n;
    cin >> n;
    char M[n+2][n+2];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> M[i][j];
        }
    }
    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {-1, 1, -1, 1};
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(M[i][j] == 'X'){
            int cnt = 0;
            for(int k = 0; k < 4; k++){
                int X = dx[k] + i;
                int Y = dy[k] + j;
                if(M[X][Y] == 'X' && X >= 0 && Y >= 0 && X <= n && Y <= n)cnt++;
              }
              if(cnt == 4)ans++;
            }
        }
    }
    cout << ans << endl;
    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}