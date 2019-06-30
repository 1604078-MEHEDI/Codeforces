#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 1005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

int a[maxn], t[maxn], l[maxn], r[maxn];
int main()
{
	FASTIO
	///*
	//double start_time = clock();
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
//*/
	int T;
	//cin >> T;
	T = 1;
	for (int cs = 1; cs <= T; cs++) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			cin >> t[i] >> l[i] >> r[i];
			if (t[i]) {
				for (int j = l[i]; j < r[i]; j++) {
					a[j] = 1;
				}
			}
		}
		for (int i = 1; i <= m; i++) {
			if (t[i]) continue;
			bool ok = false;

			for (int j = l[i]; j < r[i]; j++)
				if (!a[j]) ok = true;
			if (!ok) {
				cout << "NO\n";
				return 0;
			}

		}

		int k = n;
		cout << "YES\n" << n;
		for (int i = 2; i <= n; i++) {
			if (a[i - 1]) cout << " " << k;
			else cout << " " << --k;
		}

	}

	//double end_time = clock();
	//printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
	return 0;
}