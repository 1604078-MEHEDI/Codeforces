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

const int N = 2e5 + 5;
int cost[N], man[N];
bool done[N];
vector<int>idx[N];
//int a[N];
int Tree[4 * N];

void build(int u, int s, int e)
{
	if (s == e) {
		Tree[u] = s;
	} else {
		int m = (s + e) >> 1;
		build(2 * u, s, m);
		build(2 * u + 1, m + 1, e);
		Tree[u] = max(Tree[u * 2], Tree[2 * u + 1]);
	}
}

int query(int u, int s, int e, int l, int r)
{
	if (r < s || e < l) return 0;
	else if (l <= s && e <= r) return Tree[u];
	else {
		int m = (s + e) >> 1;
		int x = query(2 * u, s, m, l, r);
		int y = query(2 * u + 1, m + 1, e, l, r);
		return max (x, y);
	}
}

void update(int u, int s, int e, int idx, int x)
{
	if (s == e) {
		Tree[u] = x;
	} else {
		int m = (s + e) >> 1;
		if (idx <= m)update(2 * u, s, m, idx, x);
		else update(2 * u + 1, m + 1, e, idx, x);
		Tree[u] = max(Tree[2 * u], Tree[2 * u + 1]);
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
	int T;
	//scanf("%d", &T);
	T = 1;
	cin >> T;
	for (int cs = 1; cs <= T; cs++) {
		int n;
		cin >> n;
		ll sm = 0;
		vector<pair<int, int>> v;
		for (int i = 1; i <= n; i++) {
			cin >> man[i] >> cost[i];
			sm += cost[i];
			v.push_back({cost[i], i});
		}
		sort(v.rbegin(), v.rend());
		build(1, 1, n);

		for (auto x : v) {
			int u = x.second;
			int v = query(1, 1, n, 1, n - man[u]);
			if (v == 0)continue;
			update(1, 1, n, v, 0);
			sm -= cost[u];
		}
		cout << sm << endl;
	}
	return 0;
}