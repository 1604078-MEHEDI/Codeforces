#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    map<int, int>mp, m;
    int n;
    cin >> n;
    int ar[n+1],k=0,a[n+1];
    for(int i = 0; i <n; i++)
    {
        cin >>a[i];
        m[a[i]]++;
    }
    cout<<m.size()<<"\n";
    for(int i = n - 1; i >= 0; i--)
    {
        mp[a[i]]++;
        if(mp[a[i]] == 1)
        {
           // cout<<a[i]<<" ";
            ar[k++] = a[i];
        }
    }

    for(int i = k-1; i >= 0; i--)
        cout<<ar[i]<<" ";
        return 0;
}
