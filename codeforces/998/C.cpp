#include<bits/stdc++.h>
using namespace std;

int  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    long long n,x,y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    long long cnt=0;
    long long a=0,b=0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1')cnt++;
            if(s[i] == '0'){
                b = 1;
            }
            else
            {
                a += b;
                b = 0;
            }
    }
    if(s[n-1]=='0')a++;
    //cout<<a<<endl;
    if(a==0){
        cout<<a<<endl;
        return 0;
    }
    long long mn = a*y;
    long long ans = mn;
    while(a>1){
            mn -= y;
            mn += x;
            ans = min(mn,ans);
            a--;
    }
    cout<<ans<<endl;
    return 0;
}
