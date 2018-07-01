#include<bits/stdc++.h>
using namespace std;
int a[12345];

int  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int mn = 99999;
    int idx = 0;
    for(int i = 0; i < n; i++){
        cin >>a[i];
        if(mn > a[i]){
            mn = a[i];
            idx = i;
        }
    }
    if(n == 1){
     cout<<-1<<endl;
     return 0;
    }
    if(n == 2 && (a[0]==a[1])){
        cout<<-1<<endl;
        return 0;
    }
    else
    {
        cout<<n-1<<endl;
        for(int i = 0; i < n; i++){
            if(i == idx)continue;
            else
                cout<<i+1<<" ";
        }
    }
    return 0;

}
