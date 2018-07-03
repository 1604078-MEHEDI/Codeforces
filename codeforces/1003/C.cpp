#include<bits/stdc++.h>
using namespace std;
//vector< pair<int ,int>v;
int ar[12345];//a[12345];
//queue<double>q;
//stack<double>st;

int  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    double n,k;
    cin >> n >>k;
    double sum = 0,mx=0,ans=0;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        sum +=a;
        ar[i] = sum;
        if(i >= k){
            mx = double(sum/double(i));
            //cout<<mx<<endl;
            ans = max(mx,ans);
            //cout<<ans<<endl;
        }
//        q.push(a);
    }
    double res=0;
    for(int i = 0; i <= n; i++){
           // int cnt = k;
        for(int j =i+1; j <= n; j++){
            res = ar[j] - ar[i];
          int  cnt = j - i;
           // cout<<res<<" "<<cnt<<endl;
           if(cnt>= k){
            res = res/double(cnt);
            ans = max(res, ans);
           }
        }
    }
   cout<<fixed<<setprecision(15)<<ans<<endl;
    return 0;
}
