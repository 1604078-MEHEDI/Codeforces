#include<bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int visit[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<pair<int,int > >vp;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        vp.push_back({x,i});
    }
    sort(vp.rbegin(), vp.rend());
    long long ans = 0;
    for(int  i =0 ; i < m*k; i++){
        int idx = vp[i].second;
        int val = vp[i].first;
        ans += val;
        visit[idx] = 1;
    }
    cout << ans << endl;
    int cnt = 0;
    vector<int>points;
    for(int i = 1; i <= n; i++){
        if(visit[i])cnt++;
        if(cnt == m){
            points.push_back(i);
            cnt = 0;
        }
    }
    for(int i = 0; i < points.size()-1; i++){
        if(i)cout << " ";
      cout << points[i];
    }
    cout << endl;
    return 0;
}
