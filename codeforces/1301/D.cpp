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
	for (int cs = 1; cs <= T; cs++) {
		int n, m, k;
		cin >> n >> m >> k;
		if (k > 4 * n * m - 2 * n - 2 * m) {
			cout << "NO\n";
			return 0;
		}
		vector<string> ans;
		bool flag = false;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (flag)break;
			string str = "";
			for (int j = 1; j < m; j++) {
				cnt++;
				str += "R";
				if (cnt == k) {
					flag = true;
					break;
				}
			}
			if (str.size())ans.push_back(str);
			if (flag) break;
			if (i == 1) {
				str = "";
				for (int j = 1; j < m; j++) {
					cnt++;
					str += "L";
					if (cnt == k) {
						flag = true;
						break;
					}
				}
				if (str.size())ans.push_back(str);
				if (flag) break;
				cnt++;
				ans.push_back("D");
				if (cnt == k) {
					flag = true;
					break;
				}
			}
			else if (i < n) {
				str = "";
				for (int j = 1; j <= m; j++) {
					if (flag)break;
					if (j == m) {
						cnt++;
						str += "D";
						if (cnt == k) {
							flag = true;
							break;
						}
					}
					else {
						cnt++;
						str += "U";
						if (cnt == k) {
							flag = true;
							break;
						}
						cnt++;
						str += "D";
						if (cnt == k) {
							flag = true;
							break;
						}
						cnt++;
						str += "L";
						if (cnt == k) {
							flag = true;
							break;
						}
					}
				}
				if (str.size())ans.push_back(str);
			}
			else if (i == n) {
				str = "";
				for (int j = 1; j < m; j++) {
					if (flag)break;
					cnt++;
					str += "U";
					if (cnt == k) {
						flag = true;
						break;
					}
					cnt++;
					str += "D";
					if (cnt == k) {
						flag = true;
						break;
					}
					cnt++;
					str += "L";
					if (cnt == k) {
						flag = true;
						break;
					}
				}
				//dbg(cnt);
				if (str.size())ans.push_back(str);
				if (flag)break;
				str = "";
				for (int j = 1; j < n; j++) {
					cnt++;
					str += "U";
					if (cnt == k) {
						flag = true;
						break;
					}
				}
				if (str.size())ans.push_back(str);
			}
		}

		cout << "YES\n";
		vector < pair<int, string>> vec;
		//cout << (int)ans.size() << endl;
		for (auto it : ans) {
			if (it[0] == 'U' && it[1] == 'D' && it[2] == 'L') {
				//cout << (int)it.size() / 3 << " " << "UDL\n";
				vec.push_back({(int)it.size() / 3, "UDL"});
				if ((int)it.size() % 3) {
					if ((int)it.size() % 3 == 1) {
						//cout << 1 << " " << it[it.size() - 1] << endl;
						int tt = it.size() - 1;
						string tm = "";
						tm +=  it[tt];
						vec.push_back({1, tm});
					}
					else {
						//cout << 1 << " " << it[it.size() - 2] << it[it.size() - 1] << endl;
						string tm = "";
						tm += it[it.size() - 2];
						tm += it[it.size() - 1];
						vec.push_back({1, tm});
					}
				}
			}
			else {
				string tm = "";
				tm +=  it[0];
				if (it[0] != it[1])
					vec.push_back({1, it});
				else vec.push_back({(int)it.size(), tm});
				//cout << 1 << " " << it << endl;
			}
		}
		//dbg(cnt);
		cout << (int)vec.size() << endl;
		for (auto it : vec) {
			cout << it.first << " " << it.second << endl;
		}
	}
	return 0;
}