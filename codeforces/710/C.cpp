///Help from -> Matrix.code
#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false),cin.tie(0);
#define ll long long

int f(int n,int x, int y)
{
    int m = (x + 2 * y + 1)%n;
   // cout<<"("<<m<<")";
    return m;
}

int main()
{
  IO
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
      for(int j = 0; j < n; j++)
      {
          cout<<f(n, n - j - 1, i)*n + f(n, j, i) + 1<<" ";
      }
      cout<<endl;
  }
  return 0;
}
