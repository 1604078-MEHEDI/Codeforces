#include<bits/stdc++.h>
using namespace std;

int main()
{
    int y,w;

    cin >> y >> w;

    int ans = 7 - max(y, w);

    cout<<ans/__gcd(6, ans)<<"/"<<6/__gcd(6, ans)<<"\n";

    return 0;
}
