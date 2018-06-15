#include<bits/stdc++.h>
using namespace std;
int prime[300000], nprime;

int mark[1000002];

void sieve(int n)
{
    int i = 0,j, limit = sqrt(n*1)+2;

    mark[1] = 1;

    for(i = 4; i <= n; i +=2)mark[i] = 1;

    prime[nprime++] = 2;

    for(i = 3; i <= n; i += 2)
    {
        if(!mark[i])
        {
            prime[nprime++] = i;

            if(i <= limit)
            {
                for(j = i*i; j <= n; j += i * 2)
                {
                    mark[j] = 1;
                }
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(50);
    int n,m;
    cin >> n >> m;
    if(!mark[m]){
            int cnt = 0;
    for(int i = n+1; i <= m; i++)
    {
        if(!mark[i])cnt++;
    }
    if(cnt >1)cout<<"NO\n";
    else cout<<"YES\n";
    }
    else
        cout<<"NO\n";
    return 0;
    }
