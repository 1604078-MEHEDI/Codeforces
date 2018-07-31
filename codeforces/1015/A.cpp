#include<bits/stdc++.h>
using namespace std;
int vis[101];

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        for(int j =x; j <= y; j++){
            if(vis[j] == 0){
                vis[j] = 1;
            }
        }
    }
    vector<int>v;
    for(int i =1; i <=m; i++){
        if(vis[i] ==0){
            v.push_back(i);
        }
    }
    int l = v.size();
    cout<<l<<endl;
    for(int i =0; i <l; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
