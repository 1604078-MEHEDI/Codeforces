#include<bits/stdc++.h>
using namespace std;
int ar[1000000];

int main()
{
    int n,k;
    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    sort(ar, ar+n);
    // for(int j = 1; j <= n; j++)
    // cout<<ar[j]<<" ";
    int p = k;
    if(k == 0)
    {
        if(ar[0] == 1)
            cout<<"-1"<<endl;
        else
            cout<<"1"<<endl;
        return 0;
    }

    if(k == n)
    {
        cout<<1000000000<<endl;
        return 0;
    }
    if(ar[p-1] == ar[p])
        cout<<"-1"<<endl;
    else
        cout<<ar[p-1]<<endl;
    return 0;
}
