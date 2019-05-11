#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 200005;

bool visit[maxn];
vector<int>graph[maxn], curr_graph;
int degree[maxn];

void dfs(int u)
{
    visit[u] = true;
    curr_graph.push_back(u);

    for(auto v : graph[u])
    {
        if(!visit[v])
            dfs(v);
    }
}

int countSingleCycles(int n)
{
    int cnt = 0;

    for(int i = 1; i <= n; i++)
    {
        if(!visit[i])
        {
            curr_graph.clear();
            dfs(i);

            int flag = 1;
            for(auto v: curr_graph)
            {
                if(degree[v] == 2)continue;
                else
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)cnt++;
        }
    }
    return cnt;
}


int main()
{
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    cout << countSingleCycles(n)<<endl;
    return 0;
}

