#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<LL>v, v2;
LL lcm(LL a, LL b)
{
    return a/__gcd(a,b) *b;
}

vector<long long> get_divs(LL p)
{
    vector<LL>res;
    if(p > 1e12) return res;
    for(LL x = 2; x*x <= p; x++)
    {
        if(p%x == 0)
        {
            res.push_back(x);
            if(p/x != x) res.push_back(p/x);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
   //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        LL n;
        cin >> n;
        LL mx = 1;
        v.clear();
        for(int i = 1; i <= n; i++)
        {
            LL x;
            cin >> x;
            v.push_back(x);
            if(mx > 1e12) continue;
            mx = lcm(mx, x);
        }
        sort(v.begin(), v.end());
        if(mx == v.back()) mx = mx * v[0];
        // vector<LL>nw;
        v2 = get_divs(mx);
        //  cout << mx << endl;
        /*cout << res.size() << " ---- "<<v.size() << endl;
        for(int i = 0; i < n; i++)
        {
            cout << res[i] << " "<<v[i] << endl;
        }*/
        if(v == v2)
        {
            cout << mx << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}
