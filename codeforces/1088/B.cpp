#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
//set<ll>s;
ll s[100005];
int main()
{

    //double start_time = clock();
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  #endif

   ll n,k;
   cin >> n >> k;
   for(ll i = 1; i <= n; i++){
    cin >> s[i];
   }
   sort(s+1, s+n+1);
   ll cnt = 1;
   ll sub = 0;
    for(ll i = 0; i < k; i++){
      if(cnt <= n){
        while(1){
          if(cnt > n){
            cout << "0\n";
            break;
          }
          ll val = s[cnt];
          //cout << val << "--------"<<sub<<endl;
          ll ans = val - sub;
          if(ans > 0)cout << ans<<endl;
          else {
            cnt++;
            continue;
          }
         // s.erase(s.begin(), cnt-1);
          sub += ans;
          //cout << sub << "-------"<<endl;
          cnt++;
          break;
        }
      }
      else
      cout << "0"<<endl;
    }
    return 0;
}