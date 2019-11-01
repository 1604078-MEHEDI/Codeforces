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

vector<int> z_function(string s)
{
	int n = (int) s.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

vector<int> z_algo(string s)
{
	int n = s.length();
	vector <int> z(n);

	int l = 0, r = 0;
	for (int k = 1; k < n; k++) {
		if (k > r) {
			l = r = k;
			while (r < n && s[r] == s[r - l]) r++;

			z[k] = r - l;
			r--;
		}
		else {
			// inside box
			int i = k - l;
			if (z[i] < r - k + 1) z[k] = z[i];
			else {
				l = k;
				while (r < n && s[r] == s[r - l]) r++;
				z[k] = r - l;
				r--;
			}
		}
	}
	return z;
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
	string text;// pattern;
	cin >> text ;//>> pattern;
	//text += "$" + pattern;
	auto ans = z_function(text);
	int n = text.length();
	// for (auto x : ans) cerr << x << " ";
	// cerr << endl;
	map<int, int> mp;
	// for (int i = n; i >= 1; i--) {
	//     mp[i] = 1;
	//     // dbg(i, mp[i]);
	// }

	map<int, bool> valid;
	int mx = 0, mn = INT_MAX;
	set<int> st;
	for (int i = n - 1; i >= 0; i--) {
		if (i == n - ans[i]) {
			valid[ans[i]] = true;
			st.insert(ans[i]);
			mn = min(mn, ans[i]);
			mx = max(mx, ans[i]);
		}
	}
	for (auto x : ans) {
		if (x == 0)continue;
		mp[x]++;
		//dbg(x, mp[x]);
	}
	//dbg(mn, mx);
	//dbg(mx, mp[mx]);
	string tt = "after";
	for (int i = n; i >= mn; i--) {
		//if (mp[i] == 0)continue;
		//dbg(i, mp[i]);
		mp[i] += mp[i + 1];
		//dbg(tt, i, mp[i]);
	}
	vector<int> vt;
	for (auto x : st)vt.push_back(x);
	reverse(vt.begin(), vt.end());
	vector<pair<int, int> > v;
	//int sm = 0;
	for (auto x : vt) {
		//sm += mp[x];
		//dbg(x);
		v.push_back({x, mp[x] + 1});
	}
	cout << (int)v.size() + 1 << endl;
	for (int i = (int)v.size() - 1; i >= 0; i--) {
		cout << v[i].first << " " << v[i].second << endl;
	}
	cout << n << " " << 1 << endl;
	return 0;
}