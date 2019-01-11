#include<bits/stdc++.h>
using namespace std;
#define Max 200005
vector<int>graph[Max];
int color[Max], visit[Max];

int bfs(int s)
{
    int cnt, mx = 0;
    queue<int>Q;
    Q.push(s);
    color[s] = 1;
    visit[s] = 1;

    while(!Q.empty()){
        cnt = 1;
        int u = Q.front();
        Q.pop();

        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            if(!visit[v]){
                visit[v] = color[u];

                while(color[u] == cnt || visit[u] == cnt){
                    cnt++;
                }
                color[v] = cnt++;
                mx = max(cnt, mx);
                Q.push(v);
            }
        }
    }
    return mx - 1;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << bfs(1) << endl;
    for(int i = 1; i <= n; i++){
        cout << color[i] << " ";
    }
    return 0;
}
