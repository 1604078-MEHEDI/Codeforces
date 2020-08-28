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
const int N = 200006;

// CONVEX HULL TRICK

/* Instructions
-> For Linear Version:
1. Sort lines based on decreasing M and in case of tie, increasing B.
2. Sort query points according to increasing X.
3. Clear the class, add all lines and then query.
*/


ll dp[N], tm[N];
ll cost[N], val[N], sm[N];

inline ll getConst(ll u) {
	return dp[u] + u * sm[u] - cost[N];
	// constant part: *** EDIT HERE ***
}


// dp when last partition ended at u and this one ends at v
inline ll getDP(ll u, ll v) {
	return cost[v] - v * sm[u] + getConst(u);
	// partition equation: *** EDIT HERE ***
}

// derived from equation above
// m = -sum[u]
// c = getconst(u)
// have to minimize m*sum[v] + c
// have to maximize -m*sum[v] - c

/*
Convex Hull Linear
needs increasing x/decreasing slopes
Minimizes Result: mx + b
Insert lines with slope = m, const = b
Query best result for x with eval(x)
Complexity: N [ for infinite partition ], NK [ for K partition ]
*/

class HullLinear
{
	int pointer;////Keeps track of the best line from previous query
	vector<ll> M; ////Holds the slopes of the lines in the envelope
	vector<ll> B; ////Holds the y-intercepts of the lines in the envelope

	//Returns true if line l3 is always better than line l2
	bool bad(int l1, int l2, int l3) {
		/*
		intersection(l1,l2) has x-coordinate (b1-b2)/(m2-m1)
		intersection(l1,l3) has x-coordinate (b1-b3)/(m3-m1)
		set the former greater than the latter, and cross-multiply to
		eliminate division. use deterministic comuputation with long
		long if sufficient.
		*/
		return (B[l3] - B[l1]) * (M[l1] - M[l2]) > (B[l2] - B[l1]) * (M[l1] - M[l3]);
	}
public:
	void Clear() {
		pointer = 0;
		M.clear();
		B.clear();
	}

	//Adds a new line (with lowest slope) to the structure
	void Insert(ll m, ll b) {
		if (M.size() > 0 && M.back() == m)return;///Same Gradient. Don't add.
		//First, let's add it to the end
		M.push_back(m);
		B.push_back(b);
		//If the penultimate is now made irrelevant between the antepenultimate
		//and the ultimate, remove it. Repeat as many times as necessary
		while (M.size() >= 3 && bad(M.size() - 3, M.size() - 2, M.size() - 1)) {
			M.erase(M.end() - 2);
			B.erase(B.end() - 2);
		}
	}

	//Returns the minimum y-coordinate of any intersection between a given vertical
	//line and the lower envelope
	ll Eval(ll x) {
		// Any better line must be to the right, since query values are
		//non-decreasing
		while (pointer < (int) M.size() - 1 && M[pointer + 1]*x + B[pointer + 1] < M[pointer]*x + B[pointer]) {
			pointer++;
		}
		return M[pointer] * x + B[pointer];
	}
	ll calcCost(ll p, ll x) {
		return M[p] * x + B[p];
	}

	ll onelineQuery(ll x) {
		ll l = 0, r = M.size() - 1;
		ll ret = LLONG_MIN;
		while (abs(l - r) > 3) {
			ll mid_l = (2 * l + r) / 3;
			ll mid_r = (l + 2 * r) / 3;
			if (calcCost(mid_l, x) > calcCost(mid_r, x)) {
				r = mid_r;
				ret = max(ret, calcCost(mid_l, x));
			}
			else l = mid_l;
		}
		for (int i = l; i <= r; i++)
			ret = max(ret, calcCost(i, x));
		return ret;
	}
} CHT;

int n;
ll a[N], suff[N], pref[N];
void solve() {
	for (int i = 1; i <= n; i++) {
		suff[i] = suff[i - 1];
		suff[i] += i * a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	CHT.Clear();
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		//dbg(i);
		ans = max(ans, a[i]);
		ll x = pref[i];
		if (i > 1) {
			ll ret = CHT.onelineQuery(x) + suff[i];
			ans = max(ans, ret);
		}
		ll m = -(i - 1);
		ll b = (i - 1) * pref[i-1] - suff[i - 1];
		CHT.Insert(m, b);
	}
	cout << ans << "\n";
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
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	solve();
	///cout << solve() << "\n";
	return 0;
}