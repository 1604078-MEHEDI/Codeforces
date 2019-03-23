#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> graph[maxn], ans;
int given[maxn], target[maxn];

void dfs(int curr, int p, int flip, int flip_child)
{
    if(flip) given[curr] ^= 1;

    if(given[curr] != target[curr]){
        ans.push_back(curr); // we need to flip this node.
        flip ^= 1;
    }
    for(int u = 0; u < graph[curr].size(); u++){
        int v = graph[curr][u];
        if(v != p){
            dfs(v, curr, flip_child, flip);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        cin >> given[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> target[i];
    }
    dfs(1,-1,0,0);
   // sort(ans.begin(), ans.end());
    int sz = ans.size();
    cout << sz << endl;
    for(int i = 0; i < sz; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
