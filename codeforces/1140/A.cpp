#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n+5];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int last = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
         //   if(last >= a[i]) continue;
  //  cout << last << endl;
            cnt++;
        for(int j = i; j <= a[i]; j++){
                i = max(i, a[j]);
        }
    }
    cout << cnt << endl;
    return 0;
}
