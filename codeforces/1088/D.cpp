#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
//set<ll>s;
int a[100005];

int query(int a, int b)
{
  cout << "? "<<a<< " "<<b<<endl;
  int ans;
  cin >> ans;
  if(ans == -2)exit(0);
  return ans;
}

int k = 30;
int main()
{

    //double start_time = clock();
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  #endif

  int a = 0, b = 0;
  int compare = -2;
  for(int i = k - 1; i >= 0; i--){
    if(compare == -2){
      compare = query(a,b);
    }
    if(compare == 0){
      int ans = query(a,b ^ (1 << i));
      if(ans == 1)
       {
         a^= (1 << i);
         b^= (1 << i);
      }
    }
    else{
      int nw = query(a^(1 << i), b^(1 << i));
      if(nw != compare){
        if(compare == -1) b^= (1 << i);
        else a ^= (1 << i);
        compare = -2;
      }
      else{
        int nw = query(a, b^(1 << i));
        if(nw == 1){
          a ^= (1 << i);
           b ^= (1 << i);
         }
      }
    }
  }
  cout << "! "<<a<< " "<<b<<endl;
  return 0;
}