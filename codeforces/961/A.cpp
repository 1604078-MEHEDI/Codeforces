#include<bits/stdc++.h>
using namespace std;
map<int, int>mp;

int main()
{
    int n,m,ar[1001],a,q=99999,p;

    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        cin>>a;

        mp[a]++;
    }

    map<int,int>::iterator it;

    for (it = mp.begin(); it != mp.end(); it++)
    {
        p = it->second;
        //cout<<p<<" ";

        if(q > p)
        {
            q = p;
        }
    }
    int s = mp.size();
   // cout<<s;
    if(s>=n)
    cout<<q<<endl;
    else
        cout<<0<<endl;
}
