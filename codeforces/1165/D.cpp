#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<LL>res;
LL lcm(LL a, LL b)
{
    return a/__gcd(a,b)*b;
}

void get_divs(LL n)
{
    if(n > 1e12) return;
    for(LL x = 2; x*x <= n; x++)
    {
        if(n%x == 0)
        {
            res.push_back(x);
            if(n/x != x) res.push_back(n/x);
        }
    }
    sort(res.begin(), res.end());
    //return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    LL t;
    cin >> t;
    while(t--)
    {
        res.clear();
        LL n;
        cin >> n;
        vector<LL>v;
        LL mx = 1;
        for(LL i = 0; i < n; i++)
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
        get_divs(mx);
        //  cout << mx << endl;
        /*cout << res.size() << " ---- "<<v.size() << endl;
        for(int i = 0; i < n; i++)
        {
            cout << res[i] << " "<<v[i] << endl;
        }*/
        if(res == v)
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
