#include<bits/stdc++.h>
using namespace std;

int prime[300000],nprime;
int mark[1000002];
int ar[1000000];

void sv(int n)
{
    int i,j,limit = sqrt(n*1) + 2;
    mark[1] = 1;

    for(i = 4; i<=n; i +=2)mark[i]  = 1;

    prime[nprime++] = 2;

    for(i = 3; i <= n; i +=2)
    {
        if(!mark[i])
        {
            prime[nprime++] = i;

            if(i <= limit)
            {
                for(j = i*i; j <= n; j += i*2)
                    mark[j] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 100000;
    sv(n);
    int m,k=0,p=0,q=0;
    cin>>m;

    for(int i=0; i <=m; i++)
    {
        //if(prime[i] == 0)continue;
       // cout<<prime[3]<<" ";
        p = prime[i];
      //  q = prime[i] * prime[i];
        if(p <= m)ar[k++] = p;
       // if(q <= m) ar[k++] = q;
        int cnt = 1;
        while(1)
        {
            cnt++;
            q = pow(p, cnt);
            if(q > m)break;
            ar[k++] = q;
        }
    }
  //  cout<<endl;
    cout<<k<<"\n";
    for(int i=0; i < k; i++)
        cout<<ar[i]<<" ";

}
