#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--){
        int l,r,d;
        cin >> l >> r >> d;
        if(l > d){
            cout <<d<<endl;
        }
        else{
            cout << (r/d + 1)*d<<endl;
        }
    }
    return 0;
}
