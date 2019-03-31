#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
vector<pair<int, pair<int,int>>> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n+2];
    int idx = 1, eq, cnt = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mp[a[i]]++;
        if(mp[a[i]] > cnt){
            cnt = mp[a[i]];
            eq = a[i];
            idx = i;
        }
    }
    for(int i = idx+1; i <= n; i++){
        if(a[i] == eq) continue;
        if(a[i] < eq ){
            a[i] = eq;
            v.push_back({1, {i, i - 1}});
        }
        else{
            a[i] = eq;
            v.push_back({2, {i, i - 1}});
        }
    }

    for(int i = idx - 1; i >= 1; i--){
        if(a[i] == eq) continue;
        if(a[i] < eq ){
            a[i] = eq;
            v.push_back({1, {i, i + 1}});
        }
        else{
            a[i] = eq;
            v.push_back({2, {i, i + 1}});
        }
    }
    cout << v.size()<<endl;
    for(auto x: v){
        cout << x.first<< " "<<x.second.first << " "<<x.second.second<<endl;
    }
    return 0;
}
