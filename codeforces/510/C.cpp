/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
//const ll mod = 998244353;


inline void normal(ll &a) { a %= mod; (a < 0) && (a += mod); }
inline ll modMul(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a * b) % mod; }
inline ll modAdd(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a + b) % mod; }
inline ll modSub(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while (p) { if (p & 1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define slll(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ss(ch) scanf("%s",ch)
#define pi(x) printf("%d",x)
#define pii(x,y) printf("%d %d",x,y)
#define piii(x,y,z) printf("%d %d %d",x,y,z)
#define pl(x) printf("%lld",x)
#define pll(x,y) printf("%lld %lld",x,y)
#define plll(x,y,z) printf("%lld %lld %lld",x,y,z)
#define ps(ch) printf("%s",ch)
#define F(i,a,b)      for(int i= a; i <= b; i++)
#define R(i,b,a)      for(int i= b; i >= a; i--)

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, -1, 0, 1, -1, 0, 1};
int kx8[] = {1, 1, 2, 2, -1, -1, -2, -2};
int ky8[] = {2, -2, 1, -1, 2, -2, 1, -1};
/* for Random Number generate
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
*/
///**
template < typename F, typename S >ostream& operator << ( ostream& os, const pair< F, S > & p ) {return os << "(" << p.first << ", " << p.second << ")";}
template < typename T >ostream &operator << ( ostream & os, const vector< T > &v ) {os << "{"; for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin() ) os << ", "; os << *it;} return os << "}";}
template < typename T >ostream &operator << ( ostream & os, const set< T > &v ) {os << "["; for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin()) os << ", "; os << *it;} return os << "]";}
template < typename F, typename S >ostream &operator << ( ostream & os, const map< F, S > &v ) {os << "["; for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin() ) os << ", "; os << it -> first << " = " << it -> second ;} return os << "]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
void faltu () { cerr << endl; }
template <typename T>void faltu( T a[], int n ) {for (int i = 0; i < n; ++i) cerr << a[i] << ' '; cerr << endl;}
template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) { cerr << arg << ' '; faltu(rest...); }

// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less 
using namespace __gnu_pbds;

// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;
// find_by_order(k) – ফাংশনটি kth ordered element এর একটা পয়েন্টার রিটার্ন করে। অর্থাৎ তুমি চাইলেই kth ইন্ডেক্সে কি আছে, সেটা জেনে ফেলতে পারছো!
// order_of_key(x) – ফাংশনটি x এলিমেন্টটা কোন পজিশনে আছে সেটা বলে দেয়।
//*//**___________________________________________________**/
const int N = 1000006;

//Kahn’s algorithm, is somewhat similar to BFS.
const int maxn = 35;
vector<int>graph[maxn];
priority_queue<int, vector<int>, greater<int> > PQ;
int in_degree[maxn];
vector<int> ans;

void go(string &a, string &b) {
	int len = min(a.size(), b.size());
	for (int i = 0; i < len; i++) {
		if (a[i] == b[i])continue;
		int u = a[i] - 'a' + 1;
		int v = b[i] - 'a' + 1;
		graph[u].push_back(v);
		in_degree[v]++;
		return;
	}
	if (len == (int)a.size())return;
	cout << "Impossible\n";
	exit(0);
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

	int n;
	cin >> n;
	string a;
	cin >> a;
	for (int i = 1;  i < n; i++) {
		string b;
		cin >> b;
		go(a, b);
		a = b;
	}


	for (int i = 1; i <= 26; i++)
	{
		//  cout << in_degree[i] << " ";
		if (in_degree[i] == 0)
			PQ.push(i);
	}
	if (PQ.size() == 0)
	{
		cout << "Impossible\n";
		return 0;
	}

	//cout << PQ.size()<<endl;
//    for(int i = 0; i < n; i++){
//        for(int x = 0; x < graph[i].size(); x++)
//            cout << graph[i][x]<< " ";
//        cout << "-----------\n";;
//    }
	while (!PQ.empty())
	{
		int u = PQ.top();
		// cout <<  u << endl;
		ans.push_back(u);

		PQ.pop();
		for (int x = 0; x < (int) graph[u].size(); x++)
		{
			int v = graph[u][x];
			//  cout << u << " "<<v << endl;
			in_degree[v]--;
			if (in_degree[v] == 0)PQ.push(v);
		}
	}
	//cout << ans.size()<<endl;
	int sz = ans.size();
	//dbg(sz);
	if (sz < 26)
	{
		cout << "Impossible\n";
		return 0;
	}
	for (int i = 0; i < 26; i++)
	{
		char ch = ans[i] + 'a' - 1;
		cout << ch;
	}
	cout << "\n";
	return 0;
}

