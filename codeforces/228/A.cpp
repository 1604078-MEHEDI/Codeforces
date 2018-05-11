#include<bits/stdc++.h>
using namespace std;
//map < int , int> mp;
set < int > s;
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(0) ;
   // cout.tie(0);
      //int ck = 1,ans = 0;
    for(int i = 0; i < 4; i++)
    {
        int a;
        cin >> a;
        //mp[a]++;
        s.insert(a);
    }
    cout<<4 - s.size();
    //cout<<ans<<endl;
}
