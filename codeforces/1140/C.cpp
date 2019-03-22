#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<pair<LL, LL> > v, vt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    LL n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        LL t,b;
        cin >> t >> b;
        v.push_back({b,t});
        vt.push_back({t,b});
    }
    sort(v.rbegin(), v.rend());
    multiset<LL>s;
    LL sum = 0;
    LL mn = 9999999;
    LL ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(s.size() < k)
        {
            s.insert(v[i].second);
            sum += v[i].second;
        }
        else{
            if(v[i].second > *(s.begin())){
                sum -= (*s.begin());
                s.erase(s.begin());
                sum += v[i].second;
                s.insert(v[i].second);
            }
        }
       // mn = min(mn, v[i].first);
        LL res = sum * v[i].first;
        ans = max(ans, res);
    }
     cout << ans << endl;

    return 0;
}
