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


/* for Random Number generate
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
*/
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

const int N = 1e6 + 6;
int lp[N], dist[N];
vector<int> d[N], v[N], pr;
vector<vector<int> > e;
int ans;
void init()
{
	pr.push_back(1);
	for (int i = 2 ; i < N; i++) {
		if (!lp[i]) {
			pr.push_back(i);
			for (int j = i; j < N; j += i)
				lp[j] = i;
		}
		d[i] = d[i / lp[i]];
		auto it = find(d[i].begin(), d[i].end(), lp[i]);
		if (it != d[i].end()) d[i].erase(it);
		else d[i].push_back(lp[i]);
	}
}

void bfs()
{
	//dbg(ans);
	for (int i : pr) {
		if (i * i > N)break;
		for (int j : pr)
			dist[j] = 0;
		//dbg(ans);
		queue<pair<int, int>> Q;
		for (int j : v[i]) {
			Q.push({j, (e[j][0] == i)});
			dist[e[j][0] ^ e[j][1] ^ i] = 1;
		}
		//dbg(ans);
		while (!Q.empty()) {
			//dbg(ans);
			auto p = Q.front();
			Q.pop();
			int node = e[p.first][p.second];
			for (auto  u : v[node]) {
				if (u != p.first) {
					pair<int, int> np(u, e[u][0] == node);
					int nn = e[np.first][np.second];
					if (!dist[nn] && nn != i) {
						Q.push(np);
						dist[nn] = dist[node] + 1;
					}
					else ans = min(ans, dist[node] + dist[nn] + 1);
				}
			}
		}
	}
	//dbg(ans);
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
	init();
	int n;
	ans = mod;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (d[x].empty()) {
			cout << 1 << endl;
			return 0;
		}
		if (d[x].size() == 1) d[x].push_back(1);
		e.push_back({d[x][0], d[x][1]});
		v[d[x][0]].push_back(i);
		v[d[x][1]].push_back(i);
	}
	//dbg(ans);
	bfs();
	//dbg(ans);
	if (ans == mod) ans = -1;
	cout << ans << endl;
	return 0;
}