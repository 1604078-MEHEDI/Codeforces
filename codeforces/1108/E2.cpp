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

int dx[]  = {0, 0, 1, -1};
int dy[]  = {1, -1, 0, 0};
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
const int N = 100006;
int tr[4 * N][2];
int lazy[4 * N];
int a[N],l[N], r[N];
int n, m;
vector<int> add_seg[N], del_seg[N];

void propagate(int node, int b, int e)
{
	if (lazy[node] == 0)return;
	tr[node][0]  += lazy[node];
	tr[node][1] += lazy[node];
	if (b != e) {
		lazy[2 * node] += lazy[node];
		lazy[2 * node + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void build(int node, int b, int e)
{
	if (b == e) {
		tr[node][0] = a[b];
		tr[node][1] = a[b];
		lazy[node] = 0;
		return;
	}
	int lc = node * 2;
	int rc = lc + 1;
	int mid = (b + e) >> 1;
	build(lc, b, mid);
	build(rc, mid + 1, e);
	tr[node][0] = min(tr[lc][0], tr[rc][0]);
	tr[node][1] = max(tr[lc][1], tr[rc][1]);
	lazy[node] = 0;
}

int Query(int t, int node, int b, int e, int l, int r)
{
	propagate(node, b, e);
	if (l > e || r < b)return 0;
	if (b >= l && e <= r)return tr[node][t];

	int lc = node * 2;
	int rc = lc + 1;
	int mid = (b + e) >> 1;
	int ql = Query(t,lc, b, mid, l, r);
	int qr = Query(t,rc, mid + 1, e, l, r);
	tr[node][0] = min(tr[lc][0], tr[rc][0]);
	tr[node][1] = max(tr[lc][1], tr[rc][1]);
	int ret;
	if (t)ret = max(ql, qr);
	else ret = min(ql, qr);
	return ret;
}

void update(int node, int b, int e, int l, int r, int x)
{
	propagate(node, b, e);
	if (l > e || r < b)return;
	if (b >= l && e <= r) {
		lazy[node] = x;
		propagate(node, b, e);
		return;
	}

	int lc = node * 2;
	int rc = lc + 1;
	int mid = (b + e) >> 1;
	update(lc, b, mid, l, r, x);
	update(rc, mid + 1, e, l, r, x);
	tr[node][0] = min(tr[lc][0], tr[rc][0]);
	tr[node][1] = max(tr[lc][1], tr[rc][1]);
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
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= m; i++) {
		cin >> l[i] >> r[i];
		add_seg[l[i]].push_back(i);
		del_seg[r[i]].push_back(i);
	}

	int ans, id, mx = a[1], mn = a[1];
	int ok = 0;
	for (int i = 1; i <= n; i++) {
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	ans = mx - mn;
	if (m == 0) {
		cout << ans << "\n" << 0 << "\n";
		return 0;
	}
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		int k = add_seg[i].size();
		for (int j = 0; j < k; j++) {
			int seg = add_seg[i][j];
			update(1, 1, n, l[seg], r[seg], -1);
		}
		mx = Query(1, 1, 1, n, 1, n);
		mn = Query(0, 1, 1, n, 1, n);
		int cur = mx - mn;
		if (cur > ans) {
			ans = cur;
			id = i;
			ok = 1;
		}
		k = del_seg[i].size();
		for (int j = 0; j < k; j++) {
			int seg = del_seg[i][j];
			update(1, 1, n, l[seg], r[seg], +1);
		}
	}
	cout << ans << "\n";
	if (!ok) {
		cout << 0 << "\n";
		return 0;
	}
	vector<int> res;
	for (int i = 1; i <= m; i++) {
		if (l[i] <= id && r[i] >= id)res.push_back(i);
	}

	cout << (int)res.size() << '\n';
	for (auto &x : res)
		cout << x << " ";
	return 0;
}