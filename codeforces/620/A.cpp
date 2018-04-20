#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c,d;
    cin>>a>>b>>c>>d;

    if(a < 0)int x1 = a*(-1);
    int x1 = a;
    if(b < 0)int y1 = b*(-1);
    int y1 = b;
    if(c < 0)int x2 = c*(-1);
    int x2 = c;
    if(d < 0)int y2 = d*(-1);
    int y2 = d;

    int p = abs(x1 - x2);
    int q = abs(y1 - y2);

    cout<<max(p, q)<<endl;
    return 0;
}
