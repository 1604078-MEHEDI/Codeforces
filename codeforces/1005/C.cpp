#include<bits/stdc++.h>
using namespace std;
#define  LL long long
LL x[123456],ck[12345];
map<LL, LL>mp,a;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    LL n;
    cin >> n;
    for(LL i = 0; i < n; i++)
    {
        cin >> x[i];
        mp[x[i]]++;
    }
    LL cnt = 0;
    for(LL i = 0; i < n; i++)
    {
        LL p = x[i];
        LL test = 0LL;
        for(LL j = 0; j < 31; j++)
        {
            int ck = 1 << j;
            //cout<<ck<<endl;
            LL pk =(ck - x[i]);
                if(pk == x[i])
                {
                    if(mp[pk] > 1LL)
                    {
                        test++;
                        break;
                    }
                }
                else
                {
                    if(mp[pk])
                    {
                        test++;
                        break;
                    }
                }
        }
        if(test == 0LL)cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
