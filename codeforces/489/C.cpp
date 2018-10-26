#include <bits/stdc++.h>
using namespace std;

#define long long ll;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int max1(int x, int sum)
{
  int cnt = 0,ans = 0;
  int ck = x;
  while(sum) {
       ans = min(9,sum);
      sum = sum - ans;
      cout << ans;
      x--;
      cnt++;
  }
 // cout << cnt << " *** "<<ck<<endl;
  while(1) {
    if(cnt >= ck)break;
      cout << "0";
      cnt++;
  }
}

int min1(int x, int sum)
{
  int cnt = 0,ans = 0;
  while(x) {
      if(cnt == 0){
         ans = max(1, sum - (x-1)*9);
      }
      else{
        ans = max(0, sum - (x-1)*9);
      }
      cnt++;
      x--;
      cout << ans;
      sum = sum - ans;
  }
}


int main()
{
  FastIO;
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int m,s;
    cin >> m >> s;
    if(m == 1 && s < 10){
      cout << s << " "<<s<<endl;
      return 0;
    }
    int test = m*9;
    if(s > test || s < 1){
      cout << "-1 -1";
      return 0;
    }
     min1(m,s);
     cout << " ";
     max1(m, s);
    return 0;
}
