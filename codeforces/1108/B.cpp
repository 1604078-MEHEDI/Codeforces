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
   cin >> n;
   vector<int>num2,d;
   for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    d.push_back(x);
   }
   sort(d.begin(), d.end());
   int ans = d[n-1];
   for(int i = 0; i < n; i++){
    if(d[i] == d[i-1]){
        num2.push_back(d[i]);
        continue;
    }
    if(ans%d[i] != 0) num2.push_back(d[i]);
   }
   sort(num2.begin(), num2.end());
   cout << ans << " "<<num2[num2.size()-1]<<endl;

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}