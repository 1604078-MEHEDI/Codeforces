#include<bits/stdc++.h>
using namespace std;
const  int maxn = 100005;
int ans[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 2; i <= n; i++){
        if(!ans[i]){
            ans[i] = ++cnt;
            for(int j = i; j <= n; j += i)
                ans[j] = cnt;
        }
        cout << ans[i] << " ";
    }
    return 0;
}
