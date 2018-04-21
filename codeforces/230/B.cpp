#include<bits/stdc++.h>
using namespace std;
int prime[300000], nprime;
int mark[1000002];
void sv(int n)
{
    int i, j, limit = sqrt(n *1) + 2;
    mark[1] = 1;

    for(i = 4; i <= n; i += 2) mark[i]  = 1;

    prime[nprime++] = 2;
    for(i  = 3; i<=n; i +=2)
    {
        if(!mark[i])
        {
            prime[nprime++] = i;

            if(i <= limit)
            {
                for(j = i*i; j <= n; j += i*2)
                    mark[j]  = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int count=1000000;
    long long m,a,ck;
    cin>>m;
    sv(count);
   /* for(int i=0; i<nprime; i++)
    {
        count++;
        //cout<<prime[i]<<" ";
        cout<<mark[i]<<" ";
    }
    cout<<endl;
  //  cout<<count;*/

    for(int i=1; i<=m; i++)
    {
        cin>>a;
        ck = sqrt(a);
      //  cout<<ck<<" ";
       // cout<<mark[ck]<<" ";
        if(mark[ck]==0 && ck*ck == a)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;

}
