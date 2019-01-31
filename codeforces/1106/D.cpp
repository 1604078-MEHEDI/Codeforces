#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define MAX 100005
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
    vector<int> graph[MAX];
    int visit[MAX];
    int n, m;
    cin >> n >> m;
    //cerr << n <<" "<< m<<endl;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        //cerr << u << " "<<v<<endl;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    //priority_queue<int, vector<int>, greater<int> > PQ;
    //PQ.push(1);
    set<int>s;
    s.insert(1);
    visit[1] = 1;
    while(!s.empty())
    {
        int u = *s.begin();
        s.erase(s.begin());
            //ans.push_back(u);
            cout << u << " ";
        for(int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            if(visit[v] == 0){
                s.insert(v);
                visit[v] = 1;
            }
        }
    }
    return 0;
}