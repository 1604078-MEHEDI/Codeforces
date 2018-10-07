#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a1,a2,x,y,b1,b2;
    cin >> x >> y >> a1 >> b1 >>a2 >>b2;
    if((x>a1 && x < a2) || (x<a1 && x > a2))cout<<"NO\n";
    else if((y>b1 && y < b2) || (y<b1 && y > b2))cout<<"NO\n";
    else cout<<"YES\n";
    return 0;
}
