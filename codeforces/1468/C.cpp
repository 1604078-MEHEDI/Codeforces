#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define         pb         push_back
#define         sf(x)      scanf("%d",&x)
#define         sfl(x)     scanf("%lld",&x)
#define         pf(x)      printf("%d\n",x)
#define         pfl(x)     printf("%lld\n",x)
#define         endl       '\n'
#define         pii        pair<int,int>
#define         mapii      map<int,int>
#define         mapll      map<ll,ll>
#define         mapci      map<char,int>
#define         mapcl      map<char,ll>
#define         mapsi      map<string,int>
#define         mapsl      map<string,ll>
#define         pll        pair<ll,ll>
#define         vi         vector<int>
#define         vl         vector<ll>
#define         vd         vector<double,double>
#define         all(c)     c.begin(),c.end()
#define         F          first
#define         S          second
#define         mp         make_pair
#define        ftc(x)      cerr << #x << ": " << x << " " << endl;
#define         PI         acos(-1)
#define         lcm(a,b)   ((a*b)/__gcd(a,b))
#define        optimize    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define        sqr(a)       ((a)*(a))

int main()
{
    int t;
    set<pll>p1;
    set<pll>p2;
    cin >> t;
    ll cnt = 1;
    vl ans;
    while(t--)
    {

        ll i,j,k,l,m,n;

        cin >> l ;

        if(l==1)
        {
            cin >> m;
           // cout << cnt << " " << m << endl;
            p1.insert({-1*m,cnt});
            p2.insert({cnt,m});
            cnt++;
        }
        else if(l==2)
        {
            pll pk = *p2.begin();
            ans.pb(pk.F);
            p2.erase(pk);
            p1.erase({-1*pk.S,pk.F});
        }
        else if(l==3)
        {
            pll pk = *p1.begin();
           // cout << pk.S << endl;
            ans.pb(pk.S);
            p1.erase(pk);
            p2.erase({pk.S,-1*pk.F});
        }





    }
    for(auto x : ans)cout << x << " ";
    cout << endl;

}
