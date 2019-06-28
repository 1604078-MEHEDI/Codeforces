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
    //T = 1;
    for(int cs = 1; cs <= T; cs++)
    {
      int n;
      cin >> n;
      vector<int> cnt(n);
      vector<int> cnt_good(n);
      for(int i = 0; i < n; i++){
        int a, f;
        cin >> a >> f;
        --a;
        cnt[a]++;
        if(f) cnt_good[a]++;
      }

      vector<vector<int> > types(n+1);
      for(int i = 0; i < n; i++){
        types[cnt[i]].push_back(cnt_good[i]);
        //cerr << cnt[i] << " "<< cnt_good[i] << endl;
      }

      int ans1 = 0;
      int ans2 = 0;
      multiset<int> cur;
      for(int i = n; i > 0; i--){
        for(auto x: types[i]){
          cur.insert(x);
        //  cerr << x << endl;
        }

          if(!cur.empty()){
            int t = *cur.rbegin();
            ans1 += i;
            ans2 += min(i, t);
            cur.erase(cur.find(t));
          }
      }
      cout << ans1 << " "<<ans2 << endl;
    }

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
    return 0;
}