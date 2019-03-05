#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a == 0 && d == 0 && c > 0)cout << 0 << endl;
    else if(a == d)cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}
