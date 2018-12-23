#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k;
    cin >> n >> k;
    long long res = 0;
    for(int i = k-1; i >0; i--){
        if(n%i == 0){
            res = n/i;
            long long ans = res*k + i;
            cout << ans << endl;
            return 0;
        }
    }
}
