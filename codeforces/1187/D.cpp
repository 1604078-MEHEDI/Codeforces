#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 300005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

int a[maxn], b[maxn];
deque<int> pos[maxn];
int tree[maxn * 5];

int query(int node, int lw, int hi, int i, int j)
{
	if (i > hi || j < lw) return INT_MAX;
	if (lw >= i && hi <= j)return tree[node];
	int lft = node * 2;
	int rgt = node * 2 + 1;
	int mid = (lw + hi) / 2;
	int x = query(lft, lw,  mid, i, j);
	int y = query(rgt, mid + 1, hi, i, j);
	return min(x, y);
}

void update(int node, int lw, int hi, int i, int val)
{
	if (i > hi || i < lw) return;
	if (lw == hi) {
		tree[node] = val;
		return;
	}
	int lft = node * 2;
	int rgt = node * 2 + 1;
	int mid = (lw + hi) / 2;
	update(lft, lw, mid, i, val);
	update(rgt, mid + 1, hi, i, val);
	tree[node] = min(tree[lft], tree[rgt]);
}

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
	//T = 1;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) pos[i].clear();
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			pos[a[i]].push_back(i);
		}
		for (int i = 1; i <= n; i++)
			update(1, 1, n, i, a[i]);

		for (int i = 1; i <= n; i++)
			scanf("%d", &b[i]);

		bool ok = true;

		for (int i = 1; i <= n; i++) {
			if (pos[b[i]].empty()) {
				ok = false;
				break;
			}
			int nxt = pos[b[i]].front();
			pos[b[i]].pop_front();

			int mn = query(1, 1, n, 1, nxt);
			if (mn < b[i]) {
				ok = false;
				break;
			}
			update(1, 1, n, nxt, INT_MAX);
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}

	//double end_time = clock();
	//printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
	return 0;
}