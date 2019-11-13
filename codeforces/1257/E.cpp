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

const int N = 2e5 + 7;
const int inf = 1e9 + 7;
int id[N];
int cnt[3];
vector<int> v[3];

int a[N];
int tr[4 * N];
int lz[4 * N];


//1. merge left and right
int combine(int lft, int rgt)
{
	return min(lft, rgt);
}

//2. push lazy down and merge lazy
void propagate(int u, int l, int r)
{
	tr[u] += lz[u];
	if (l != r) {
		lz[2 * u] += lz[u];
		lz[2 * u + 1] += lz[u];
	}
	lz[u] = 0;
}

void update(int u, int s, int e, int l, int r, int x)
{
	propagate(u, s, e);
	if (r < s || e < l) return;
	else if (l <= s && e <= r) {
		lz[u] += x;             // 4.merge lazy
		propagate(u, s, e);
	}
	else {
		int mid = (s + e) / 2;
		update(2 * u, s, mid, l, r, x);
		update(2 * u + 1, mid + 1, e, l, r, x);
		tr[u] = combine(tr[2 * u], tr[2 * u + 1]);
	}
}

int query(int u, int s, int e, int l, int r)
{
	propagate(u, s, e);
	if (r < s || e < l) return inf; /// 5. Proper null value
	else if (l <= s && e <= r) return tr[u];
	else {
		int mid = (s + e) / 2;
		return combine(query(2 * u, s, mid, l, r), query(2 * u + 1, mid + 1, e, l, r));
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
	int n = 0;
	for (int i = 0; i < 3; i++) cin >> cnt[i];
	for (int i = 0; i < 3; i++) {
		int k = cnt[i];
		n += k;
		v[i].resize(k);
		for (int j = 0; j < k; j++) {
			cin >> v[i][j];
			id[v[i][j]] = i;
		}
	}

	int choto = cnt[0], boro = 0;
	int ans = inf;
	for (int i = n; i >= 0; i--) {
		int moves = i - choto + boro;
		int COUNT = query(1, 0, n, i, n);
		ans = min(ans, moves + COUNT);

		if (id[i] == 0) {choto--; boro++;}
		if (id[i] == 1) {update(1, 0, n, 0, i - 1, 1);}
		if (id[i] == 2) update(1, 0, n, i, n, 1);
	}
	cout << ans << endl;
}