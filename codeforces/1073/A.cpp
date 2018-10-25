#include <bits/stdc++.h>
using namespace std;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
  
  int n;
  string s,x,y,z;
  cin >> n >> s;
  int flag=0;
  for(int i = 0; i < n - 1; i++){
   // cout << s[i] << " "<< s[i+1]<<" "<< s[i+2]<<endl;
    if(s[i] != s[i+1]){
      flag = 1;
      //cout << "----------------"<<endl;
      x = s[i];
      y = s[i+1];
     // z = s[i+2];
      break;
    }
  }
  //cout << str<<endl;
  if(flag){
    cout<< "YES"<<endl;
    cout<<x<<y<<endl;
  }
  else{
    cout << "NO\n";
  }
  return 0;
}
