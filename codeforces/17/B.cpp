
#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
template < typename F, typename S >ostream& operator << ( ostream& os, const pair< F, S > & p ) {return os << "(" << p.first << ", " << p.second << ")";}
template < typename T >ostream &operator << ( ostream & os, const vector< T > &v ) {os << "{";for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin() ) os << ", ";os << *it;}return os << "}";}
template < typename T >ostream &operator << ( ostream & os, const set< T > &v ) {os << "[";for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin()) os << ", ";os << *it;}return os << "]";}
template < typename F, typename S >ostream &operator << ( ostream & os, const map< F, S > &v ) {os << "[";for (auto it = v.begin(); it != v.end(); ++it) {if ( it != v.begin() ) os << ", ";os << it -> first << " = " << it -> second ;}return os << "]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
void faltu () { cerr << endl; }
template <typename T>void faltu( T a[], int n ) {for (int i = 0; i < n; ++i) cerr << a[i] << ' ';cerr << endl;}
template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) { cerr << arg << ' '; faltu(rest...); }

const ll N = 30005;
ll id[N], nodes, edges, idx;

pair <ll, pair<ll, ll> > p[N], output[N];
int vis[N];
void initialize()
{
  for (ll i = 0; i < N; i++)
  {
    id[i] = i;
  }
}

ll root(ll x)
{
  while (id[x] != x)
  {
    id[x] = id[ id[x] ];
    x = id[x];
  }
  return x;
}

void union1(ll x, ll y)
{
  ll p = root(x);
  ll q = root(y);
  if(p == q) return;
  id[p] = id[q];
}

ll kruskal(pair <ll, pair<ll, ll> > p[])
{
  int n = nodes;
  idx = 0;
  ll x, y;
  ll cost, minimumcost = 0;
  int cnt = 0;
  for (ll i = 0; i < edges; i++)
  {
    /// selecting edges one by one in increasing order from the beginning.
    x = p[i].second.first;
    y = p[i].second.second;
    cost = p[i].first;
    /// check if the selected edge is creating a cycle or not
    if (x != y && !vis[y])
    {
      vis[y] = x;
      cnt++;
      minimumcost += cost;
      output[idx++] = make_pair(cost, make_pair(x, y));
      union1(x, y);
    }
  }
  //dbg(cnt,n);
  if (cnt+1 != n)return -1;
  return minimumcost;
}

int main()
{
  ///*
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  //*/

  // freopen("in.txt", "r", stdin);

  ll x, y;
  ll weight, minimumcost;
  initialize();
  // scanf("%lld %lld", &nodes, &edges);
  scanf("%lld", &nodes);
  for (int i = 0; i < nodes; i++) {
    int x;
    cin >> x;
  }
  scanf("%lld", &edges);
  //cout << nodes << " & "<<edges<<endl;
  for (ll i = 0; i < edges; i++)
  {
    cin >> x >> y >> weight;
    p[i] = make_pair(weight, make_pair(x, y));
  }
  sort(p, p + edges);
  // for(ll i = 0; i < edges; i++){
  // cout << p[i].second.first << " "<<p[i].second.second << " "<<p[i].first<<endl;
  //}
  minimumcost = kruskal(p);
  //cout << "MST :- ";
  printf("%lld\n", minimumcost);
  // for (ll i = 0; i < idx; i++) {
  //   cout << output[i].second.first << " " << output[i].second.second << " " << output[i].first << endl;
  // }
}

