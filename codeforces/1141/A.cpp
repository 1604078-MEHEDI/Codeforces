#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    if(n == m){
        cout << 0 << endl;
        return 0;
    }
    if(m%n != 0){
        cout << -1<<endl;
        return 0;
    }
    n = m/n;
    int cnt = 0;
    while(1){
            if(n == 1) break;
        if(n % 3 == 0){
            n /= 3;
            cnt++;
        }
        else if(n %2 == 0){
            n /= 2;
            cnt++;
        }
        else if(n > 1){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << cnt << endl;
}
