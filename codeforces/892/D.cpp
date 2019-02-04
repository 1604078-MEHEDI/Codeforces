#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>

PII a[500];

void ck_print(int n)
{
    for(int i = 1; i <= n; i++)cout << a[i].first << " "<<a[i].second<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a+n+1);
  //  ck_print(n);
    int ans[n+2];
    for(int i = 1; i < n; i++)ans[a[i].second] = a[i+1].first;
    ans[a[n].second] = a[1].first;
    for(int i = 1; i <= n; i++)cout << ans[i] << " ";
    return 0;
}
