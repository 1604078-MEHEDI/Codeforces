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
const int MX = 26;

struct Vertex
{
	int next[MX], go[MX];
	int leaf = -1;
	int p = -1;
	char ch;
	int link = -1, leaflink = -1;

	Vertex(int p = -1, char ch = '$'): p(p), ch(ch) {
		memset(next, -1, sizeof next);
		memset(go, -1, sizeof next);
	}
};

vector<Vertex> Trie(1);

void add_string(string const &s, int idx)
{
	int v = 0;
	for (char ch : s) {
		int c = ch - 'a';
		if (Trie[v].next[c] == -1) {
			Trie[v].next[c] = Trie.size();
			Trie.emplace_back(v, ch);
		}
		v = Trie[v].next[c];
	}
	Trie[v].leaf = idx;
}

int aho_corasick(int v, char ch);

int get_link(int v)
{
	if (Trie[v].link == -1) {
		if (v == 0 || Trie[v].p == 0)
			Trie[v].link = 0;
		else
			Trie[v].link = aho_corasick(get_link(Trie[v].p), Trie[v].ch);
		get_link(Trie[v].link);
		Trie[v].leaflink = (Trie[Trie[v].link].leaf != -1) ? Trie[v].link : Trie[Trie[v].link].leaflink;
	}
	return Trie[v].link;
}

int aho_corasick(int v, char ch)
{
	int c = ch - 'a';
	if (Trie[v].go[c] == -1) {
		if (Trie[v].next[c] != -1)
			Trie[v].go[c] = Trie[v].next[c];
		else
			Trie[v].go[c] = v == 0 ? 0 : aho_corasick(get_link(v), ch);
	}
	return Trie[v].go[c];
}

string s;
int n;
int K[N];
string M[N];
vector<int> ans[N];

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

	cin >> s >> n;
	for (int i = 0; i < n; i++) {
		cin >> K[i] >> M[i];
		add_string(M[i], i);
	}

	int v = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		v = aho_corasick(v, s[i]);
		get_link(v);
		int cur = Trie[v].leaf == -1 ? Trie[v].leaflink : v;
		while (cur != -1) {
			ans[Trie[cur].leaf].push_back(i);
			cur = Trie[cur].leaflink;
		}
	}

	for (int i = 0; i < n; i++) {
		int minLength = INF;
		for (int j = K[i]; j <= (int)ans[i].size(); j++) {
			minLength = min(minLength, ans[i][j - 1] - ans[i][j - K[i]]);
		}
		if (minLength == INF)
			cout << "-1\n";
		else cout << minLength + M[i].size() << endl;
	}

}