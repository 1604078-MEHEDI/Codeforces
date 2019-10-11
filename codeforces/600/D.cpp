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
typedef long double ld;

ld distance(ld x1, ld y1, ld x2, ld y2)
{
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

ld area(ld a, ld r)
{
  ld ar1 = 0.5 * r * r * sin(a);
  ld ar2 = 0.5 * a * r * r;
  return ar2 - ar1;
}

ld solve(ld x1, ld y1, ld r1, ld x2, ld y2, ld r2, ld d)
{
  ld A1, A2;
  A1 = 2.0 * acos((r1 * r1 + d * d - r2 * r2) / (2.0 * r1 * d));
  A2 = 2.0 * acos((r2 * r2 + d * d - r1 * r1) / (2.0 * r2 * d));
  return area(A1, r1) + area(A2, r2);
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
  int T;
  //scanf("%d", &T);
  T = 1;
  for (int cs = 1; cs <= T; cs++) {
    ld x1, y1, r1, x2, y2, r2;
    ld d;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    cout << setprecision(10) << fixed;
    d = distance(x1, y1, x2, y2);
    if (d >= (r1 + r2)) cout << 0 << endl;
    else if (d + min(r1, r2) <= max(r1, r2))
      cout << min(PI * r1 * r1, PI * r2 * r2) << endl;
    else {
      cout << solve(x1, y1, r1, x2, y2, r2, d) << endl;
    }
  }
  return 0;
}