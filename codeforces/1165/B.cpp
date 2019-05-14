#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 200007;
int a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)cin >> a[i];
    sort(a, a+n);
    int cnt = 0;
    int solve = 1;
    for(int i = 0; i < n; i++)
    {
        if(a[i] >= solve)
        {
            cnt++;
            solve++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
