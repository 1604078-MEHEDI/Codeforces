#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    long long X = 0, Y = 0;
    while(T--){
        char c;
        long long x,y;
        cin >> c >> x >> y;
        if(y > x)swap(x,y);
        if(c == '+'){
          X = max(X,x);
          Y = max(Y,y);
        }
        else{
            if( (x >= X && y >= Y))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
