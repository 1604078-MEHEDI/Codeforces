#include<bits/stdc++.h>
using namespace std;
//char ck [101][101];
int a[1234567];
//int sum[123456];
//const inf = 1 << 28;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    int tot=0;
    for(int i = 1; i <= n; i++){
            int b;
         cin >> b;
         tot += b;
         a[i] = tot;
    }
    int mn = 1e9, idx=k;
    for(int i = 1; i <= n; i++){
        if(i >= k){
            int val = a[i] - a[i-k];
            if(mn > val){
                mn = val;
                idx = i - (k - 1);
            }
        }
    }
    cout<<idx<<endl;
    return 0;
}
