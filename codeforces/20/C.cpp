#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

vector<pair<ll, ll> > graph[100005];
vector<ll> p, d;

void dijkstra(ll s, ll n)
{
//    int n = graph.size();
	d.assign(n, INF);
	p.assign(n, -1);

	d[s] = 0;
	using pii = pair<ll, ll>;
	priority_queue<pii, vector<pii>, greater<pii>> PQ;

	PQ.push({0, s});

	while (!PQ.empty()) {
		ll v = PQ.top().second;
		ll d_v = PQ.top().first;
		PQ.pop();
		if (d_v != d[v]) continue;

		for (auto x : graph[v]) {
			ll to = x.first;
			ll len = x.second;

			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
				PQ.push({d[to], to});
			}
		}
	}
}

int main()
{
	//FASTIO
	///*
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	//*/
	ll v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		--u;
		--v;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}
	dijkstra(0, v);
	// for (int i = 0; i < v; i++) {
	// 	cout << d[i] << " ";
	// }
	// cout << endl;
	ll x = v - 1;
	//cerr << p[x] << " ";
	stack<int> ans;
	while (p[x] != -1) {
		ans.push(x + 1);
		//cout << x + 1 << " ";
		x = p[x];
	}
	ans.push(1);
	if (ans.size() == 1) {
		cout << "-1\n";
		return 0;
	}
	while (!ans.empty())cout << ans.top() << " ", ans.pop();
	cout << endl;
	return 0;
}