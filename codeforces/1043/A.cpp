#include <bits/stdc++.h>
using namespace std;

#define long long ll;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main()
{
  FastIO;
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int sum =0,mx = 0;
    for(int i = 0; i < n; i++){
      int x;
      cin >>x;
      sum += x;
      mx = max(mx,x);
    }
    int i = mx;
    while(1) {
        int ans = i*n;
        //cout << ans << " "<<sum<<endl;
        int ck = ans - sum;
        if(ck > sum){
          cout << i << endl;
          return 0;
        }
        i++;
    }
    
    return 0;
}