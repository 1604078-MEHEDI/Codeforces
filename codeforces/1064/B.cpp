#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int x;
        scanf("%d", &x);
        int cnt = __builtin_popcount(x);
        int ans = 1 << cnt;
        printf("%d\n", ans);
    }
    return 0;
}
