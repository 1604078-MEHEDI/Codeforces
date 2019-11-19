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
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i].first;
			v[i].second = i + 1;
		}
		if (n != m || n < 3)cout << "-1\n";
		else {
			sort(v.begin(), v.end());
			ll sm = 0;
			vector<pair<int, int> > ans, tm;
			if (n == 3) {
				vector<pair<int, int> > ans;
				ans.push_back({v[0].second, v[1].second});
				ans.push_back({v[0].second, v[2].second});
				ans.push_back({v[1].second, v[2].second});
				sm += v[0].first + v[1].first;
				sm += v[0].first + v[2].first;
				sm += v[1].first + v[2].first;
				cout << sm << endl;
				for (auto x : ans) {
					cout << x.first << " " << x.second << endl;
				}
				continue;
			}
			int l = 0, r = n - 1;
			while (l < r) {
				sm += (v[l].first + v[r].first);
				tm.push_back({l, r});
				ans.push_back({v[l].second, v[r].second});
				l++;
				r--;
			}
			//dbg(m);
			for (int i = 0; i < (int)tm.size() - 1; i++) {
				int x = tm[i].first;
				//int y = tm[i].second;
				//int z = tm[i + 1].first;
				int w = tm[i + 1].second;
				sm += v[x].first + v[w].first;
				ans.push_back({v[x].second, v[w].second});
			}
			//dbg(m);


			if (n & 1) {
				sm += v[(n + 1) / 2 - 1].first + v[n - 1].first;
				ans.push_back({v[(n + 1) / 2 - 1].second, v[n - 1].second}); // mid to last
				sm += v[(n + 1) / 2 - 1].first + v[tm[(int)tm.size() - 1].first].first;
				ans.push_back({v[(n + 1) / 2 - 1].second, v[tm[(int)tm.size() - 1].first].second});

				//ans.push_back({v[tm[0].second].second , v[tm[(int)tm.size() - 1].first].second});
				//sm += v[tm[0].second].first + v[tm[(int)tm.size() - 1].first].first;
			}
			else {
				ans.push_back({v[tm[0].second].second , v[tm[(int)tm.size() - 1].first].second});
				sm += v[tm[0].second].first + v[tm[(int)tm.size() - 1].first].first;
			}
			//dbg(m);
			// while (m > 0) {
			// 	sm += v[0].first + v[1].first;
			// 	ans.push_back({v[0].second, v[1].second});
			// 	m--;
			// }
			cout << sm << endl;
			for (auto x : ans) {
				cout << x.first << " " << x.second << endl;
			}
		}
	}
	return 0;
}