#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char M[1006][1006];
int vis[1006][1006];
int cnt[100006];
int dfs(int x, int y, int v)
{
    vis[x][y] = v;
    for(int j = 0; j < 4; j++){
        int _x = x + dx[j];
        int _y = y + dy[j];
        if(vis[_x][_y])continue;

        if(M[_x][_y] == '.')dfs(_x, _y, v);
        else cnt[v]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> M[i][j];
        }
    }
    for(int i = 1; i <= k; i++)
    {
        int x,y;
        cin >> x >> y;
        if(vis[x][y] == 0)dfs(x,y,i);
        cout<<cnt[vis[x][y]]<<endl;
    }
    return 0;
}
