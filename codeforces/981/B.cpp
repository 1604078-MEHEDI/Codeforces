#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(0),cin.tie(0);
#define ll long long

map<ll, ll>m1,m2;

int main()
{
    IO

    int n;
    cin >> n;
    while(n--)
    {
        ll a,x;
        cin >>a>>x;
        m1[a] = x;
    }
    int m;
    cin >> m;
    while(m--)
    {
        ll b,y;
        cin >>b>>y;
        m2[b] = y;
        if(m1[b] < m2[b])
        {
            m1[b] = y;
        }
    }
   map<ll, ll>::iterator it;
   ll sum = 0;
   for(it = m1.begin(); it != m1.end(); it++)
   {
       sum += it->second;
   }
   cout<<sum<<endl;

}
