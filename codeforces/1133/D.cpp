#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long double a[maxn],b[maxn];
map<long double, int>c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int flag = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) cin >> b[i];
    int count = 0, ans = 0;
    for(int i = 0; i < n; i++){
            if(a[i] > 0 && b[i] > 0)flag = 1;
            else if(a[i] == 0 && b[i] == 0)
            {
                count++;
                continue;
            }
            else if(a[i] == 0)continue;
       long double x =  (long double) (-(b[i]/a[i]) );
        c[x]++;
       ans =  max(ans, c[x]);
       // cout << x << endl;
    }

    cout << (ans+ count) << endl;
    return 0;
}
