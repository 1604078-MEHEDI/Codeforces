#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
  
  int n;
  cin >> n;
  int a[n];
  queue<int>sq;
  for(int i =0; i < n; i++){
    int x;
    cin >> x;
    sq.push(x);
    a[x] = 1;
  }
  for(int i =0; i < n; i++){
    int x;
    cin >> x;
  //  cout<<sq.front()<<"--------"<<x<<endl;
    int cnt = 0;
    if(a[x] == 1){
      while(!sq.empty()){
        if(i >= n)break;
        if(sq.front() == x){
          cnt++;
          a[x] = 0;
          sq.pop();
          break;
        }
        else{
          a[sq.front()] = 0;
          sq.pop();
          cnt++;
        }
      }
        cout << cnt<< " ";
    }
    else{
      a[x] = 0;
      cout << "0 ";
    }
  }

  return 0;
}
