#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define inf 2000000000
#define infLL 2000000000000000000
#define MAX5 100005
#define MAX6 1000006
#define MAX7 10000007
#define sf(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sfs(a) scanf("%s", a)
#define sline(a) scanf("%[^\n]%*c", a);
#define pf(a) printf("%d\n", a)
#define pfl(a) printf("%lld\n", a)
#define pfs(a) printf("%s\n", a)
#define Case(t) printf("Case %d: ", t)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mod 1000000007
#define Mod 998244353
#define PI acos(-1.0)
#define eps 1e-9
#define mem(a, b) memset(a, b, sizeof(a))
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

const int N = MAX7;

ll d[N], ans[N];

void divisors() {
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j+=i) {
            d[j]+=i;
        }
    }
}

int main()
{
    //#ifndef ONLINE_JUDGE
    //    freopen("in.txt","r",stdin);
    //    freopen("out.txt","w",stdout);
    //#endif

    FASTIO;
    divisors();
    for(int i = 1; i < N; i++) {
        if(d[i] < N && ans[d[i]]==0) {
            ans[d[i]] = i;
        }
    }
    int T;
    sf(T);
    while(T--) {
        int n;
        sf(n);
        if(ans[n]==0) pf(-1);
        else pfl(ans[n]);
    }
    
    return 0;
}