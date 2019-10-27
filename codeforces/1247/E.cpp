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

const int N = 2007, Mod = 1e9 + 7;
//const int mod = 1e9 + 7;
int R[N][N], D[N][N], dp[N][N][2], Q1[N][N], Q2[N][N];

char grid[N][N];

int q1(int l, int r, int idx)
{
    if (l > r) return 0;
    return (Q1[idx][l] - Q1[idx][r + 1] + Mod) % Mod;
}

int q2(int l, int r, int idx)
{
    if (l > r) return 0;
    return (Q2[l][idx] + Mod - Q2[r + 1][idx] ) % Mod;
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
    if (n == 1 && m == 1) {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> grid[i][j];

    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            R[i][j] = (grid[i][j] == 'R') + R[i][j + 1];
            D[i][j] = (grid[i][j] == 'R') + D[i + 1][j];
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            if (i == n && j == m) {
                dp[i][j][1] = dp[i][j][0] = (grid[i][j] == '.');
            }
            else {
                if (D[i][j] != (n - i + 1)) {
                    int r = m - R[i][j + 1];
                    dp[i][j][1] = q1(j + 1, r, i);
                }
                if (R[i][j] != (m - j + 1)) {
                    int d = n - D[i + 1][j];
                    dp[i][j][0] = q2(i + 1, d, j);
                }
            }
            Q1[i][j] = (dp[i][j][0] + Q1[i][j + 1]) % Mod;
            Q2[i][j] = (dp[i][j][1] + Q2[i + 1][j]) % Mod;
        }
    }
    cout << (dp[1][1][1] + dp[1][1][0]) % Mod << endl;
}