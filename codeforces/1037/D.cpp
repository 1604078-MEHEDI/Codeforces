#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 1000005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;

inline void normal(ll &a) { a %= mod; (a < 0) && (a += mod); }
inline ll modMul(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a * b) % mod; }
inline ll modAdd(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a + b) % mod; }
inline ll modSub(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while (p) { if (p & 1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }


///**
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

// find_by_order(k) – ফাংশনটি kth ordered element এর একটা পয়েন্টার রিটার্ন করে। অর্থাৎ তুমি চাইলেই kth ইন্ডেক্সে কি আছে, সেটা জেনে ফেলতে পারছো!
// order_of_key(x) – ফাংশনটি x এলিমেন্টটা কোন পজিশনে আছে সেটা বলে দেয়।

//*//**___________________________________________________**/

const int N = 2e5 + 5;
vector<int> g[N];
bool vis[N];
bool ts[N];
vector<int> check, ans;
int cm[N];

void bfs(int s)
{
	queue<int> Q;
	Q.push(s);
	vis[s] = true;
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		ans.push_back(u);
		for (auto v : g[u]) {
			if (vis[v])continue;
			vis[v] = true;
			Q.push(v);
		}
	}
}

bool cmp(int a, int b)
{
	return cm[a] < cm[b];
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
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	check = vector<int> (n + 1);
	for (int i = 0; i < n; i++) {
		cin >> check[i];
		cm[check[i]] = i;
	}

	for (int i = 1; i <= n; i++) {
		sort(g[i].begin(), g[i].end(), cmp);
	}

	bfs(1);
	ans.push_back(0);
	//dbg(ans);
	//dbg(check);
	if (ans == check) puts("Yes");
	else puts("No");
	return 0;
}