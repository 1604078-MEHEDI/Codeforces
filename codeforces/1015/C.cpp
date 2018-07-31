#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> >v;

int main()
{
    int n,m;
    cin >> n >> m;
    long long sum = 0;
    for(int i =0; i < n; i++){
        int a,b;
        cin >> a >> b;
        sum += a;
        int p = a - b;
        v.push_back(make_pair(p,b));
    }
    sort(v.rbegin(), v.rend());
    int cnt=0;
    int p = n;
    for(int i=0; i <n; i++){
            if(sum<=m)break;
            else{
                if(v[i].second > m){
                        cout<<-1<<endl;
                return 0;
                }
                sum -= v[i].first;
                cnt++;
            }
    }
    if(sum <= m){
        cout<<cnt<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }
    return 0;
}
