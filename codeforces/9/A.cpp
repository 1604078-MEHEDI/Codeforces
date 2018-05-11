#include<bits/stdc++.h>
using namespace std;

int main()
{
    int y,w;

    cin >> y >> w;

    int mx = max(y, w);
    int ans = 7 - mx;
    if(ans == 7)cout<<0<<"/"<<1<<"\n";
    else if(ans == 6) cout<<1<<"/"<<1<<"\n";
    else if(ans == 5)cout<<5<<"/"<<6<<"\n";
    else if(ans == 4)cout<<2<<"/"<<3<<"\n";
    else if(ans  == 3)cout<<1<<"/"<<2<<"\n";
    else if(ans == 2)cout<<1<<"/"<<3<<"\n";
    else if(ans == 1)cout<<1<<"/"<<6<<"\n";
    else cout<<0<<"/"<<1<<"\n";
    return 0;
}
