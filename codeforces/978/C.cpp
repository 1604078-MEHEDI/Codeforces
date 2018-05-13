#include<bits/stdc++.h>
using namespace std;
//vector<pair<long long, long long> >v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,k=0;

    cin >>n >>m;
    long long p = 0,j,x=1,y=1;
    long long ar[n+1],sum[n+1];
    sum[0] = 0;
    for(int i = 1; i<=n; i++)
    {
        long long a;
        cin >>a;
        p += a;
        sum[++k] = p;
        // cout<<sum[k]<<" ";
    }
    int xx = 1;
    for(int i = 1; i <= m; i++)
    {
        long long b;
        cin >>b;
        for(int i = xx; i <= k; i++)
        {
            if(sum[i] >= b)
            {
                cout<<i<<" "<<b-sum[i-1]<<endl;
                xx = i;
                break;
            }
        }
    }
}
