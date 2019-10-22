//Lagrange Polynomial
//lagrange(n,k) = 1^k + 2^k + 3^k + ... + n^k modulo Prime
//Complexity : O(k log (MOD))
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

const ll Mod = 1e9 + 7;
const int MX = 1000010;

namespace lgr {
short factor[MX];
int P[MX], S[MX], a[MX], inv[MX];

inline  ll power(ll a, ll b)    //a is base, b is exponent
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

int lagrange(ll n, int k) {
    if (!k) return (n % Mod);
    if (!inv[0]) {
        int x = 1;
        for (int i = 2; i < MX; i++) x = ((ll)x * i) % Mod;
        inv[MX - 1] = power(x, Mod - 2);
        for (int i = MX - 2; i >= 0; i--)
            inv[i] = ((ll)inv[i + 1] * (i + 1)) % Mod;
    }
    k++;
    for (int i = 0; i <= k; i++) factor[i] = 0;
    for (int i = 4; i <= k; i += 2) factor[i] = 2;
    for (int i = 3; (i * i) <= k; i += 2) {
        if (!factor[i])
            for (int j = (i * i), x = (i << 1); j <= k; j += x)
                factor[j] = i;
    }

    a[1] = 1;
    a[0] = 0;
    for (int i = 2; i <= k; i++) {
        if (!factor[i]) a[i] = power(i, k - 1);
        else a[i] = ((ll)a[factor[i]] * a[i / factor[i]]) % Mod;

    }
    for (int i = 1; i <= k; i++) {
        a[i] += a[i - 1];
        if (a[i] >= Mod) a[i] -= Mod;
    }
    if (n <= k) return a[n];

    P[0] = 1;
    S[k] = 1;
    for (int i = 1; i <= k; i++)
        P[i] = ((ll)P[i - 1] * ((n - i + 1) % Mod)) % Mod;
    for (int i = k - 1; i >= 0; i--)
        S[i] = ((ll)S[i + 1] * ((n - i - 1) % Mod)) % Mod;
    int res = 0;
    for (int i = 0; i <= k; i++) {
        int x = (ll)a[i] * P[i] % Mod * S[i] % Mod * inv[k - i] % Mod * inv[i] % Mod;
        if ((k - i) & 1) {
            res -= x;
            if (res < 0) res += Mod;
        }
        else {
            res += x;
            if (res >= Mod) res -= Mod;
        }
    }
    return (res % Mod);
}
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
    ll n;
    int k;
    cin >> n >> k;
    cout << lgr::lagrange(n, k) << endl;
    return 0;
}