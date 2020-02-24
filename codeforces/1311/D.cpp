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
// ll xx, yy, zz;

// ll go(ll m, ll a, ll b, ll c)
// {
// 	//dbg(m, a, b, c);
// 	ll A;
// 	A = m;
// 	ll B1 = (b / A) * A;
// 	ll B2 = (b + A - 1) / A;

// 	ll C11 = B1 > 0 ? (c / B1) * B1 : 0;
// 	ll C12 = B1 > 0 ? (c + B1 - 1 / B1) * B1 : 0;
// 	ll C21 = B2 > 0 ? (c / B2) * B2 : 0;
// 	ll C22 = B2 > 0 ? (c + B2 - 1 / B2) * B2 : 0;
// 	ll r1 = abs(A - a) + abs(B1 - b) + abs(C11 - c);
// 	ll r2 = abs(A - a) + abs(B1 - b) + abs(C12 - c);
// 	ll r3 = abs(A - a) + abs(B2 - b) + abs(C21 - c);
// 	ll r4 = abs(A - a) + abs(B2 - b) + abs(C22 - c);
// 	ll ret = min(r1, min(r2, min(r3, r4)));
// 	if (ret == r1 && B1 && C11) {
// 		xx = A;
// 		yy = B1;
// 		zz = C11;
// 		return ret;
// 	}
// 	else if (ret == r2 && B1 && C12) {
// 		xx = A;
// 		yy = B1;
// 		zz = C12;
// 		return ret;
// 	}
// 	else if (ret == r3 && B2 && C21) {
// 		xx = A;
// 		yy = B2;
// 		zz = C21;
// 		return ret;
// 	}
// 	xx = A;
// 	yy = B2;
// 	zz = C22;
// 	//dbg(ret);
// 	return ret;
// }

const ll N = 3e4 + 5;

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
		ll a, b, c;
		cin >> a >> b >> c;
		ll ans = 2e18;
		ll x, y, z;
		for (ll A = 1; A <= N; A++) {
			for (ll B = A; B <= N; B += A) {
				ll C1 = B * (c / B + (c % B > 0));
				ll C2 = B * (c / B);
				ll C;
				ll tt = min(abs(C1 - c), abs(C2 - c));
				if (tt == abs(C1 - c)) C = C1;
				else C = C2;
				ll ret = abs(A - a) + abs(B - b) + abs(C - c);
				if (ans > ret) {
					ans = ret;
					x = A;
					y = B;
					z = C;
				}
			}
		}
		cout << ans << endl;
		cout << x << " " << y << " " << z << endl;
	}
	return 0;
}