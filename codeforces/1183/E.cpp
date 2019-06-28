/// upsolve: topic- BFS
#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 100005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

const ll mod = 1e9 + 7;


int main()
{
    FASTIO
    ///*
    //double start_time = clock();
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
//*/
    int T;
    //cin >> T;
    T = 1;
    for(int cs = 1; cs <= T; cs++)
    {
      int n, k;
      cin >> n >> k;
      string s;
      cin >> s;
      int ans = 0;
      queue<string> Q;
      set<string > st;
      Q.push(s);
      st.insert(s);
      while(!Q.empty() && int(st.size()) < k){
        string u = Q.front();
        Q.pop();
        for(int i = 0; i < (int) u.size(); i++){
          string v = u;
          //cerr << v << " ";
          v.erase(i, 1);
         // cerr << v << endl;
          if(!st.count(v) && (int)st.size() + 1 <= k){
            Q.push(v);
            st.insert(v);
            ans += n - v.size();
          }
        }
      }
      if((int) st.size() < k) cout << "-1\n";
      else cout << ans << endl;
    }

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
    return 0;
}