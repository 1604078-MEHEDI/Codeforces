#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn  = 3e5 + 5;
vector<LL>v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    LL sum = 0;
    for(int i = 0; i < n; i++){
        LL x;
        cin >> x;
        sum += x;
        v.push_back(x);
    }
    sort(v.rbegin(), v.rend());
    int m;
    cin >> m;
    while(m--){
        int x;
        cin >> x;
        cout << sum - v[x-1]<<endl;
    }
    return 0;
}
