#include<bits/stdc++.h>
using namespace std;
vector<int>v[1001];
int a[1001];
int visit[1001];

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        v[x].push_back(a[i]);
    }
    for(int i = 1; i <= m; i++){
        sort(v[i].rbegin(), v[i].rend());
    }
    for(int i = 1; i <= m; i++){
            int x = v[i][0];
        visit[x] = 1;
    }
    int cnt = 0;
    for(int i = 1; i <= k; i++){
        int x;
        cin >> x;
        //cout << x<< " -------" << endl;
        int t = a[x];
        if(visit[t] != 1)cnt++;
    }
    cout << cnt << endl;
    return 0;
}
