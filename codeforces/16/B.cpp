#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> >vp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        vp.push_back(make_pair(b,a));
    }
    sort(vp.rbegin(), vp.rend());
    long long sum = 0;
    for(int i = 0; i< m; i++){
            if(n <= 0)break;
        if(vp[i].second <= n){
            n -= vp[i].second;
            sum += vp[i].first *vp[i].second;
        }
    else
    {
        sum += vp[i].first * n;
        n = 0;
    }
    }
    cout<<sum<<endl;
    return 0;
}
