/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
//using PLL = pair<ll, ll>;
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


using PLL = pair<ll, ll>;


const PLL M = make_pair(1e9 + 7, 1e9 + 9); ///Should be large primes
const ll base = 10;                 ///Should be a prime larger than highest value
const int N = 1e6 + 7;              ///Highest length of string

ostream& operator<<(ostream& os, PLL hash) {
    return os << "(" << hash.first << ", " << hash.second << ")";
}


PLL operator+ (PLL a, ll x)     {return make_pair(a.first + x, a.second + x);}
PLL operator- (PLL a, ll x)     {return make_pair(a.first - x, a.second - x);}
PLL operator* (PLL a, ll x)     {return make_pair(a.first * x, a.second * x);}
PLL operator+ (PLL a, PLL x)    {return make_pair(a.first + x.first, a.second + x.second);}
PLL operator- (PLL a, PLL x)    {return make_pair(a.first - x.first, a.second - x.second);}
PLL operator* (PLL a, PLL x)    {return make_pair(a.first * x.first, a.second * x.second);}
PLL operator% (PLL a, PLL m)    {return make_pair(a.first % m.first, a.second % m.second);}

PLL pb[N];
void Init() {
    pb[0] = make_pair(1, 1);
    for (int i = 1; i < N; i++)
        pb[i] = (pb[i - 1] * base) % M;
}

vector<PLL> hashList(string s) {
    int n = s.size();
    vector<PLL> ans(n + 1);
    ans[0] = make_pair(0, 0);

    for (int i = 1; i <= n; i++)
        ans[i] = (ans[i - 1] * base + (s[i - 1] - '0')) % M;
    return ans;
}

PLL Hash(vector<PLL> &hashlist, int l, int r) {
    int len = (r - l + 1);
    return ((hashlist[r] - hashlist[l - 1] * pb[len]) % M + M) % M;
}
vector<PLL> hashes;
string s;
int n;

bool Check(int i, int j) {
    if (!(0 < i && i < j && j < n)) return 0;
    if (i > 1 && s[0] == '0')return 0;
    if (j > i + 1 && s[i] == '0') return 0;
    if (n > j + 1 && s[j] == '0') return 0;

    PLL l = Hash(hashes, 1, i);
    PLL r = Hash(hashes, i + 1, j);
    PLL s = Hash(hashes, j + 1, n);
    return (l + r) % M == s;
}

void go(int i, int j) {
    if (Check(i, j)) {
        string t = s;
        t.insert(t.begin() + j, '=');
        t.insert(t.begin() + i, '+');
        cout << t << "\n";
        exit(0);
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
    Init();
    cin >> s;
    n = s.size();
    hashes = hashList(s);
    for (int i  = 1; i <= n; i++) {
        int len = n - i;
        go(len - 1, i);
        go(len, i);
        go(i - len, i);
        go(i - len + 1, i);
    }
    return 0;
}