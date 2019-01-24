#include <bits/stdc++.h>
using namespace std;

#define INF 1<<30
#define MAX 10005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);


int main()
{
    FASTIO
    ///*
    //double start_time = clock();
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    //*/

  int n;
  string s;
  cin >> n >> s;
  int lmt = n+1;
  string ans;
  string color = "BGR";

  do{
    int cnt = 0;
    string x;
    for(int i = 0;i < n; i++){
      x += color[i%3];
      if(color[i%3] != s[i])cnt++;
    }
    if(lmt > cnt){
      lmt = cnt;
      ans = x;
    }
  } while(next_permutation(color.begin(), color.end()));
  cout << lmt << endl<<ans<<endl;
    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}