#include<bits/stdc++.h>
using namespace std;
int a[123];
vector<int>v;

int  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cnt=0;
    //while(1){
    int c1=0,c2=0;
        for(int j = 0; j < n-2; j++){

              if(a[j] % 2 == 0)c1++;
              else c2++;
              if( c1 == c2 && c1>0 && c2 >0){
                    int p = abs(a[j] - a[j+1]);
                    if(p <= m){
                       v.push_back(p);
                       //c1=0;
                       //c2=0;
                    }
                }
        }
   // }
   sort(v.begin(), v.end());
   for(int i = 0; i < v.size(); i++){
      //  cout<<v[i]<<endl;
    if(v[i] <=m){
        m -= v[i];
        cnt++;
    }
   }
   cout<<cnt<<endl;
   return 0;
}
