#include<bits/stdc++.h>
using namespace std;
char s[55][55];
int visit[55][55];
int visit1[55][55];
  int n;

int dx[4] = {1, 0, -1, 0};// r-u-l-d
int dy[4] = {0, 1, 0, -1};
vector<pair<int,int> > start, End;
void bfs(int x, int y)
{
    queue<pair<int,int>> Q;
    Q.push({x,y});
    visit[x][y] = 1;
    start.push_back({x,y});
    while(!Q.empty())
    {
        int X = Q.front().first;
        int Y = Q.front().second;
        Q.pop();
        for(int i = 0; i < 4; i++){
            int r = X + dx[i];
            int c = Y + dy[i];
            if(r > 0 && c > 0 && r <= n && c <= n && s[r][c] == '0' && visit[r][c] == 0){
                visit[r][c] = 1;
                Q.push({r,c});
                start.push_back({r,c});
            }
        }
    }
}

void bfs1(int x, int y)
{
    queue<pair<int,int>>Q;
    Q.push({x,y});
    visit1[x][y] = 1;
    End.push_back({x,y});
    while(!Q.empty())
    {
        int X = Q.front().first;
        int Y = Q.front().second;
        Q.pop();
        for(int i = 0; i < 4; i++){
            int r = X + dx[i];
            int c = Y + dy[i];
            if(r > 0 && c > 0 && r <= n && c <= n && s[r][c] == '0' && visit1[r][c] == 0){
                visit1[r][c] = 1;
                Q.push({r,c});
                End.push_back({r,c});
            }
        }
    }
}
int main()
{
    int sx,sy,fx,fy;
    cin >> n;
    cin >> sx >> sy >> fx >> fy;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> s[i][j];
        }
    }

    bfs(sx,sy);
    bfs1(fx,fy);
    int ans = INT_MAX;
    for(int i = 0; i < start.size(); i++){
        int x1 = start[i].first;
        int y1 = start[i].second;
        for(int j = 0; j < End.size(); j++){
            int x2 = End[j].first;
            int y2 = End[j].second;
            int x = x1 - x2;
            int y = y1 - y2;
            int res = x*x + y*y;
            ans = min(ans, res);
        }
    }
    cout << ans << endl;
    return 0;
}
