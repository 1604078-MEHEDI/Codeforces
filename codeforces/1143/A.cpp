#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n+2];
    int one = 0, zero = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 0) zero++;
        else one++;
    }
    int mn = 1;
    for(int i = 1; i <= n; i++){
        if(a[i] == 0)zero--;
        else one--;
        if(one == 0 || zero == 0){
            mn = i;
            break;
        }
    }
    cout << mn << endl;
    return 0;
}
