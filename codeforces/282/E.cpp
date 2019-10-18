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

const int N = 1e6 + 1e3;
ll a[N];

struct node
{
    ll value;
    node *child[2];
    node() {
        value = 0;
        child[0] = child[1] = NULL;
    }
};

node *root;
ll xorAll = 0;

void Insert(ll x)
{
    node* cur = root;
    // start from the msb, insert all bits of pre_xor into Trie
    ll tt, val;
    for (ll i = 41; i >= 0; i--) {
        // Find current bit in given prefix
        tt = (1LL << i);
        val = (x & tt);
        if (val) val = 1;
        // Create a new node if needed
        if (cur->child[val] == NULL)
            cur->child[val] = new node();
        cur = cur->child[val];
    }
    // Store value at leaf node
    cur->value = x;
}

ll query(ll pre_xor)
{
    node *cur = root;
    ll tt, val;
    for (int i = 41; i >= 0; i--) {
        tt = (1LL << i);
        val = (pre_xor & tt);
        if (val) val = 1;

        // Traverse Trie, first look for a
        // prefix taht has oppsite bit
        if (cur->child[1 - val] != NULL)
            cur = cur->child[1 - val];

        // If there is no prefix with opposite
        // bit, then look for same bit
        else if (cur->child[val] != NULL)
            cur = cur->child[val];
    }
    return pre_xor ^ (cur->value);
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
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        xorAll ^= a[i];
    }

    root  = new node();
    ll maxGot = xorAll;
    ll total = 0;
    Insert(total);
    for (int i = 1; i <= n; i++) {
        total ^= a[i];
        Insert(total);
        xorAll ^= a[i];
        maxGot = max(maxGot, query(xorAll));
    }
    cout << maxGot << endl;
    return 0;
}