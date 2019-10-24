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
const int N = 2e5 + 100;
int l[N], r[N];
int lmt = 200000;
int Tree[4 * N], lazy[4 * N];
vector<int> ans, idx;
bool cmp(int x, int y) {
    return r[x] < r[y];
}

void propagte(int pos, int l, int r)
{
    if (!lazy[pos]) return;
    Tree[pos] += lazy[pos];
    if (l != r) {
        lazy[2 * pos] += lazy[pos];
        lazy[2 * pos + 1] += lazy[pos];
    }
    lazy[pos] = 0;
}

void update(int pos, int l, int r, int i, int j, int x)
{
    propagte(pos, l, r);
    if (l > j || r < i)return;
    if (i <= l && j >= r) {
        lazy[pos] += x;
        propagte(pos, l, r);
        return;
    }
    int m = (l + r) / 2;
    update(2 * pos, l, m, i, j, x);
    update(2 * pos + 1, m + 1, r, i, j, x);
    Tree[pos] = max(Tree[2 * pos], Tree[2 * pos + 1]);
}

int query(int pos, int l, int r, int i, int j)
{
    propagte(pos, l, r);
    if (l > j || r < i) return 0;
    if (i <= l && j >= r) return Tree[pos];
    int m = (l + r) / 2;
    int lft = query(2 * pos, l, m, i, j);
    int rgt = query(2 * pos + 1, m + 1, r, i, j);
    return max(lft, rgt);
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
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        idx.push_back(i);
        l[i] = u;
        r[i] = v;
    }
    sort(idx.begin(), idx.end(), cmp);

    for (int i = 0; i < n; i++) {
        int id = idx[i];
        int x = query(1, 1, lmt, l[id], r[id]);
        if (x < k)
            update(1, 1, lmt, l[id], r[id], 1);
        else
            ans.push_back(id);
    }
    cout << (int)ans.size() << endl;
    for (auto x : ans)
        cout << x << " ";
}