#include <bits/stdc++.h>

#define       pb                 push_back
#define       sf                 scanf
#define       pf                 printf
#define       sz                 100005
#define       MOD                1000000007
#define       optimize           ios::sync_with_stdio(0);cin.tie(0);
#define       inf                0x3f3f3f3f
#define       READ               freopen("in.txt", "r", stdin);
#define       WRITE              freopen("out.txt", "w", stdout);

using namespace std;

typedef       long long int      ll;

int main()
{
    // READ
    optimize

    int tc;
    
    cin >> tc;
    
    while(tc--)
    {
    	ll n, m, a, b, time = 0;

    	cin >> n >> m >> a >> b; vector <ll> ar(m);

    	for(ll i = 0; i < m; i++) cin >> ar[i];

    	sort(ar.rbegin(), ar.rend());

    	if(b>=a) time = b-1;
    	else time = n-b;

    	ll fat = abs(a-b)-1;

    	ll in = 1, cn = 0;

    	for(ll i = 0; i < m; i++)
    	{
    		if(ar[i]+in<=time)
    		{
    			in++;
    			cn++;
    		}
    	}

    	cout << min(fat, cn) << endl;
    }


    return 0;
}