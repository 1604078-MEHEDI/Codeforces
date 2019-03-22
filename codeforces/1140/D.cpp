#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long ans =0;
    for(long long i = 2; i < n; i++){
        ans += (i*(i+1));
    }
    cout << ans << endl;
    return 0;
}
