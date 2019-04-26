#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100005;
map<LL, bool> mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    LL n;
    cin >> n;
    int cnt = 1;
    mp[n] = true;
    n += 1;
    while(1)
    {
         if(mp[n] == true && n%10 != 0)
            {
              //  cout << n << "------------\n";
                break;
            }
        if(n%10 != 0)
        {
          //  cout << n << endl;
            if(mp[n] == false)cnt++;
            mp[n] = true;
            n += 1;
        }
        else
        {
            n /=10;
        }
    }
    cout << cnt << endl;
    return 0;
}
