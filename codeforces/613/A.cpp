/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
using pii = pair<int, int>;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
//const ll mod = 998244353;


inline void normal(ll &a) { a %= mod; (a < 0) && (a += mod); }
inline ll modMul(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a * b) % mod; }
inline ll modAdd(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a + b) % mod; }
inline ll modSub(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while (p) { if (p & 1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define slll(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ss(ch) scanf("%s",ch)
#define pi(x) printf("%d",x)
#define pii(x,y) printf("%d %d",x,y)
#define piii(x,y,z) printf("%d %d %d",x,y,z)
#define pl(x) printf("%lld",x)
#define pll(x,y) printf("%lld %lld",x,y)
#define plll(x,y,z) printf("%lld %lld %lld",x,y,z)
#define ps(ch) printf("%s",ch)
#define F(i,a,b)      for(int i= a; i <= b; i++)
#define R(i,b,a)      for(int i= b; i >= a; i--)
#define REP(i,n) for(int i = 0; i < (n); i++)

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, -1, 0, 1, -1, 0, 1};
int kx8[] = {1, 1, 2, 2, -1, -1, -2, -2};
int ky8[] = {2, -2, 1, -1, 2, -2, 1, -1};
/* for Random Number generate
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
*/
///**
template < typename F, typename S >ostream& operator << ( ostream& os, const pair< F, S > & p ) {return os << "(" << p.first << ", " << p.second << ")";}
template < typename T >ostream &operator << ( ostream & os, const vector< T > &v ) {os << "{"; for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin() ) os << ", "; os << *it;} return os << "}";}
template < typename T >ostream &operator << ( ostream & os, const set< T > &v ) {os << "["; for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin()) os << ", "; os << *it;} return os << "]";}
template < typename F, typename S >ostream &operator << ( ostream & os, const map< F, S > &v ) {os << "["; for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin() ) os << ", "; os << it -> first << " = " << it -> second ;} return os << "]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
void faltu () { cerr << endl; }
template <typename T>void faltu( T a[], int n ) {for (int i = 0; i < n; ++i) cerr << a[i] << ' '; cerr << endl;}
template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) { cerr << arg << ' '; faltu(rest...); }

// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less 
using namespace __gnu_pbds;

// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;
// find_by_order(k) – ফাংশনটি kth ordered element এর একটা পয়েন্টার রিটার্ন করে। অর্থাৎ তুমি চাইলেই kth ইন্ডেক্সে কি আছে, সেটা জেনে ফেলতে পারছো!
// order_of_key(x) – ফাংশনটি x এলিমেন্টটা কোন পজিশনে আছে সেটা বলে দেয়।
//*//**___________________________________________________**/
const int N = 100006;


const double eps = 1e-8;
int dblcmp(double d)
{
	if (fabs(d) < eps)return 0;
	return d > eps ? 1 : -1;
}
inline double sqr(double x) {return x * x;}
/*
point()						- Empty constructor
point(double x, double y)	- constructor
input()						- double input
output()					- .2lf output
operator ==					- compares x and y
operator <					- compares first by x, then by y
len()						- gives length from origin
len2()						- gives square of length from origin
distance(point p)			- gives distance from p
add(point p)				- returns new point after adding curresponging x and y
sub(point p)				- returns new point after subtracting curresponging x and y
mul(double b)				- returns new point after multiplieing x and y by b
div(double b)				- returns new point after divideing x and y by b
dot(point p)				- dot product
det(point p)				- cross product of 2d points
rad(point a, point b)		- Probably radius of circumcircle of the triangle
trunc(double r)				- return point that is truncated the distance from center to r
rotleft()					- returns 90 degree ccw rotated point
rotright()					- returns 90 degree cw rotated point
rotate(point p, double angle) - returns point after rotateing the point centering at p by angle radian ccw
*/
struct point
{
	double x, y;
	point()             {                                    }
	point(double _x, double _y) {    x = _x; y = _y;           }
	void input()        {   scanf("%lf%lf", &x, &y);           }
	void output()       {   printf("%.2f %.2f\n", x, y);       }
	bool operator==(point a)const {
		return dblcmp(a.x - x) == 0 && dblcmp(a.y - y) == 0;
	}
	bool operator<(point a)const {
		return dblcmp(a.x - x) == 0 ? dblcmp(y - a.y) < 0 : x < a.x;
	}
	point operator-(point a)const {
		return point(x - a.x, y - a.y);
	}
	double len()        {   return hypot(x, y);              }
	double len2()       {   return x * x + y * y;            }
	double distance(point p) {return hypot(x - p.x, y - p.y); }
	point add(point p)  {   return point(x + p.x, y + p.y);  }
	point sub(point p)  {   return point(x - p.x, y - p.y);  }
	point mul(double b) {   return point(x * b, y * b);      }
	point div(double b) {   return point(x / b, y / b);      }
	double dot(point p) {   return x * p.x + y * p.y;              }
	double det(point p) {   return x * p.y - y * p.x;              }
	double rad(point a, point b) {
		point p = *this;
		return fabs(atan2(fabs(a.sub(p).det(b.sub(p))), a.sub(p).dot(b.sub(p))));
	}
	point trunc(double r) {
		double l = len();
		if (!dblcmp(l))return *this;
		r /= l;
		return point(x * r, y * r);
	}
	point rotleft()     {   return point(-y, x);              }
	point rotright()    {   return point(y, -x);              }
	point rotate(point p, double angle) {
		point v = this->sub(p);
		double c = cos(angle), s = sin(angle);
		return point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
	}
};

