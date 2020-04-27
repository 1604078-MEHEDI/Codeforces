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
const int N = 10000006;
const int nx = 1e5 + 5;
const int prCnt = 700005;
int lp[N];
int prIdx[N];
vector<int> pr;
void linearSieve()
{
	for (int i = 2; i < N; i++) {
		if (lp[i] == 0) {
			lp[i] = i;
			prIdx[i] = pr.size();
			pr.push_back(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < N; j++)
			lp[i * pr[j]] = pr[j];
	}
}
vector<int> g[nx];
int parent[nx][17];
int lvl[nx];
int in[nx], out[nx];
int tim;
ll a[nx];

vector<int> primeOccur[prCnt][24];
vector<int> invOccur[prCnt][24];

inline void primeFactorization(int x, vector<int> &rt)
{
	while (x > 1) {
		int g = lp[x];
		rt.push_back(prIdx[g]);
		rt.push_back(0);
		while (x % g == 0) {
			x /= g;
			rt[rt.size() - 1]++;
		}
	}
}

int lca(int a, int b)
{
	if (lvl[a] < lvl[b])swap(a, b);
	for (int k = 16; k >= 0; k--) {
		if (lvl[a] - (1 << k) >= lvl[b])
			a = parent[a][k];
	}
	if (a == b)return a;
	for (int k = 16; k >= 0; k--) {
		if (parent[a][k] != parent[b][k]) {
			a = parent[a][k];
			b = parent[b][k];
		}
	}
	return parent[a][0];
}

void dfs(int u, int p)
{
	in[u] = ++tim;
	vector<int> fct;
	primeFactorization(a[u], fct);
	for (int i = 0; i + 1 < (int)fct.size(); i += 2) {
		primeOccur[fct[i]][fct[i + 1]].push_back(in[u]);
	}
	lvl[u] = 1 + lvl[p];
	parent[u][0] = p;
	for (int k = 1; k <= 16; k++) {
		parent[u][k] = parent[parent[u][k - 1]][k - 1];
	}
	for (auto v : g[u]) {
		if (p == v)continue;
		dfs(v, u);
	}
	out[u] = ++tim;

	for (int i = 0; i + 1 < (int) fct.size(); i += 2) {
		invOccur[fct[i]][fct[i + 1]].push_back(out[u]);
	}
}

ll subQuery(int lc, int u, const vector<int>& xfct)
{
	ll rt = 1;
	ll st = in[lc];
	ll ed = in[u];
	for (int i = 0; i + 1 < (int) xfct.size(); i += 2) {
		ll sm = 0;
		for (int j = 1; j < 24; j++) {
			ll tm = 0;
			tm += upper_bound(primeOccur[xfct[i]][j].begin(), primeOccur[xfct[i]][j].end(), ed) -
			      lower_bound(primeOccur[xfct[i]][j].begin(), primeOccur[xfct[i]][j].end(), st);

			tm -= upper_bound(invOccur[xfct[i]][j].begin(), invOccur[xfct[i]][j].end(), ed) -
			      lower_bound(invOccur[xfct[i]][j].begin(), invOccur[xfct[i]][j].end(), st);

			sm += tm * min(j, xfct[i + 1]);
		}
		rt = modMul(rt,  modPow(pr[xfct[i]], sm));
	}
	return rt;
}

ll Query(int u, int v, int x)
{
	int lc = lca(u, v);
	vector<int> fct;
	primeFactorization(x, fct);
	ll up = subQuery(lc, u, fct);
	ll vp = subQuery(lc, v, fct);
	up = modMul(up, vp);
	up = modMul(up, modInverse(__gcd(a[lc], (ll) x)));
	return up;
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
	linearSieve();
	int n;
	si(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		sii(u, v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)sl(a[i]);
	dfs(1, 0);
	int q;
	si(q);
	while (q--) {
		int u, v, x;
		siii(u, v, x);
		printf("%lld\n", Query(u, v, x));
	}
	return 0;
}