#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const int N = 200006;

struct line
{
	ll m, c;
	line(ll x, ll y) {
		m = x;
		c = y;
	}
};

struct ConvexHullTricks
{
	vector<line> vec;
	ll t, ptr;
	void init(ll x) {
		t = x;
		ptr = 0;
		vec.clear();
	}

	ll func(ll idx, ll x) {
		ll ret = vec[idx].m * x + vec[idx].c;
		return ret;
	}

	bool bad(line f1, line f2, line f3) {
		__int128 a = (f3.c - f1.c);
		a = a * (f1.m - f2.m);

		__int128 b = (f2.c - f1.c);
		b = b * (f1.m - f3.m);
		if (t == 1)return a <= b;
		else if (t == 2)return a >= b;
		else if (t == 3)return a >= b;
		else return a <= b;
	}

	void add(line x) {
		if (!vec.empty() && vec.back().m == x.m)return;
		vec.push_back(x);
		ll sz = vec.size();
		while (sz >= 3 && bad(vec[sz - 3], vec[sz - 2], vec[sz - 1])) {
			vec.erase(vec.end() - 2);
			sz--;
		}
	}

	ll ask(ll x) {// ternary Search
		if (vec.empty())return 0;
		ll l = 0, r = vec.size() - 1;

		ll ret = (t & 1) ? LLONG_MAX : LLONG_MIN;
		while (l <= r) {
			ll m1 = (l + (r - l) / 3);
			ll m2 = (r - (r - l) / 3);
			ll ans1 = func(m1, x);
			ll ans2 = func(m2, x);
			if (ans1 > ans2) {
				if (t & 1) {
					ret = min(ret, ans2);
					l = m1 + 1;
				}
				else {
					ret = max(ret, ans1);
					r = m2 - 1;
				}
			}
			else {
				if (t & 1) {
					ret = min(ret, ans1);
					r = m2 - 1;
				}
				else {
					ret = max(ret, ans2);
					l = m1 + 1;
				}
			}
		}
		return ret;
	}

	ll ask1(ll x) {
		if (vec.empty())return 0;
		if (ptr >= (int)(vec.size())) ptr = (int)(vec.size() - 1);
		while (ptr < (int)(vec.size() - 1)) {
			if (t & 1) {
				if (func(ptr, x) > func(ptr + 1, x))ptr++;
				else break;
			}
			else {
				if (func(ptr, x) < func(ptr + 1, x))ptr++;
				else break;
			}
		}
		return func(ptr, x);
	}
};

ll a[N], P[N];

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
	ll n;
	cin >> n;
	ConvexHullTricks CHT;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		P[i] = P[i - 1] + a[i];
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans += i * a[i];
	ll mx = 0;
	CHT.init(2);
	for (int i = n; i >= 1; i--) {
		ll tm = - (i * a[i] - P[i]);
		mx = max(mx, CHT.ask(a[i]) + tm);
		CHT.add(line(i, -P[i]));
	}

	CHT.init(4);
	for (int i = 1; i <= n; i++) {
		ll tm = P[i - 1] - (i * a[i]);
		if (i > 1)mx = max(mx, CHT.ask(a[i]) + tm);
		CHT.add(line(i, -P[i - 1]));
	}
	cout << ans + mx << "\n";
	return 0;
}