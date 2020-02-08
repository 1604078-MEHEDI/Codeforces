#include<bits/stdc++.h>
using namespace std;
const int maxn = (int) 2e5 + 5;
typedef long long ll;

struct edge
{
	ll u, v, w;
};

vector<edge>graph, output;
ll parent[maxn], mstValue = 0;

bool cmp (edge a, edge b)
{
	return a.w < b.w;
}

ll Find(ll r)
{
	if (parent[r] == r)
		return r;
	return parent[r] = Find(parent[r]);
}

void initPar(ll r)
{
	for (ll i = 0; i <= r; i++)parent[i] = i;
}

void kruskals_Algorithm(ll n)
{
	sort(graph.begin(), graph.end(), cmp);
	// for (ll i = 0; i < (ll)graph.size(); i++) {
	// 	cout << graph[i].u << " " << graph[i].v << " " << graph[i].w << endl;
	// }
	initPar(n);
	ll cnt = 0;
	ll sz = (ll)graph.size();
	for (ll i = 0; i < sz; i++) {
		ll uPr = Find(graph[i].u);
		ll vPr = Find(graph[i].v);

		if (uPr != vPr) {
			if (cnt == n - 1) break;

			output.push_back(graph[i]);
			mstValue += graph[i].w;
			parent[uPr] = vPr;
			cnt++;
		}
	}
}

int main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("in.txt", "r", stdin);
// 	freopen("out.txt", "w", stdout);
// 	freopen("error.txt", "w", stderr);
// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	// freopen("in.txt", "r", stdin);

	ll n, e;
	cin >> n >> e;
	ll mn = 2e17;
	vector<ll> v(n + 1);
	ll x = -1;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		if (mn > v[i]) {
			mn = v[i];
			x = i;
		}
	}
	for (ll i = 0; i < e; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		edge input;
		input.u = u;
		input.v = v;
		input.w = w;
		graph.push_back(input);
	}

	for (int i = 1; i <= n; i++) {
		if (x == i)continue;
		edge input;
		input.u = x;
		input.v = i;
		input.w = (mn + v[i]);
		graph.push_back(input);
	}

	kruskals_Algorithm(n);
	cout << mstValue << endl;

	//cout << "MST Value : " << mstValue << endl;

	// for (ll i = 0; i < (ll)output.size(); i++) {
	// 	cout << output[i].u << " " << output[i].v << " " << output[i].w << endl;
	// }

	return 0;
}