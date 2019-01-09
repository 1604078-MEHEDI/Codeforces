#include<bits/stdc++.h>
using namespace std;
int cnt[5005];
//vector<int >ans;
vector<pair<int,int> >v;
int ans[50005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,k;
    cin >> n >> k;
    int mx = 0;
    for(int i = 0; i < n; i++){
            int x;
        cin >> x;
        cnt[x]++;
        v.push_back({x,i});
        mx = max(mx, cnt[x]);
    }
    if(mx > k){
        cout << "NO\n";
    }
    else{
        sort(v.begin(), v.end());
        int x = 1;
        for(int i = 0; i < n; i++){
            int idx = v[i].second;
            ans[idx] = x;
            if(x == k){
                x = 0;
            }
            x++;
        }
        cout << "YES\n";
        for(int i = 0; i < n; i++){
            cout << ans[i]<< " ";
        }
    }
    return 0;
}
