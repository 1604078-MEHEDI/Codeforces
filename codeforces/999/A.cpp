#include<bits/stdc++.h>
using namespace std;
int a[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;
    int cnt  = 0,ck=0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(k >= a[i] && ck == 0)cnt++;
        else ck++;
    }
    int pk = 0;
    for(int i = n; i > 0; i--){
        if(k >= a[i] && pk == 0)cnt++;
        else pk++;
    }
    if(cnt > n)cout<<n<<endl;
    else cout<<cnt<<endl;
    return 0;
}
