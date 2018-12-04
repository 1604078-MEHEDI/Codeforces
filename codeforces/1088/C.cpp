#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
//set<ll>s;
int a[100005];
int main()
{

    //double start_time = clock();
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  #endif

  int n;
  cin >> n;
  for(int i = 1; i <= n; i++)cin >> a[i];

    int mx = 100000;
  cout << n+1<<endl;
  cout << 1 << " " << n << " " << mx << endl;
  for(int i = 1; i <= n; i++){
    a[i] += mx;
    cout << 2 << " "<< i << " " << a[i] - i << endl;
  }
  return 0;
}