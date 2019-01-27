#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define MAX 10005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const int Max = 2e5 + 5;
int visit[Max];

bool cmp(const pair<pair<int,char>, int> &x, const pair<pair<int,char>, int> &y){
   // cerr << x.first.second << " "<<y.first.second <<endl;
    if(x.first.second == y.first.second)
        return x.second > y.second;
    return x.first.first < y.first.first;
}

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

    int n,k;
    cin >> n >> k;
    int a[n+2];
    for(int i = 0; i < n; i++)cin >> a[i];
        string s;
      cin >> s;
      vector<int>res;
      ll ans = 0;
      res.push_back(a[0]);
      for(int i = 1; i < n; i++){
        if(s[i-1] != s[i]){
           // cerr << a[i] << " "<<s[i]<<endl;
            sort(res.rbegin(), res.rend());
            for(int j = 0; j < res.size() && j < k; j++){
                ans += res[j];
            }
            res.clear();
        }
        res.push_back(a[i]);
      }
      sort(res.rbegin(), res.rend());
      for(int i = 0; i < res.size() && i < k ; i++)ans += res[i];
    cout << ans << endl;

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);

    return 0;
}