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
const int N = 2005;
const int Mod = 1e9 + 7;
string grid[N];
int row[N][N];
int col[N][N];
ll dp[N][N][2];

ll crow[N][N];
ll ccol[N][N];

ll add(ll a, ll b) {return (a + b) >= Mod ? a + b - Mod : a + b;}
ll sub(ll a, ll b) {return add(a, Mod - b);}


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
    for (int i = 0; i < n; i++) cin >> grid[i];

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            row[i][j] = row[i][j + 1] + (grid[i][j] == 'R');
            col[i][j] = col[i + 1][j] + (grid[i][j] == 'R');
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int bakirow = n - i;
            int bakicol = m - j;

            // 0 means I got a down move
            if (bakirow == col[i][j]) dp[i][j][0] = 0;
            else {
                int lmt = m - 1 - row[i][j + 1];
                dp[i][j][0] = sub(crow[i][j + 1], crow[i][lmt + 1]);
                if (i == n - 1 && j == m - 1) dp[i][j][0] = 1;
            }

            // 1 means I got a right move
            if (bakicol == row[i][j]) dp[i][j][1] = 0;
            else {
                int lmt = n - 1 - col[i + 1][j];
                dp[i][j][1] = sub(ccol[i + 1][j], ccol[lmt + 1][j]);
                if (i == n - 1 && j == m - 1) dp[i][j][1] = 1;
            }

            crow[i][j] = add(crow[i][j + 1], dp[i][j][1]);
            ccol[i][j] = add(ccol[i + 1][j], dp[i][j][0]);
        }
    }

    int ans = add(dp[0][0][0], dp[0][0][1]);
    if (n == 1 && m == 1 && grid[n - 1][m - 1 == '.']) ans = 1;
    cout << ans << endl;
}