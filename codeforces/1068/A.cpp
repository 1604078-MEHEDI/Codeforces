#include <bits/stdc++.h>
using namespace std;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
  

  long long n,m,k,l;
  cin >> n >> m >> k >> l;
  if(m > n){
    cout << "-1"<<endl;
    return 0;
  }
  long long tot = k+l;
  long long each = tot/m;
  if(tot%m)each++;
  if(each*m <= n)cout<<each<<endl;
  else cout<< "-1"<<endl;
}