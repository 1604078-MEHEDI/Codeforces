#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int y,b,r;
    cin >> y >> b >> r;
    while(1){
        if((r - 1) <= b && (r - 2) <= y ){
            cout << (3*r - 3)<<endl;
            return 0;
        }
        r--;
    }
}
