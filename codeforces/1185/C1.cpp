///upsolve: minmum valuta n/2 er cheye beshi thaklei Bob win otherwise Alice
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
    int n,m;
    cin >> n >> m;
    int a[n+2];
    priority_queue<int> PQ, TQ;
   // priority_queue<int, vector<int>, greater<int> > TQ;
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    int sum = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
      sum += a[i];
      if(sum <= m)cout << cnt << " ";
      else{
        while(!PQ.empty() && sum > m){
          int x = PQ.top();
          PQ.pop();
          if(sum > m) sum -= x;//
          else break;
          TQ.push(x);
          cnt++;
        }
        cout << cnt << " ";
        while(!TQ.empty()){
          int x = TQ.top();
          TQ.pop();
          //cerr << sum << " ";
          sum += x;
          PQ.push(x);
          //cerr << x << endl;
          cnt--;
          if(cnt < 0) cnt = 0;
        }
      }
      //cerr << sum << endl;
      PQ.push(a[i]);
    }
    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}