#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a, b, sizeof(a) )
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))
#define long long    ll

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main()
{
    IO
    int k;
    cin >>k;
    vector<pair<int, pair<int, int> > > vp;
    for(int t = 0; t < k; t++)
    {
        int n;
        cin >> n;
        vector<int>x(n);
        for(int i = 0; i < n; i++)
            cin >> x[i];
        int sum = accumulate(x.begin(), x.end(), 0);
        for(int i = 0; i < n; i++)
            vp.push_back(make_pair(sum - x[i], make_pair(t,i)));
    }

    stable_sort(vp.begin(), vp.end());

    for(int i = 0; i < int(vp.size()) - 1; i++)
    {
        if(vp[i].first == vp[i+1].first && vp[i].second.first != vp[i+1].second.first)
        {
            cout<<"YES"<<endl;
            cout<<vp[i+1].second.first + 1 << " " <<vp[i+1].second.second + 1<<endl;
             cout<<vp[i].second.first + 1 << " " <<vp[i].second.second + 1<<endl;
             return 0;

        }
    }
    cout<<"NO\n";
    return 0;
}
