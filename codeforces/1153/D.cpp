#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define maxn 300005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
int color[maxn];
int leaf[maxn];
int ans[maxn];
vector<int> graph[maxn];

void dfs(int u, int p = 0)
{
    for(auto v: graph[u]){
        dfs(v);
    }

    if(!graph[u].size()){
        leaf[u] = 1;
        ans[u] = 1;
        return;
    }
    for(auto v: graph[u]){
        leaf[u] += leaf[v];
    }

    if(color[u]){
        int mn = INF;
        for(auto v: graph[u]){
            mn = min(mn, leaf[v] - ans[v]);
        }
        ans[u] = leaf[u] - mn;
    }
    else{
         ans[u] = 1;
        for(auto v: graph[u]){
            ans[u] = ans[u] + ans[v] - 1;
        }
    }
}


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
    for(int i = 1; i <= n; i++){
        cin >> color[i];
    }
    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        graph[x].push_back(i);
       // graph[i].push_back(x);
    }
    dfs(1);
    cout << ans[1]<<endl;
    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}