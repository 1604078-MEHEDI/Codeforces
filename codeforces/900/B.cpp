#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b ,c;
    cin >> a >> b >> c;
    for(int i = 1; i <= 100000; i++){
            a *= 10;
        int ans = a/b;
        //cout << ans<< " ";
        if(ans == c){
            cout << i<<endl;
            return 0;
        }
        a = a%b;
    }
    cout << -1<<endl;
    return 0;
}
