/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
using pii = pair<int, int>;
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
#define REP(i,n) for(int i = 0; i < (n); i++)

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, -1, 0, 1, -1, 0, 1};
int kx8[] = {1, 1, 2, 2, -1, -1, -2, -2};
int ky8[] = {2, -2, 1, -1, 2, -2, 1, -1};
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


const int N = 200006;
const int inf = 2 * mod;
int a[N];
pii sg[4 * N];

void build(int id, int b, int e) {
    if (b == e) {
        sg[id] = {a[b], a[b]};
        return;
    }
    int Left = 2 * id, Right = Left + 1, mid = (b + e) / 2;
    build(Left, b, mid);
    build(Right, mid + 1, e);
    sg[id].first = max(sg[Left].first, sg[Right].first);
    sg[id].second = min(sg[Left].second, sg[Right].second);
}

pii query(int id, int b, int e, int l, int r) {
    if (b > r || e < l) return {0, inf};
    if (b >= l && e <= r) return sg[id];
    int Left = 2 * id, Right = Left + 1, mid = (b + e) / 2;
    pii p1, p2;
    p1 = query(Left, b, mid, l, r);
    p2 = query(Right, mid + 1, e, l, r);
    return {max(p1.first, p2.first), min(p1.second, p2.second)};
}


//Credit:  bi11a1

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
    int T;
    T = 1;
    //scanf("%d", &T);
    cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)cin >> a[i];
        build(1, 0, n - 1);
        int i, mx = 0, l, r, mid, ans;
        pii P;
        for (i = 0; i < n; i++) {
            mx = max(mx, a[i]);

            // left-max
            l = i + 2, r = n - 1, ans = -1;
            while (l <= r) {
                mid = (l + r) / 2;
                P = query(1, 0, n - 1, mid, n - 1);
                if (P.first == mx) {
                    ans = mid;
                    r = mid - 1;
                }
                else if (P.first < mx) r = mid - 1;
                else l = mid + 1;
            }
            if (ans == -1)continue;
            int lft = ans;
            //dbg(lft);

            // right-max
            l = lft, r = n - 1, ans = -1;
            while (l <= r) {
                mid = (l + r) / 2;
                P = query(1, 0, n - 1, mid, n - 1);
                if (P.first == mx) {
                    ans = mid;
                    l = mid + 1;
                }
                else if (P.first < mx) r = mid - 1;
                else l = mid + 1;
            }

            if (ans == -1)continue;
            int rgt = ans;

           // dbg(lft, rgt);


            // mid-min
            l = lft - 1, r = rgt - 1, ans = -1;
            while (l <= r) {
                mid = (l + r) / 2;
                P = query(1, 0, n - 1, i + 1, mid);
                if (P.second == mx) {
                    ans = mid;
                    break;
                }
                else if (P.second < mx) r = mid - 1;
                else l = mid + 1;
            }

            if (ans == -1)continue;
            //dbg(lft, rgt, ans);
           // dbg(i,ans);
            cout << "YES\n";
            cout << i + 1 << " " << ans - i << " " << n - ans - 1 << "\n";
            break;
        }
        if (i == n)cout << "NO\n";
    }
    return 0;
}