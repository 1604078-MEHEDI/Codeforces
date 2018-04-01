#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,p,ar[101];
cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }

    for(int i=0; i<n-1; i++)
    {
        p = abs(ar[i]-ar[i+1]);
        if(p>=2)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;
}
