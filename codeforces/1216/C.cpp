/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

inline void normal(ll &a) { a %= mod; (a < 0) && (a += mod); }
inline ll modMul(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a * b) % mod; }
inline ll modAdd(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a + b) % mod; }
inline ll modSub(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while (p) { if (p & 1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define slll(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ss(ch) scanf("%s",ch)
#define pi(x) printf("%d",x)
#define pii(x,y) printf("%d %d",x,y)
#define piii(x,y,z) printf("%d %d %d",x,y,z)
#define pl(x) printf("%lld",x)
#define pll(x,y) printf("%lld %lld",x,y)
#define plll(x,y,z) printf("%lld %lld %lld",x,y,z)
#define ps(ch) printf("%s",ch)
#define F(i,a,b)      for(int i= a; i <= b; i++)
#define R(i,b,a)      for(int i= b; i >= a; i--)

/* for Random Number generate
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
*/
///**
template < typename F, typename S >ostream& operator << ( ostream& os, const pair< F, S > & p ) {return os << "(" << p.first << ", " << p.second << ")";}
template < typename T >ostream &operator << ( ostream & os, const vector< T > &v ) {os << "{"; for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin() ) os << ", "; os << *it;} return os << "}";}
template < typename T >ostream &operator << ( ostream & os, const set< T > &v ) {os << "["; for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin()) os << ", "; os << *it;} return os << "]";}
template < typename F, typename S >ostream &operator << ( ostream & os, const map< F, S > &v ) {os << "["; for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin() ) os << ", "; os << it -> first << " = " << it -> second ;} return os << "]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
void faltu () { cerr << endl; }
template <typename T>void faltu( T a[], int n ) {for (int i = 0; i < n; ++i) cerr << a[i] << ' '; cerr << endl;}
template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) { cerr << arg << ' '; faltu(rest...); }

// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less 
using namespace __gnu_pbds;

// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;
// find_by_order(k) – ফাংশনটি kth ordered element এর একটা পয়েন্টার রিটার্ন করে। অর্থাৎ তুমি চাইলেই kth ইন্ডেক্সে কি আছে, সেটা জেনে ফেলতে পারছো!
// order_of_key(x) – ফাংশনটি x এলিমেন্টটা কোন পজিশনে আছে সেটা বলে দেয়।
//*//**___________________________________________________**/
const int N = 1000006;

int a[4][5];
bool dp[N];

void go(int l, int r)
{
    memset(dp, false, sizeof dp);
   // dbg(l, r, a[0][l], a[0][r]);
    for (int i = a[0][l]; i < a[0][r]; i++)
        dp[i] = true;
    //dbg(l, r, a[1][l], a[1][r]);
    for (int i = a[1][l]; i < a[1][r]; i++)
        dp[i] = false;
   // dbg(l, r, a[2][l], a[2][r]);
    for (int i = a[2][l]; i < a[2][r]; i++)
        dp[i] = false;
}

bool isOutside(int x, int y, int i)
{
    int p = a[i][0], q = a[i][1], r = a[i][2], s = a[i][3];
    // dbg(x, y);
    if (x < p || x > r || y < q || y > s)return true;
    return false;
}

int main()
{
    //FASTIO
    ///*
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
//*/
    for (int t = 0; t < 3; t++) {
        for (int i = 0; i < 4; i++) {
            cin >> a[t][i];
        }
    }

    go(0, 2);
    for (int i = 0; i < N; i++)
        if (dp[i]) {
            cout << "YES\n";
            return 0;
        }


    go(1, 3);
    for (int i = 0; i < N; i++)
        if (dp[i]) {
            cout << "YES\n";
            return 0;
        }


    //We check if there is any corner which is outside BOTH black sheet !

    // Coordinates of Corners of White Sheet
    /*
        Diagramatic Representation of White Sheet

        (d_x,d_y) _________ (c_x,x_y)
                 |         |
                 |         |
       (a_x,a_y) |_________| (b_x,b_y)

    */

    int a_x = a[0][0];
    int a_y = a[0][1];

    int b_x = a[0][2];
    int b_y = a[0][1];

    int c_x = a[0][2];
    int c_y = a[0][3];

    int d_x = a[0][0];
    int d_y = a[0][3];
    // dbg(a_x, a_y);
    // dbg(b_x, b_y);
    // dbg(c_x, c_y);
    // dbg(d_x, d_y);

    if (isOutside(a_x, a_y, 1) && isOutside(a_x, a_y, 2)) {
        cout << "YES\n"; return 0;
    }
    else if (isOutside(b_x, b_y, 1) && isOutside(b_x, b_y, 2)) {
        cout << "YES\n"; return 0;
    }
    else if (isOutside(c_x, c_y, 1) && isOutside(c_x, c_y, 2)) {
        cout << "YES\n"; return 0;
    }
    else if (isOutside(d_x, d_y, 1) && isOutside(d_x, d_y, 2)) {
        cout << "YES\n"; return 0;
    }
    cout << "NO\n";
    return 0;

}