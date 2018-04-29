#include<bits/stdc++.h>
#define LL long long
#define IO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int ar[20000001];

int main()
{
    IO
    int n,sum = 0,cnt=0;
    int mx1=0, mx2=0,mx=0;

    cin>>n;
    int x[n+1], y[n+1];

    for(int i = 1; i <= n; i++)
    {
        cin >> x[i];
        //mx1 = max(mx1, x[i]);
        ar[x[i]] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> y[i];
        //mx2 = max(mx1, y[i]);
        ar[y[i]] = 1;
    }
    //mx = max(mx1, mx2);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int p = x[i] ^ y[j];
          //  if(p > mx)continue;
             //   ar[p]++;
                if(ar[p] ==  1)
                {
                    cnt++;
                  //  ar[p] = 1;
                }
              //  else
                 //   ar[p] = 0;
        }
    }
    if(cnt % 2 == 0)
    cout<<"Karen"<<endl;
    else
        cout<<"Koyomi"<<endl;
    return 0;

}
