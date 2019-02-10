#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long x,y,z,a,b,c,total;
    cin >> x >> y >> z >> a >> b >> c;
    int dimitry = 0 , michal = 0, andrew = 0;
    if(a >= x){
        andrew = 1;
        a -= x;
    }
    if((a+b) >= y){
        michal = 1;
         total = a+b;
        total -= y;
    }
    if(andrew == 1 && michal == 1 && (total + c) >= z){
        cout << "YES\n";
    }
    else cout << "NO\n";
    return 0;
}
