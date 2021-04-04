#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define        lcm(a,b)   ((a*b)/__gcd(a,b))
#define        optimize    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define        sqr(a)       ((a)*(a))
#define         MAX        15000
#define         max5        100000
#define         max6        1000000
#define         mod       1000000007
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
#define        ei(x)      cerr << #x << ": " << x << " " << endl;
#define         PI         acos(-1)


vl v,tmp;

int main()
{


    optimize

    ll i,j,k,l,m,n;

    cin >> n;

    for(i=0; i<2*n; i++)
    {
        cin >> l;

        v.pb(l);
        tmp.pb(l);
    }

    ll cnt=0,ck;

    ll ts=-1;

    while(cnt<=n)
    {
         ck=0;

        for(i=0; i<2*n; i++)
        {
            if(tmp[i]!=i+1)
            {
                ck=1;
                break;
            }
        }
        if(!ck)
        {
            ts=cnt;
            break;
        }

        if(cnt%2==0)
        {
            for(i=0; i<2*n-1; i+=2)
            {
                swap(tmp[i],tmp[i+1]);
            }
        }
        else
        {
            for(i=0; i<n; i++)
            {
                swap(tmp[i],tmp[i+n]);
            }
        }

        cnt++;
    }

    ll t1,t2;
    t1=ts;

  //  cout << t1 << endl;

    cnt=0;

    ts=-1;

    while(cnt<=n)
    {
         ck=0;

        for(i=0; i<2*n; i++)
        {
            if(v[i]!=i+1)
            {
                ck=1;
                break;
            }
        }
        if(!ck)
        {
            ts=cnt;
            break;
        }

        if(cnt%2)
        {
            for(i=0; i<2*n-1; i+=2)
            {
                swap(v[i],v[i+1]);
            }
        }
        else
        {
            for(i=0; i<n; i++)
            {
                swap(v[i],v[i+n]);
            }
        }

        cnt++;
    }

    t2=ts;

  //  cout << t1 << " " << t2 << endl;

    if(t1==-1)ts=t2;
    else if(t2==-1)ts=t1;
    else ts=min(t1,t2);

    cout << ts << endl;

}
