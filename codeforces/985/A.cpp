#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(0),cin.tie(0);

int ar[1000],br[1000],cr[1000];

int main()
{
    IO
    int n;

    cin >> n;
    int cnt = 0,count=0;
    for(int i = 1; i <= n/2; i++)
    {
        cin >>ar[i];
        if(ar[i] %2 == 0)cnt++;
        br[ar[i]] = 999;
        cr[ar[i]] = 999;
    }
    sort(ar+1, ar+n/2+1);
    if(cnt == n/2)
    {
        cout<<0<<endl;
        return 0;
    }
    int mv1 = 0, mv2 = 0,kk=2,k=1;
        for(int i = 1; i <= n/2; i++)
        {
            if(ar[i] % 2 != 0)
            {
                for(int j = kk; j <= n; j += 2 )
                {
                    if(br[j] == 0)
                    {
                        mv1 += abs(j - ar[i]);
                        br[j] = 999;
                        kk = j+2;
                        break;
                    }
                }
            }
        }
       // cout<<count<<endl;
        for(int i = 1; i <= n/2; i++)
        {
            if(ar[i] % 2 == 0)
            {
                for(int j = k; j <= n; j += 2 )
                {
                    if(cr[j] == 0)
                    {
                       //cout<<j<<"--"<<ar[i]<<endl;
                        mv2 += abs(j - ar[i]);
                        cr[j] == 999;
                        k = j+2;
                        break;
                    }
                }
            }
        }

    cout<<min(mv1,mv2)<<endl;
    return 0;
}
