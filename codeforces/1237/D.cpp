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
        int n;
        cin >> n;
        vector<int> a(3 * n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i + n] = a[i + 2 * n] = a[i];
        }

        vector<int> ans(3 * n);
        vector<int> st_mx;
        vector<int> st_mn;

        for (int i = 3 * n - 1; i >= 0; i--) {
            while (!st_mx.empty() && a[st_mx.back()] < a[i])
                st_mx.pop_back();
            while (!st_mn.empty() && a[st_mn.back()] > a[i])
                st_mn.pop_back();

            int lo = 0, hi = (int)st_mn.size();
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (a[st_mn[mid]] * 2 < a[i])
                    lo = mid + 1;
                else hi = mid;
            }

            int nxt = 3 * n;
            if (lo > 0)
                nxt = min(nxt, st_mn[lo - 1]);
            if (!st_mx.empty())
                nxt = min(nxt, st_mx.back());
            if (nxt < 3 * n && a[nxt] >= a[i])
                ans[i] = ans[nxt];
            else
                ans[i] = nxt;
            st_mn.push_back(i);
            st_mx.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            cout << (ans[i] == 3 * n ? -1 : ans[i] - i) << " ";
        }
    }
    return 0;
}