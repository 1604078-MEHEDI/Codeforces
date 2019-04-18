#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

bool cmp(const pair<LL, LL> &a, const pair<LL, LL> &b)
{

    return a.first - a.second >  b.first - b.second;
}
vector<pair<LL, LL> > v1, v2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    LL n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        LL a,b;
        cin >> a >> b;
        v1.push_back({a, b});
        v2.push_back({b, a});
    }
    sort(v1.begin(), v1.end(), cmp);
    //cout << "-------------------------\n";
    LL sum = 0;
    int idx = 0;
    for(int i = 1; i <= n; i++){
        LL x = v1[idx].first;
        LL y = v1[idx].second;
       // cout << x << " "<<y<< " "<<(x - y)<<endl;
        idx++;
        sum += x * (i - 1) + y * (n - i);
    }
    cout << sum<<endl;
    return 0;
}
