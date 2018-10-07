#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        long long a,b;
        cin >> a >> b;
        if((a - b) > 1)cout<<"NO\n";
        else
        {
            long long x = a + b;
            bool prime = (x >= 2);
            for(long long i = 2; i*i <= x; i++)
            {
                if(x % i == 0)
                {
                    cout <<"NO\n";
                    prime = false;
                    break;
                }
            }
            if(prime)
                cout<<"YES\n";
        }
    }
    return 0;
}
