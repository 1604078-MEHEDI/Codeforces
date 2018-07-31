#include<bits/stdc++.h>
using namespace std;
vector<int>v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    long long sum = 0;
    for(int i =0; i < n; i++){
        int a,b;
        cin >> a >> b;
        sum += a;
        int p = a - b;
        v.push_back(p);
    }
    sort(v.rbegin(), v.rend());
    int cnt=0;
    for(int i=0; i <n; i++){
            if(sum<=m)break;
            else{
                sum -= v[i];
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
