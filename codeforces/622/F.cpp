#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 100005
#define tc printf("Case %d: ", cs)
#define tcn printf("Case %d:\n", cs);
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);

#define dbg1(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define dbg4(w,x, y, z) cerr << #w << " = " << w << ", " <<#x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    for (auto it = v.begin(); it != v.end(); ++it) {
        if ( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    for (auto it = v.begin(); it != v.end(); ++it) {
        if ( it != v.begin()) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    for (auto it = v.begin(); it != v.end(); ++it) {
        if ( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)

void faltu () { cerr << endl; }

template <typename T>
void faltu( T a[], int n ) {
    for (int i = 0; i < n; ++i) cerr << a[i] << ' ';
    cerr << endl;
}

template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) { cerr << arg << ' '; faltu(rest...); }
// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less 
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

/**___________________________________________________**/
const int nx = 1e6 + 6;
const int Mod = 1e9 + 7;

ll n, k;
ll val[nx];
ll ans, cur;
ll power(ll a, ll b)    //a is base, b is exponent
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (b % 2 == 1)
        return (power(a, b - 1) * a) % Mod;
    ll q = power(a, b / 2);
    return (q * q) % Mod;
}


int main()
{
    FASTIO
    ///*
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
//*/

    cin >> n >> k;
    for (ll i = 1;  i <= k + 2; i++) {
        val[i] = (val[i - 1] + power(i, k)) % Mod;
    }
    if (n <= k + 2) {
        cout << val[n] << endl;
        return 0;
    }

    ans = 0ll;
    cur = 1ll;
    for (ll i = 2; i <= k + 2; i++) {
        cur = (1ll * cur * (n - i)) % Mod;
        cur = (1ll * cur * power(Mod + 1ll - i, Mod - 2)) % Mod;
    }

    for (ll i = 1; i <= k + 2; i++) {
        ans = (ans + 1ll * cur * val[i]) % Mod;
        cur = (1ll * cur * (n - i)) % Mod;
        cur = (1ll * cur * (i - k - 2 + Mod)) % Mod;
        cur = (1ll * cur * power((1ll * (n - i - 1) * i) % Mod, Mod -  2)) % Mod;
    }
    cout << ans << endl;
    return 0;
}