/*
Stores two points

line()								- Empty constructor
line(point a, point b)				- line through a and b
operator ==							- checks if two points are same
line(point p, double angle)			- one end p, another end at angle degree
line(double a, double b, double c)	- line of equation ax + by + c = 0
input()								- inputs a and b
adjust()							- orders in such a way that a < b
length()							- distance of ab
angle()								- returns 0 <= angle < 180
relation()							- 0 if collinear
									  1 if ccw
							  		  2 if cw
pointonseg(point p)					- returns 1 if point is on segment
parallel(line v)					- returns 1 if they are parallel
segcrossseg(line v)					- returns 0 if does not intersect
									  returns 1 if non-standard intersection
									  returns 2 if intersects
segcrossseg_inside(line v)			- returns 1 if intersects strictly inside
									  returns 0 if not
linecrossseg(line v)				- v is line
linecrossline(line v)				- 0 if parallel
									  1 if coincides
									  2 if intersects
crosspoint(line v)					- returns intersection point
dispointtoline(point p)				- distance from point p to the line
dispointtoseg(point p)				- distance from p to the segment
lineprog(point p)					- returns projected point p on ab line
symmetrypoint(point p)				- returns reflection point of p over ab
*/
struct line
{
	point a, b;
	line()              {                                    }
	line(point _a, point _b) { a = _a; b = _b;                     }
	bool operator==(line v) { return (a == v.a) && (b == v.b);      }
	line(point p, double angle) {
		a = p;
		if (dblcmp(angle - PI / 2) == 0) {
			b = a.add(point(0, 1));
		} else {
			b = a.add(point(1, tan(angle)));
		}
	}
	//ax+by+c=0
	line(double _a, double _b, double _c) {
		if (dblcmp(_a) == 0) {
			a = point(0, -_c / _b);
			b = point(1, -_c / _b);
		} else if (dblcmp(_b) == 0) {
			a = point(-_c / _a, 0);
			b = point(-_c / _a, 1);
		} else {
			a = point(0, -_c / _b);
			b = point(1, (-_c - _a) / _b);
		}
	}
	void input()        {   a.input(); b.input();            }
	void adjust()       {   if (b < a)swap(a, b);                }
	double length()     {   return a.distance(b);            }
	double angle() {
		double k = atan2(b.y - a.y, b.x - a.x);
		if (dblcmp(k) < 0)k += PI;
		if (dblcmp(k - PI) == 0)k -= PI;
		return k;
	}
	int relation(point p) {
		int c = dblcmp(p.sub(a).det(b.sub(a)));
		if (c < 0)return 1;
		if (c > 0)return 2;
		return 3;
	}
	bool pointonseg(point p) {
		return dblcmp(p.sub(a).det(b.sub(a))) == 0 && dblcmp(p.sub(a).dot(p.sub(b))) <= 0;
	}
	bool parallel(line v) {
		return dblcmp(b.sub(a).det(v.b.sub(v.a))) == 0;
	}
	int segcrossseg(line v) {
		int d1 = dblcmp(b.sub(a).det(v.a.sub(a)));
		int d2 = dblcmp(b.sub(a).det(v.b.sub(a)));
		int d3 = dblcmp(v.b.sub(v.a).det(a.sub(v.a)));
		int d4 = dblcmp(v.b.sub(v.a).det(b.sub(v.a)));
		if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2)return 2;
		return ((d1 == 0 && dblcmp(v.a.sub(a).dot(v.a.sub(b))) <= 0) ||
		        (d2 == 0 && dblcmp(v.b.sub(a).dot(v.b.sub(b))) <= 0) ||
		        (d3 == 0 && dblcmp(a.sub(v.a).dot(a.sub(v.b))) <= 0) ||
		        (d4 == 0 && dblcmp(b.sub(v.a).dot(b.sub(v.b))) <= 0));
	}
	int segcrossseg_inside(line v) {
		if (v.pointonseg(a) || v.pointonseg(b) || pointonseg(v.a) || pointonseg(v.b)) return 0;
		int d1 = dblcmp(b.sub(a).det(v.a.sub(a)));
		int d2 = dblcmp(b.sub(a).det(v.b.sub(a)));
		int d3 = dblcmp(v.b.sub(v.a).det(a.sub(v.a)));
		int d4 = dblcmp(v.b.sub(v.a).det(b.sub(v.a)));
		if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2)return 1;
		return ((d1 == 0 && (dblcmp(v.a.sub(a).dot(v.a.sub(b)))) <= 0) ||
		        (d2 == 0 && dblcmp(v.b.sub(a).dot(v.b.sub(b))) <= 0) ||
		        (d3 == 0 && dblcmp(a.sub(v.a).dot(a.sub(v.b))) <= 0 ) ||
		        (d4 == 0 && dblcmp(b.sub(v.a).dot(b.sub(v.b))) <= 0));
	}
	int linecrossseg(line v) { //*this seg v line
		int d1 = dblcmp(b.sub(a).det(v.a.sub(a)));
		int d2 = dblcmp(b.sub(a).det(v.b.sub(a)));
		if ((d1 ^ d2) == -2)return 2;
		return (d1 == 0 || d2 == 0);
	}
	int linecrossline(line v) {
		if ((*this).parallel(v)) {
			return v.relation(a) == 3;
		}
		return 2;
	}
	point crosspoint(line v) {
		double a1 = v.b.sub(v.a).det(a.sub(v.a));
		double a2 = v.b.sub(v.a).det(b.sub(v.a));
		return point((a.x * a2 - b.x * a1) / (a2 - a1), (a.y * a2 - b.y * a1) / (a2 - a1));
	}
	double dispointtoline(point p) {
		return fabs(p.sub(a).det(b.sub(a))) / length();
	}
	double dispointtoseg(point p) {
		if (dblcmp(p.sub(b).dot(a.sub(b))) < 0 || dblcmp(p.sub(a).dot(b.sub(a))) < 0) {
			return min(p.distance(a), p.distance(b));
		}
		return dispointtoline(p);
	}
	point lineprog(point p) {
		return a.add(b.sub(a).mul(b.sub(a).dot(p.sub(a)) / b.sub(a).len2()));
	}
	point symmetrypoint(point p) {
		point q = lineprog(p);
		return point(2 * q.x - p.x, 2 * q.y - p.y);
	}
};

pair<ll, ll> P[N];
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
	ll n, x, y;
	cin >> n >> x >> y;
	double mn = LLONG_MAX, mx = 0.0;
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		a -= x;
		b -= y;
		P[i] = make_pair(a, b);
	}

	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		line l1 = line(point(P[i].first, P[i].second), point(P[j].first, P[j].second));
		double v = l1.dispointtoseg(point(0, 0));
		mx = max(mx, v);
		mn = min(mn, v);
		v = point(0, 0).distance(l1.a);
		mx = max(mx, v);
		mn = min(mn, v);
	}
	double v = mx * mx - mn * mn;
	if (n == 1) {
		v = 2.0 * mx;
	}
	cout << fixed << setprecision(10) << v*PI << "\n";
	return 0;
}