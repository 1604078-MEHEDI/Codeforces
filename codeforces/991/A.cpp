
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c , d;
    cin >> a >> b >> c >> d;
    a -= c;
    b -= c;
    d -= c;
    d = d - (a + b);
    if(d <= 0|| a < 0 || b < 0)
        cout<<"-1\n";
    else
        cout<<d<<endl;
    return 0;
}
