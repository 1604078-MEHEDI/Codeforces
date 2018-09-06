#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int p = (2*k+1);
    // cout<<p<<endl;
    if(k == 0)
    {
        cout<<n<<endl;
        for(int i = 1; i <= n; i++)
        {
            cout<<i<<" ";
        }
        return 0;
    }
    else if(k >= n)
    {
        cout<<1<<endl;
        cout<<n<<endl;
        return 0;
    }
    else if(n % p == 0)
    {
        cout<<(n/p)<<endl;
        cout<<(k+1)<<" ";
        int ans = (k+1) + p;
        for(int i = 1; i < (n/p); i++)
        {
            cout<<ans<<" ";
            ans += p;
        }
    }
    else if(p >= n)
    {
        cout<<1<<endl;
        cout<<k<<endl;
        return 0;
    }
    else
    {
        int ans = n/p + 1;
        // cout<<p<<" ";
        cout<<ans<<endl;
        if(((ans- 1)*p + k + 1) >= n)
        {
            int res = 1;
            cout<<res<<" ";
            res += p;
            for(int i = 1; i < ans; i++)
            {
                cout<<res<<" ";
                res += p;
            }
        }
        else
        {
            int ext = n - (ans - 1)*p;
            int val = ext/2 + 1;
            for(int i = 0; i < ans; i++)
            {
                cout<<val<<" ";
                val += p;
            }
        }
    }
    return 0;
}
