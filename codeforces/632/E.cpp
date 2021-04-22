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
#define sline(a) scanf("%[^\n]s",a)
#define Case(t) printf("Case %d:\n",t)

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, -1, 0, 1, -1, 0, 1};
int kx8[] = {1, 1, 2, 2, -1, -1, -2, -2};
int ky8[] = {2, -2, 1, -1, 2, -2, 1, -1};
/* for Random Number generate
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//*/
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
// const int N = 1000006;




typedef complex<double> CD;
struct FFT {
    int N;
    vector<int> perm;

    void precalculate() {
        perm.resize(N);
        perm[0] = 0;

        for (int k = 1; k < N; k <<= 1) {
            for (int i = 0; i < k; i++) {
                perm[i] <<= 1;
                perm[i + k] = 1 + perm[i];
            }
        }
    }

    void fft(vector<CD> &v, bool invert = false) {
        if (v.size() != perm.size()) {
            N = v.size();
            assert(N && (N & (N - 1)) == 0);
            precalculate();
        }

        for (int i = 0; i < N; i++)
            if (i < perm[i])
                swap(v[i], v[perm[i]]);

        for (int len = 2; len <= N; len <<= 1) {
            double angle = 2 * PI / len;
            if (invert) angle = -angle;
            CD factor = polar(1.0, angle);

            for (int i = 0; i < N; i += len) {
                CD w(1);
                for (int j = 0; j < len / 2; j++) {
                    CD x = v[i + j], y = w * v[i + j + len / 2];
                    v[i + j] = x + y;
                    v[i + j + len / 2] = x - y;
                    w *= factor;
                }
            }
        }
        if (invert)
            for (CD &x : v) x /= N;
    }

    vector<bool> multiply(const vector<bool> &a, const vector<bool> &b) {
        vector<CD> fa(a.begin(), a.end()), fb(b.begin(), b.end());

        int n = 1;
        while (n < (int) (a.size() + b.size()))  n <<= 1;
        fa.resize(n);
        fb.resize(n);

        fft(fa);
        fft(fb);
        for (int i = 0; i < n; i++) fa[i] *= fb[i];
        fft(fa, true);

        vector<bool> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = round(fa[i].real());
        return ans;
    }
} fft;

vector<bool> FastExpo(vector<bool>v, int p) {
    vector<bool> ret({1});
    while (p > 0) {
        if (p & 1)ret = fft.multiply(ret, v);
        p /= 2;
        v = fft.multiply(v, v);
    }
    return ret;
}


const int M = 1005;
bool vis[M];
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
    for (int cs = 1; cs <= T; cs++) {
        int n, k, x;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            vis[x] = 1;
        }
        vector<bool>a;
        for (int i = 0; i < M; i++) {
            a.push_back(vis[i]);
        }
        auto ans = FastExpo(a, k);
        // dbg(ans);
        for (int i = 0; i < (int)ans.size(); i++) {
            if (ans[i] > 0)cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}