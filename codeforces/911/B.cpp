#include <bits/stdc++.h>
using namespace std;

#define long long ll;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 10000000;
int dx[4] = {-1, 0, 0 , 1};
int dy[4] = {0, 1, -1, 0};

int main()
{
  FastIO;
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  #endif

    int n,a,b;
    cin >> n >> a >> b;
    int hg = (a+b)/n;
    //int mn = min(a,b);
   // int mx = max(a,b);
    while(hg > 0) {
      int cnt_A = a/hg;
      int cnt_B = b/hg;
      int ans = min(cnt_A, cnt_B);
      if(cnt_A + cnt_B >= n && ans > 0)break;
      else hg--;
     }
     cout << hg<<endl;
     return 0;
}