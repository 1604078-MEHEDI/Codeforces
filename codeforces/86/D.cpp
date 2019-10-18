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
int cnt[N * 5];
int a[N];
ll ans[N];
ll res;
int block;

struct Query
{
    int l, r, id, pos;
    bool operator < (const Query &q) const {
        if (pos == q.pos) return r < q.r;
        return pos < q.pos;
    }
} Q[N];

inline void add(int x)
{
    res += ((cnt[a[x]] << 1) + 1) * a[x];
    ++cnt[a[x]];
}

inline void del(int x)
{
    res -= ((cnt[a[x]] << 1) - 1) * a[x];
    --cnt[a[x]];
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
    int n, t;
    scanf("%d %d", &n, &t);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    block = (int)sqrt(n);

    for (int i = 1; i <= t; i++) {
        scanf("%d %d", &Q[i].l, &Q[i].r);
        Q[i].id = i;
        Q[i].pos = (Q[i].l - 1) / block + 1;
    }

    sort(Q + 1, Q + t + 1);
    int l = 1, r = 0;
    for (int i = 1; i <= t; i++) {
        while (l > Q[i].l) add(--l);
        while (l < Q[i].l) del(l++);
        while (r < Q[i].r) add(++r);
        while (r > Q[i].r) del(r--);
        ans[Q[i].id] = res;
    }
    for (int i = 1; i <= t; i++)
        printf("%I64d\n", ans[i]);
    return 0;
}