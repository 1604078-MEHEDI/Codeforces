#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n+2];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int x = a[n-2] - a[0];
    int y = a[n-1] - a[1];
    cout << min(x,y)<<endl;
    return 0;
}
