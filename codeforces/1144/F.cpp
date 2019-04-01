#include<bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int n,m;
vector<int> graph[maxn], color;
vector<pair<int,int>>a;
bool bipartite;

void dfs(int s, int c)
{
    color[s] = c;
    for(auto x: graph[s]){
        if(color[x] == -1)
            dfs(x, c^1);
        else{
            if(color[x] == color[s])
                bipartite = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        --u;
        --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        a.push_back({u,v});
    }

    bipartite = true;
    color = vector<int>(n, -1);
    dfs(0, 0);
    if(!bipartite){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(int i = 0; i < m; i++){
        cout << (color[a[i].first] < color[a[i].second]);
    }
    cout << endl;
    return 0;
}
