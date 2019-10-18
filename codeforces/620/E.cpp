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

const int N = 4e5 + 1;
int n, q, color[N], from[N], to[N], T;
ll seg[4 * N], lazy[4 * N];
vector<int> graph[N];

inline void propagate(int p, int l, int r)
{
    if (!lazy[p]) return;
    seg[p] = lazy[p];
    if (l != r)
        lazy[p * 2] = lazy[p * 2 + 1] = lazy[p];
    lazy[p] = 0;
}

void update(int p, int l, int r, int s, int e, ll v)
{
    propagate(p, l, r);
    if (l > e || r < s) return;
    if (l >= s && r <= e) {
        lazy[p] = v;
        propagate(p, l, r);
        return;
    }

    int m = (l + r) >> 1;
    update(p * 2, l, m, s, e, v);
    update(p * 2 + 1, m + 1, r, s, e, v);
    seg[p] = seg[p * 2] | seg[p * 2 + 1];
}

ll query(int p, int l, int r, int s, int e)
{
    propagate(p, l, r);
    if (l > e || r < s) return 0;
    if (l >= s && r <= e) return seg[p];
    int m = (l + r) >> 1;
    return query(p * 2, l, m, s, e) | query(p * 2 + 1, m + 1, r, s, e);
}

void dfs(int u, int p)
{
    from[u] = ++T;
    update(1, 1, n, T, T, 1LL << color[u]);
    for (auto v : graph[u])
        if (v != p)
            dfs(v, u);
    to[u] = T;
}

int main()
{
  //  FASTIO
    ///*
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
//*/
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &color[i]);
        --color[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, -1);

    while (q--) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int v, c;
            scanf("%d %d", &v, &c);
            --c;
            update(1, 1, n, from[v], to[v], 1LL << c);
        }
        else {
            int v, ans = 0;
            scanf("%d", &v);
            ll val = query(1, 1, n, from[v], to[v]);
            ans = __builtin_popcountll(val);
            printf("%d\n", ans);
        }
    }

    return 0;
}