#include<bits/stdc++.h>
using namespace std;
int a[12345];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cnt=0;
    for(int i = 1; i < n; i++){
        int ck = a[i] - a[i-1];
       // cout<<ck<<endl;
        if(ck > m*2)cnt +=2;
        else if(ck == m*2)cnt++;

    }
    cout<<cnt+2<<endl;
    return 0;
}
