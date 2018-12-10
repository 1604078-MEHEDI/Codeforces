#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    scanf("%d %d", &n, &k);
    int cnt = 1;
    int a[n+2];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        if(a[i] != a[i+1])cnt++;
        else{
            ans = max(cnt, ans);
            cnt = 1;
        }
    }
    printf("%d\n", max(cnt, ans));
    return 0;
}
