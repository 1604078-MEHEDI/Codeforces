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

const int nx = 2e5 + 10;
int a[nx], mn_pos, mx_pos;
struct node
{
    int mn, mx;
} Tree[nx * 4];

void init(int node, int b, int e)
{
    if (b == e) {
        Tree[node] = {b, b};
        return;
    }
    int mid = (b + e) >> 1;
    int lft = mid << 1;
    int rgt = lft + 1;
    init(lft, b, mid);
    init(rgt, mid + 1, e);
    Tree[node].mn = a[Tree[lft].mn] < a[Tree[rgt].mn] ? Tree[lft].mn : Tree[rgt].mn;
    Tree[node].mx = a[Tree[lft].mx] > a[Tree[rgt].mx] ? Tree[lft].mx : Tree[rgt].mx;
}

void query(int t, int b, int e, int i, int j)
{
    if (i <= b &&  e <= j) {
        mn_pos = a[mn_pos] < a[Tree[t].mn] ? mn_pos : Tree[t].mn;
        mx_pos = a[mx_pos] > a[Tree[t].mx] ? mx_pos : Tree[t].mx;
        return;
    }
    if (j < b || e < i) return;
    int mid = (b + e) >> 1;
    int lft = mid << 1;
    int rgt = lft + 1;
    query(lft, b, mid, i, j);
    query(rgt, mid + 1, e, i, j);
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
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    init(1, 1, n);

    for (int i = 1; i <= m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        mn_pos = l;
        mx_pos = l;
        query(1, 1, n, l, r);


        if (a[mn_pos] == x && a[mx_pos] == x) {
            cout << "-1\n";
        }
        else if (a[mn_pos] == x)
            cout << mx_pos << endl;
        else cout << mn_pos << endl;
    }


    return 0;
}