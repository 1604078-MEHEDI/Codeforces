#include<bits/stdc++.h>
using namespace std;
int a[12345],x[12345];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n;
    cin >> n;
    int cnt=0,j=0,mx=0;
    for(int i =0; i < n; i++){
        cin >> x[i];
        mx = max(mx, x[i]);
        if(x[i] == 1){
            cnt++;
            if(cnt > 1){
                a[j++] = x[i-1];
                mx = 0;
            }
        }
    }
    if(cnt > 1){
    cout<<cnt<<endl;
    for(int i = 0; i < j; i++)
        cout<<a[i]<<" ";
        cout<<x[n-1];
    }
    else{
        cout<<cnt<<endl;
        cout<<mx<<endl;
    }
    return 0;
}
