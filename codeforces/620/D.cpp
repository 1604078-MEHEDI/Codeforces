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

typedef pair<ll, ll> pll;
vector<pair<ll, pll> >v;

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
    int T;
    //scanf("%d", &T);
    T = 1;
    for (int cs = 1; cs <= T; cs++) {
        int n, m;
        cin >> n;
        vector<ll> a(n);
        ll sm_a = 0, sm_b = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sm_a += a[i];
        }
        cin >> m;
        vector<ll> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            sm_b += b[i];
        }
        int idx_a = -1, idx_b = -1;
        ll swap1 = LLONG_MAX; // case 1
        ll swap0 = abs(sm_a - sm_b); // case 0
        // dbg(sm_a, sm_b, swap1);
        for (int i = 0; i < n; i++) {
            ll res1 = sm_a - a[i];
            for (int j = 0; j < m; j++) {
                ll res2 = sm_b - b[j];
                ll t1 = res1 + b[j];
                ll t2 = res2 + a[i];
                ll dif = abs(t1 - t2);
                if (swap1 > dif) {
                    swap1 = dif;
                    idx_a = i;
                    idx_b = j;
                }
            }
        }

        ll swap2 = LLONG_MAX;
        ll aa1 = -1, bb1 = -1;
        ll aa2 = -1, bb2 = -1;

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                v.push_back({2 * (b[i] + b[j]), {i, j}});
            }
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ll cur = sm_a - sm_b - 2 * (a[i] + a[j]);
                ll target = -cur;

                pair<ll, pll> P = {target, {INT_MAX, INT_MAX}};
                auto it = upper_bound(v.begin(), v.end(), P);
                if (it != v.end()) {
                    ll Now = abs(cur + it->first);
                    if (Now < swap2) {
                        swap2 = Now;
                        aa1 = i; bb1 = it->second.first;
                        aa2 = j; bb2 = it->second.second;
                    }
                }

                if (it != v.begin()) {
                    it--;
                    ll Now = abs(cur + it->first);
                    if (Now < swap2) {
                        swap2 = Now;
                        aa1 = i; bb1 = it->second.first;
                        aa2 = j; bb2 = it->second.second;
                    }
                }
            }
        }

        ll Mn = min(swap0, min(swap1, swap2));
        if (Mn == swap0) cout << swap0 << "\n0\n";
        else if (Mn == swap1) {
            cout << swap1 << "\n1\n" << idx_a + 1 << " " << idx_b + 1 << endl;
        }
        else {
            cout << swap2 << "\n2\n" << aa1 + 1 << " " << bb1 + 1 << "\n" << aa2 + 1 << " " << bb2 + 1 << endl;
        }

    }
    return 0;
}