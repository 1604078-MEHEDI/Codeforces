#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
//set<ll>s;
int a[100005];

int n,x,y;
int main()
{

    //double start_time = clock();
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  #endif

  int a = 0, b = 0;
  cout << "? 0 0\n";
  fflush(stdout);
  cin >> n;
  for(int i = 29; i >= 0; i--){
    cout << "? "<<((1 << i) | a) <<" "<<b<<endl;
    fflush(stdout);
    cin >> x;
    cout << "? "<<a<< " "<< ( (1 << i) | b) <<endl;
    fflush(stdout);
    cin >> y;
    if(x == y){
      if(n == -1)b |= 1 << i;
      else a |= 1 << i;
      n = x;
    }
    else{
      if(x == -1){
        a |= 1 << i;
        b |= 1 << i;
      }
    }
  }
  cout << "! "<<a<< " "<<b<<endl;
  return 0;
}