#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define MAX 150005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

int parent[MAX];
vector<int> graph[MAX], adj[MAX];
int visit[MAX];

void Initialization(int n)
{
    for(int i = 0; i <= n; i++)
    {
        parent[i] = i;
        adj[i].push_back(i);
    }
}

int find_parent(int x)
{
    if(parent[x] == x)return x;
    return parent[x] = find_parent(parent[x]);
}

void make_union(int x, int y)
{
//    parent[find_parent(x)] = find_parent(y);
    x = find_parent(x);
    y= find_parent(y);
    if(adj[x].size() < adj[y].size())
        swap(x,y);
    parent[y] = x;
    graph[adj[x].back()].push_back(y);
    for(auto t: adj[y])
    {
        adj[x].push_back(t);
    }

}

bool isUnion(int x, int y)
{
    return find_parent(x) == find_parent(y);
}

void bfs(int s)
{
    queue<int>Q;
    Q.push(s);
    visit[s] = 1;
    while(!Q.empty())
    {
        int u  = Q.front();
        Q.pop();
        cout << u << " ";
        for(int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            if(visit[v] == 0)
            {
                visit[v] = 1;
                Q.push(v);
            }
        }
    }
}
void dfs(int s)
{
    if(visit[s])return;
    visit[s] = 1;
    cout << s << " ";
    for(int i = 0; i < graph[s].size(); i++)
        dfs(graph[s][i]);
}

int main()
{
// FASTIO
    /*
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    //*/

    int n;
    cin >> n;
    Initialization(n);
    for(int i = 0; i < n-1; i++)
    {
        int x,y;
        cin >> x >> y;
        make_union(x,y);
    }
//    for(int i = 1; i <= n; i++){
//            cout << i << "------------> ";
//        for(int j =0; j < graph[i].size(); j++){
//            cout << graph[i][j] << " ";
//        }
//        cout << endl;
//    }
    bfs(find_parent(1));
//double end_time = clock();
//printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
}
