#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n+2];
    int start = 0, flag = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 1 && flag == 0){
            start++;
        }
        else{
            flag++;
        }
    }
  //  cout << start << endl;
    int ck = 0, cnt = 0, ans = 0;
    for(int i  = 1; i <= n; i++){
            if(a[i] == 1){
                cnt++;
                ans = max(cnt, ans);
                ck = i;
            }
            else{
                cnt = 0;
            }
    }
    if(ck == n) start += cnt;
    cout << max(ans, start)<<endl;
    return 0;
}

