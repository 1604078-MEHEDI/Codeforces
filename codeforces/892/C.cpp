#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n+2];
    int gcd;
    int one = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] == 1)one++;
        if(i == 0)gcd = a[i];
        else
        {
            gcd = __gcd(gcd, a[i]);
        }
    }
    // cout << "Enter---\n";
    if(one > 0)
    {
        cout << n - one << endl;
        return 0;
    }
    else if(gcd > 1)cout << "-1";
    else
    {
      //  cout << "Enter---\n";
        int mn = 99999;
        for(int i = 0; i < n; i++)
        {
            gcd = a[i];
            for(int j  = i+1; j < n; j++)
            {
                gcd = __gcd(gcd, a[j]);
                if(gcd == 1)
                {
                    mn = min(mn, j-i);
                    break;
                }
            }
        }
        cout << mn + (n-1)<<endl;
    }
    return 0;
}
