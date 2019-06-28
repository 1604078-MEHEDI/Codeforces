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
    cin >> T;
   // T = 1;
    for(int cs = 1; cs <= T; cs++)
    {
      int n;
      cin >> n;
      set<int> st;
      for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        st.insert(x);
      }
      int ans = 0;
      int mx = *st.rbegin();
     // cerr << mx << endl;
      if(mx % 2 == 0 && mx % 3 == 0 && mx %5  == 0){
        if(st.count(mx/2) && st.count(mx/3) && st.count(mx/5)){
          ans = max(ans, mx/2 + mx/3 + mx/5);
        }
        //cerr << ans << endl;
      }

      vector<int> res;
      //cerr <<"-------------\n";
      while(!st.empty() && (int) res.size() < 3){
        int x = *st.rbegin();
       // cerr <<x << endl;
        //cerr << *prev(st.end()) << endl;
        st.erase(prev(st.end()));
        bool ok = true;
        for(auto it: res) ok &= (it % x != 0);
          if(ok) res.push_back(x);
      }
      ans = max(ans, accumulate(res.begin(), res.end(), 0));
      cout << ans << endl;
    }

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
    return 0;
}