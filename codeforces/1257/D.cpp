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
int n, m;
int a[N];
int tr[4 * N];
vector<pair<int, int> > heros;
int days[N];

void init(int node, int l, int r)
{
	if (l == r) {
		tr[node] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	int lft = 2 * node;
	int rgt = lft + 1;
	init(lft, l, mid);
	init(rgt, mid + 1, r);
	tr[node] = max(tr[lft], tr[rgt]);
}

int query(int node, int b, int e, int l, int r)
{
	if (l > e || r < b) return 0;
	if (b >= l && e <= r) return tr[node];
	int mid = (b + e) / 2;
	int lft = 2 * node;
	int rgt = lft + 1;
	int q1 = query(lft, b, mid, l, r);
	int q2 = query(rgt, mid + 1, e, l, r);
	return max(q1, q2);
}

bool check(int l, int r)
{
	int mx = query(1, 1, n, l, r);
	int lw = lower_bound(heros.begin(), heros.end(), make_pair(mx, -1)) - heros.begin();
	int tot = days[lw];
	if (tot >= r - l + 1) return true;
	else return false;
}

int calc(int pos)
{
	int lw = 1, hi = n - pos + 1;
	int best = 0;
	while (lw <= hi) {
		int mid = (lw + hi) / 2;
		if (check(pos, pos + mid - 1)) {
			best = mid;
			lw = mid + 1;
		}
		else hi = mid - 1;
	}
	return best;
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
		heros.clear();
		cin >> n;
		int mxMonster = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			mxMonster = max(mxMonster, a[i]);
		}
		bool flag = false;

		cin >> m;
		for (int i = 1; i <= m; i++) {
			int p, s;
			cin >> p >> s;
			if (p >= mxMonster) flag = true;
			heros.push_back({p, s});
		}
		if (!flag) {
			cout << -1 << endl;
			continue;
		}

		init(1, 1, n);

		sort(heros.begin(), heros.end());
		int cur = 0;
		for (int i = m - 1; i >= 0; i--) {
			cur = max(cur, heros[i].second);
			days[i] = cur;
		}
		int ans = 0;
		int pos = 1;
		while (pos <= n) {
			int len = calc(pos);
			ans++;
			pos += len;
		}
		cout << ans << endl;
	}
	return 0;
}